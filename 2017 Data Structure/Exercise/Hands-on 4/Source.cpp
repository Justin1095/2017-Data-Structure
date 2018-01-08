// Justin Seda
#include <iostream>    // needed to perform C++ I/O 
#include <time.h>
#include<math.h>
using namespace std;

double Ex1(int[], int);
double Ex2(int[], int);
double Ex3(int[], int);
double Ex4(int[], int);
int Ex5(int[], int[], int);
double powerN( int x, int n);
double powerLogN( int x,  int n);

 const int MAX = 3;

int count1 = 0;
int count2 = 0;

int main()
{
	clock_t start, stop;
	double res;

	int * A = new int[MAX];
	int * B = new int[MAX];

	for (int i = 0; i < MAX; i++)
	{
		A[i] = i + 1;
	}

	/*for (int i = 0; i < MAX; i++)
	{
		B[i] = i + 1;
		for (int j = 0; j <= i; j++)
		{
			B[i] = B[i] + j;
		}
	} */

	B[0] = 1;
	for (int j = 1; j < MAX; j++)
	{
		B[j] = B[j - 1] + (j + 1);
	} 


	
	start = clock();
	res = Ex1(A, MAX);
	stop = clock();

	cout << "The sum of the elements in A is " << res << endl;
	cout << "Running time for Ex1 is " << static_cast<double>(stop - start) / (CLOCKS_PER_SEC) << endl;
	cout << endl;

	start = clock();
	res = Ex2(A, MAX);
	stop = clock();

	cout << "The sum of the elements in A is " << res << endl;
	cout << "Running time for Ex2 is " << static_cast<double>(stop - start) / (CLOCKS_PER_SEC) << endl;
	cout << endl;

	start = clock();
	res = Ex3(A, MAX);
	stop = clock();

	cout << "The sum of the elements in A is " << res << endl;
	cout << "Running time for Ex3 is " << static_cast<double>(stop - start) / (CLOCKS_PER_SEC) << endl;
	cout << endl;
	

	start = clock();
	res = Ex4(A, MAX);
	stop = clock();

	cout << "The sum of the elements in A is " << res << endl;
	cout << "Running time for Ex4 is " << static_cast<double>(stop - start) / (CLOCKS_PER_SEC) << endl;
	cout << endl; 

	start = clock();
	res = Ex5(A, B, MAX);
	stop = clock();

	cout << "The sum of the elements in B equal to the sum of prefix sums in A is " << res << endl;
	cout << "Running time for Ex5 is " << static_cast<double>(stop - start) / (CLOCKS_PER_SEC) << endl;
	cout << endl;
	
	 int x = 2; 
	 int n = 2;

	start = clock();
	res = powerN(x , n);
	stop = clock();

	cout << "The sum of the elements in powerN( x, n) for 2^n is " << res << endl;
	cout << "Running time for powerN( x, n) is " << static_cast<double>(stop - start) / (CLOCKS_PER_SEC) << endl;
	cout << endl;

	start = clock();
	res = powerLogN(x, n);
	stop = clock();

	cout << "The sum of the elements in powerLogN( x, n) for 2^n is " << res << endl;
	cout << "Running time for powerLogN( x, n) is " << static_cast<double>(stop - start) / (CLOCKS_PER_SEC) << endl;
	cout << endl;

	system("pause");
	return 0;
}


double Ex1(int A[], int n)
{
	double s = A[0];
	for (int i = 1; i <= n - 1; i++)
	{
		s = s + A[i];
	}
	return s;
}


double Ex2(int A[], int n)
{
	double s = A[0];
	for (int i = 2; i <= n - 1; i = i + 2)
	{
		s = s + A[i];
	}
	return s;
}


double Ex3(int A[], int n)
{

	double s = 0;
	for (int i = 0; i <= n - 1; i++)
	{
		s = s + A[0];
		for (int j = 1; j <= i ; j++)
		{
			s = s + A[j];
		}
	}
	return s;
}


 double Ex4(int A[], int n)
{
	double s = A[0];
	double t = s;
	for (int i = 1; i <= n - 1; i++)
	{
		s = s +A[i];
		t = t + s;
	}
	return t;
}


int Ex5(int A[], int B[], int n)
{
	int c = 0;
	int s;
	for(int i = 0; i <= n - 1; i++)
	{
		int s = 0;
		for(int j = 0; j <= i; j++)
		{
			s = s + A[0];
			for(int k = 1; k <= j; k++)
			{
				s = s + A[k];
			} 
		}
		if(B[i] = s)
		{
			c = c + 1;
		}
	}
	return c;
} 


  double powerN( int x,  int n)
 {
	 if (n == 0)
	 {
		//count1++; 
		 cout << "The count result is " << count1 << endl;
		 return 1;
	 }
	 else
	 {
		 count1++;
		 return x * powerN(x, n - 1);
	 }
 }


  double powerLogN( int x,  int n)
 {
	 if (n == 0)
	 {
		//count2++;
		 cout << "The count result is " << count2 << endl;
		 return 1;
	 }
	 else if( n > 0 && n % 2 != 0)
	 {
		 count2++;
		 return x * pow(powerLogN(x, (n - 1)/2), 2);
	 }
	 else if (n > 0 && n % 2 == 0)
	 {
		 count2++;
		 return pow(powerLogN(x, n/2), 2);
	 }
 } 
 
