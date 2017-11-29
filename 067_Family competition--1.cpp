#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#define pii pair<int,int>
#define mp make_pair
#define ff first
#define ss second
using namespace std;
int dist(int a,int b){
	return abs(a-b);
}
int dist_min(int a,int b){
	return (abs(a)-abs(b));
}
bool sign(int a){
	return (a<0);
}
bool way(pii p1,pii p2){
	if(abs(p1.ff)!=abs(p2.ff))return abs(p1.ff)<abs(p2.ff);
	return p1.ss<p2.ss;
}
int main(){
	int n,k;cin>>n>>k;
	vector<pii> v(n);
	vector<int> ans(n,0);
	for(auto &x:v)cin>>x.ss>>x.ff;
	sort(v.begin(),v.end(),way);
	for(int i=0;i<n;i++){
		for(int j=i-1;j>=0 && dist_min(v[i].ff,v[j].ff)<=k;j--){
			cerr<<i<<" "<<j<<endl;
			if(sign(v[j].ff)!=sign(v[i].ff) && v[i].ss>v[j].ss)ans[i]=max(ans[i],ans[j]+1);
			cerr<<(sign(v[j].ff)!=sign(v[i].ff) && v[i].ss>v[j].ss)<<" "<<sign(v[j].ff)<<sign(v[i].ff) <<"*"<< v[i].ss<<v[j].ss<<endl;
		}
		int maxo=0;for(auto x:ans){if(x>maxo)maxo=x;cerr<<x<<" ";}cerr<<endl;
	}
	for(auto &x:v)cerr<<x.ff<<" ";cerr<<endl;
	for(auto &x:v)cerr<<x.ss<<" ";cerr<<endl;
	
	int maxo=0;for(auto x:ans){if(x>maxo)maxo=x;cerr<<x<<" ";}
	cout<<maxo;
	return 0;
}