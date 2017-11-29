#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#define mi INT_MIN
#define ll long long
using namespace std;
vector<ll> v(550);
vector<ll> m(550);
int n;

bool m_give(int i){
    if(i>=n)return false;
    return true;
}

void make(int src){
    if(src>=n)return ;
    make((src+1)*2-1);make((src+1)*2);
    if(m_give((src+1)*2-1)&&m_give((src+1)*2))m[src]=v[src]+max(m[(src+1)*2-1],m[(src+1)*2]);
    else if(m_give((src+1)*2-1))m[src]=v[src]+v[(src+1)*2-1];
    else if(m_give((src+1)*2))m[src]=v[src]+v[(src+1)*2];
    else m[src]=v[src];
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t;cin>>t;
    while(t--){
        cin>>n;
        int i=0;
        for(int i=0;i<n;i++)cin>>v[i];
        make(0);
        ll ans=((m_give((i+1)*2-1))?m[(i+1)*2-1]:0)+((m_give((i+1)*2))?m[((i+1)*2)]:0)+v[i];
        // for(auto x:m)cout<<x<<" ";cout<<endl;
        for(i=0;i<n;i++)ans=max(ans,((m_give((i+1)*2-1))?m[(i+1)*2-1]:0)+((m_give((i+1)*2))?m[((i+1)*2)]:0)+v[i]);
        cout<<ans<<endl;
    }
    return 0;
}