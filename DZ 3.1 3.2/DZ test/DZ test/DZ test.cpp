#include <iostream>




class smart_array
{
private:
    int arraySize{};
    int array_addIndex{};
    int* smartArray;
public:

    smart_array(int _arraySize) : arraySize(_arraySize)
    { 
        smartArray = new int[_arraySize];
    }

    smart_array(const smart_array& other) :
        arraySize(other.arraySize),
        array_addIndex(other.array_addIndex),
        smartArray(new int[other.arraySize])
    {
        std::copy(other.smartArray, other.smartArray + arraySize, smartArray); 
    }

    smart_array& operator=(smart_array& other) //типо вроде можно ссылкой или надо... хуй знает
    {
        
        this->arraySize = other.arraySize;
        this->array_addIndex = other.array_addIndex;
        delete[] this->smartArray;
        smartArray = new int[this->arraySize];
        
        for (int i = 0; i < this->arraySize; i++)
        {
            this->smartArray[i] = other.smartArray[i];
                
        }
        
        return *this;
    }


    void add_element(int element)
    {
        if(array_addIndex+1>arraySize)
        {
            throw std::out_of_range("Index out of range");
        }
        smartArray[array_addIndex] = element;
        array_addIndex++;
    }

    int get_element(int index)
    {
        if(index >= arraySize)
        {
            throw std::out_of_range("Index out of range");
        }
        return smartArray[index];
    }

    ~smart_array()
    {
        delete[] smartArray;
    }
};






int main()
{
    try {
        smart_array arr(5);
        arr.add_element(1);
        arr.add_element(4);
        arr.add_element(155);
        arr.add_element(14);
        arr.add_element(15);
       
        std::cout << arr.get_element(1) << std::endl;


        smart_array new_arr(6);
        new_arr.add_element(231);
        new_arr.add_element(334); 
        new_arr.add_element(155); 
        new_arr.add_element(1422); 
        new_arr.add_element(135); 
        new_arr.add_element(1315); 
        arr = new_arr;

        std::cout << arr.get_element(3) << std::endl;
        std::cout << new_arr.get_element(3) << std::endl;
    }
    catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }
}

