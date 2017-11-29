#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>
using namespace std;
int ans=0;
map<int,int> mp;
vector<int> v[100010];
int in[100010];
set<int> d;

int ct(int a,int b){
    a=a&b;
    int ret=0;
    while(a>0){
        if(a&1)ret++;a=a>>1;
    }
    return ret;
}

int find_min(int a){
    int min=1<<30,ret=-1;
    for(auto x:d){
        if(ct(mp[x],mp[a])<min){
            min=ct(mp[x],mp[a]);ret=x;
        }
    }
    return ret;
}

set<int> path(int a,int fd){
    set<int> ret;
    if(a==fd){
        ret.insert(a);
        return ret;
    }
    for(auto x:v[a]){
        ret=path(x,fd);
        if(ret.find(fd)!=ret.end()){ret.insert(a);break;}
    }
    return ret;
}

void apply(int a,int fd,int flip){
    set<int> se=path(a,fd);
    for(auto x:se){
        mp[x]^=flip;
    }
    ans++;
}

int main(){
    int n,a;cin>>n>>a;
    for(int i=0,x,y;i<n-1;i++){
        cin>>x>>y;
        v[y].push_back(x);
        in[x]++;
    }
    for(int i=1;i<=n;i++){
        if(i!=a && in[i]==0)d.insert(i);
    }
    cout<<a<<endl;
    for(auto x:d)cout<<x;cout<<endl;
    while(!d.empty()){
        int i=find_min(a);
        cout<<i<<endl;
        d.erase(i);
        int x=mp[a]^mp[i];
        apply(a,i,x);
        for(auto x:v[i]){in[x]--;if((!in[x])&&mp[x])d.insert(x);}
    }
    cout<<ans;
    return 0;
}