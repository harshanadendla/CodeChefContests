// pilla sum...ventane vachindi le....input chadavadam rala...si,pi,vi.....ante horizontal anukunna....sarigga question artham cheskola
//1.5 hr ki submit chesa.....rank sNakipoindi.

#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,ans=LLONG_MIN;
        cin>>n;
        ll a,b,c,x;
        for(ll i=0;i<n;i++)
        {
            cin>>a>>b>>c;
            x=(b/(a+1));
            x*=c;
            if(x>ans) ans=x;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
