#include <iostream>
#include <vector>

using namespace std;

class FunctorSumCount
{
private:
    int sum{};
    int count{};
public:

    int get_sum()
    {
        return sum;
    };
    int get_count() 
    {
        return count;
    };

    void operator()(vector<int> Arr)
    {
        for(int i = 0; i < Arr.size(); i++ )
        {
            if(Arr[i] % 3 == 0)
            {
                count++;
                sum += Arr[i];
            }
           
        }
    }
};

int main()
{
    vector<int> vec{ 4,1 ,3 ,6 ,25 ,54 };
    FunctorSumCount a;
    a(vec);
    cout << a.get_sum() << endl;
    cout << a.get_count() << endl;
   
}

