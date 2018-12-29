#include <stdio.h>
#include "quicksort_serial.h"
#include "quichsort_parallel.h"
#include <stdlib.h>
#include <time.h>


int* mockup_data(int * arr, int count)
{
	// static int* arr = calloc(count, sizeof(int)); //?!
	for (int i = 0; i < count; i++)
	{
		arr[i] = rand();
	}
	return arr;
}

void print_data(int* arr, const int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d\t", arr[i]);
	}
}

int main() {
	const int SIZE = 10;
		
	int* intArray = (int*) malloc(SIZE * sizeof(int));
	// mockup_data(intArray, SIZE);
	/*
	printf("\n\nInput Array: \n");	
	print_data(intArray, SIZE);

	const int start_s = clock();
	// quicksort_serial(intArray, 0, SIZE - 1);
	quicksort_parallel(intArray, 0, SIZE - 1);
	const int stop_s = clock();
	
	printf("\n\nOutput Array: \n");
	print_data(intArray, SIZE);

	const float time_elapse = (stop_s - start_s) / (float)CLOCKS_PER_SEC * 1000;
	printf ("\n\nTime spent is %f seconds", time_elapse);
	*/

	/*
	printf("\n\nInput Array: \n");
	int aa[5] = { 2, 5, 6, 2, 1 };
	print_data(aa, 5);
	// add_scan_serial(intArray, SIZE);
	printf("\n\nOutput Array: \n");
	int* a = add_scan_serial(aa, 5);
	*/
	int* a = reduced_para();
	print_data(a, 10);

	free(intArray);
}