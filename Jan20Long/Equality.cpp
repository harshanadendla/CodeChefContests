Chef Aditi keeps changing the flavours of her dishes and she wants to analyse feedback from her customers in order to improve her performance. The customers visiting Aditi's restaurant can rate the food online and Aditi knows an aggregated rating for each day. As she is busy cooking, you should perform the data analysis.

You are given a sequence A1,A2,…,AN of distinct integers denoting the customers' feedback during N days. You should process Q queries. In each query, you are given two integers L and R. Consider any contiguous subsequence Ap,Ap+1,…,Aq, where L≤p<q≤R; let's call it a maximal increasing subsequence if the following conditions hold:

Ap<Ap+1…<Aq
if p>L, then Ap<Ap−1
if q<R, then Aq>Aq+1
Similarly, let's define a maximal decreasing subsequence. You should find out if the number of maximal increasing subsequences is equal to the number of maximal decreasing subsequences (with L≤p<q≤R).

For example, if A=(10,20,30,5), we can see that the only maximal increasing subsequence of this sequence (for L=1 and R=N) is (10,20,30), since (10,20) does not satisfy the third condition and (20,30) does not satisfy the second condition, and there is only one maximal decreasing subsequence (30,5).

AC: MIL and MDL come alternately. They occur one afer the other. So, check the first two and last two elements.
If the range started with an MIL and ended with a MDL or vice versa...since they come aternately...it implies that number of MILS=
number of MDLS. If both the sart and end are ether both MILS or both Mdls...it means that their frequency differs. 

#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll n,q;
    cin>>n>>q;
    ll a[n];
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }
    ll l,r;
    while(q--)
    {
        cin>>l>>r;
        ( (a[l-1]<a[l])&&(a[r-1]<a[r-2]) || (a[l-1]>a[l])&&(a[r-1]>a[r-2]) ) ? printf("YES\n") : printf("NO\n") ;
    }
    return 0;
}
