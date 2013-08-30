#include <string>
#include <map>

typedef unsigned int uint32;

class Entity
{
protected:
    Entity()
    {
        m_id = 0;
    }

public:
    virtual ~Entity()
    {
    }

    void id(uint32 _id)
    {
        m_id = _id;
    }

    uint32 id()
    {
        return m_id;
    }

    void name(std::string _name)
    {
        m_name = _name;
    }

    std::string name()
    {
        return m_name;
    }
    
private:
    uint32 m_id;
    std::string m_name;
};

//对所有子元素进行回调
template<typename Concrete_Entity>
class Entity_Exec
{
public:
    Entity_Exec()
    {
    }

    virtual ~Entity_Exec()
    {
    }

    virtual bool exec(Concrete_Entity *entity)
    {
        return true;        
    }    
};

//条件执行
template<typename Concrete_Entity>
class Entity_Exec_Condition
{
public:
    Entity_Exec_Condition()
    {
    }

    virtual ~Entity_Exec_Condition()
    {
    }

    virtual bool can_exec(Concrete_Entity *entity) = 0;
};

template<typename Key>
class Entity_Map
{
protected:
    Entity_Map()
    {
    }

    ~Entity_Map()
    {
    }

    void add_entity(Key key, Entity *entity)
    {
        m_entity_map[key] = entity;
    }

    Entity* get_entity(Key key) const
    {
        typename std::map<Key, Entity*>::const_iterator iter = m_entity_map.find(key);

        if(iter == m_entity_map.end())
        {
            return NULL;
        }

        return iter->second;
    }

    uint32 size()
    {
        return m_entity_map.size();
    }

    bool empty()
    {
        return m_entity_map.empty();
    }

    void clear()
    {
        m_entity_map.clear();
    }

    template<typename Concrete_Entity>
    void exec(Entity_Exec<Concrete_Entity> &cb)
    {
        for(typename std::map<Key, Entity*>::iterator iter = m_entity_map.begin(); iter != m_entity_map.end(); ++iter)
        {
            cb.exec(static_cast<Concrete_Entity*>(iter->second));
        }
    }

    template<typename Concrete_Entity>
    bool exec_until_false(Entity_Exec<Concrete_Entity> &cb)
    {
        for(typename std::map<Key, Entity*>::iterator iter = m_entity_map.begin(); iter != m_entity_map.end(); ++iter)
        {
            if(!cb.exec(static_cast<Concrete_Entity*>(iter->second)))
            {
                return false;
            }            
        }

        return true;        
    }

    template<typename Concrete_Entity>
    bool exec_until_true(Entity_Exec<Concrete_Entity> &cb)
    {
        for(typename std::map<Key, Entity*>::iterator iter = m_entity_map.begin(); iter != m_entity_map.end(); ++iter)
        {
            if(cb.exec(static_cast<Concrete_Entity*>(iter->second)))
            {
                return true;                
            }            
        }

        return false;        
    }
    
    template<typename Concrete_Entity>
    bool exec_if(Entity_Exec<Concrete_Entity> &cb, Entity_Exec_Condition<Concrete_Entity> &cond)
    {
        bool ret = false;
        
        for(typename std::map<Key, Entity*>::iterator iter = m_entity_map.begin(); iter != m_entity_map.end(); ++iter)
        {
            Concrete_Entity *concrete_entity = static_cast<Concrete_Entity*>(iter->second);

            if(cond.can_exec(concrete_entity))
            {
                ret = true;                
                cb.exec(concrete_entity);
            }
        }

        return ret;        
    }

    template<typename Concrete_Entity>
    bool delete_if(Entity_Exec_Condition<Concrete_Entity> &cond, Entity_Exec<Concrete_Entity> &cb_before_delete = Entity_Exec<Concrete_Entity>())
    {
        bool ret = false;
        
        for(typename std::map<Key, Entity*>::iterator iter = m_entity_map.begin(); iter != m_entity_map.end();)
        {
            Concrete_Entity *concrete_entity = static_cast<Concrete_Entity*>(iter->second);
            
            if(cond.can_exec(concrete_entity))
            {
                ret = true;                
                cb_before_delete.exec(concrete_entity);
                m_entity_map.erase(iter++);
            }
            else
            {
                ++iter;
            }            
        }

        return ret;        
    }
    
private:
    std::map<Key, Entity*> m_entity_map;
};

class Entity_ID : protected Entity_Map<uint32>
{
protected:
    typedef Entity_Map<uint32> Super;
    
    Entity_ID()
    {
    }

    void add_entity(Entity *entity)
    {
        Super::add_entity(entity->id(), entity);
    }
};

class Entity_Name : protected Entity_Map<std::string>
{
protected:
    typedef Entity_Map<std::string> Super;
    
    Entity_Name()
    {
    }

    void add_entity(Entity *entity)
    {
        Super::add_entity(entity->name(), entity);
    }
};

//占位
class Entity_None
{
protected:
    Entity_None()
    {
    }

    void clear()
    {
    }

    void add_entity(Entity *entity)
    {
    }

    template<typename Concrete_Entity>
    bool delete_if(Entity_Exec_Condition<Concrete_Entity> &cond, Entity_Exec<Concrete_Entity> &cb_before_delete = Entity_Exec<Concrete_Entity>())
    {
        return true;
    }
};

//提取基类的trait
template<typename T>
struct Get_Super
{
};

template<>
struct Get_Super<uint32>
{
    typedef Entity_ID Super;
};

template<>
struct Get_Super<std::string>
{
    typedef Entity_Name Super;
};

template<typename Concrete_Entity_Type, typename Super1, typename Super2 = Entity_None>
class Entity_Manager : private Super1, private Super2
{
protected:
    Entity_Manager()
    {
    }
    
    void add_entity(Entity *entity)
    {
        Super1::add_entity(entity);
        Super2::add_entity(entity);
    }

    template<typename Concrete_Entity>
    bool delete_if(Entity_Exec_Condition<Concrete_Entity> &cond)
    {
        Entity_Exec<Concrete_Entity> cb;
        
        return Super1::delete_if(cond, cb) && Super2::delete_if(cond, cb);
    }
    
    template<typename Concrete_Entity>
    bool delete_if(Entity_Exec_Condition<Concrete_Entity> &cond, Entity_Exec<Concrete_Entity> &cb_before_delete)
    {
        return Super1::delete_if(cond, cb_before_delete) && Super2::delete_if(cond, Entity_Exec<Concrete_Entity>());
    }

    template<typename Key>
    Concrete_Entity_Type* get_entity(Key key) const
    {
        return static_cast<Concrete_Entity_Type*>(Get_Super<Key>::Super::get_entity(key));        
    }

public:
    uint32 size()
    {
        return Super1::size();
    }

    bool empty()
    {
        return Super1::empty();
    }

    void clear()
    {
        Super1::clear();
        Super2::clear();
    }

    template<typename Concrete_Entity>
    bool exec_until_false(Entity_Exec<Concrete_Entity> &cb)
    {
        return Super1::exec_until_false(cb);        
    }

    template<typename Concrete_Entity>
    bool exec_until_true(Entity_Exec<Concrete_Entity> &cb)
    {
        return Super1::exec_until_true(cb);        
    }
    
    template<typename Concrete_Entity>
    bool exec_if(Entity_Exec<Concrete_Entity> &cb, Entity_Exec_Condition<Concrete_Entity> &cond)
    {
        return Super1::exec_if(cb, cond);        
    }
    
    template<typename Concrete_Entity>
    void exec(Entity_Exec<Concrete_Entity> &cb)
    {
        Super1::exec(cb);
    }
};

