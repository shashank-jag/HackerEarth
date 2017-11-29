#include <stdio.h>
#include <vector>
#include <map>
#include <set>
#define ll long long
using namespace std;

map<int,ll> ans;
set<int> v[100010];
int val[100010];
set<int> done;

ll find_(int src){
    // printf("%d-->",src);
    if(done.find(src)!=done.end())return 0;
    if(ans.find(src)!=ans.end())return ans[src];
    int ret=val[src];
    done.insert(src);
    for(auto x:v[src]){
        ret+=find_(x);
    }
    ans[src]=ret;
    return ret;
}

int main(){
    int t;scanf("%d",&t);
    while(t--){
        ans.clear();done.clear();
        int n,m;scanf("%d%d",&n,&m);
        for(int i=0;i<=n;i++)v[i].clear();
        for(int i=0;i<m;i++){
            int x,y;scanf("%d%d",&x,&y);
            v[x].insert(y);
            v[y].insert(x);
        }
        for(int i=1;i<=n;i++)scanf("%d",&val[i]);
        ll ans_=0;
        for(int i=1;i<=n;i++){
            done.clear();
            ans_=max(ans_,find_(i));
        }
        printf("%lld\n",ans_);
    }
    return 0;
}