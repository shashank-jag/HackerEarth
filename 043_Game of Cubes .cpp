#include <set>
#include <string>
#include <iostream>
#include <utility>
#include <string>
#include <algorithm>
#define ff first
#define ss second
#define pii pair<int,int>
using namespace std;

set<pii> done,pres,nw,d2;
int r,c;
pii lowest;
bool is_val(pair<int,int> p){
    if(p.ff<0 || p.ff>=r || p.ss<0 || p.ss>=c)return false;
    return true;
}

void dfs(pii p){
    // cout<<p.ff<<p.ss<<endl;
    // for(auto x:done)cout<<x.ff<<x.ss<<"->"<<endl;
    if(!is_val(p)){
        // cout<<"not valid"<<p.ff<<p.ss<<endl;
        return ;}
    if(done.find(p)!=done.end()){
        // cout<<"done"<<p.ff<<p.ss<<endl;
        return ;}
    if(pres.find(p)==pres.end()){
        // cout<<"not present"<<p.ff<<p.ss<<endl;
        return ;}
    // cout<<"___"<<endl;
    done.insert(p);
    pii x=p;
    x.ff--;
    dfs(x);
    x=p;
    x.ff++;
    dfs(x);
    x=p;
    x.ss--;
    dfs(x);
    x=p;
    x.ss++;
    dfs(x);
}

void low(pii p){
    if(!is_val(p)){
        // cout<<"not valid"<<p.ff<<p.ss<<endl;
    return ;}
    if(d2.find(p)!=d2.end()){
        // cout<<"done"<<p.ff<<p.ss<<endl;
    return ;}
    if(nw.find(p)==nw.end())return;
    d2.insert(p);
    pii x=p;
    x.ff--;
    dfs(x);
    x=p;
    x.ff++;
    dfs(x);
    x=p;
    x.ss--;
    dfs(x);
    x=p;
    x.ss++;
    dfs(x);
    lowest=min(lowest,p);
}

void make(pii p,set<pii> &s){
    if(!is_val(p)){
        // cout<<"not valid"<<p.ff<<p.ss<<endl;
    return ;}
    if(s.find(p)!=s.end()){
        // cout<<"done"<<p.ff<<p.ss<<endl;
    return ;}
    if(nw.find(p)==nw.end())return;
    s.insert(p);
    pii x=p;
    x.ff--;
    dfs(x);
    x=p;
    x.ff++;
    dfs(x);
    x=p;
    x.ss--;
    dfs(x);
    x=p;
    x.ss++;
    dfs(x);
}

pii get_closest(pii lo){
    for(int i=lo.ff;i>=0;i--){
        if(done.find(make_pair(i,lo.ss))!=done.end())return make_pair(i,lo.ss);
    }
    return make_pair(0,lo.ss);
}
void print(){
    for(int i=r-1;i>=0;i--){
        for(int j=0;j<c;j++){
            if(pres.find(make_pair(i,j))!=pres.end())cout<<"x";
            else cout<<'.';
        }
        cout<<endl;
}}
void print(pii p){
    cout<<p.ff<<p.ss<<endl;
}
void fall(){
    d2.clear();
    lowest=*(nw.begin());low(lowest);
    print(lowest);
    set<pii> r;
    make(lowest,r);
    pii h=get_closest(lowest);
    print(h);
    int diff=lowest.ff-h.ff;
    for(auto x:r){x.ff-=diff;done.insert(x);nw.erase(x);}
    print();
    if(nw.size()>0)fall();
}


int main(){
    // ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    string s;
    cin>>r>>c;
    for(int i=r-1;i>=0;i--){
        cin>>s;
        for(int j=0;j<c;j++){
            if(s[j]=='x')pres.insert(make_pair(i,j));
        }
    }
    // for(auto x:pres)cout<<x.ff<<" "<<x.ss<<endl;
    int q;cin>>q;
    for(int i=1;i<=q;i++){
        int x;cin>>x;x--;
        // cout<<x<<endl;
        if(i%2){
            for(int i=0;i<c;i++)if(pres.find(make_pair(x,i))!=pres.end()){
                pres.erase(make_pair(x,i));
                break;
            }
        }
        else {
            for(int i=c-1;i>=0;i--)if(pres.find(make_pair(x,i))!=pres.end()){
                pres.erase(make_pair(x,i));
                break;
            }
        }
        // for(auto x:pres)cout<<x.ff<<" "<<x.ss<<endl;
        // cout<<"___"<<endl;
        
        for(int i=0;i<c;i++){
            if(pres.find(make_pair(0,i))!=pres.end()){
                dfs(make_pair(0,i));
            }
        }
        
        while(done!=pres){
            nw.clear();
            for(auto x:pres){
                if(done.find(x)!=done.end())nw.insert(x);
                else{
                    nw.insert(x);
                }
            }
         print();
            fall();
            pres=nw;done.clear();
            for(int i=0;i<c;i++){
                if(pres.find(make_pair(0,i))!=pres.end()){
                    dfs(make_pair(0,i));
                }
            }
        }
    print();
    }
    return 0;
}