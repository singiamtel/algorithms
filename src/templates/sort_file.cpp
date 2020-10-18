#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

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

		// Sort here

		auto end = high_resolution_clock::now();

		for(auto i: data){
			cout << i << endl;
		}

		auto duration = duration_cast<microseconds>(end - start);
		cout << duration.count() / 1000000.0 << " Seconds" << endl;
	}
}
