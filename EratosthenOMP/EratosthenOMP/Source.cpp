#include <iostream>
#include <time.h> 
#include <omp.h>
#include <math.h>
#include <ctime>
#pragma opm

using namespace std;
int main(int argc, char *argv[])
{

	long long i, j, S; 
	long long N; 
	bool *mas; 
	double t1, t2,t;



	cout << "Simple numbers from 1 to N " << endl;
	cout << "Input N " << endl;
	cin >> S;
	N = S + 1;


	mas = new bool[N]; 
	t1 = omp_get_wtime();
	t = clock();
#pragma omp parallel for 
	for (i = 1; i <= S; i++) mas[i] = true;

#pragma omp parallel for
	for (i = 2; i <= (int)sqrt(N); ++i) {
		if (mas[i]) {
#pragma omp parallel for
			for (j = (i*i); j <= S; j += i)
				if (mas[j]) mas[j] = false;
		}
	}
#pragma omp barrier


	unsigned long long count = 0;
	for (i = 1; i <= S; i++)
		if (mas[i]) count++;

	t2 = omp_get_wtime();

	cout << "Primes : " << count << endl;
	cout << "Total elapsed time : " << t2 - t1 << endl;
	cout << "Total elapsed time : " << (clock() - t) / CLOCKS_PER_SEC << endl;
	system("pause");
	return 0;
}
/*
#include <iostream>
#include <time.h> 
#include <omp.h>
#include <math.h>
#include <ctime>
#pragma opm

using namespace std;

int main(int argc, char *argv[]) {
	int N, sqrtN=0; 
	int c = 2; //next circle
	int m = 3; //next prime
	int *list; 
	double t1, t2, t;

	cout << "Input N:" << endl;
	cin >> N;


	sqrtN = (int)sqrt(N);
	list = (int*)malloc(N * sizeof(int));
	t1 = omp_get_wtime();
#pragma omp parallel for
	for (c = 2; c <= N - 1; c++) {
		list[c] = 0;
	}
	for (c = 2; c <= sqrtN; c++) {
		if (list[c] == 0) {
#pragma omp parallel for
			for (m = c + 1; m <= N - 1; m++) {
				if (m%c == 0) {
					list[m] = 1;
				}
			}
		}
	}
	

	int count = 0;
	for (c = 2; c <= N - 1; c++) {
		if (list[c] == 0) {
			count++;
		}
	}
	cout<< count<<endl;
	t2 = omp_get_wtime();
	cout << "Total elapsed time : " << t2 - t1 << endl;
	free(list);
	system("pause");
	return 0;
}*/