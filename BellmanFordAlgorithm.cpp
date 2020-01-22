#include <bits/stdc++.h>

using namespace std;

struct edge {
    int src, dest;
    double weight;
};

int main()
{
    int edgeNumber, nodeNumber, a, b,c;
    cin >> nodeNumber >> edgeNumber;


    edge infoArr[edgeNumber];
    long long int distance[nodeNumber];
    for(int i=0; i<edgeNumber; i++)
    {
        cin >> a >> b >> c;
        infoArr[i].src =a;
        infoArr[i].dest=b;
        infoArr[i].weight=c;
    }

    for(int i=0; i<nodeNumber; i++)
        distance[i]=INT32_MAX;


    int src;
    cout << "SRC\n";
    cin >> src;
    distance[src]=0;

    for(int j=0; j<nodeNumber; j++)
        for(int i=0; i<edgeNumber; i++)
        {
            int u=infoArr[i].src, v=infoArr[i].dest, w=infoArr[i].weight;
            if(distance[u] != INT_MAX && distance[u]+w<distance[v])
                distance[v]=distance[u]+w;
        }

    for(int i=0; i<nodeNumber; i++)
        cout << distance[i] << "\t";
    cout << endl;


    return 0;
}

/*
6 10
2 4 4
0 1 5
1 2 2
0 2 3
3 4 -1
1 3 6
2 3 7
2 5 2
4 5 -2
3 5 1

*/
