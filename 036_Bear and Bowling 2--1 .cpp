#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#define ff first
#define ss second
using namespace std;
vector<int> p,p_val;
vector<int>no,done;
vector<int> ans;
int find(int x){
	if(p[x]==x)return x;
	p[x]=find(p[x]);
	return p[x];
}
void union_(int s,int x){
	if(p[x]!=x){
		p[x]=find(p[x]);
	}
	if(p[s]!=s){
		p[s]=find(p[s]);
	}
	p_val[p[x]]+=p_val[p[s]];
	p[p[s]]=p[x];
}
int main(){
	int n;cin>>n;
	ans.resize(n);
	for(int i=0,x;i<n;i++){
		p.push_back(i);
		p_val.push_back(1);
		done.push_back(0);
		cin>>x;no.push_back(make_pair(x,i));
	}
	ans.resize(n);
	sort(no.begin(),no.end());
	for(auto x:no){
		if(x.ss+1<n &&done[x.ss+1]==1)
			union_(x.ss,x.ss+1);
		if(x.ss-1>=0 &&done[x.ss-1==1])
			union_(x.ss,x.ss+1);
		ans[p_val[p[x.ss]]]=1;
	}
	for(auto x:ans)cout<<x;
	return 0;
}