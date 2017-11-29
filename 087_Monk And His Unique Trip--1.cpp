#include <iostream>
#include <vector>
#include <stack>
#include <utility>

#define mx 200010
#define ff first
#define ss second
#define pii pair<int,int>

using namespace std;

vector<int> g[mx];
vector<int> rg[mx];
vector<int> gc[mx];

stack<int> S;
vector<int> vis(mx,0);
vector<int> compo(mx,0);
vector<int> dist(mx,0);
vector<pii> edges;



void dfs1(int node){
	// cerr<<node<<" "<<vis[node]<<endl;
	if(vis[node])return;
	vis[node]=true;
	for(auto x:g[node])
		dfs1(x);
	S.push(node);
}

void dfs2(int node,int cur){
	// cerr<<node<<" "<<cur<<" "<<vis[node]<<endl;
	if(vis[node])return;
	vis[node]=true;
	compo[node]=cur;
	for(auto x:rg[node])
		dfs2(x,cur);
}

void dfs3(int node){
	if(vis[node])return;
	vis[node]=true;
	for(auto x:gc[node])
		dfs3(x);
	S.push(node);
}

int main(){
	int n,m;cin>>n>>m;
	for(int i=0;i<m;i++){
		int x,y;cin>>x>>y;
		// cerr<<x<<"*"<<y<<endl;
		g[x].push_back(y);
		rg[y].push_back(x);

		edges.push_back(make_pair(x,y));
	}
	// cerr<<"**..pumg pung thist"<<endl;
	// vis.clear();vis.resize(n+1,0);
	for(int i=1;i<=n;i++){
		if(!vis[i])dfs1(i);
	}
	// cerr<<"**..pumg pung thist"<<endl;
	// vis.clear();vis.resize(n+1,0);
	// compo.clear();compo.resize(n+1,0);
	for(int i=0;i<=n;i++)vis[i]=0,compo[i]=0;
	int com=0,ans=0;

	while(S.size()){
		if(!vis[S.top()])dfs2(S.top(),++com);
		else S.pop();
	}

	// for(auto x:compo)cerr<<x<<" ";
	// cerr<<"**..pumg pung thist"<<endl;

	for(auto pa:edges){
		if(compo[pa.ff] != compo[pa.ss]){
			gc[compo[pa.ff]].push_back(compo[pa.ss]);
		}
	}
	++com;
	// cerr<<"**..pumg pung thist"<<endl;
	// vis.clear();vis.resize(com+1,0);
	// dist.clear();dist.resize(com+1,0);
	for(int i=0;i<=com;i++)vis[i]=0,dist[i]=0;

	for(int i=1;i<=com;i++){
		if(!vis[i])dfs3(i);
	}
	// cerr<<"**..pumg pung thist"<<endl;
	while(S.size()){
		int u = S.top();
		S.pop();
		for(auto v:gc[u]){
			dist[v] = max(dist[v],dist[u]+1);
		}
	}
	// cerr<<"**..pumg pung thist"<<endl;
	for(int i=1;i<=com;i++){
		if(ans<dist[i])ans=dist[i];
	}
	cout<<ans;
	return 0;
}