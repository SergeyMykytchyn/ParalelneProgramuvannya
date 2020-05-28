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
	double t1, t2, t;



	cout << "Simple numbers from 1 to N " << endl;
	cout << "Input N " << endl;
	cin >> S;
	N = S;


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
	//cout << "Total elapsed time : " << (clock() - t) / CLOCKS_PER_SEC << endl;
	system("pause");
	return 0;
}