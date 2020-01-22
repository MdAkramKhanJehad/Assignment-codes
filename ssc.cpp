#include<iostream>
#define WHITE 1
#define GRAY 2
#define BLACK 3

using namespace std;

int totalNode, totalEdge, times = 0;
int graph[100][100], color[100];
int startingTime[100], finishingTime[100];
int topologicalOrder[100], graphT[100][100], scc[100], counter = 0;

void dodfsForGraph(int x)
{
    color[x] = GRAY;
    ++times;
    startingTime[x] = times;

    for(int i=0; i<totalNode; i++)
    {
        if(graph[x][i] == 1)
        {
            if(color[i] == WHITE)
                dodfsForGraph(i);
        }

    }

    color[x] = BLACK;
    ++times;
    finishingTime[x] = times;
}

void dfsForGraph()
{
    for(int i=0; i<totalNode; i++)
        color[i] = WHITE;

    for(int i=0; i<totalNode; i++)
        if(color[i] == WHITE)
            dodfsForGraph(i);

}

void dotopologicalOrder()
{
    int tmpfinishingtime[totalNode];
    for(int i=0; i<totalNode; i++)
        tmpfinishingtime[i] = finishingTime[i];

    for(int i=0; i<totalNode; i++)
    {
        int max = tmpfinishingtime[i];
        int maxIndex = i;
        for(int j=0; j<totalNode; j++)
        {
            if(tmpfinishingtime[j]>=max){
                max = tmpfinishingtime[j];
                maxIndex = j;
            }
        }

        topologicalOrder[i] = maxIndex;
        tmpfinishingtime[maxIndex] = INT32_MIN;
    }
}


void dodfsForGraphT(int x)
{
    color[x] = GRAY;
    ++times;
    startingTime[x] = times;

    for(int i=0; i<totalNode; i++)
    {
        if(graphT[x][i] == 1)
        {
            if(color[i] == WHITE)
                dodfsForGraphT(i);
        }

    }

    color[x] = BLACK;
    ++times;
    finishingTime[x] = times;
    scc[counter] = x;
    counter++;

}


void dfsForGraphT()
{
    for(int i=0; i<totalNode; i++)
    {
        color[i] = WHITE;
        startingTime[i] = 0;
        finishingTime[i] = 0;
    }

    times = 0;

    for(int i=0; i<totalNode; i++)
    {
        if(color[topologicalOrder[i]] == WHITE)
        {
            dodfsForGraphT(topologicalOrder[i]);
            scc[counter] = -1;
            counter++;
        }
    }
}

void printDfsForGraph()
{
    int tmpstime[totalNode];
    for(int i=0; i<totalNode; i++)
        tmpstime[i] = startingTime[i];

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

        cout <<  minIndex << " (" << startingTime[minIndex] << "/" << finishingTime[minIndex] << ") " << " -> ";
        tmpstime[minIndex] = INT32_MAX;
    }

    cout << endl;

}


int main()
{
    cin >> totalNode >> totalEdge;

    for(int i=0; i<totalEdge; i++)
    {
        int n1,n2;
        cin >> n1 >> n2;
        graph[n1][n2] = 1;
    }

    dfsForGraph();

    printDfsForGraph();

    dotopologicalOrder();

    cout <<"topological order : ";
    for(int i=0; i<totalNode; i++)
        cout << topologicalOrder[i] << " ";

    cout << endl;

    //transpose
    for(int i=0; i<totalNode; i++)
    {
        for(int j=0; j<totalNode; j++)
            graphT[j][i] = graph[i][j];
    }

    for(int i=0; i<totalNode; i++)
    {
        for(int j=0; j<totalNode; j++)
        {
            cout << "Edges after tranpose: \n";
            if(graphT[i][j] ==1 )
                cout << i << " -> " << j << endl;

        }
    }

    dfsForGraphT();

    cout << endl;

    for(int i=0; i<counter; i++)
        cout << scc[i] << " ";

    cout << endl;

    return 0;
}

/*
8 12
0 1
1 5
1 6
2 6
2 3
3 7
4 1
5 4
5 2
6 5
6 7
7 3
*/
