#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <ctime>

#define MAX_RAND_INTERVAL 100000

using namespace std;

int main(int argc, char * argv[]){
	int len = atoi(argv[1]);
	srand(time(NULL));
	ofstream output_file;
	output_file.open("unsorted");
	for(int i = 0; i<len; ++i){
		output_file << rand() % MAX_RAND_INTERVAL << endl;
	}
	output_file.close();
	return 0;
}
