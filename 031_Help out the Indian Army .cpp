#include <iostream>
#include <queue>
#include <algorithm>
#define ff first
#define ss second
#define ll long long
using namespace std;
int main(){
	ll n,s,e,x,y;cin>>n>>s>>e;
	deque<pair<ll,ll> > v(n);
	for(int i=0;i<n;i++){
		cin>>x>>y;
		v[i].ff=x-y;v[i].ss=x+y;
	}
	sort(v.begin(),v.end());
	ll ans=0,ma=s;
	for(auto x:v){
		if(ma<x.ff)ans+=x.ff-ma;
		ma=max(ma,x.ss);
		if(ma>=e)break;
	}
	if(ma<e)ans+=e-ma;
	cout<<ans;
	return 0;
}