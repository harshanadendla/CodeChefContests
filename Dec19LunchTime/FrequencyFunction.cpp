#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,count=0;
		vector<int> a(n),b(n);
		multiset<int> newB;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			if(a[i]==-1) count++;
			else b[a[i]]++;
		}
		int x;
		for(int i=0;i<n;i++)
		{
			cin>>x;
			while(x--) newB.insert(i);
		}
		if( accumulate(newB.begin(),newB.end(),0) > n )
		{
			cout<<"impossible\n";
			continue;
		}
		vector<int> ans;
		int k=0;
		for(int i=0;i<n;i++)
		{
			auto idx=newB.lower_bound(b[i]);
			if(idx==newB.end())
			{
				cout<<"continue\n";
				goto here;
			}
			int dif=*idx-b[i];
			while(dif) ans.push_back(i);
			newB.erase(idx);
		}
		if(ans.size()!=n)
		{
			cout<<"impossible\n";
			continue;
		}
		for(int i=0;i<n;i++)
		{
			if(a[i]==-1) a[i]=ans[k++];
		}
		for(int i : z) cout<<z<<" ";
		cout<<"\n";
	}
	return 0;
}
