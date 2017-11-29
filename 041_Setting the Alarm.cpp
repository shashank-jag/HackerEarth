#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <string>
using namespace std;
struct x{
    int hh,mm;
    bool l;
};

bool operator<(const x &a, const x &b)
{
    if(a.hh!=b.hh)return a.hh < b.hh;
    if(a.mm!=b.mm)return a.mm<b.mm;
    return a.l>b.l;
}
set<struct x > done;
deque<struct x> d,d1;

struct x make(string s,string t){
    struct x ret;
    ret.hh=((s[0]-'0')*10+(s[1]-'0'));
    ret.mm=((s[3]-'0')*10+(s[4]-'0'));
    if(t[0]=='a')ret.l=true;
    else ret.l=false;
    return ret;
}

void inc_hr(struct x &a,struct x &a1){
    a1=a;
    if(a1.hh==11)a1.l^=true;a1.hh++;a1.hh%=12;if(a1.hh==0)a1.hh=12;
}
void dec_hr(struct x &a,struct x &a1){
    a1=a;
    if(a1.hh==12)a1.l^=true;a1.hh+=11;a1.hh%=12;if(a1.hh==0)a1.hh=12;
}

void inc_mm(struct x &a,struct x &a1){
    a1=a;
    if(a1.mm==59){a1.mm=0;inc_hr(a1,a1);}
    else a1.mm+=1;
}
void dec_mm(struct x &a,struct x &a1){
    a1=a;
    if(a1.mm==0){a1.mm=59;dec_hr(a1,a1);}
    else a1.mm-=1;
}

void ch_l(struct x &a,struct x &a1){
    a1=a;a1.l^=true;
}


int bfs(struct x s,struct x end){
    done.clear();d.clear();d1.clear();
    int ti=0;
    d.push_back(s);
    done.insert(s);
    //cerr<<s.hh<<s.mm<<s.l<<endl;
    //cerr<<end.hh<<end.mm<<end.l<<endl;
    //cerr<<"***============***"<<endl;
    while(done.find(end)==done.end()){
        // //cerr<<ti<<endl;
        //cerr<<"***"<<endl;
        ti++;
        for(auto &a:d){
            struct x a1;
            inc_hr(a,a1);
            //cerr<<a1.hh<<a1.mm<<a1.l<<endl;
            if(done.find(a1)==done.end()){
            d1.push_back(a1);
            done.insert(a1);}
            dec_hr(a,a1);
            //cerr<<a1.hh<<a1.mm<<a1.l<<endl;
            if(done.find(a1)==done.end()){
            d1.push_back(a1);
            done.insert(a1);}
            
            inc_mm(a,a1);
            //cerr<<a1.hh<<a1.mm<<a1.l<<endl;
            if(done.find(a1)==done.end()){
            d1.push_back(a1);
            done.insert(a1);}
            dec_mm(a,a1);
            //cerr<<a1.hh<<a1.mm<<a1.l<<endl;
            if(done.find(a1)==done.end()){
            d1.push_back(a1);
            done.insert(a1);}
            
            ch_l(a,a1);
            //cerr<<a1.hh<<a1.mm<<a1.l<<endl;
            if(done.find(a1)==done.end()){
            d1.push_back(a1);
            done.insert(a1);}
            //cerr<<"++++"<<endl;
            if(done.find(end)!=done.end())break;
        }
        d=d1;d1.clear();
    }
    return ti;
}


int main(){
    int t;cin>>t;
    while(t--){
        string s,t;cin>>s>>t;
        struct x st=make(s,t);
        cin>>s>>t;
        struct x end=make(s,t);
        cout<<bfs(st,end)<<endl;
    }
    return 0;
}