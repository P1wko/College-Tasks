#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;


int max(int a, int b)
{
	if (a > b) return a;
	else return b;
}

int carPacking(int capacity, int weight[], int profit[], int n)
{
	if (n == 0 || capacity == 0)
		return 0;

	if (weight[n - 1] > capacity)
		return carPacking(capacity, weight, profit, n - 1);

	else
		return max(
			profit[n - 1]
			+ carPacking(capacity - weight[n - 1], weight, profit, n - 1),
			carPacking(capacity, weight, profit, n - 1));
}

int main()
{
	int cars;
	scanf("%d", &cars);

	for (int j = 0; j < cars; j++)
	{
		int n;
		scanf("%d", &n);
		if (n <= 0)
		{
			printf("%d\n", 0);
			break;
		}
		int maxProfit = 0;
		int maxWeight = 0;
		int weight[15];
		int profit[15];

		for (int i = 0; i < n; i++)
		{
			scanf("%d", &profit[i]);
			maxProfit += profit[i];
		}
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &weight[i]);
			if (weight[i] > 100 && profit[i] <= 5)
			{
				maxProfit -= profit[i];
				profit[i] -= 5;
			}
			else if (weight[i] > 100 && profit[i] > 5)
			{
				maxProfit -= 5;
				profit[i] -= 5;
			}
			maxWeight += weight[i];
		}

		int capacity;
		scanf("%d", &capacity);

		if (maxWeight <= capacity)
		{
			maxProfit -= 20;
			if (maxProfit <= 0) printf("%d\n", 0);
			else printf("%d\n", maxProfit);
		}
		else
		{
			int money = carPacking(capacity, weight, profit, n);
			money -= 20;
			if (money < 0) printf("%d\n", 0);
			else printf("%d\n", money);
		}
	}
}

