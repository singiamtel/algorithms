#include <stdio.h>
#include <stdlib.h>	// for malloc
#include <stdint.h> // for uint_t
#include <time.h>	// for clock()
#include <assert.h>	// for assert

void test(uint64_t* array, const uint32_t size){
	clock_t start, end;
	start = clock();

	// Sort here

	end = clock();
	for(int i=0; i<size-1; ++i){
		assert(array[i] <= array[i+1]);
	}
	printf("Sorting took %f seconds\n", ((double) (end - start)) / CLOCKS_PER_SEC);
}

int main(int argc, char * argv[]){
	FILE * input = fopen(argv[1], "r");
	uint32_t filesize = 50, size = 0;
	uint64_t last;
	uint64_t* file_array = (uint64_t*) malloc(sizeof(uint64_t) * filesize);
	(void)fscanf(input, "%ld", &last);
	while (!feof(input))
	{
		(void)fscanf(input, "%ld", &last);
		if(size >= filesize){
			filesize+=30;
			file_array = realloc(file_array, sizeof(uint64_t) * (filesize));
		}
		file_array[size] = last;
		size++;
	}
	test(file_array, size);

	fclose(input);
	free(file_array);

	return 0;
}