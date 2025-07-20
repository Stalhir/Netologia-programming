#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
void noDuplicate(vector<T>& vec)
{
	std::sort(vec.begin(), vec.end());
	auto it = std::unique(vec.begin(), vec.end());
	vec.erase(it, vec.end());
}

int main()
{
	vector<int> a{ 1, 1, 2, 5, 6, 1, 2, 4 };
	noDuplicate(a);
	for(int i = 0; i < a.size(); i++)
	{
		cout << a[i] << endl;
	}
}
