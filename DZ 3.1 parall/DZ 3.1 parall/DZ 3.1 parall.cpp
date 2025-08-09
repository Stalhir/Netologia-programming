#include <iostream>
#include <thread>
#include <future>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
void SortW(vector<T>& arr)
{
    for(auto i = arr.begin(); i != arr.end(); ++i)
    {
        
        promise<typename std::vector<T>::iterator> prom;
        auto futureMin = prom.get_future();

        thread([&prom, i, end = arr.end()]() {
            auto min_it = min_element(i, end);
            prom.set_value(min_it);
        }).detach();

        
        auto itmin = futureMin.get();
        std::iter_swap(i, itmin);
    }
}





template<typename T>
void print_vector(vector<T> arr)
{
    for(int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << "\t";
    }
}

int main()
{
    vector<int> arr{ 5, 1 , 4 , 7, 12, 3 , 4, 5, 8, 11,  };
    SortW(arr);
    print_vector(arr);
}
