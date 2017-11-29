#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>

#define ff first
#define ss second
#define pii pair<int,int> 
#define piv pair<int,vector<int> > 
using namespace std;

map<pii,int> gc;
map<piv,int> dp;
vector<pii> rnk;

bool cmp(pii p1,pii p2){
    return gc[p1]<gc[p2];
}
vector<int> done;

int getG(int i,int tot){
    if(i>=rnk.size()||tot==2)return 0;
    if(dp[{i,done}])return dp[{i,done}];
    int ret1 = getG(i+1,tot);
    // cerr<<"Level "<<i<<" done->";for(auto x:done)cerr<<x<<" ";cerr<<" ret1 "<<ret1<<endl;
    if(done[rnk[i].ff]==0 || done[rnk[i].ss]==0)return ret1;
    done[rnk[i].ff]--;done[rnk[i].ss]--;
    int ret2 = getG(i+1,tot-2) + gc[rnk[i]] ;
    done[rnk[i].ff]++;done[rnk[i].ss]++;
    // cerr<<"Level "<<i<<" done->";for(auto x:done)cerr<<x<<" ";cerr<<" ret2 "<<ret2<<endl;
    dp[{i,done}]=max(ret1,ret2);
    return max(ret1,ret2);
}

int main(){
    int n;cin>>n;vector<int> v(n);
    for(auto &x:v)cin>>x;
    // cerr<<"***"<<endl;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            gc[{i,j}]=__gcd(v[i],v[j]);
            rnk.push_back({i,j});
        }
    }
    cout<<"****"<<endl;
    sort(rnk.begin(),rnk.end());
    // for(auto x:rnk)cout<<x.ff<<" "<<x.ss<<"->"<<gc[x]<<endl;
    // vector <int> vec(n,2);
    done.resize(n,2);
    cout<<getG(0,n*2)<<endl;
    return 0;
}