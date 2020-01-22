#include <bits/stdc++.h>

using namespace std;

int main()
{
    int edgeNumber, nodeNumber, a, b, weight;
    cin >> nodeNumber >> edgeNumber;
    long long int arr[nodeNumber][nodeNumber];
    
    for(int i=0; i<nodeNumber; i++)
    {
        for(int j=0; j<nodeNumber; j++)
        {
            if(i==j)
                arr[i][j]=0;
            else
                arr[i][j]=INT32_MAX;
        }
    }

    for(int loop=0; loop<edgeNumber; loop++)
    {
        cin >> a >> b >> weight;
        arr[a][b]=weight;
    }

    for(int i=0; i<nodeNumber; i++)
    {
        for(int j=0; j<nodeNumber; j++)
        {
            for(int k=0; k<nodeNumber; k++)
            {
                if(arr[j][k]>(arr[j][i]+arr[i][k]))
                    arr[j][k]=arr[j][i]+arr[i][k];
            }
        }
    }


    for(int i=0; i<nodeNumber; i++)
    {
        for(int j=0; j<nodeNumber; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }


    return 0;
}