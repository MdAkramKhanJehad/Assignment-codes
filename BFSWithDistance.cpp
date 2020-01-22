#include<iostream>
#include<stdio.h>
#include<queue>
#define WHITE 1
#define GRAY 2
#define BLACK 3
using namespace std;

int numberOfNode, numberOfEdge;
int graph[100][100];
int color[100];
int parent[100];
int dis[100];

void bfs(int startingNode)
{
    for(int i=0; i<numberOfNode; i++)
    {
        color[i] = WHITE;
        parent[i] = -1;
        dis[i] = INT32_MIN;
    }

    dis[startingNode] = 0;
    parent[startingNode] = -1;

    queue<int> q;
    q.push(startingNode);

    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        color[x] = GRAY;

        cout << x << " -> ";

        for(int i=0; i<numberOfNode; i++)
        {
            if(graph[x][i] == 1)
            {
                if(color[i] == WHITE)
                {
                    parent[i] = x;
                    dis[i] = dis[x] + 1;
                    q.push(i);
                }
            }
        }

        color[x] = BLACK;
    }

    cout << endl;
}

void printDis()
{
    for(int i=0; i<numberOfNode; i++)
        cout << "Distance of " << i << " is " << dis[i] << " from 0" << endl;

}

int main()
{

    cin >> numberOfNode >> numberOfEdge;

    int n1, n2;
    for(int i=0; i<numberOfEdge; i++)
    {
        cin >> n1 >> n2;
        graph[n1][n2] = 1;
    }

    bfs(0);
    printDis();


    return 0;
}

/*
8 18
0 1
1 0
0 4
4 0
1 5
5 1
5 2
2 5
5 6
6 5
6 2
2 6
6 7
7 6
7 3
3 7
3 2
2 3



*/

