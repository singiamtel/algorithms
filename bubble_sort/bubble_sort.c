#include <stdio.h>
#include <stdlib.h>	// for malloc
#include <stdint.h> // for uint_t
#include <time.h>	// for clock()

static inline void swap(uint64_t *array, uint32_t i, uint32_t j){
	uint32_t tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
}

void bubble_sort(uint64_t * array, uint32_t size){
	for(int i=0; i<size; ++i){
		for(int j=0; j<size-i-1; ++j){
			if(array[j] > array [j+1]) swap(array, j, j+1);
		}
	}
}

void test(uint64_t* array, uint32_t size){
	clock_t start, end;
	start = clock();
	bubble_sort(array, size);
	end = clock();
	for(int i=0; i<size; ++i){
		printf("%ld\n", array[i]);
	}
	printf("Sorting took %f seconds\n", ((double) (end - start)) / CLOCKS_PER_SEC);
}

int main(int argc, char * argv[]){
	FILE * input = fopen(argv[1], "r");
	uint32_t filesize = 50, size = 0;
	uint64_t last;
	uint64_t* file_array = (uint64_t*) malloc(sizeof(uint64_t) * filesize);
	fscanf(input, "%ld", &last);
	while (!feof(input))
	{
		fscanf(input, "%ld", &last);
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