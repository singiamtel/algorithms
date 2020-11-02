#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

static inline void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int part(vector<int>& data, int low, int high)
{
	int piv = data[high];
	int i = (low - 1);

	for (int j = low; j <= high- 1; j++)
	{
		if (data[j] <= piv)
		{
			i++;
			swap(&data[i], &data[j]);
		}
	}
	swap(&data[i + 1], &data[high]);
	return (i + 1);
}

void quicksort(vector<int>& data, int low, int high)
{
	if (low < high)
	{
		int pi = part(data, low, high);
		quicksort(data, low, pi - 1);
		quicksort(data, pi + 1, high);
	}
}

int main(int argc, char *argv[])
{
	ifstream input;
	input.open(argv[1]);

	if (input.is_open())
	{
		int aux;
		vector<int> data;
		while (input >> aux)
		{
			data.push_back(aux);
		}

		auto start = high_resolution_clock::now();

		quicksort(data, 0, data.size() - 1);

		auto end = high_resolution_clock::now();

		for(auto i: data){
			cout << i << endl;
		}

		auto duration = duration_cast<microseconds>(end - start);
		cout << duration.count() / 1000000.0 << " Seconds" << endl;
	}
}
