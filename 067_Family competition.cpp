#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define pii pair<int,int>
#define mp make_pair
#define ff first
#define ss second
using namespace std;
int dist(int a,int b){
	return abs(a-b);
}
int sign(int a){
	return (a<0);
}
int main(){
	int n,k;cin>>n>>k;
	vector<pii> v(n);
	for(auto &x:v)cin>>x.ff>>x.ss;
	sort(v.begin(),v.end());
	vector<int>ans(n,0);
	// for(auto &x:v)cerr<<x.ff<<" ";cerr<<endl;
	// for(auto &x:v)cerr<<x.ss<<" ";cerr<<endl;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(dist(v[i].ss,v[j].ss)<=k && v[i].ff<v[j].ff && sign(v[i].ss)!=sign(v[j].ss) )ans[j]=max(ans[i]+1,ans[j]);
		}
		// for(auto x:ans){cerr<<x<<" ";}cerr<<endl;
	}
	int maxo=0;for(auto x:ans){if(x>maxo)maxo=x;}
	cout<<maxo;
	return 0;
}