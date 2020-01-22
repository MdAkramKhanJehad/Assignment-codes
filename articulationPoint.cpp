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
int parent[100];
int discoveryTime[100];
int low[100];
int articulationPoint[100];
int times = 0;

void dodfs(int startingNode)
{

    color[startingNode] = GRAY;
    ++times;
    discoveryTime[startingNode] = times;
    low[startingNode] = times;
    int child = 0;

    for(int i=0; i<totalNode; i++)
    {
        if(graph[startingNode][i] == 1)
        {
            if(color[i] == WHITE) {
                child++;
                parent[i] = startingNode;
                dodfs(i);

                low[startingNode] = min(low[startingNode], low[i]);
                if(parent[startingNode]!=-1 && low[i]>=discoveryTime[startingNode])
                    articulationPoint[startingNode] = 1;
                if(parent[startingNode]==-1 && child>1)
                    articulationPoint[startingNode] = 1;
            }

            else if(i!=parent[startingNode])
            {
                low[startingNode] = min(low[startingNode], discoveryTime[i]);
            }
        }
    }

    color[startingNode] = BLACK;
    ++times;
}

void dfs()
{
    for(int i=0; i<totalNode; i++){
        color[i] = WHITE;
        parent[i] = -1;
        articulationPoint[i] = 0;
    }
    
    for(int i=0; i<totalNode; i++)
    {
        if(color[i] == WHITE)
            dodfs(i);
    }

}


int main()
{

    cin >> totalNode >> totalEdge;

    int n1, n2;
    for(int i=0; i<totalEdge; i++)
    {
        cin >> n1 >> n2;
        graph[n1][n2] = 1;
        graph[n2][n1] = 1;
    }

    dfs();

    cout <<"Articulations points : ";

    for(int i=0; i<totalNode; i++)
        if(articulationPoint[i] == 1)
            cout << i << " ";
    cout << endl;

    return 0;
}
/*
8 9
0 1
0 2
1 2
2 3
3 4
4 5
4 6
5 6
6 7

*/
