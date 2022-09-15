#include <iostream>
using namespace std;
#define N 10
#define MAX 2

void radixSort(int A[], int n, int k)
{
	int radix = 1, temp = 0;
	int M[N];
	for (int i = 1; i < k; i++)
	{
		for (int j = 0; j < n; j++)
		{
			temp = (A[j] / radix) % 10;
			M[temp] = A[j];
		}
		temp = 0;
		radix *= 10;
	}

	for (int i = 0; i < N; i++)
	{
		A[i] = M[i];
	}
}

int main()
{
	int Array[N] = { 93, 50, 20, 24, 16, 76, 11, 44, 54, 99 };

	cout << "{ ";
	for (int i = 0; i < N; i++)
	{
		cout << Array[i] << ' ';
	}
	cout << "}" << endl;

	radixSort(Array, N, MAX);

	cout << "{ ";
	for (int i = 0; i < N; i++)
	{
		cout << Array[i] << ' ';
	}
	cout << "}" << endl;
}