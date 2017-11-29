#include <iostream>
#define ll unsigned long long 
#define mod 1000000007
using namespace std;
int ct[150],temp[150];
int inp[100010];

void make(int no){
    for(int i=0;i<=150;i++)temp[i]=0;
    for(int i=0;i<=150;i++){
        if(ct[i]){
            temp[i^no]+=ct[i];
        }
    }
    for(int i=0;i<=150;i++)ct[i]=(temp[i]+ct[i])%mod;
    ct[no]=(ct[no]+1)%mod;
    // for(int i=0;i<=100;i++)cout<<ct[i]<<" ";cout<<endl;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    for(int i=0;i<=150;i++)ct[i]=0;
    for(int i=0;i<n;i++)cin>>inp[i];
    for(int i=0;i<n;i++)make(inp[i]);
    ll ans=0;
    for(int i=0;i<=100;i++){
        ll ways=ct[i];
        ll w=(ct[i]-1+mod)%mod;
        ways=(w*ways)%mod;
        ways=(ways*500000004)%mod;
        ans+=ways;
        if(ans>=mod)ans%=mod;
    }
    cout<<ans;
    return 0;
}