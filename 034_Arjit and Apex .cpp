#include <iostream>
#include <set>
#include <algorithm>
#include <utility>
#include <map>
#include <vector>
#define ff first
#define ss second
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
    int n,m;cin>>n>>m;
    vector<pair<int,int> > v1(n),v2(m);
    map<int,int> ct1,ct2;
    for(int i=0;i<n;i++){
        cin>>v1[i].ff>>v1[i].ss;
        ct1[v1[i].ff]++;
    }
    for(int i=0;i<m;i++){
        cin>>v2[i].ff>>v2[i].ss;
        ct2[v2[i].ff]++;
    }
    set<pair<int,int> > se;
    for(auto x:v1)se.insert(x);
    for(auto x:v2)se.insert(x);
    int pref=v1.size()+v2.size()-se.size(),ok=0;
    for(auto x:ct1){
        ok+=min(x.second,ct2[x.first]);
    }
    int g,h;cin>>g>>h;
    if(g<=ok&&h<=pref)cout<<"Great";
    else if(g<=ok)cout<<"Good";
    else cout<<":(";
    cout<<endl;
    // cerr<<pref<<" "<<ok<<endl;
    }
    return 0;
}