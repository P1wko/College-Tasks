#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int matrix[1000][1000] = { 0 };
int apex;//wierzchołki
int walls;//ściany
int apexOnWalls;//liczba wierzchołków na ścianie
int A[1000];//wierzchołki ściany
int tests;//liczba figur
int cycles;//cycles
//int i, j, k, l, y, z;//zmienne globalne potrzebne do pętli i przeliczeń
int suma;
int pc[1000];//lista wierzchołków dla wierzchołka i z którymi potencjalnie moze stworzyć cykl

int clearing(int apex)
{
	if (apex < 100)
	{
		for (int i = 0; i < apex; i++)
		{
			for (int j = (i + 1); j < apex; j++)
			{
				if (matrix[i][j] == 1)
				{
					matrix[i][j] = 0;
					matrix[j][i] = 0;
					if (matrix[i][i] == 1)
					{
						matrix[i][i] = 0;
					}
					if (matrix[j][j] == 1)
					{
						matrix[j][j] = 0;
					}
				}
			}
		}
	}
	else
	{
		memset(matrix, 0, sizeof(matrix));
	}
	return 0;
}
int diagonal()
{
	scanf_s("%d", &walls);
	for (int i = 0; i < walls; i++)
	{

		scanf_s("%d", &apexOnWalls);
		for (int j = 0; j < apexOnWalls; j++)
		{
			scanf_s("%d", &A[j]);
		}
		for (int j = 0; j < apexOnWalls; j++)
		{
			for (int k = (j + 1); k < apexOnWalls; k++)
			{
				if (matrix[A[j]][A[k]] == 1)
				{
					continue;
				}
				if (matrix[A[j]][A[k]] == 0)
				{
					matrix[A[j]][A[k]] = 1;
					matrix[A[k]][A[j]] = 1;
					if (matrix[A[j]][A[j]] == 0)
					{
						matrix[A[j]][A[j]] = 1;
					}
					if (matrix[A[k]][A[k]] == 0)
					{
						matrix[A[k]][A[k]] = 1;
					}
				}

			}
		}
	}
	return 0;
}
int cycleFunction()
{
	cycles = 0;
	for (int i = 0; i < apex - 3; i++)
	{
		suma = 0;
		for (int j = (i + 1); j < apex; j++)
		{
			if (matrix[i][j] == 0)
			{
				pc[suma] = j;
				suma += 1;
			}
		}
		if (suma >= 2)
		{
			for (int j = 0; j < suma; j++)
			{
				for (int k = (j + 1); k < suma; k++)
				{
					for (int l = (i + 1); l < apex; l++)
					{
						if (matrix[pc[j]][l] == 1)
						{
							continue;
						}
						if (matrix[pc[k]][l] == 1)
						{
							continue;
						}
						cycles = cycles + 1;
					}
				}
			}
		}
	}
	return 0;
}



int main()
{
	scanf_s("%d", &tests);
	for (int z = 0; z < tests; z++)
	{

		scanf_s("%d", &apex);
		clearing(apex);
		diagonal();
		cycleFunction();
		printf_s("%d\n", cycles);
	}
	return 0;
}

