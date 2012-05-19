#include <iostream>
#include <list>
#include <string>
#include <map>
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
    
    class object_pool
    {
    public:
        object_pool(uint32 sz)
        {
            mObjectSz = sz;            
        }

        object_pool()
        {
        }        

        void addNewList(void* p)
        {
            mNewList.push_back(p);
        }

        void* allocate()
        {
            if(mFreeList.empty())
            {
                void *buf = operator new(mObjectSz);
                mUseList.push_back(buf);

                return buf;                
            }

            void *buf = mFreeList.front();
            mFreeList.pop_front();

            return buf;
        }

        bool deallocate(void *p)
        {
            for(std::list<void*>::iterator iter = mUseList.begin(); iter != mUseList.end(); ++iter)
            {
                void *addr = *iter;

                if(addr <= p && addr + mObjectSz > p)
                {
                    mUseList.erase(iter);
                    mFreeList.push_back(addr);

                    return true;                    
                }
            }

            return false;            
        }
        
    private:
        std::list<void*> mFreeList;
        std::list<void*> mUseList;
        std::list<void*> mNewList;
        uint32 mObjectSz;        
    };    
        
    template<typename T>
    T* new_object(bool pool = false)
    {
        std::string nameT (typeid(T).name());

        if(mPoolMap.find(nameT) == mPoolMap.end())
        {
            mPoolMap.insert(std::make_pair(nameT, object_pool(sizeof(T))));
        }
            
        if(!pool)
        {
            T *pObj = new T;                        
            mPoolMap[nameT].addNewList(pObj);            

            return pObj;            
        }

        void *buf = mPoolMap[nameT].allocate();

        return new (buf) T();        
    }

    template<typename T>
    void del_object(T *pObj)
    {
        std::string nameT (typeid(*pObj).name());

        if(mPoolMap.find(nameT) == mPoolMap.end())
        {            
            return;
        }

        if(!mPoolMap[nameT].deallocate(pObj))
        {
            delete pObj;

            return;            
        }

        pObj->~T();        
    }

    std::map<string, object_pool> mPoolMap;
};

MemMgr mgr;

int main()
{
    Base1 *p = mgr.new_object<Tst>(true);
    mgr.del_object(p);

    cout << sizeof(unsigned long long int) << endl;
    
}
