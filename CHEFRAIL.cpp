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
#define bug1 cout<<"hi1"<<endl
#define bug2 cout<<"hi2"<<endl
#define bug3 cout<<"hi3"<<endl
const int N=1e5+5;
const int mod=1e9+7;

int lpf[N];
map<int,vi> dna;

void pre() {
    for (int i=1;i<N;i++) {
        lpf[i]=i;
    }

    for (int i=4;i<N;i+=2) {
        lpf[i]=2;
    }

    for (int i=3;i*i<N;i+=2) {
        if (lpf[i]==i) {
            for (int j=i*i;j<N;j+=i) {
                if (lpf[j]==j) {
                    lpf[j]=i;
                }
            }
        }
    }

    for (int i=1;i<N;i++) {
        if (floor(sqrt(i)) == ceil(sqrt(i))) {
            dna[i].pb(1);
            continue;
        }
        map<int,int> m;
        int j=i;
        while (j!=1) {
            m[lpf[j]]++;
            j/=lpf[j];
        }
        for (auto it=m.begin();it!=m.end();it++) {
            int val=it->s;
            if (val%2) {
                dna[i].pb(it->f);
            }
        }
    }
}

void solve() {
    int n,m;
    cin>>n>>m;

    int ans=0;
    bool xzero=false,yzero=false;
    set<int> xneg,xpos,yneg,ypos;
    map<int,int> hashx,hashy;
    map<vi,vi> wowx,wowy;

    for (int i=0,x;i<n;i++) {
        cin>>x;
        if (x<0) {
            wowx[dna[-x]].pb(-x);
            hashx[x*x]++;
        } else if (x>0) {
            xpos.insert(x);
            hashx[x*x]++;
        } else {
            ans+=(n-1)*m;
        }
    }

    for (int i=0,y;i<m;i++) {
        cin>>y;
        if (y<0) {
            wowy[dna[-y]].pb(-y);
            hashy[y*y]++;
        } else if(y>0) {
            ypos.insert(y);
            hashy[y*y]++;
        } else {
            ans+=n*(m-1);
        }
    }

    for (int i : xpos) {
        for (int j : wowx[dna[i]]) {
            ans+=hashy[i*j];
        }
    }

    for (int i : ypos) {
        for (int j : wowy[dna[i]]) {
            ans+=hashx[i*j];
        }
    }

    cout<<ans<<"\n";
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