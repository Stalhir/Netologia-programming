#include <iostream>
#include <mutex>
#include <thread>


using namespace std;

class Data
{
private:
    int data;
    mutex mut;
public:
    
    int Getdata()
    {
        return data;
    }

    void Setdata(int value)
    {
        this->data = value;
    }

    void Lswap( Data& other)
    {
        this->mut.lock();
        other.mut.lock();

        std::swap(this->data, other.data);

        this->mut.unlock();
        other.mut.unlock();
    }
   
    void Uswap(Data& other)
    {
        unique_lock<mutex> lock(this->mut);
        unique_lock<mutex> lock2(other.mut);

        std::swap(this->data, other.data);

        lock.unlock();
        lock2.unlock();
    }

    void Sswap(Data& other)
    {
        std::scoped_lock lock(this->mut, other.mut);

        std::swap(this->data, other.data);
    }

};

int main()
{
    Data a, b;
    a.Setdata(5);
    b.Setdata(15);

    // a.Lswap(b)
    // a.Uswap(b)
    a.Sswap(b);
    
    std::cout << a.Getdata() << " " << b.Getdata();
}

