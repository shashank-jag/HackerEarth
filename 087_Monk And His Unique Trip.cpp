#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>

using namespace std;

int n,m,timer=0;
vector<int> gr[100010];
vector<int> strt(100010,-1);
vector<int> en(100010,-1);
vector<int> trav(100010,0);

map<int,int> mp;
int ctr,mai;

vector<int> par(100010);

int _find(int i){
    if(par[i]==i)return i;
    return par[i]=_find(par[i]);
}

void _union(int a,int b){
    if(a==-1 || b==-1)return;
    int x=_find(a),y=_find(b);
    if(x==y)return ;
    par[x]=y;
    _find(a);
}

void dfs(int node,int par){
    // cout<<node<<"n "<<par<<"p "<<endl;
    timer++;
    strt[node]=timer;
    int ret = -1;
    for(auto x:gr[node]){
        // if(x==par)continue;
        if(strt[x]==-1)dfs(x,node);
        if(en[x]>strt[node]);
        else {
            _union(x,node);
            // cout<<x<<"<+>"<<node<<endl;
            // strt[node]=strt[x];
            en[node]=strt[x];
            // cout<<en[node]<<" "<<strt[x]<<endl;
        }
    }
    timer++;
    if(en[node]==-1)en[node]=timer;
    // cout<<node<<" "<<en[node]<<"_"<<endl;
    return ;
}

void dfs2(int node,int p,vector<int> &trav,set<int> &se){
    if(trav[node])return;
    se.insert(par[node]);
    trav[node]=1;
    for(auto x:gr[node]){
        dfs2(x,node,trav,se);
    }
}



int make(int node,int pr=-1){
    // cout<<node<<".";
    trav[node]=1;
    int pres = 0;
    if(mp[par[node]]==0)pres++;
    mp[par[node]]++;
    int mx=0,sm=0;
    for(auto x:gr[node]){
        if(x==pr || trav[x])continue;
        int r = make(x);
        if(x>mx)mx=x;
        else if(x>sm)sm=x;
    }
    mai = max(mai,pres+mx+sm);
    cout<<node<<" p"<<par[node]<<" pr"<<pres<<" m"<<mx<<" s"<<sm<<" mai"<<mai<<endl;
    return pres+mx;
}


int main(){
    cin>>n>>m;
    for(int i=0;i<=n;i++)par[i]=i;
    while(m--){
        int x,y;cin>>x>>y;
        gr[x].push_back(y);//gr[y].push_back(x);
    }
    for(int i=1;i<=n;i++)if(strt[i]==-1)dfs(i,-1);
    for(int i=1;i<=n;i++){
        par[i]=_find(i);
        // cerr<<i<<" "<<par[i]<<"p "<<strt[i]<<"s "<<en[i]<<"e ->"<<endl;;
    }
    // cout<<endl;
    // set<int> se;for(int i=1;i<=n;i++)se.insert(par[i]);
    // cout<<(se.size()-1)<<endl;
    // vector<int >trav(n+1,0);
    int ans=0;
    for(int i=1;i<=n;i++){
        if(!trav[i]){
            // se.clear();
            // dfs2(i,-1,trav,se);
            // ans=max(ans,(int)se.size()-1);
            mp.clear();
            ctr=0,mai=0;
            mai = min(mai , make(i));
            ans = min(mai,ans);
        }
    }
    cout<<ans<<endl;
    return 0;
}