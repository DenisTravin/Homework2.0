#include <iostream>
#include <cstdio>
#include <vector>

const int maxCity = 100;//max of cities 

int min(int a, int b)//return minimum between 2 int numbers
{
	if (a > b)
	{
		return b;
	}
	else
	{
		return a;
	}
}

void main(void)
{
	FILE *in;
	int matrixGraph[maxCity][maxCity] = {};
	int m = 0;
	int n = 0;
	in = fopen("in.txt", "r");
	fscanf(in, "%i %i", &n, &m);
	//fill graph matrix by max numbers
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i != j)
			{
				matrixGraph[i][j] = INT16_MAX;
			}
		}
	}
	//add edges to graph matrix
	for (int i = 0; i < m; i++)
	{
		int a, b, len;
		fscanf(in, "%i %i %i", &a, &b, &len);
		matrixGraph[a - 1][b - 1] = len;
		matrixGraph[b - 1][a - 1] = len;
	}
	int capitals[maxCity];//array of capitals 
	int k = 0;
	fscanf(in, "%i", &k);
	for (int i = 0; i < k; i++)
	{
		fscanf(in, "%i", &capitals[i]);
		capitals[i]--;
	}
	fclose(in);
	//Floyd algorithm 
	for (int i = 0; i < n; i++)
	{
		for (int u = 0; u < n; u++)
		{
			for (int v = 0; v < n; v++)
			{
				matrixGraph[u][v] = min(matrixGraph[u][v], matrixGraph[u][i] + matrixGraph[i][v]);
			}
		}
	}

	int cities[maxCity];//array for capitals for all cities
						//finding capital for each city
	for (int i = 0; i < n; i++)
	{
		cities[i] = capitals[0];
		for (int j = 1; j < k; j++)
		{
			if (matrixGraph[i][cities[i]] >= matrixGraph[i][capitals[j]])
			{
				cities[i] = capitals[j];
			}
		}
	}
	//output:
	for (int i = 0; i < k; i++)
	{
		printf("\n%i country: ", i + 1);
		for (int j = 0; j < n; j++)
		{
			if (cities[j] == capitals[i])
			{
				printf("%i ", j + 1);
			}
		}
	}
	scanf("%*s");
}
/*
Test 1:
Input:
7 8
5 1 3
5 2 2
5 3 2
5 4 1
5 6 2
7 1 1
7 4 2
7 6 1
2
5 6
Output:
1 country: 2 3 4 5
2 country: 1 6 7
Test 2:
Input:
8 7
2 3 1
2 4 1
2 5 1
2 1 5
1 6 1
1 7 1
1 8 1
2
1 2
Output:
1 country: 1 6 7 8
2 country: 2 3 4 5
*/