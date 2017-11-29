#include <iostream>
#include <set>
#include <vector>
using namespace std;

set<int> v[100010];
int in[100010];
set<int> trav;
int n,m,t;
void bfs(){
    vector<int> d,d1;
    for(int i=1;i<=n;i++)if(in[i]==0){d.push_back(i);trav.insert(i);}
    while(!d.empty()){
        // for(auto x:d)cout<<x<<" ";cout<<endl;
        for(auto i:d){
            for(auto x:v[i]){
                // if(trav.find(x)!=trav.end())continue;
                in[x]--;
                if(in[x]==0){d1.push_back(x);trav.insert(x);}
            }
        }
        d=d1;d1.clear();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin>>t;
    while(t--){
        cin>>n>>m;
        // cout<<"*****************"<<endl;
        // cout<<n<<" "<<m<<endl;
        for(int i=1;i<=n;i++){in[i]=0;v[i].clear();}
        for(int i=0,x,y;i<m;i++){
            cin>>x>>y;
            in[y]++;
            v[x].insert(y);
        }
        bfs();
        // cout<<trav.size()<<endl;
        // for(auto x:trav)cout<<x<<" ";
        if(trav.size()==n)cout<<1<<endl;else cout<<0<<endl;
        trav.clear();
    }
    return 0;
}