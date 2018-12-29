#include "mandelbrot_parallel.h"
#include "mandelbrot_serial.h"
#include <time.h>


int main()
{
	
	const int max_iteration = 10000;	
	const int width = 58, height = 34;
	// const int width = 78, height = 44;

	printf("\n\n ---- MANDELBROT FRACTAL GENERATION ----\n\n");
	
	printf("\n\n\n ---- SERIAL ALGORITHM ----\n\n");
	
	int start_serial = clock();
	generate_fractal_serial(max_iteration, width, height);
	int stop_serial = clock();

	printf("\n\n\n ---- PARALLEL ALGORITHM WITH 1 THREAD ----\n\n");

	int start_para1 = clock();
	generate_fractal_parallel(1, max_iteration, width, height);
	int stop_para1 = clock();

	printf("\n\n\n ---- PARALLEL ALGORITHM WITH 2 THREADS ----\n\n");
	
	int start_para2 = clock();
	generate_fractal_parallel(2, max_iteration, width, height);
	int stop_para2 = clock();
	
	printf("\n\n\n ---- PARALLEL ALGORITHM WITH 4 THREAD2 ----\n\n");
	
	int start_para4 = clock();
	generate_fractal_parallel(4, max_iteration, width, height);
	int stop_para4 = clock();


	printf("\n\nEXPERIMENT RESULTS : \n");
	
	printf("\nSERIAL : \n");
	float time_elapse_serial = (stop_serial - start_serial) / (float)CLOCKS_PER_SEC * 1000;
	printf("\n\nTime spent is %f seconds", time_elapse_serial);
	
	printf("\nPARALLEL 1 THREAD : \n");
	float time_elapse_para1 = (stop_para1 - start_para1) / (float)CLOCKS_PER_SEC * 1000;
	printf("\n\nTime spent is %f seconds", time_elapse_para1);
	
	printf("\nPARALLEL 2 THREADS : \n");
	float time_elapse_para2 = (stop_para2 - start_para2) / (float)CLOCKS_PER_SEC * 1000;
	printf("\n\nTime spent is %f seconds", time_elapse_para2);
	
	printf("\nPARALLEL 4 THREADS : \n");
	float time_elapse_para4 = (stop_para4 - start_para4) / (float)CLOCKS_PER_SEC * 1000;
	printf("\n\nTime spent is %f seconds", time_elapse_para4);
	// int* pause;
	// getc(pause);
}