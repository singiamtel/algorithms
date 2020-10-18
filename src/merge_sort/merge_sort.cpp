#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

void merge(vector<int>& arr, int left, int middle, int right){
	// End of first and second subarrays
	int n1 = middle - left + 1,
		n2 = right - middle;

	// Create temp arrays 
	vector<int> arr1, arr2;

	// Copy data to temp arrays
	for (int i = 0; i < n1; i++)
	{
		arr1.push_back(arr[left + i]);
	}
	for (int j = 0; j < n2; j++)
	{
		arr2.push_back(arr[middle + 1 + j]);
	}

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
	while (i < n1)
	{
		arr[k] = arr1[i];
		++i;
		++k;
	}
	while (j < n2)
	{
		arr[k] = arr2[j];
		++j;
		++k;
	}
	
}

void mergeSort(vector<int>& arr, int left, int right){
	if(left < right){
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
