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
        T* ptr = badPtr; 
        badPtr = nullptr; 
        return ptr;
    }
    
    MyUnique_ptr(MyUnique_ptr&& other) noexcept : badPtr(std::move(other.badPtr)) { other.badPtr = nullptr;  }
    
    MyUnique_ptr& operator=(MyUnique_ptr&& other) noexcept
    {
        if (this != &other) {
            delete badPtr;
            this->badPtr = std::move(other.badPtr);
            other.badPtr = nullptr;
        }
        return *this;
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

    std::cout << "Docker work";
}
