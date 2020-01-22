#include<iostream>
using namespace std;

int totalVertices,totalEdge;
int graph[100][100];
int dis[100];
bool visited[100];

int minimum()
{
    int min = INT32_MAX, minIndex = 0;

    for(int i=0; i<totalVertices; i++)
        if(visited[i]==false && dis[i]<=min){
            min = dis[i], minIndex = i;
            //cout <<"min : "<< min << " min index : "<< minIndex<< endl;
        }
    return minIndex;
}

void dijkstra(int source)
{
    for(int i=0; i<totalVertices; i++)
        dis[i] = INT32_MAX, visited[i] = false;

    dis[source] = 0;

    for(int i=0; i<totalVertices; i++)
    {
        int u = minimum();
        visited[u] = true;
        //cout <<"\n u : "<< u<<" source : "<< source<< endl;
        for(int v=0; v<totalVertices; v++)
            if(visited[v]==false && graph[u][v]!=0 && dis[u]!=INT32_MAX && (dis[u]+graph[u][v])<dis[v])
                dis[v] = (dis[u]+graph[u][v]);

    }
}


int main()
{
    cin >> totalVertices >> totalEdge;


    for(int i=0; i<totalVertices; i++)
        for(int j=0; j<totalVertices; j++)
            graph[i][j] = 0;


    for(int i=0; i<totalEdge; i++)
    {
        int n1,n2,weight;
        cin >> n1 >> n2 >> weight;
        graph[n1][n2] = weight;
    }


    for(int i=0; i<totalVertices; i++)
    {
        cout << i << " --> " << endl;
        dijkstra(i);

        for(int i=0; i<totalVertices; i++)
            cout << i << "\t" << dis[i] << endl;
        cout << endl;
    }




}

/*

5 10
0 1 10
0 3 5
1 2 1
1 3 2
2 4 4
3 1 3
3 2 9
3 4 2
4 2 6
0 4 2
*/
