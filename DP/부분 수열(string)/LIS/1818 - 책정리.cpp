#include <iostream>
#include <vector>
using namespace std;

int N;
int books[200001];
vector<int> cache;

int lowerBound(int lo, int hi, int num)
{
	while (lo < hi)
	{
		int mid = (lo + hi) / 2;
		if (cache[mid] >= num)
		{
			hi = mid;
		}
		else
		{
			lo = mid + 1;
		}
	}
	return hi;
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> books[i];
	}
	for (int i = 0; i < N; i++)
	{
		if (cache.empty() || cache[cache.size() - 1] < books[i])
		{
			cache.push_back(books[i]);
		}
		else
		{
			int idx = lowerBound(0, cache.size() - 1, books[i]);
			cache[idx] = books[i];
		}
	}
	cout << N - cache.size();
}