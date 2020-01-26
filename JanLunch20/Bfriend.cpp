// a,b,minR,maxR ekkadunna sare ans is min(abs(fi-a)+abs(fi-b),ans)...anthe.....daannnii ooooo complicate chesi....muco case...tarvato case....
//madyalo 2 cases....baga overaction chesa

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
        ll n,a,b,ans;
        cin>>n>>a>>b>>ans;
        if(b<a)
        {
            ll t=a;
            a=b;
            b=t;
        }
        set<ll> s;
        ll minR=LLONG_MAX;
        ll maxR=LLONG_MIN;
        for(ll i=0;i<n;i++)
        {
            ll x;
            cin>>x;
            s.insert(x);
            if(x<minR) minR=x;
            if(x>maxR) maxR=x;
        }
        if(b<minR)
        {
            ans+=(minR-b+minR-a);
        }
        else if(a>maxR)
        {
            ans+=(a-maxR+b-maxR);
        }
        else if((a<minR && b>maxR) || (a<minR&&b<maxR&&b>minR) || (a>minR&&a<maxR&&b>maxR))
        {
            ans+=(b-a);
        }
        else
        {
            ll p=*s.upper_bound(a);
            ll q=*s.upper_bound(b);
            if(p==q)
            {
                auto it=s.begin();
                while((*it)<a)
                {
                    it++;
                }
                it--;
                ll this1=(a-(*it)+b-(*it));
                ll that1=(q-b+q-a);
                ans+=min(this1,that1);
            }
            else
            {
                ans+=(b-a);
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
