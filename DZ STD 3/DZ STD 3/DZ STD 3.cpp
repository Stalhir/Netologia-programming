#include <iostream>
#include <memory>

using namespace std;

template<class T>
class Vector
{
private:
    shared_ptr<T[]> array;
    int Size{};
    int CapacitySize{};
public:
    Vector() : array(nullptr), Size(0), CapacitySize(0) {}

    void push_back(T value)
    {
        if (Size >= CapacitySize)
        {
         int newCapacity = (CapacitySize == 0) ? 1 : CapacitySize * 2;

            shared_ptr<T[]> newArray(new T[newCapacity]);
             

            if(array)
            {
                for (int i = 0; i < Size; i++)
                {
                    newArray[i] = array[i];
                }
            }
            
            array = newArray;
            CapacitySize = newCapacity;
             
        }
        array[Size] = value;
        Size++;
    }
    T& at(int index)
    {
        return array[index];
    }

    int size() { return Size; }

    int capacity() { return CapacitySize; }
};

int main()
{
    Vector<int> a;

        a.push_back(10);
        std::cout << a.at(0) << endl;
        cout << a.size() << " " << a.capacity() << endl;
        a.push_back(20);
        a.push_back(30);
        cout << a.size() << " " << a.capacity() << endl;
    
    std::cout << "";
}

