#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007

vector<ll> factorise(ll n)
{
    vector<ll> res;
    ll k=sqrt(n);
    for(ll i=1;i<=k;i++)
    {
        if(n%i==0)
        {
            res.push_back(i);
            if(i!=(n/i)) res.push_back((n/i));
        }
    }
    return res;
}

ll calc(vector<ll> factors)
{
    ll res=1;
    for(ll i=0;i<factors.size();i++)
    {
        res=res*(1+factors[i]);
        res%=mod;
    }
    return --res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        cout<<(calc(factorise(n))%mod)<<"\n";
    }
    return 0;
}