Ada stacked three bricks on top of each other. Initially, their widths (from top to bottom) are W1,W2,W3.

Ada's strength is S. Whenever she hits a stack of bricks, consider the largest k≥0 such that the sum of widths of the topmost k bricks does not exceed S; the topmost k bricks break and are removed from the stack. Before each hit, Ada may also decide to reverse the current stack of bricks, with no cost.

Find the minimum number of hits Ada needs in order to break all bricks if she performs the reversals optimally. You are not required to minimise the number of reversals.

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
        int s,w1,w2,w3;
        cin>>s>>w1>>w2>>w3;
        int sum=w1+w2+w3;
        if(s==1 || (s==2 && (sum>=5 || (sum==4 && w2==2))) || (s==3 && sum==6))
        {
            cout<<"3\n";
        }
        else if(sum<=s) 
        {
            cout<<"1\n";
        }
        else
        {
            cout<<"2\n";
        }
    }
    return 0;
}
