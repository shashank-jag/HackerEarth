#include <iostream>
#include <queue>
#include <utility>
#include <map>
#include <string>
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
using namespace std;

deque<pii> dq,dq1;
pii s,e;
map<pii,int> turns;
deque<pii> dir;
string v[1010];
int n,m;

bool notValid(pii p){
    if(p.ff<0 ||p.ss<0 || p.ff>=n || p.ss>=m)return true;
    if(v[p.ff][p.ss]!='.'&&v[p.ff][p.ss]!='H')return true;
    return false;
}

pii add(pii a,pii b){
    a.ff+=b.ff,a.ss+=b.ss;return a;
}

void disp(){
    for(int i=0;i<n;i++){
    for(int j=0;j<m;j++)cout<<turns[make_pair(i,j)]<<" ";cout<<endl;}
}

void dfs(){
    dq.pb(s);
    while(dq.size()){
        for(auto x:dq){
            for(auto x:dq)cout<<x.ff<<" "<<x.ss<<"*";cout<<endl;
                disp();
            cout<<"****************"<<endl;
            pii temp_x=x;
            // if(x==e)continue;
            for(auto d:dir){
                while((!notValid(add(d,x)))&&(turns[add(d,x)]==0 || turns[add(d,x)]>=turns[temp_x]+1)){
                    x=add(d,x);dq1.pb(x);turns[x]=turns[temp_x]+1;
                    // if(x==e)break;
                }
                x=temp_x;
            }
        }
        dq=dq1;dq1.clear();
    }
}


int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;for(int i=0;i<n;i++)cin>>v[i];
    s.ff=-4,s.ss=-4,e.ff=-4,e.ss=-4;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j]=='V')s.ff=i,s.ss=j;
            if(v[i][j]=='H')e.ff=i,e.ss=j;
        }
    }
    dir.pb(mp(0,1));
    dir.pb(mp(1,0));
    dir.pb(mp(-1,0));
    dir.pb(mp(0,-1));
    dfs();
    cout<<turns[e]-1<<endl;
    disp();
    return 0;
}