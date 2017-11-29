#include <iostream>
#define ll unsigned long long 
#define mod 1000000007
#define mx 256
using namespace std;
ll ct[mx],temp[mx];
int inp[100010];

void make(int no){
    for(int i=0;i<mx;i++)temp[i]=0;
    for(int i=0;i<mx;i++){
        if(ct[i]){
            temp[i^no]+=1;
        }
    }
    for(int i=0;i<mx;i++)ct[i]=temp[i]+ct[i];
    ct[no]++;
    // for(int i=0;i<=120;i++)cout<<ct[i]<<" ";cout<<endl;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;

    for(int i=0;i<mx;i++)ct[i]=-1;
    for(int i=0;i<n;i++)cin>>inp[i];
    for(int i=0;i<n;i++)make(inp[i]);
    ll ans1=0;
    for(int i=0;i<mx;i++){
        cerr<<ct[i]<<" ";
        if(ct[i]<1)continue;
        ct[i]--;
        ans1+=((1<<(ct[i]-1))%mod)*(((1<<ct[i])-1)%mod);
        if(ans1>mod)ans1%=mod;
        cerr<<ans1<<" "<<endl;
    }
    cout<<endl<<ans1;
    return 0;
}