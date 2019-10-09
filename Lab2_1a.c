#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define NP 10000000
int vect1[NP]
int main(int argc, char *argv[]){
	unsigned long int i, n =(unsigned long int)NP;
	clock_t start, end;
	double totsum = 0.0;
	 srand(time(NULL));
	 for ( i = 0; i <n; i++) vect1[i] = (rand() % 100 + 1);
	start = clock();
	for (i = 0; i < n; i++){
		totsum += (double)vect1[i];
	}
	end = clock;
	double t =(double) (end-start)/CLOCKS_PER_SEC;
	printf("Time elapsed is %f secs. \n",t);
	return 0;
}