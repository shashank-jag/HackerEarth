#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int pow_(int no,int p){
    int ret=1;
    while(p){
        if(p&1)ret*=no;
        p/=2;
        no*=no;
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int num,x;cin>>num;x=num;
    vector<int> in,pre,nxt;
    while(num){
        in.emplace_back(num%10);
        num/=10;
    }
    reverse(in.begin(),in.end());
    for(auto &x:in){
        pre.emplace_back(((pre.size())?pre.back():0)*10 + x);
    }
    // for(auto x:in)cout<<x<<" ";cout<<endl;
    // for(auto x:pre)cout<<x<<" ";cout<<endl;
    int ans=0;
    for(int i=0;i<(int)in.size();i++){
        if(i+1!=(int)in.size() && in[i+1]==0)continue;
        int l=pre[i];
        int r=x%pow_(10,in.size()-1-i);
        if(l==0 || r==0)continue;
        if(l==r){
            ans++;
            continue;
        }
        // if((l/10)%r==0)ans++;
        // else if((r/10)%l==0)ans++;
        if(l>r){
            //case 1:
            int a=l,b=r;
            while(a>b)a/=10;
            if(a==b)ans++;
        }
        else {
            //case 2:
            int a=r,b=l;
            while(a>b)a/=10;
            if(a==b)ans++;
        }
    }
    cout<<ans;
    return 0;
}