#include <bits/stdc++.h>

using namespace std;

int calc(int *val, int* wt, int W, int nOfItems)
{
    int k[nOfItems+1][W+1];

    for(int j=0; j<W+1; j++)
        k[0][j]=0;

    for(int i=1; i<nOfItems+1; i++)
    {
        for(int j=0; j<W+1; j++)
        {
            if(wt[i-1]<=j)
                k[i][j]=max(val[i-1]+k[i-1][j-wt[i-1]], k[i-1][j]);
            else
                k[i][j]=k[i-1][j];
        }
    }

    return k[nOfItems][W];
}

int main()
{
    int val[] = {60, 100, 120};
    int wt[] = {1, 2, 3};
    int  W = 5, n=5;

    cout << calc(val, wt, W, n)<< endl;

    return 0;
}


