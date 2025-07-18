#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	string text{ "Hello world!!" };
	std::unordered_map<char, int> freq;

	for (auto c : text) {
		freq[c]++;
	}

	std::vector<std::pair<char, int>> sorted(freq.begin(), freq.end());

	for (int i = 0; i < sorted.size(); i++)
	{
		for (int j = 0; j < sorted.size() - i - 1; j++)
		{
			if (sorted[j].second < sorted[j+1].second)
			{
				swap(sorted[j], sorted[j + 1]);
			}
		}
	}
	


	for (auto a : sorted) {
		std::cout << a.first << ": " << a.second << std::endl;
	}
}
