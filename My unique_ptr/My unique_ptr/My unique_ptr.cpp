#include <iostream>


template<typename T>
class MyUnique_ptr
{
private:
    T* badPtr = nullptr;


public:
    explicit MyUnique_ptr(T* pointer) : badPtr(pointer)
    {

    }
    ~MyUnique_ptr()
    {
        delete badPtr;
    }

    MyUnique_ptr(const MyUnique_ptr&) = delete;
    MyUnique_ptr& operator=(const MyUnique_ptr&) = delete;
     
    T* release()
    {
        delete badPtr;
        badPtr = nullptr;
        return badPtr;
    }
    

    T& operator*()
    {
        return *badPtr;
    }

    T* operator->()
    {
        return badPtr;
    }

};





int main()
{

    int a{10};
    MyUnique_ptr<int> natural(new int);
  

}
