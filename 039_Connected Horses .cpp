#include <iostream>
#include <vector>
#include <set>
#include <utility>
#define ff first
#define ss second
using namespace std;
set<set<pair<int,int> > >paths;
set<pair<int,int> > done;
set<pair<int,int> > is_pres;

void go(pair<int,int> p,set<pair<int,int> >&se){
    se.insert(p);
    int ct=0;
    // cout<<p.ff<<" "<<p.ss<<"******"<<endl;
    done.insert(p);
    if(is_pres.find(make_pair(p.ff-2,p.ss-1))!=is_pres.end()){
        pair<int,int> in=make_pair(p.ff-2,p.ss-1);
        if(done.find(in)==done.end()){
        se.insert(p);
        done.insert(in);
        go(in,se);ct++;}
    }
    if(is_pres.find(make_pair(p.ff-2,p.ss+1))!=is_pres.end()){
        pair<int,int> in=make_pair(p.ff-2,p.ss+1);
        if(done.find(in)==done.end()){
        se.insert(p);
        done.insert(in);
        go(in,se);ct++;}
    }
    if(is_pres.find(make_pair(p.ff-1,p.ss-2))!=is_pres.end()){
        pair<int,int> in=make_pair(p.ff-1,p.ss-2);
        if(done.find(in)==done.end()){
        se.insert(p);
        done.insert(in);
        go(in,se);ct++;}
    }
    if(is_pres.find(make_pair(p.ff+1,p.ss-2))!=is_pres.end()){
        pair<int,int> in=make_pair(p.ff+1,p.ss-2);
        if(done.find(in)==done.end()){
        se.insert(p);
        done.insert(in);
        go(in,se);ct++;}
    }
    if(is_pres.find(make_pair(p.ff+2,p.ss-1))!=is_pres.end()){
        pair<int,int> in=make_pair(p.ff+2,p.ss-1);
        if(done.find(in)==done.end()){
        se.insert(p);
        done.insert(in);
        go(in,se);ct++;}
    }
    if(is_pres.find(make_pair(p.ff+2,p.ss+1))!=is_pres.end()){
        pair<int,int> in=make_pair(p.ff+2,p.ss+1);
        if(done.find(in)==done.end()){
        se.insert(p);
        done.insert(in);
        go(in,se);ct++;}
    }
    if(is_pres.find(make_pair(p.ff-1,p.ss+2))!=is_pres.end()){
        pair<int,int> in=make_pair(p.ff-1,p.ss+2);
        if(done.find(in)==done.end()){
        se.insert(p);
        done.insert(in);
        go(in,se);ct++;}
    }
    if(is_pres.find(make_pair(p.ff+1,p.ss+2))!=is_pres.end()){
        pair<int,int> in=make_pair(p.ff+1,p.ss+2);
        if(done.find(in)==done.end()){
        se.insert(p);
        done.insert(in);
        go(in,se);ct++;}
    }
    // for(auto x:se)cout<<x.ff<<" "<<x.ss<<"_>";cout<<endl;
}

int main(){
    long long ans=1,mod=1000000007;
    vector<long long> fac(1,1);
    for(int i=1;i<=1010;i++)fac.push_back((fac.back()*i)%mod);
    int n,k,m,t;
    cin>>t;
    while(t--){
        paths.clear();is_pres.clear();done.clear();
        cin>>n>>k>>m;
        while(m--){
            int x,y;cin>>x>>y;
            is_pres.insert(make_pair(x,y));
        }
        ans=1;
        for(auto x:is_pres){
            if(done.find(x)!=done.end())continue;
            set<pair<int,int> > se;
            go(x,se);
            ans=(ans*fac[se.size()])%mod;
        }
        
        // for(auto x:paths)ans=(ans*x.size())%mod;
        cout<<ans<<endl;
    }
    return 0;
}