#include <iostream>
using namespace std;
#define N 10

void insertSort(int A[], int n)
{
	int index, temp;

	for (int i = 2; i < n; i++)
	{
		index = i - 1;
		temp = A[i];
		while (index >= 1 && temp < A[index])
		{
			A[index + 1] = A[index];
			index--;
		}
		A[index + 1] = temp;
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

	insertSort(Array, N);

	cout << "{ ";
	for (int i = 0; i < N; i++)
	{
		cout << Array[i] << ' ';
	}
	cout << "}" << endl;
}