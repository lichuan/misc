#include <sys/time.h>
#include <list>
#include <cstdlib>
#include <map>
#include <iostream>

typedef int int32;
typedef unsigned int uint32;

struct Point
{
    Point(int32 x, int32 y)
    {
        m_x = x;
        m_y = y;
    }

    Point()
    {
        m_x = 0;
        m_y = 0;
    }

    int32 hash() const
    {
        return m_x * 10000 + m_y;
    }    

    bool operator==(const Point &pos) const
    {
        return m_x == pos.m_x && m_y == pos.m_y;
    }    
    
    int32 m_x;
    int32 m_y;
};

//路径节点
struct Node
{
    Node(const Point &pos, int32 g, int32 h, const Node *parent)
    {
        m_pos = pos;
        m_g = g;
        m_h = h;
        m_f = g + h;        
        m_parent = parent;        
    }

    Point m_pos; //节点的坐标
    int32 m_g; //缓存g值
    int32 m_h; //缓存h    
    int32 m_f; //缓存f值
    const Node *m_parent; //该节点的前置节点
};

//A星寻路实现
template<typename T, int32 MAX_NODE>
class Astar_Impl
{
    template<int32>
    friend class Astar;
    
private:
    Astar_Impl(const T &point_check) : m_point_check(point_check)
    {
    }

    ~Astar_Impl()
    {
        clear_node();        
    }
    
    bool is_block(const Point &pos) const
    {
        return m_point_check.is_block(pos);
    }

    int32 h_value(const Point &src_pos, const Point &dest_pos) const
    {
        int32 x_diff = src_pos.m_x - dest_pos.m_x;
        int32 y_diff = src_pos.m_y - dest_pos.m_y;
        x_diff = abs(x_diff);
        y_diff = abs(y_diff);
        int32 v1 = 0;
        int32 v2 = 0;        

        if(x_diff > y_diff)
        {
            v1 = x_diff - y_diff;
            v2 = y_diff;            
        }
        else
        {
            v1 = y_diff - x_diff;
            v2 = x_diff;
        }

        return v1 * 10 + v2 * 14; //横竖方向的权重10，斜方向的权重14
    }

    bool exist_in_close(const Point &pos)
    {
        return m_close_map.find(pos.hash()) != m_close_map.end();
    }

    void clear_node()
    {
        for(std::map<int32, Node*>::const_iterator iter = m_open_map.begin(); iter != m_open_map.end(); ++iter)
        {
            delete iter->second;
        }
        
        for(std::map<int32, Node*>::const_iterator iter = m_close_map.begin(); iter != m_close_map.end(); ++iter)
        {
            delete iter->second;
        }
    }
    
    Node* get_minimum_f_node_from_open()
    {
        std::multimap<int32, Node*>::iterator iter = m_order_by_f_map.begin();

        return iter->second;
    }

    Node* get_node_from_open(const Point &pos)
    {
        std::map<int32, Node*>::const_iterator iter = m_open_map.find(pos.hash());

        if(iter == m_open_map.end())
        {
            return NULL;
        }

        return iter->second;
    }

    const Node* add_around_node_to_open(const Node *cur_node, const Point &dest_pos)
    {
        static int32 around_offset[8][2] = {
            {0, -1}, //top
            {1, -1}, //top-right
            {1, 0},
            {1, 1},
            {0, 1},
            {-1, 1},
            {-1, 0},
            {-1, -1},
        };

        const Point &cur_pos = cur_node->m_pos;
        int32 g_inc = 0;        
        
        for(int32 i = 0; i != 8; ++i)
        {
            Point pos(cur_pos.m_x + around_offset[i][0], cur_pos.m_y + around_offset[i][1]);

            if(pos == dest_pos)
            {
                return cur_node;
            }

            if(is_block(pos))
            {
                continue;
            }

            if(exist_in_close(pos))
            {
                continue;
            }

            g_inc = 10;
            
            //判断斜方向的两边是否有阻挡
            if(i % 2 == 1)
            {
                int32 idx_1 = (i - 1) % 8;
                int32 idx_2 = (i + 1) % 8;
                Point pos_1(cur_pos.m_x + around_offset[idx_1][0], cur_pos.m_y + around_offset[idx_1][1]);
                Point pos_2(cur_pos.m_x + around_offset[idx_2][0], cur_pos.m_y + around_offset[idx_2][1]);

                if(is_block(pos_1) || is_block(pos_2))
                {
                    continue;
                }

                g_inc = 14;                
            }

            Node *node = get_node_from_open(pos);
            int32 g = cur_node->m_g + g_inc;

            if(node != NULL)
            {
                if(node->m_g > g)
                {
                    node->m_parent = cur_node;
                    node->m_g = g;
                    node->m_f = g + node->m_h;
                    m_order_by_f_map.erase(m_iter_map[node]);
                    m_iter_map[node] = m_order_by_f_map.insert(m_order_by_f_map.begin(), std::make_pair(node->m_f, node));                    
                }

                continue;
            }

            Node *new_node = new Node(pos, g, h_value(pos, dest_pos), cur_node);
            m_open_map.insert(std::make_pair(pos.hash(), new_node));
            m_iter_map.insert(std::make_pair(new_node, m_order_by_f_map.insert(m_order_by_f_map.begin(), std::make_pair(new_node->m_f, new_node))));            
        }

        return NULL;            
    }
    
