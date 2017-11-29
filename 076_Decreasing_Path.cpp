#include <iostream>
#include <map>
#include <utility>
#include <algorithm>

#define pii pair<int,int> 
#define ff first
#define ss second
#define ll long long
#define mp make_pair
#define pb push_back
#define mod 1000000007
using namespace std;

map<pii,int> v;
map<pii,int> cst;
vector<pair<int,pii> > arr;
vector<pii> dir;

int n;

bool notValid(pii p,int val){
    if(p.ff<0 || p.ss<0 || p.ff>=n || p.ss>=n || v[p]>=val)return true;
    return false;
}

ll dfs(pii p,int val){
    if(notValid(p,val))return 0;
    if(cst[p])return cst[p];
    ll ret = 1;
    for(auto x:dir){
        ret += dfs(mp(p.ff+x.ff,p.ss+x.ss),v[p]);
    }
    cst[p] = (ret)%mod;
    return ret;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    dir.push_back(mp(0,1));
    dir.push_back(mp(1,0));
    dir.push_back(mp(-1,0));
    dir.push_back(mp(0,-1));
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            pii p=mp(i,j);
            int x;cin>>x;
            v[p]=x;
            arr.pb(mp(x,p));
        }
    }
    sort(arr.begin(),arr.end());
    ll ans = 0;
    for(auto x:arr){
        ans += dfs(x.ss,101);
        ans %= mod;
    }
    cout<<ans;
    return 0;
}