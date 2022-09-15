#include <iostream>
using namespace std;
#define N 10

void bubbleSort(int A[], int n)
{
	int temp;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 1; j < n - 1; j++)
		{
			if (A[j] >= A[j + 1])
			{
				temp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = temp;
			}
		}
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

	bubbleSort(Array, N);

	cout << "{ ";
	for (int i = 0; i < N; i++)
	{
		cout << Array[i] << ' ';
	}
	cout << "}" << endl;
}