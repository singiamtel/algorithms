#include <stdio.h>
#include <stdlib.h>	// for malloc
#include <stdint.h> // for uint_t
#include <time.h>	// for clock()
#include <assert.h>	// for assert

void merge(uint64_t* data,uint32_t l,uint32_t m, uint32_t r){
	uint32_t n1 = m - l + 1;
	uint32_t n2 = r - m;
	
	uint64_t* arr1 = (uint64_t*) malloc(sizeof(uint64_t) * n1);
	uint64_t* arr2 = (uint64_t*) malloc(sizeof(uint64_t) * n2);
	for(int i = 0;i < n1; ++i){
		arr1[i] = data[i];
	}
	for(int i = 0;i < n2; ++i){
		arr2[i] = data[m + 1 + i];
	}
	
	int i = 0;
	int j = 0;
	int k = l;

	while(i < n1 && j < n2){
		if(arr1[i] <= arr2[j]){
			data[k] = arr1[i];
			++i;
		}else{
			data[k] = arr2[j];
			++j;
		}
		++k;
	}
	while(i < n1){
		data[k] = arr1[i];
		++i;
		++k;
	}
	while(j < n2){
		data[k] = arr2[i];
		++j;
		++k;
	}

	free(arr1);
	free(arr2);

}

void merge_sort(uint64_t* data, uint32_t l, uint32_t r){
	if(l < r){
		int m = l + (r -l) /2;
		merge_sort(data,l,m);
		merge_sort(data,m+1,r);
		merge(data,l,m,r);
	}
}

void test(uint64_t* array, const uint32_t size){
	clock_t start, end;
	start = clock();

	merge_sort(array,0,size);
	for(int i = 0; i < size; ++i){
		printf("%d\n", array[i]);
	}
	end = clock();
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
		if(size >= filesize){
			filesize+=30;
			file_array = (uint64_t*)realloc(file_array, sizeof(uint64_t) * (filesize));
		}
		file_array[size] = last;
		size++;
		(void)fscanf(input, "%ld", &last);
	}
	test(file_array, size);

	fclose(input);
	free(file_array);

	return 0;
}
