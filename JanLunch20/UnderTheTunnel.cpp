//contest lo tle....asusual eppatlage....sarigga no thinking....gave up....contest aina next min ans vachindi...evado bfs+"dp" anagane.
// first probem question ardam kala...input sarigga arhtam cheskola.....second fi complicate chesa....well deserved -40

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
        bool flag=false;
        int k,n;
        cin>>n>>k;
        vector<string> boards(n);
        for(int i=0;i<n;i++)
        {
            cin>>boards[i];
        }
        for(int i=0;i<n;i++)
        {
            if(boards[i][i]=='0')
            {
                cout<<"-1\n";
                flag=true;
                break;
            }
        }
        if(flag) continue;
        
        queue<pair<int,int>> q;
        q.push(make_pair(0,0));
        vector<bool> dp(n,false);
        dp[0]=true;
        while(!q.empty())
        {
            pair<int,int> p=q.front();
            q.pop();
            if(dp[p.first]) continue;
            dp[p.first]=true;
            if(p.first==n-1)
            {
                cout<<p.second<<"\n";
                flag=true;
                break;
            }
            int a=p.first;
            for(int i=k;i>0;i--)
            {
                if(a+i<=n-1)
                {
                    if(boards[a][a+i]=='1') q.push(make_pair(a+i,p.second+1));
                }
            }
            for(int i=1;i<=k;i++)
            {
                if(a-i>=0)
                {
                    if(boards[a][a-i]=='1') q.push(make_pair(a-i,p.second+1));
                }
            }
        }
        if(!flag)
        {
            cout<<"-1\n";
        }
    }
    return 0;
}
