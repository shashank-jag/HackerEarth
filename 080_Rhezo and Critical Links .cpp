#include <iostream>
#include <vector>
using namespace std;
int n,m,k;
vector<int> v[100010];
int CC[100010];
int sz[100010];
int trav[100010];
int cc,timer,ans;
int low[100010],disc[100010];
void dfs(int node){
	if(trav[node])return;
	trav[node]++;
	CC[cc]++;
	for(auto x:v[node])dfs(x);
}
void dfs2(int s,int par=-1){
	sz[s]=1;
	timer++;
	low[s]=disc[s]=timer;
	trav[s]++;
	for(auto to:v[s]){
		if(to==par)continue;
		if(!trav[to]){
			dfs2(to,s);
			low[s]=min(low[s],low[to]);
			sz[s]+=sz[to];
			if(low[to]>disc[s] and abs(sz[to]-(CC[cc]-sz[to]))<k) ans++;
		}
		else{
			low[s]=min(low[s],disc[to]);
		}
	}

}
int main(){
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		int x,y;cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	memset(trav,0,sizeof(trav));
	memset(trav,0,sizeof(CC));
	cc=0;
	for(int i=1;i<=n;i++){
		if(!trav[i])cc++,dfs(i);
	}
	memset(trav,0,sizeof(trav));
	memset(trav,0,sizeof(sz));
	cc=0,timer=0,ans=0;
	for(int i=1;i<=n;i++){
		if(!trav[i])cc++,dfs2(i);
	}
	cout<<ans<<endl;
	return 0;
}