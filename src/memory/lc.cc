#include <iostream>
#include <assert.h>
#include <list>
#include <string>
#include <map>
#include <typeinfo>

namespace memory
{
    class Object_Pool
    {
    public:
        Object_Pool(int sz)
        {
            mObjectSz = sz;
        }

        Object_Pool()
        {
        }

        void* allocate()
        {
            if(mFreeList.empty())
            {
                void *buf = operator new (mObjectSz);
                mUseList.push_back(buf);
                
                return buf;                
            }

            void *buf = mFreeList.front();
            mFreeList.pop_front();
            mUseList.push_back(buf);

            return buf;
        }

        bool deallocate(void *p)
        {
            for(std::list<void*>::iterator iter = mUseList.begin(); iter != mUseList.end(); ++iter)
            {
                void *addr = *iter;
                unsigned long long int headArr = (unsigned long long int)addr;
                unsigned long long int subArr = (unsigned long long int)p;

                if(subArr >= headArr && subArr < headArr + mObjectSz)
                {
                    mFreeList.push_back(addr);
                    mUseList.erase(iter);

                    return true;
                }
            }

            for(std::list<void*>::iterator iter = mNewList.begin(); iter != mNewList.end(); ++iter)
            {
                void *addr = *iter;
                unsigned long long int headArr = (unsigned long long int)addr;
                unsigned long long int subArr = (unsigned long long int)p;

                if(subArr >= headArr && subArr < headArr + mObjectSz)
                {
                    mNewList.erase(iter);

                    return false;
                }
            }

            //error......
            assert(false);
            
            return false;            
        }

        void add_new_list(void* p)
        {
            mNewList.push_back(p);
        }

    private:
        std::list<void*> mFreeList;
        std::list<void*> mUseList;
        std::list<void*> mNewList;
        int mObjectSz;
    };
    
    class Memory_Mgr
    {
    public:
        Memory_Mgr()
        {
        }
        
        template<typename T>
        T* new_object(bool pool = false)
        {
            return new T;
            std::string nameT (typeid(T).name());

            if(mPoolMap.find(nameT) == mPoolMap.end())
            {
                mPoolMap.insert(std::make_pair(nameT, Object_Pool(sizeof(T))));
            }

            if(!pool)
            {
                T *pObj = new T;                        
                mPoolMap[nameT].add_new_list(pObj);
                
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
                assert(false);
                
                return;
            }

            if(!mPoolMap[nameT].deallocate(pObj))
            {
                delete pObj;
                
                return;            
            }

            pObj->~T();        
        }

    private:
        std::map<std::string, Object_Pool> mPoolMap;
    };
};
