#include <iostream>
#include <stdio.h>
#include <set>
#define ll long long
using namespace std;
ll ans[10000];
set<ll>se;
int sum(int i){
    int ret=0;while(i){
        ret+=i%10;i/=10;
    }
    return ret;
}

int fd(ll i){
    int x=sum(i);
    if(x<10000 && ans[x]!=0)return ans[x];
    if(x<10000){
        ans[x]=-1;
        ans[x]=fd(x*x);
        return ans[x];
    }
    else if(se.find(x)!=se.end())return -1;
    else se.insert(x);
    return fd(x*x);
}

void make(){
    ans[1]=1;ans[4]=1;
    for(int i=1;i<10000;i++){
        if(ans[i]==1)continue;
        if(ans[i]==-1)continue;
        ans[i]=fd(i*i);
    }
}

int main(){
    ll n;cin>>n;
    make();
    while(n--){
        ll x;scanf("%lld",&x);
        if(x==1 || x==4 || fd(x*x)==1)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}