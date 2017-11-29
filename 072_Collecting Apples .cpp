#include <iostream>
#include <cstring>
#define ll long long
using namespace std;

int mil[1005],app[1005];
int dp[1005][1005];
int n;

int f(int ind,ll energy){
	if(energy>n)energy=n;
	if(ind == n)return 0;
	if(dp[ind][energy]!=-1)return dp[ind][energy];
	int res=0;
	if(energy > 0){
		res = f(ind+1,energy-1) + app[ind];
		res=max(res,f(ind+1,energy-1+mil[ind]));
	}
	else if(mil[ind]!=0){
		res = f(ind+1,energy-1+mil[ind]);
		res = max(res,app[ind]);
	}
	else {
		res = app[ind];
	}
	return dp[ind][energy]=res;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	int t;cin>>t;
	while(t--){
		memset(dp,-1,sizeof(dp));
		ll en;
		cin>>n>>en;
		for(int i=0;i<n;i++)cin>>mil[i];
		for(int i=0;i<n;i++)cin>>app[i];
		cout<<f(0,en-1)<<endl;
	}
	return 0;
}