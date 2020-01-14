Doraemon has a matrix with N rows (numbered 1 through N) and M columns (numbered 1 through M). Let's denote the element in row i and column j by Ai,j. Next, let's define a sub-row of a row r as a sequence Ar,x,Ar,x+1,…,Ar,y for some x and y (1≤x≤y≤M) and a sub-column of a column c by Ax,c,Ax+1,c,…,Ay,c for some x and y (1≤x≤y≤N).

You need to find the number of pairs (sub-row of some row, sub-column of some column) with the following properties:

Both sequences (the sub-row and the sub-column) have the same length.
This length is odd.
The central elements of both sequences are the same (they correspond to the same element of the matrix).
Both sequences are palindromes.

#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        int a[n][m]={0};
        for(ll i=0;i<n;i++)
        {
            for(ll j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        ll count=0;
        for(ll i=1;i<n-1;i++)
        {
            for(ll j=1;j<m-1;j++)
            {
                ll level=1;
                while(i-level>=0 && i+level<=n-1 && j-level>=0 && j+level<=m-1 && 
                      a[i-level][j]==a[i+level][j] && a[i][j-level]==a[i][j+level])
                {
                    count++;
                    level++;
                }
            }
        }
        cout<<((n*m)+count)<<"\n";
    }
    return 0;
}
