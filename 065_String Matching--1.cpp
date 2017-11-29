#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> d(10,0);
vector<int> ct(10,0);

vector<int> l,r;

bool chk(){
    for(int i=0;i<10;i++){
        if(ct[i]<d[i])return false;//{cout<<i<<endl;return false;}
        // else cout<<i<<ct[i]<<" "<<d[i]<<endl;;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    string s;cin>>s;
    int n;cin>>n;

    while(n--){
        int x;cin>>x;d[x]++;
    }
    int i=0,j=0;
    while(j<s.size()){
        while(j<s.size()&&(!chk())){
            ct[s[j]-'0']++;
            j++;
        }
        // break;
        if(chk()){
            while(i<s.size()&&chk()){
                ct[s[i]-'0']--;
                i++;
            }
            // cout<<i<<"*"<<j<<endl;
            l.push_back(i-1);//-1-((l.size()>0)?(l.back()+1):0));
            r.push_back(s.size()-j);
        // for(auto x:l)cout<<x<<"-";cout<<endl;
        // for(auto x:r)cout<<x<<"-";cout<<endl;
        }
    }
    int ans=0;
    for(int i=l.size()-1;i>0;i--)l[i]=l[i]-l[i-1]-1;
    // for(auto x:l)cout<<x<<"-";cout<<endl;
    // for(auto x:r)cout<<x<<"-";cout<<endl;
    for(int i=0;i<l.size();i++){
        int mi,ma;ma=max(l[i],r[i]);mi=min(l[i],r[i]);
        if(mi==0)ans+=ma+1;
        else ans+= (mi+1)*ma;
        // cout<<ans<<" ";
    }
    //l[i]*r[i]+l[i]+r[i];
    cout<<ans;
    return 0;
}