#include <iostream>
#include <map>
#include <string>
#define ll long long
#define mod 1000000007
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        string s;cin>>s;
        map<int,ll> v,t;
        ll ans=0;
        for(int i=0;i<s.size();i++){
            // for(int i=0;i<6;i++)cerr<<v[i]<<" ";cerr<<endl;
            int val=s[i]-'0';
            v[val%6]++;
            // for(int i=0;i<6;i++)cerr<<v[i]<<" ";cerr<<endl;
            if(val%2==0)for(int k=0;k<6;k++)if(k%3==(3-val%3)%3)ans=(ans+v[k])%mod;
            v[val%6]--;
            for(int i=0;i<6;i++)t[(i+val)%6]=(v[i]+v[(i+val)%6])%mod;
            // for(int i=0;i<6;i++)cerr<<t[i]<<" ";cerr<<endl;
            v=t;
            v[val%6]++;
            // cerr<<"******"<<ans<<endl;
        }
        cout<<ans<<endl;
    }
    return 0;
}