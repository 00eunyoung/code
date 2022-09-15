#include <iostream>
using namespace std;
#define N 10

void selectionSort(int A[], int n)
{
	int index, temp;
	for (int i = 0; i < n - 1; i++)
	{
		index = i;
		for (int j = i + 1; j < n; j++)
		{
			if (A[index] > A[j])
				index = j;
		}

		temp = A[i];
		A[i] = A[index];
		A[index] = temp;
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

	selectionSort(Array, N);

	cout << "{ ";
	for (int i = 0; i < N; i++)
	{
		cout << Array[i] << ' ';
	}
	cout << "}" << endl;
}