#include <iostream>
#include <set>


using namespace std;

int main()
{
	int Size, in;

	cout << "Size ";
	cin >> Size;
	set<int, greater<>> uniqSortArr;
	for (int i = 0; i < Size; i++)
	{
		cin >> in;
		uniqSortArr.insert(in);
		in = 0;
	}
	for(auto el : uniqSortArr)
	{
		cout << el << endl;
	}
	

}
