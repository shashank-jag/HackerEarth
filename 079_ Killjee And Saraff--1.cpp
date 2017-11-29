#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;
vector<int> v[200010];
vector<int> depth(200010,0);
vector<int> cnt(200010,0);
vector<int> prime(200010,1);
int fa[20][200010];

void dfs(int node,int par){
	fa[0][node]=par;
	cnt[node]=cnt[par];
	depth[node]=depth[par]+1;
	if(prime[node])cnt[node]++;
	for(auto x:v[node]){
		if(x==par)continue;
		dfs(x,node);
	}
}

int lca(int a,int b){
	if(depth[a]<depth[b])swap(a,b);
	int diff = depth[a] - depth[b];
	for(int i=0;i<20;i++){
		if((diff>>i)&1)a=fa[i][a];
	}
	if(a==b)return a;
	for(int i=19;i>=0;i--){
		if(fa[i][a]!=fa[i][b]){
			a=fa[i][a];
			b=fa[i][b];
		}
	}
	return fa[0][a];
}

int main(){
	int n,q;
	prime[0]=0;prime[1]=0;
	for(int i=2;i<200010;i++){
		if(prime[i])for(int j=2*i;j<200010;j+=i)prime[j]=0;
	}
	// cin>>n;
	scanf("%d",&n);
	for(int i=0;i<n-1;i++){
		int x,y;
		// cin>>x>>y;
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1,0);
	for(int i=1;i<20;i++){
		for(int j=1;j<=n;j++){
			if(fa[i-1][j])fa[i][j]=fa[i-1][fa[i-1][j]];
		}
	}
	// cin>>q;
	scanf("%d",&q);
	while(q--){
		int x,y;
		// cin>>x>>y;
		scanf("%d%d",&x,&y);
		int z=lca(x,y);
		// cout<<(cnt[x] + cnt[y] - cnt[z] - cnt [fa[0][z]])<<endl;
		printf("%d\n",(cnt[x] + cnt[y] - cnt[z] - cnt [fa[0][z]]));
	}
	return 0;
}