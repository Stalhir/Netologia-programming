#include <iostream>
#include <vector>
#include <set>
#include <list>
#include <algorithm>

using namespace std;

template<typename T>
void print_container(const T& cont)
{
    for (auto it = cont.begin(); it != cont.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    std::set<std::string> test_set = { "one", "two", "three", "four" };
    print_container(test_set); 

    std::list<std::string> test_list = { "one", "two", "three", "four" };
    print_container(test_list); 

    std::vector<std::string> test_vector = { "one", "two", "three", "four" };
    print_container(test_vector);  
}