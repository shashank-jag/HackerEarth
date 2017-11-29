#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

vector<int> p1;
vector<int> p2;
map<string,int> ind;

int _find(int i,vector<int> &v){
    if(i==v[i])return v[i];
    return v[i]=_find(v[i],v);
}

void _union(int i,int j,vector<int> &v){
    int a=_find(i,v),b=_find(j,v);
    if(a==b)return;
    v[a]=b;
    _find(i,v);
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m,q;cin>>n>>m>>q;
    for(int i=0;i<n;i++){
        string s;cin>>s;
        ind[s]=i;
        p1.push_back(i);
        p2.push_back(i);
    }
    for(int i=0;i<m;i++){
        int ch;string s1,s2;
        cin>>ch>>s1>>s2;cerr<< s1<<" "<<s2<<" ";
        if(ch==1){
            bool on,tw;
            on=(_find(ind[s1],p1)==_find(ind[s2],p1));
            tw=(_find(ind[s1],p2)==_find(ind[s2],p2));
            if(!on && tw)cout<<"NO"<<endl;
            else {
                cout<<"YES"<<endl;
                _union(ind[s1],ind[s2],p1);
                _union(ind[s1],ind[s2],p2);
            }
        }
        else {
            bool on,tw;
            on=(_find(ind[s1],p1)==_find(ind[s2],p1));
            tw=(_find(ind[s1],p2)==_find(ind[s2],p2));
            if((!tw) || (!on) ){
                cout<<"YES"<<endl;
                _union(ind[s1],ind[s2],p2);
            }
            else {
                cout<<"NO"<<endl;
            }
        }
    }
    for(int i=0;i<q;i++){
        string s1,s2;cin>>s1>>s2;cerr<< s1<<" "<<s2<<" ";
        bool on,tw;cerr<<"\t!";
        cerr<<(_find(ind[s1],p1))<<" "<<(_find(ind[s2],p1))<<"!";
        cerr<<(_find(ind[s1],p2))<<" "<<(_find(ind[s2],p2))<<"!";
        on=(_find(ind[s1],p1)==_find(ind[s2],p1));
        tw=(_find(ind[s1],p2)==_find(ind[s2],p2));
        cerr<<"\t";
        if(on)cout<<1<<endl;
        else if((!on) && tw && (_find(ind[s1],p2) == (_find(ind[s1],p1))  || _find(ind[s1],p2) == _find(ind[s2],p1)  ))cout<<2<<endl;
        else cout<<3<<endl;
    }
    return 0;
}