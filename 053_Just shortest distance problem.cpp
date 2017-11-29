#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;

set<int> v[10010];

vector<int> dist(10010,-1);

void bfs(int strt){
    deque <int> d,d1;
    d.push_back(strt);
    while(!d.empty()){
        for(auto i:d){
            // cerr<<i<<"-";
            for(auto x:v[i]){
                // cerr<<x<<" ";
                if(dist[x]==-1 || dist[i]+1<dist[x]){
                    dist[x]=dist[i]+1;
                    d1.push_back(x);
                }
            }
            // cerr<<endl;
        }
        d=d1;d1.clear();
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    dist[1]=0;
    int n,m;cin>>n>>m;
    while(m--){
        int t,x,y;
        cin>>t;
        if(t==1){
            cin>>x;cout<<dist[x]<<endl;
        }
        else{
            cin>>x>>y;
            v[x].insert(y);
            if(dist[x]!=-1)bfs(x);
        }
    }
    return 0;
}