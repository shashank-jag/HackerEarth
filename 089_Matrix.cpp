#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <climits>

#define pii pair<ll,ll>
#define ff first
#define ss second

#define Mx 300000
#define ll long long

using namespace std;

vector<ll> tree;
vector<pii> pt;
    
ll getMax(ll a,ll b){if(a>b)return a;return b;}
ll getMid(ll a,ll b){return (a+b)/2;}

void build(ll pos,ll b,ll e){
    if(b>e)return;
    if(b==e){
        tree[pos]=pt[b].ss;
    }
    else {
        build(pos*2,b,getMid(b,e));
        build(pos*2+1,getMid(b,e)+1,e);
        tree[pos] = getMax(tree[pos*2],tree[pos*2+1]);
    }
}

ll _get(ll pos,ll b,ll e,ll qs,ll qe){
    // cout<<pos<<" pos"<<tree[pos]<<endl;
    // cout<<b<<" "<<e<<" "<<qs<<"-"<<qe<<endl;
    if(b>e || qs>e || qe<b)return INT_MIN;
    if(b>=qs&&e<=qe)return tree[pos];
    else return max( _get(pos*2,b,getMid(b,e),qs,qe) , _get(pos*2+1,getMid(b,e)+1,e,qs,qe) );
    
}

int main(){
    ll n,q;cin>>n>>q;
    pt.resize(n);
    tree.resize(n*4);
    for(auto &x:pt)cin>>x.ff>>x.ss;
    sort(pt.begin(),pt.end());
    // for(auto x:pt)cout<<x.ff<<" "<<x.ss<<"->";cout<<endl;
    build(1,0,n-1);
    while(q--){
        pii s,e;cin>>s.ff>>s.ss>>e.ff>>e.ss;
        if(s.ff>e.ff)swap(s,e);
        auto p1=lower_bound(pt.begin(),pt.end(),s) - pt.begin();
        auto p2=lower_bound(pt.begin(),pt.end(),e) - pt.begin();
        if(p2 == n || pt[p2].ff > e.ff)p2--;
        // cout<<p1<<" "<<p2<<endl;
        if(p2<p1 ||p1==n )cout<<(abs(s.ff-e.ff) + abs(s.ss-e.ss))<<endl;
        else {
            ll ma = _get(1,0,n-1,p1,p2);
            // cout<<ma<<" ma"<<endl;
            if(ma < s.ss || ma < e.ss)cout<<(abs(s.ff-e.ff) + abs(s.ss-e.ss))<<endl;
            else cout<<(abs(s.ff-e.ff) + abs(ma-s.ss) + abs(ma-e.ss) +2)<<endl;
        }
    }
    return 0;
}