#include <iostream>
using namespace std;
#define N 10

int partition(int A[], int p, int r)
{
	int x = A[r];
	int i = p - 1, temp;
	for (int j = p; j < r; j++)
	{
		if (A[j] <= x)
		{
			temp = A[++i];
			A[i] = A[j];
			A[j] = temp;
		}
	}
	temp = A[i + 1];
	A[i + 1] = A[r];
	A[r] = temp;

	return i + 1;
}

void quickSort(int A[], int p, int r)
{
	int q;
	if (p < r)
	{
		q = partition(A, p, r);
		quickSort(A, p, q - 1);
		quickSort(A, q + 1, r);
	}
}

int main()
{
	int Array[N] = { 3, 50, 20, 24, 6, 76, 11, 44, 54, 99 };

	cout << "{ ";
	for (int i = 0; i < N; i++)
	{
		cout << Array[i] << ' ';
	}
	cout << "}" << endl;

	quickSort(Array, 0, N - 1);

	cout << "{ ";
	for (int i = 0; i < N; i++)
	{
		cout << Array[i] << ' ';
	}
	cout << "}" << endl;
}