#include <iostream>
#include <typeinfo>
using namespace std;

class Base
{
public:
    Base()
    {
        cout << "Base()" << endl;
    }

    virtual ~Base()
    {
        cout << "~Base()" << endl;
    }


    void addr()
    {
        cout << "base::addr = " << this << endl;
        cout << "typeid(addr) = " << typeid(*this).name() << endl;        
    }
    
    int v;
    

};

class Der : public Base
{
public:
    Der()
    {
        cout << "Der()" << endl;
    }

    ~Der()
    {
        cout << "~Der()" << endl;
    }
};

class Base1
{
public:
    virtual ~Base1()
    {
        cout << "~base1" << endl;
        
    }

    Base1()
    {
        cout << "base1" << endl;
    }
    

    void ddr()
    {
        cout << "ddr: " << this << endl;
    }

    int f;
    
};

    
class Der1 : public Base1
{
public:
    Der1()
    {
        cout << "der1()" << endl;
    }

    ~Der1()
    {
        cout << "~der1()" << endl;
    }        
};


class Tst :   public Der1, public Der
{
public:
    Tst()
    {
        cout << "tst()" << endl;
        
    }

    ~Tst()
    {
        cout << "~tst()" << endl;
    }

    void addr()
    {
        cout << "tst::addr = " << this << endl;
    }    
};


namespace lcc
{
    class Tst
    {
    public:
        int a;
    };
}


typedef unsigned int uint32;
typedef unsigned short uint16;
typedef unsigned char uint8;

class MemMgr
{
public:
    MemMgr()
    {
    }

    class object_node
    {
    public:
        object_node()
        {
            memory = NULL;
            prev = next = NULL;            
        }

        uint8 *mBuf;        
        object_node *mPrev
        object_node *mNext;        
    };        
    
    class object_pool
    {
    public:
        object_pool(uint32 objectSz)
        {
            mObjectSz = objectSz;            
        }

        uint32 object_size() const
        {
            return mObjectSz;            
        }

    private:
        uint32 mObjectSz;        
    };    
        
    template<typename T>
    T* new_object(bool pool = false)
    {
        if(!pool)
        {
            std::string nameT (typeid(T).name());

            if(mPoolMap.find(nameT) == mPoolMap.end())
            {
                mPoolMap.insert(std::make_paire(nameT, object_pool(sizeof(T))));
            }            
            
            return new T;
        }     
    }

    template<typename T>
    void del_object(T *ptr)
    {
        cout << "delobject: T = " << typeid(*ptr).name() << endl;
        delete ptr;        
    }

    std::map<std::string, object_pool> mPoolMap;    
};



MemMgr mgr;

int main()
{
    Tst *ptr = mgr.new_object<Tst>();
    cout << "size(tst) = " << sizeof(Tst) << endl;
    
    Base *p = ptr;    
    mgr.del_object(p);
}

    
    
