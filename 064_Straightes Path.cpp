#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <utility>
#define pii pair<int,int>
#define ff first
#define ss second
#define mp_ make_pair
#define pb push_back
using namespace std;
string v[1010];
map<pii,int> mp;
vector<pii> d;
int n,m;
pii s,e;

bool is_valid(pii p){
    if(p.ff<0||p.ss<0||p.ff>=n||p.ss>=m)return false;  
    if(v[p.ff][p.ss]=='*')return false;
    return true;
}
pii add(pii a,pii b){
    a.ff+=b.ff;a.ss+=b.ss;return a;
}
bool eq(pii a,pii b){
    return (a.ff==b.ff && a.ss==b.ss);
}
void dfs(pii p,int tur,pii dir){
    if(mp[p]!= 0 &&  mp[p]<tur || mp[e]!=0 && mp[e]<tur)return ;
    if(!is_valid(p))return;
    // cout<<p.ff<<" "<<p.ss<<" "<<tur<<" "<<mp[p]<<endl;
    mp[p]=tur;
    if(p==e)return;
    for(auto x:d)dfs(add(p,x),tur+(eq(x,dir)?0:1),x);
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>v[i];
    d.push_back(mp_(0,1));
    d.pb(mp_(1,0));
    d.pb(mp_(-1,0));
    d.pb(mp_(0,-1));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j]=='V')s.ff=i,s.ss=j;
            if(v[i][j]=='H')e.ff=i,e.ss=j;
        }
    }
    for(auto x:d)dfs(s,0,x);
    if(mp[e])cout<<mp[e];else cout<<-1;
    // for(int i=0;i<n;i++){
    // for(int j=0;j<m;j++)cout<<mp[make_pair(i,j)]<<" ";cout<<endl;}
    return 0;
}