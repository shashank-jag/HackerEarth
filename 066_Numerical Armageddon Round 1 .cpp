#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        string s;cin>>s;
        map<int,map<int,int> >v;
        for(int i=0;i<s.size();i++){
            int val=s[i]-'0';
            v[i][val%6]++;
            for(int j=0;j<i;j++){
                for(int k=0;k<7;k++){
                    v[i][((val+s[j]-'0')+6)%6]+=v[j][k];
                }
            }
            if(val%2==0)for(int k=0;k<7;k++)if(k%3==3-val%3){v[i][0]+=v[i][k];cerr<<"*"<<i<<k;cerr<<endl;}
            for(int k=0;k<7;k++)cerr<<v[i][k]<<" ";cerr<<endl;
        }
        long long ans=0;
        for(int i=0;i<s.size();i++)ans+=v[i][0];
        cout<<ans<<endl;
    }
    return 0;
}