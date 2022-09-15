#include <iostream>
#define N 10
#define small 4
using namespace std;

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

int select(int A[], int p, int r, int i)
{
	int q, k;
	if (p == r)
		return A[p];
	q = partition(A, p, r);
	k = q - p + 1;
	if (i < k)
	{
		return select(A, p, q - 1, i);
	}
	else if (i == k)
		return A[q];
	else
		return select(A, q + 1, r, i - k);
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

	int max = select(Array, 0, N - 1, small);

	cout << small << "번째로 작은 원소는 " << max << endl;
}