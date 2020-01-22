#include <stdio.h>
#include <limits.h>
#include<stdbool.h>
#include<iostream>

#define V 5

using namespace std;

int minKey(int key[], bool mstSet[])
{
	int min = INT32_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (mstSet[v] == false && key[v] < min)
			min = key[v], min_index = v;

    return min_index;
}

void primMST(int graph[V][V])
{
	int parent[V];
	int key[V];
	bool mstSet[V];

	for (int i = 0; i < V; i++)
		key[i] = INT32_MAX, mstSet[i] = false, parent[i] = INT32_MAX;
   
	key[0] = 0;
	parent[0] = -1;
	
    for (int count = 0; count < V-1; count++)
	{

		int u = minKey(key, mstSet);

		mstSet[u] = true;

		for (int v = 0; v < V; v++)
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];

	}

	printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++)
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);

}

int main()
{
int graph[V][V] = { {0, 9, 75, 0, 0},
                    {9, 0, 95, 19, 42},
                    {75, 95, 0, 51, 66},
                    {0, 19, 51, 0, 31},
                    {0, 42, 66, 31, 0}};

	primMST(graph);

	return 0;
}

