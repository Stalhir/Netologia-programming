#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <iterator>

using namespace std;

template<typename T>
void sumVectors(const vector<T>& first, const vector<T>& second, vector<T>& temp, int begin, int end)
{
	for (int i = begin; i < end; i++)
	{
		T val1 = (i < first.size()) ? first[i] : T{};
		T val2 = (i < second.size()) ? second[i] : T{};
		temp[i] = val1 + val2;
	}
}

template<typename T>
vector<T> ParallSumVectors(const vector<T>& first, const vector<T>& second, int maxThr)   
{
	auto startTime = std::chrono::steady_clock::now();
    int maxSize = max(first.size(), second.size());

	vector<T> result(maxSize, T{});
	
	

	if(maxThr <= 1)
	{
		sumVectors(first, second, result, 0, maxSize);		
		auto endTime = std::chrono::steady_clock::now();
		std::chrono::duration<double> elapsed_seconds = endTime - startTime;
		std::cout << elapsed_seconds.count() << "s";
		return result;
	}
	vector<thread> Thrs;
	
	int partSize = maxSize / maxThr;

	
	
	for(int i = 0; i < maxThr; i++)
	{
		int start = i * partSize;
		int end = (i == maxThr - 1) ? maxSize : start + partSize;

		Thrs.push_back(thread(sumVectors<T>, cref(first), cref(second), std::ref(result), start , end));
	}
	for(int i = 0; i < maxThr; i++)
	{
		Thrs[i].join();
	}
	auto endTime = std::chrono::steady_clock::now();
	std::chrono::duration<double> elapsed_seconds = endTime - startTime;
	std::cout << elapsed_seconds.count() << "s";

	return result;
}

int main()
{
	setlocale(LC_ALL, "rus");
	vector<int> a(10000, int{}), b(100000, int{});
	
	//ParallSumVectors(a, b, 2); 

	cout << "Количество свободных потоков: " << thread::hardware_concurrency() << endl;
	cout << "\t\t 1000 \t\t 10000 \t\t 100000 \t\t 1000000" << endl;

	int thr = 1;
	int elementCount = 1000;
	for (int i = 0; i < 5; i++)
	{
		cout << thr << " потоков ";
		for(int j = 0; j < 4; j++)
		{
			a = vector<int>(elementCount *= 10, int{});
			b = vector<int>(elementCount *= 10, int{});
			ParallSumVectors(a, b, thr);
			cout << "\t     ";
		}
		cout << endl;
		elementCount = 1000;
		thr *= 2;
		
	}
}
