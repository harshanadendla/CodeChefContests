#include<bits/stdc++.h>
using namespace std;

#define ll unsigned long long int

#define mod 1000000007

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int t; cin>>t;
	while(t--)
	{
		ll n; 
		cin>>n;
		ll ans=0;
		for(int i=0;i<32;i++)
		{
			ll c1,c2=0;
			ll x=1<<i;
			c1=(n/(x*2))*x;
			ll r=n%(x*2);
			if(r>=x)
			c1+=(r-x+1);
			c2=n-c1;
			ll x1=((c1*(c1-1))/2)%mod;
			ll x2=(c1*c2)%mod;
			ans=(ans+(((x1+x2)%mod)*(x))%mod)%mod;
		}
		ll x3=((n*(n+1))/2)%mod;
		ans=((ans*2)%mod + x3)%mod;
		cout<<ans<<endl;
	}
}

// ll calc(ll n) 
// { 
// 	ll ans = 0; 
// 	for (ll i = 0; i < 32; i++) { 
// 		ll k1 = 0;  
// 		ll k0 = 0; 

// 		for (ll j = 1; j <= n; j++) { 

// 			if (j & (1 << i))// if i'th bit is set 
// 				k1++; 
// 			else
// 				k0++; 
// 		} 
// 		ans = (ans + (1 << i) * (k1 * (k1 - 1) / 2) + (1 << i) * (k1 * k0))%mod; 
// 	} 
// 	return ans; 
// } 