    std::list<Point> find_path(const Point &src_pos, const Point &dest_pos)
    {
        std::list<Point> pos_list;
        
        if(is_block(src_pos) || is_block(dest_pos) || src_pos == dest_pos)
        {
            return pos_list;
        }
        
        //反向查找
        Node *node = new Node(dest_pos, 0, h_value(dest_pos, src_pos), NULL);
        m_open_map.insert(std::make_pair(dest_pos.hash(), node));        
        m_iter_map.insert(std::make_pair(node, m_order_by_f_map.insert(m_order_by_f_map.begin(), std::make_pair(node->m_f, node))));
        int32 num = 0;        

        while(!m_open_map.empty())
        {
            if(++num > MAX_NODE)
            {
                return pos_list;
            }
            
            Node *node = get_minimum_f_node_from_open();                        
            m_open_map.erase(node->m_pos.hash());
            m_order_by_f_map.erase(m_iter_map[node]);
            m_iter_map.erase(node);
            m_close_map.insert(std::make_pair(node->m_pos.hash(), node));                        
            const Node *first_node = add_around_node_to_open(node, src_pos);

            if(first_node != NULL)
            {
                const Node *node = first_node;
                std::cout << "num: " << num << std::endl;

                while(node != NULL)
                {
                    pos_list.push_back(node->m_pos);
                    node = node->m_parent;                    
                }

                return pos_list;                
            }
        }        
    }

    std::map<int32, Node*> m_open_map;
    std::map<int32, Node*> m_close_map;
    std::multimap<int32, Node*> m_order_by_f_map;
    std::map<Node*, std::multimap<int32, Node*>::iterator> m_iter_map;    
    const T& m_point_check;    
};

template<int32 MAX_NODE>
class Astar
{
public:
    static Astar* instance()
    {
        if(m_instance == NULL)
        {
            m_instance = new Astar;
        }

        return m_instance;
    }

    //对每一次查找单独创建一个A星实现类，以支持在多线程环境中进行A星寻路
    template<typename T>
    std::list<Point> find_path(const T &point_check, const Point &src_pos, const Point &dest_pos) const
    {
        Astar_Impl<T, MAX_NODE> impl(point_check);
        
        return impl.find_path(src_pos, dest_pos);
    }

private:
    Astar()
    {
    }

    static Astar *m_instance;    
};

template<int32 MAX_NODE>
Astar<MAX_NODE>* Astar<MAX_NODE>::m_instance = NULL;

class CB
{
public:
    bool is_block(const Point &pos) const
    {
        if(pos.m_x == 500 && pos.m_y != 0)
        {
            return true;
        }
        
        return false;
    }
};

int main()
{
    CB cb;
    int32 x1, y1, x2, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;
    std::cout << "src: (" << x1 << ", " << y1 << ") dest:(" << x2 << ", " << y2 << ")" << std::endl;
    struct timeval time_begin, time_end;
    gettimeofday(&time_begin, NULL);
    std::cout << "start time: " << time_begin.tv_sec << " " << time_begin.tv_usec << std::endl;    
    std::list<Point> path_list = Astar<1000000>::instance()->find_path(cb, Point(x1, y1), Point(x2, y2));
    gettimeofday(&time_end, NULL);
    std::cout << "end time: " << time_end.tv_sec << " " << time_end.tv_usec << std::endl;
    std::cout << "cost time: " << 1000000 * (time_end.tv_sec - time_begin.tv_sec) + time_end.tv_usec - time_begin.tv_usec << " 微秒" << std::endl;    
    
    for(std::list<Point>::const_iterator iter = path_list.begin(); iter != path_list.end(); ++iter)
    {
        std::cout << "(" << iter->m_x << ", " << iter->m_y << ")->";
    }

    std::cout << std::endl;
}
