#include <iostream>
#include <vector>
#define mod 1000000007
using namespace std;
vector<long long> v(1000100,0);
vector<long long> temp(1000100,0);
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t,n;
    v[0]=v[2]=v[4]=v[5]=1;
    for(int i=6;i<=1000000;i++)v[i]+=(v[i-2]+v[i-5])%mod;
    cin>>t>>n;
    while(t--){
        int cur,k;cin>>cur>>k;
        if(k>cur){
            cout<<v[cur]<<endl;
            continue;
        }
        else if(k==cur){
            cout<<v[cur]+1<<endl;
            continue;
        }
        for(int i=0;i<k;i++)temp[i]=v[i];
        int i=k;
        while(i<=cur){temp[i]=(temp[i-k]+temp[i-2]+temp[i-5])%mod;i++;}
        // for(int i=0;i<=cur;i++)cout<<temp[i]<<" ";
        cout<<temp[cur]<<endl;
    }
    return 0;
}