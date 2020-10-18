#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

void merge(vector<int> arr, int left, int right, int middle){
	// Subarrays
	vector<int> arr1 = {arr.begin(), arr.begin() + middle}, arr2 = {arr.begin() + middle,arr.end()};

	// End of first and second array
	int n1 = middle - left + 1; 
	int n2 = right - middle;
	cout << n1 << " " << n2 << endl;

	int i = 0, j = 0, k = left;

	// Merge solutions
	while (i < n1 && j < n2)
	{
		if (arr1[i] <= arr2[j])
		{
			arr[k] = arr1[i];
			++i;
		}
		else
		{
			arr[k] = arr2[j];
			++j;
		}
		++k;
	}
	while (j < n2)
	{
		arr[k] = arr2[j];
		++j;
		++k;
	}
	while (i < n1)
	{
		arr[k] = arr2[i];
		++i;
		++k;
	}
}
void mergeSort(vector<int> arr, int left, int right){
	if(left < right){
		cout << "HERE" << endl;
        int middle = left + (right - left) / 2; 
		mergeSort(arr, left, middle);
		mergeSort(arr, middle + 1, right);
		merge(arr, left, middle, right);
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

		mergeSort(data, 0, data.size()-1);

		auto end = high_resolution_clock::now();

		for(auto i: data){
			cout << i << endl;
		}
		auto duration = duration_cast<microseconds>(end - start);
		cout << duration.count() / 1000000.0 << " Seconds" << endl;
	}
}
