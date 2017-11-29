#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
#define all(x) (x).begin(),(x).end()
#define mod 1000000007
using namespace std;
int main(){
    ll n,ans=0,x;cin>>n;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++)cin>>a[i]>>b[i];
    sort(all(a));
    sort(all(b));
    for(int i=0;i<n;i++){
        x=(b[i]+a[i])*(2*i-(n-1));
        if(x>=mod)x%=mod;
        ans+=x;
        if(ans>=mod)ans%=mod;
    }
    cout<<ans;
    return 0;
}