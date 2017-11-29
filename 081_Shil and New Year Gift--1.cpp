#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int main(){
	int n,ans;
	vector<vector<int> > dp;
	vector<int> in;
	cin>>n;
	in.resize(n);
	dp.resize((1<<n),vector<int> (n,0));
	for(int i=0;i<n;i++)
		cin>>in[i];
	for(int mask=0;mask<(1<<n);mask++){
		for(int ind=0 ;ind<n;ind++){
			if(!(mask&(1<<ind)))continue;
			for(int ind2=0;ind2<n;ind2++){
				if(!(mask&(1<<ind2)))continue;
				if(ind==ind2)continue;
				dp[mask][ind] = max( dp[mask][ind] , dp[mask ^(1<<ind)][ind2] + __gcd(in[ind],in[ind2]));
			}
		}
	}
	ans=0;
	for(int i=0;i<n;i++)
		ans = max( ans , dp[(1<<n)-1][i]);
	cout<<ans;
	return 0;
}