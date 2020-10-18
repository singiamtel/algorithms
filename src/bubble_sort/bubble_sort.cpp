#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

static inline void swap (vector<int>& data, const int a,const  int b){
	int aux = data[a];
	data[a] = data[b];
	data[b] = aux;
}

void bubble_sort(vector<int> &data){
	for (int i = 0; i < data.size(); ++i){
		for(int j = 0; j < data.size()-i-1; ++j){
			if(data[j] > data[j+1]) swap(data, j, j+1);
		}
	}
}

int main(int argc, char *argv[]){
	ifstream input;
	input.open(argv[1]);

	if(input.is_open()){
		int aux;
		vector<int> data;
		while (input >> aux ){
			data.push_back(aux);
		}

		auto start = high_resolution_clock::now(); 
		bubble_sort(data);
		auto end = high_resolution_clock::now(); 

		auto duration = duration_cast<microseconds>(end - start); 
		cout << duration.count() / 1000000.0 << " Seconds" <<  endl;
	}
}
