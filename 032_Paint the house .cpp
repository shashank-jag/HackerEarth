#include <iostream>
#include <vector>
#include <utility>
#define ff first
#define ss second
#include <queue>
#include <algorithm>
using namespace std;
struct cmp{
    bool operator()(const pair<int,int> &p1,const pair<int,int> &p2){
        if(p1.ff!=p2.ff)return p1.ff<p2.ff;
        return p1.ss>p2.ss; 
    }
};
bool cmp1(pair<int,int> p1,pair<int,int> p2){
    if(p1.ff!=p2.ff)return p1.ff>p2.ff;
    return p1.ss<p2.ss;
}
int main(){
    int n,d;cin>>n>>d;
    priority_queue<pair<int,int> ,vector<pair<int,int> > ,cmp>hi;
    vector<pair<int,pair<int,int> > > v(n);
    for(int i=0;i<n;i++){
        cin>>v[i].ff>>v[i].ss.ff>>v[i].ss.ss;
    }
    pair<int,int> p=make_pair(0,0);
    int ans=0;
    sort(v.begin(),v.end());
    for(int i=1,ptr=0;d>0;i++){
        if(v[ptr].ff==i){
            hi.push(v[ptr].ss);
            ptr++;
        }
        if(hi.size()==0)continue;
        if(cmp1(hi.top(),p)){
            p=hi.top();
            ans+=p.ff;
        }
        d-=p.ss;
        // cerr<<hi.top().ff<<" "<<hi.top().ss<<" "<<ans<<" "<<p.ff<<" "<<p.ss<<endl;
    }
    // while(!hi.empty()){cerr<<hi.top().ff<<" "<<hi.top().ss<<endl;hi.pop();}
    cout<<ans;
    return 0;
}