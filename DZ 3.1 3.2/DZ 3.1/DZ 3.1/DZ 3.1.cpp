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


    void add_element(int element)
    {
        if (array_addIndex + 1 > arraySize)
        {
            throw std::out_of_range("Index out of range");
        }
        smartArray[array_addIndex] = element;
        array_addIndex++;
    }

    int get_element(int index)
    {
        if (index >= arraySize)
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
    }
    catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }
}