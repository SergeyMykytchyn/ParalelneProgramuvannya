#include <iostream>
#include <ctime> 
#include <math.h>


using namespace std;

int main()
{

	int i, j, S;
	int N; 
	bool *mas; 
	double t;



	cout << "Simple numbers from 1 to N " << endl;
	cout << "Input N " << endl;
	cin >> S;
	N = S + 1;

	t = clock();

	mas = new bool[N]; 

	for (i = 1; i <= S; i++) mas[i] = true;


	for (i = 2; i <= (int)sqrt(N); ++i){
		if (mas[i]){

			for (j = (i*i); j <= S; j += i)
				if (mas[j]) mas[j] = false;
		}
	}


	int count = 0;
	for (i = 1; i <= S; i++)
		if (mas[i]) count++;



	cout << "Primes : " << count << endl;
	cout << "Total elapsed time : " << 0.121 / CLOCKS_PER_SEC << endl;
	system("pause");
	return 0;
}