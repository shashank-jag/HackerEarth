#include <iostream>
#include <set>
#include <utility>
#include <vector>
#define pii pair<int,int> 
#define ff first
#define ss second
#define ll long long
using namespace std;
ll n,m,add;
ll a[510][510];
 
set<pii> done;
vector<pii> ans;
bool is_edge(pii p){
    if(p.ff==1 || p.ss==1 || p.ff==n || p.ss==m)return true;
    return false;
}
 
bool is_valid(pii p){
    if(p.ff>=1&&p.ss>=1 && p.ff<=n && p.ss<=m)return true;
    return false;
}
 
bool dfs(pii p){
    if(done.find(p)!=done.end())return false;
    done.insert(p);
    if(is_edge(p)){
        ans.push_back(p);
        return true;
    }
    pii x=p;
    x.ff--;
    if(a[x.ff][x.ss]<=a[p.ff][p.ss] && a[p.ff][p.ss]-a[x.ff][x.ss]<=add && dfs(x)){
        ans.push_back(p);
        return true;
    }
    x=p;
    x.ff++;
    if(a[x.ff][x.ss]<=a[p.ff][p.ss] && a[p.ff][p.ss]-a[x.ff][x.ss]<=add && dfs(x)){
        ans.push_back(p);
        return true;
    }
    x=p;
    x.ss--;
    if(a[x.ff][x.ss]<=a[p.ff][p.ss] && a[p.ff][p.ss]-a[x.ff][x.ss]<=add  && dfs(x)){
        ans.push_back(p);
        return true;
    }
    x=p;
    x.ss++;
    if(a[x.ff][x.ss]<=a[p.ff][p.ss] && a[p.ff][p.ss]-a[x.ff][x.ss]<=add  && dfs(x)){
        ans.push_back(p);
        return true;
    }
    return false;
}
 
 
int main(){
    ios_base::sync_with_stdio(false);
    int t=1;
    // cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++)cin>>a[i][j];
        }
        pii st;cin>>st.ff>>st.ss>>add;
        bool  ans_=dfs(st);
        if(ans_){
            cout<<"YES"<<endl;
            for(auto x=ans.rbegin();x!=ans.rend();x++){cout<<(*x).ff<<" "<<(*x).ss<<endl;cerr<<a[(*x).ff][(*x).ss]<<endl;}
        }
        else cout<<"NO"<<endl;
    }
    return 0;
}