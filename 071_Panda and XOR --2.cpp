#include <iostream>
#define ll unsigned long long 
#define mod 1000000007
#define MOD 1000000007
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
    ct[no]++;
    // for(int i=0;i<=100;i++)cout<<ct[i]<<" ";cout<<endl;
}
 
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    for(int i=0;i<=150;i++)ct[i]=0;
    for(int i=0;i<n;i++)cin>>inp[i];
    for(int i=0;i<n;i++)make(inp[i]);
    ll ans1=0,ans=0;
    for(int i=0;i<=150;i++){
        // ans=((ct[i]*((ct[i]-1+mod)%mod))%mod)*500000004;
        // ans%=mod;
        // ans1+=ans;
        // if(ans1>mod)ans1%=mod;
        // cout<<ct[i]<<" "<<ans<<" "<<ans1<<endl;
        ll cnt = ct[i];
        ll ways = (cnt-1+MOD)%MOD;
        ways = (ways*cnt)%MOD;
        ways = (ways*500000004)%MOD;
        ans += ways;
        if(ans >= MOD)
            ans -= MOD;
        cout<<ans<<" "<<ct[i]<<" "<<ways<<endl;
    }
    cout<<ans;
    return 0;
}
