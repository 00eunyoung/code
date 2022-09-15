#include <iostream>
#define N 10;
using namespace std;


void heapify(int A[], int k, int n)
{
	int left = 2 * k, right = 2 * k + 1, small, temp;

	if (right <= n)
	{
		if (A[left] > A[right])
			small = left;
		else
			small = right;
	}

	else if (left <= n)
		small = left;

	else
		return;

	if (A[small] > A[k])
	{
		temp = A[k];
		A[k] = A[small];
		A[small] = temp;
		heapify(A, small, n);
	}
}

void buildHeap(int A[], int n)
{
	for (int i = (n / 2); i >= 1; i--)
	{
		heapify(A, i, n);
	}
}

void heapSort(int A[], int n)
{
	int temp;
	buildHeap(A, n);
	for (int i = n; i >= 2; i--)
	{
		temp = A[1];
		A[1] = A[i];
		A[i] = temp;
		heapify(A, 1, i - 1);
	}
}

int main()
{
	int Array[10] = { -1, 50, 20, 24, 6, 76, 11, 44, 54, 99 };

	cout << "{ ";
	for (int i = 1; i < 10; i++)
	{
		cout << Array[i] << ' ';
	}
	cout << "}" << endl;

	heapSort(Array, 9);

	cout << "{ ";
	for (int i = 1; i < 10; i++)
	{
		cout << Array[i] << ' ';
	}
	cout << "}" << endl;
}