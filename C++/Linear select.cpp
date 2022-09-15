#include <iostream>
using namespace std;
#define N 10
#define small 3

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

int linearSelect(int A[], int p, int r, int i)
{
	int temp, k = 0;
	int A1[5], A2[5], A3[5];
	if (r <= 5)
	{
		temp = A[0];
		for (int i = 0; i < r; i++)
		{
			if (temp >= A[i])
				temp = A[i];
		}
		return temp;
	}
	else if (r > 5)
	{
		for (int i = 0; i < r / 5; i++)
		{
			switch (i)
			{
			case 0:
			{
				for (int j = 0; j < 5; j++)
				{
					A1[j] = A[k];
					k++;
					if (A[k + 1] == '\0')
						break;
				}
				break;
			}

			case 1:
			{
				for (int j = 0; j < 5; j++)
				{
					A2[j] = A[k];
					k++;
					if (A[k + 1] == '\0')
						break;
				}
				break;
			}
			case 3:
			{
				for (int j = 0; j < 5; j++)
				{
					A3[j] = A[k];
					k++;
					if (A[k + 1] == '\0')
						break;
				}
				break;
			}
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

	int max = linearSelect(Array, 0, N - 1, small);

	cout << small << "번째로 작은 원소는 " << max << endl;
}