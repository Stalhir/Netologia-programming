#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <thread>
#include <future>

using namespace std;

template<typename Iterator, typename Func>
void AsyncFor_each(Iterator begin , Iterator end , Func func, int min_block_size = 1)
{
	int size = std::distance(begin, end);
	if (size <= min_block_size) 
	{
		func(*begin);
		return;
	}
	
	Iterator mid = begin;
	std::advance(mid, size / 2);

	auto future = async(std::launch::async, AsyncFor_each<Iterator, Func>, mid, end, func, min_block_size);

	AsyncFor_each(begin, mid, func, min_block_size);


	future.get();
};
 
 
int main()
{
	vector<int> a{3, 2, 7, 4, 5};


	AsyncFor_each(a.begin(), a.end(), [](int x) { cout << x << " "; });
}
