#include <iostream>
#include <vector>

using namespace std;

template<typename T>
T squaring(T number)
{
    return number * number;
}
template <typename T>
vector<T> squaring(vector<T> arr)
{
    vector<T> result;
    for(int i = 0; i < arr.size(); i++)
    {
        result.push_back(arr[i] * arr[i]);
    } 
    return result;
}



int main()
{
    int a{5};
    cout << squaring(a) << endl;
    vector<double> b{ 5,10,15,2 };
    b = squaring(b);
    for (int i = 0; i < b.size(); i++)
    {
        cout << b[i] << endl;
    }
}

