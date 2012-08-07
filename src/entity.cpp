#include <string>
#include <iostream>
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



//��������Ԫ�ؽ��лص�
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

    virtual void exec(Concrete_Entity *entity) = 0;
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



//ռλ
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
};



//��ȡ�����trait
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



template<typename Super1, typename Super2 = Entity_None>
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

    template<typename Key>
    Entity* get_entity(Key key) const
    {
        return Get_Super<Key>::Super::get_entity(key);
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
    void exec(Entity_Exec<Concrete_Entity> &cb)
    {
        Super1::exec(cb);
    }
};



//ѧ��
class Student : public Entity
{
public:
    Student()
    {
    }

    Student(uint32 _id, std::string _name)
    {
        id(_id);
        name(_name);
    }
};



//�༶ ֧�ְ�id��nameȥ����ѧ��
class Class : public Entity, public Entity_Manager<Entity_ID, Entity_Name>
{
public:
    Class()
    {
    }

    Class(uint32 _id)
    {
        id(_id);
    }

    void add_student(Student *student)
    {
        add_entity(student);
    }

    //��id����ѧ��
    Student* get_student(uint32 id)
    {
        return static_cast<Student*>(get_entity(id));
    }

    //����������ѧ��
    Student* get_student(std::string name)
    {
        return static_cast<Student*>(get_entity(name));
    }
};



//�꼶 ֧�ְ�idȥ�����༶
class Grade : private Entity_Manager<Entity_ID>
{
public:
    Grade()
    {
    }

    //��Ӱ༶
    void add_class(Class *cls)
    {
        add_entity(cls);
    }

    //��id�����༶
    Class* get_class(uint32 id)
    {
        return static_cast<Class*>(get_entity(id));
    }
};



//�԰༶�������ѧ�����лص�����ӡ����ѧ�������֣�id
class CB : public Entity_Exec<Student>
{
public:
    CB()
    {
    }

    void exec(Student *student)
    {
        std::cout << "ѧ��id: " << student->id() << " ѧ������: " << student->name() << std::endl;
    }
};



int main()
{
    //ѧ��
    Student student1(1, "�ҽ�1��ѧ��");
    Student student2(2, "�ҽ�2��ѧ��");

    //5�Ű༶
    Class class_5(5);
    class_5.add_student(&student1);
    class_5.add_student(&student2);
    
    //�꼶
    Grade grade;
    grade.add_class(&class_5);

    //���꼶��ȡ5�Ű༶
    Class* cls = grade.get_class(5);

    CB cb;    
    cls->exec(cb);
    
    return 0;
}
