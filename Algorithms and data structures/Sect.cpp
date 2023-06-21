#include <iostream>
using namespace std;

int main()
{
	int n = 0;
	int k = 0;
	int runs = 0;
	cin >> runs;
	for (int i = 0; i < runs; i++)
	{
		cin >> n >> k;

		if (k < 0) k = n + 1 + k;

		bool isFirst = false;
		int alive = k;
		int lastDead = 0;
		int* P = new int[n + 1];


		for (int j = 0; j < n; j++)
		{
			P[j] = j + 1;
		}

		while (alive >= 1)
		{
			for (int j = 0; j < n; j++)
			{
				if (!isFirst && P[j] > 0) isFirst = true;
				else if (isFirst && P[j] > 0)
				{
					lastDead = P[j];
					P[j] = -1;
					alive--;
					isFirst = false;
				}
				if (alive == 0) break;
			}
		}
		cout << lastDead << endl;
		delete[] P;
	}
}
