Dr.D is now fond of matrices. He is particularly interested in Doofish Matrices. A Doofish Matrix of order N is a matrix with N rows (numbered 1 through N) and N columns (numbered 1 through N) such that:

Each element of this matrix is an integer between 1 and 2N−1 inclusive.
For each i and j (1≤i≤N, 1≤j≤2N−1), the integer j appears in the i-th row and/or in the i-th column.
Now, for a given N, Dr.D is wondering if there is a Doofish Matrix of order N. Find such a matrix or determine that it does not exist. If there are multiple solutions, you may find any one.

!RR:-
void doofish(ll n){
    ll i,j;
    ll n1=n-1;
    ll h[n-1]={0};
    ll h1[n-1]={0};
    for(i=0;i<n;i++){
        h[i]=i+2;
        h1[i]=i+n+1;
    }
    
    ll a[n][n],k=0;
    cout<<"Hooray\n";
    for(i=0;i<n;i++){
    k=(i-1)%n;
        for(j=0;j<=i;j++)
        {
            (i==j)  ? a[i][j]=1 : (a[j][i]=h[k],a[i][j]=h1[k]) ;
            (i==n1) ? k=(k+2)%n1 : k=(k+1)%n1;        
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
        cout<<a[i][j]<<" ";
        cout<<endl;
    }
}

or

RR:-
for(int i=0;i<N;i++)
{
    for(int j=0;j<N;j++)
    {
        printf("%d%c", i==j ? 2*N-1 : (i+j)*( i<N-1&&j<N-1 ? N/2 : 1)%(N-1)+(i>j?N:1)," \n"[j==N-1]);
    }
}
