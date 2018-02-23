/*
File: Sklaver-rod.c

Author: Erika Sklaver 
Date: 04/07/2017
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <float.h>
#include <limits.h>
#include "Sklaver-rod.h" 

int prices_in_class[10] = {1, 5, 8, 9, 19, 17, 17, 20, 24, 30};


int maxrev_recursive(int n, int * price_array){
	int array[n];


	for(int i=0; i<n; i++){
		array[i] = price_array[i] + maxrev_recursive(n-i-1, price_array);
	}

	int max_val = 0; 

	for(int i=0; i<n; i++){
		if(array[i]>max_val){
			max_val = array[i];
		}
	}


	return max_val;

} 

int maxrev_DP(int n, int * T, int * price_array){

	if(T[n]>= 0){

		return T[n];
	}

	int array[n];

	for(int i=0; i<n; i++){
		array[i] = price_array[i] + maxrev_DP(n-i-1, T, price_array);
	}

	int max_val = 0; 

	for(int i=0; i<n; i++){
		if(array[i]>max_val){
			max_val = array[i];
		}
	}

	T[n] = max_val; 

	return max_val;

}

int main (int argc, char **argv){

	printf("you entered n=%s\n", argv[1]);

	int n = atoi(argv[1]);

	int price_array[n]; 

	srand(time(NULL));
	int r = rand() % 10;
	price_array[0]= r; 

	for(int i =1; i<n; i++){

			price_array[i]= price_array[i-1]+ (rand()%10);

	}

	clock_t begin = clock();

	int opt_rev = maxrev_recursive(n, price_array);
	//if you want prices from class uncomment the following line, and comment line above
	//int opt_rev = maxrev_recursive(n, prices_in_class);
	clock_t end = clock();
	double time_spent_recursive = (double)(end - begin) / CLOCKS_PER_SEC;

	printf("Running maxrev_recursive with n =%d: maxrev = %d, total time = %f seconds \n", n, opt_rev, time_spent_recursive);

	int t_array[n+1]; 

	for(int i=0; i<n+1; i++){
		t_array[i]= INT_MIN;
	}

	clock_t begin2 = clock();

	int other_opt_rev = maxrev_DP(n, t_array, price_array);
	//if you want prices from class uncomment the following line, and comment line above
	//int other_opt_rev = maxrev_DP(n, t_array, prices_in_class);

	clock_t end2 = clock();
	double time_spent_dp = (double)(end2 - begin2) / CLOCKS_PER_SEC;

	printf("Running maxrev_DP with        n =%d: maxrev = %d, total time = %f seconds \n", n, other_opt_rev, time_spent_dp);
	

	return 1; 
}