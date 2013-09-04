#include "BattleUnit.h"
#include "BattleObj.h"
#include "SceneMgr.h"

int CBattleMoveProc::DoMove(CBattleObj *battle_obj)
{
    CBattleUnit *pUnit = m_holder;
    int cur_tick = battle_obj->m_iCurrTick;    

    if(pUnit == NULL)
    {
        return -1;        
    }
        
    if(pUnit->m_state != battle_unit_state::STATE_MOVE)
    {
        return -1;        
    }
    
    MapInfo *mapInfo = SCENE_MGR->GetMapInfo(battle_obj->m_stBattleCfg.iMapId);

    if(mapInfo == NULL)
    {
        return -1;        
    }

    if(m_next_pos_tick < cur_tick)
    {
        return 0;
    }

    PointInfo posInfo = CBattleUtils::GetPosFromPixel(m_next_pos_pixel.iPosX, m_next_pos_pixel.iPosY, mapInfo->tileHeight, mapInfo->startH);
    pUnit->iPosX = posInfo.iPosX;
    pUnit->iPosY = posInfo.iPosY;

    if(m_is_last_pixel)
    {
        pUnit->m_state = battle_unit_state::STATE_NONE;
        ResetMove();        

        return 0;        
    }

    return pUnit->MovePath(battle_obj, m_pos_list, m_next_pos_pixel);    
}

int CBattleUnit::MovePath(CBattleObj *battle_obj, std::list<PointInfo> &posList, PointInfo last_node_pixel)
{
    CBattleUnit *pUnit = this;
    const double PIXEL_INTERVAL = battle::PIXEL_INTERVAL;    
    const double PIXEL_SPEED = pUnit->GetSpeed();    
    const double FRAME_NUM = battle::FRAME_NUM;    
    double remain_dis = PIXEL_INTERVAL;    
    int cur_tick = battle_obj->m_iCurrTick;
    MapInfo *mapInfo = SCENE_MGR->GetMapInfo(battle_obj->m_stBattleCfg.iMapId);

    if(mapInfo == NULL)
    {
        return -1;        
    }
    
    while(!posList.empty())
    {
        const PointInfo &pos = posList.front();
        PointInfo nodePixel = CBattleUtils::GetPixelFromPos(pos.iPosX, pos.iPosY, mapInfo->tileHeight, mapInfo->startH);
        double pixel_dis = CBattleUtils::GetLineDistance(nodePixel.iPosX, nodePixel.iPosY, last_node_pixel.iPosX, last_node_pixel.iPosY);
        
        if(pixel_dis == remain_dis)
        {
            pUnit->m_move_proc.m_next_pos_tick = (double)cur_tick + PIXEL_INTERVAL * FRAME_NUM / PIXEL_SPEED;
            pUnit->m_move_proc.m_next_pos_pixel = nodePixel;
            posList.pop_front();            
            pUnit->m_move_proc.m_pos_list = posList;
            
            if(posList.empty())
            {
                //最后一个节点
                pUnit->m_move_proc.m_is_last_pixel = true;                
            }

            break;
        }

        if(pixel_dis < remain_dis)
        {
            remain_dis = remain_dis - pixel_dis;            
            posList.pop_front();
            
            if(posList.empty())
            {
                pUnit->m_move_proc.m_next_pos_pixel = nodePixel;
                pUnit->m_move_proc.m_next_pos_tick = (double)cur_tick + (PIXEL_INTERVAL - remain_dis) * FRAME_NUM / PIXEL_SPEED;
                pUnit->m_move_proc.m_is_last_pixel = true;

                break;                
            }

            last_node_pixel = nodePixel;            
        }
        else
        {
            double x_dis = nodePixel.iPosX - last_node_pixel.iPosX;
            double y_dis = nodePixel.iPosY - last_node_pixel.iPosY;
            PointInfo nodePixelLast;
            nodePixelLast.iPosX = last_node_pixel.iPosX + remain_dis * x_dis / pixel_dis;
            nodePixelLast.iPosY = last_node_pixel.iPosY + remain_dis * y_dis / pixel_dis;
            PointInfo posInfo = CBattleUtils::GetPosFromPixel(nodePixelLast.iPosX, nodePixelLast.iPosY, mapInfo->tileHeight, mapInfo->startH);
        
            if(!SCENE_MGR->CanStay(battle_obj->m_stBattleCfg.iMapId, posInfo.iPosX, posInfo.iPosY))
            {
                if(m_state == battle_unit_state::STATE_MOVE)
                {                
                    CSSvrPkt pkg;
                    pkg.stHead.iCmd = SU_CMD_BATTLE_RESET_POS;
                    pkg.stBody.stBattleResetPos.iUnitid = pUnit->iUnitId;
                    pkg.stBody.stBattleResetPos.iTick = cur_tick;                
                    pkg.stBody.stBattleResetPos.iPosX = pUnit->iPosX;                
                    pkg.stBody.stBattleResetPos.iPosY = pUnit->iPosY;
                    battle_obj->SendBroadcast(pkg);
                }                
                
                return -1;
            }

            pUnit->m_move_proc.m_next_pos_pixel = nodePixelLast;
            pUnit->m_move_proc.m_next_pos_tick = (double)cur_tick + PIXEL_INTERVAL * FRAME_NUM / PIXEL_SPEED;
            pUnit->m_move_proc.m_pos_list = posList;            

            break;
        }        
    }

    return 0;    
}
