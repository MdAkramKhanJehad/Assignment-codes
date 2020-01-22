#include<iostream>
#include<stdio.h>
#include<stack>

#define WHITE 1
#define GRAY 2
#define BLACK 3
using namespace std;

int totalNode, totalEdge;
int graph[100][100];
int color[100];
int discoveryTime[100];
int finishingTime[100];
int times = 0;

void dodfs(int startingNode)
{

    color[startingNode] = GRAY;
    ++times;
    discoveryTime[startingNode] = times;

    for(int i=0; i<totalNode; i++)
    {
        if(graph[startingNode][i] == 1)
        {
            if(color[i] == WHITE)
                dodfs(i);
        }
    }

    color[startingNode] = BLACK;
    ++times;
    finishingTime[startingNode] = times;
}

void dfs()
{
    for(int i=0; i<totalNode; i++)
        color[i] = WHITE;
    for(int i=0; i<totalNode; i++)
    {
        if(color[i] == WHITE)
            dodfs(i);
    }

}

void printdfs()
{
    int tmpstime[totalNode];
    for(int i=0; i<totalNode; i++)
        tmpstime[i] = discoveryTime[i];

    for(int i=0; i<totalNode; i++)
    {
        int min = tmpstime[i];
        int minIndex = i;
        for(int j=0; j<totalNode; j++)
        {
            if(tmpstime[j]<=min) {
                min = tmpstime[j];
                minIndex = j;
            }
        }

        cout << (char)('A' + minIndex) << " -> ";
        tmpstime[minIndex] = INT32_MAX;
    }

    cout << endl;

}


int main()
{

    cin >> totalNode >> totalEdge;

    int n1, n2;
    for(int i=0; i<totalEdge; i++)
    {
        cin >> n1 >> n2;
        graph[n1][n2] = 1;
    }

    dfs();
    printf("DFS : ");
    printdfs();
    
    printf("\nstarting and Finishing time:\n");
    
    for(int i=0; i<totalNode; i++)
        cout << (char)('A'+i) << " (" << discoveryTime[i] << " / " << finishingTime[i] << ")" << endl;
    
    
    printf("\nPrint in topological order: ");
    
    int tmpftime[totalNode];
    for(int i=0; i<totalNode; i++)
        tmpftime[i] = finishingTime[i];

    for(int i=0; i<totalNode; i++)
    {
        int max = tmpftime[i];
        int maxIndex = i;
        for(int j=0; j<totalNode; j++)
        {
            if(tmpftime[j]>=max) {
                max = tmpftime[j];
                maxIndex = j;
            }
        }

        cout << (char)('A' + maxIndex) << " -> ";
        tmpftime[maxIndex] = INT32_MIN;
    }

    cout << endl;

    return 0;
}
/*
10 13
0 1
0 5
1 7
3 2
3 4
3 7
3 8
4 8
6 0
6 1
6 2
8 2
9 4*/
