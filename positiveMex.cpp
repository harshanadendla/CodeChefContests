//ac in 1 go!
//nee bondaa......emo....if  is missing in the array...i am actually accessing a[-1]
//i wondered.....that is not a seg fault....\__/
//thu yadava....fluke lo kalisesindi
//so added that if (...)....now satisfied

/*
    YES PAIN YES GAIN
*/
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
using namespace std;
using namespace __gnu_pbds;
template<class T>
using rbTree=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define unmap unordered_map
#define mset multiset
#define pii pair<int,int>
#define vi vector<int>
#define vpii vector<pair<int,int>>
#define vvi vector<vector<int>>
#define mem(u,v) memset(u,v,sizeof(u))
#define all(x) x.begin(),x.end()
#define r_all(x) x.rbegin(),x.rend()
#define dbg(x) cout<<#x<<" "<<x<<"\n"
#define bug1 cout<<"hi1"<<endl
#define bug2 cout<<"hi2"<<endl
#define bug3 cout<<"hi3"<<endl
const int N=1e5+5;
const int mod=998244353;

int p[N];

int Mmul(int a,int b) {
    return ((a%mod)*(b%mod))%mod;
}

int Madd(int a,int b) {
    return ((a%mod)+(b%mod))%mod;
}

void pre() {
    p[0]=1;
    for (int i=1;i<N;i++) {
        p[i]=Mmul(p[i-1],2);
    }
}

void solve() {
    int n;
    cin>>n;

    int a[n];
    map<int,int> cnt;
    for (int i=0;i<n;i++) {
        cin>>a[i];
        cnt[a[i]]++;
    }

    sort(a,a+n);

    int mex=1;

    int i=0;
    int ans=0;
    int prev=1;
    while(i<n) {
        while(i<n && a[i]==mex) {
            i++;
        }
        if (i==0) {
            ans=p[n];
            break;
        }
        int res=Mmul(prev,mex);
        res=Mmul(res,p[n-i]);
        ans=Madd(ans,res);
        prev=Mmul(prev,p[cnt[a[i-1]]]-1);

        mex++;

        if (a[i]==mex && i!=0) {
            continue;
        } else {
            res=Mmul(prev,mex);
            res=Mmul(res,p[n-i]);
            ans=Madd(ans,res);
            break;
        }
    }

    cout<<ans%mod<<"\n";
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    pre();

    int t=1;
    cin>>t;

    while(t--) {
        solve();
    }

    return 0;
}