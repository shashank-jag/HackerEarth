#include <iostream>
#include <vector>

using namespace std;

vector<int> v[200010];
vector<int> a(200010,1);
vector<int> depth(200010,0);
vector<int> cnt(200010,0);
int fa[20][200010];


void dfs(int cur,int par){
    fa[0][cur] = par;
    cnt[cur]=cnt[par];
    depth[cur]=depth[par]+1;
    if(a[cur])cnt[cur]++;
    for(auto x:v[cur]){
        if(x==par)continue;
        dfs(x,cur);
    }
}

int lca(int u,int v){
    if(depth[u]<depth[v])swap(u,v);
    int diff = depth[u]-depth[v];
    for(int i=0;i<20;i++){
        if((diff>>i) &1)u=fa[i][u];
    }
    if(u==v)return u;
    for(int i=19;i>=0;i--){
        if(fa[i][u]!=fa[i][v]){
            u=fa[i][u];
            v=fa[i][v];
        }
    }
    return fa[0][u];
}

int main(){
    int n,q,m,cur,hi=200000;
    a[0]=0;a[1]=0;
    for(int i=2;i<=200000;i++){
        if(a[i])for(int j=2;i*j<200000;j++)a[i*j]=0;
    }
    cin>>n;
    int x,y;
    for(int i=0;i<n-1;i++){
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1,0);
    for(int j=1;j<20;j++){
        for(int i=1;i<=n;i++){
            if(fa[j-1][i])fa[j][i]=fa[j-1][fa[j-1][i]];
        }
    }
    cin>>q;
    while(q--){
        cin>>x>>y;
        int z = lca(x,y);
        cerr<<z<<"**"<<endl;
        cout<<(cnt[x]+cnt[y]-cnt[z]-cnt[fa[0][z]])<<endl;
    }
    return 0;
}