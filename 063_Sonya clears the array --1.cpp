#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <climits>
using namespace std;

long long inf = 1e9;
vector<int> primeNo;
int n;
vector<int> v;
long long dp[510][510]={inf};

void maker(){
    vector<int> sei(1010000,1);
    for(int i=2;i<1010000;i++){
        if(sei[i]){
            for(int j=2;j*i<1010000;j++)sei[i*j]=0;
        }
    }
   
    for(int i=2;i<1010000;i++){
        if(sei[i]==1){primeNo.push_back(i);}
    }

    for(int i=0;i<510;i++)
    for(int j=0;j<510;j++)dp[i][j]=inf;
}

int calc(int n1,int n2){
    auto x=lower_bound(primeNo.begin(),primeNo.end(),max(v[n2],v[n1]))-primeNo.begin();
    while(x==0 || primeNo[x-1]<v[n1] || primeNo[x]<v[n2]){x++;}
    int ret=(primeNo[x])-v[n2];x--;ret+=(primeNo[x])-v[n1];
    return ret;
}

int make(){
    dp[0][0]=0;
   for(int wind=2;wind<=n;wind+=2){
    for(int i=1,j=wind;j<=n;j++,i++){
        // cerr<<i<<"&&&"<<j<<endl;
        int add=calc(i,j);
        // cerr<<add<<"***"<<endl;
        if(wind!=2)add+=dp[i+1][j-1];
        // cerr<<add<<"***"<<endl;
        dp[i][j]=add+1;
    }
   }
   // for(auto x:v)cout<<x<<"*";cout<<endl;
   // for(int i=0;i<=n;i++){
   //  for(int j=0;j<=n;j++){
   //      cout<<dp[i][j]<<" ";
   //  }cout<<endl;
   // }
   for(int i=1;i<=n;i++){
    for(int j=0;j<=n;j++){
        dp[i][j]=min(dp[i-1][j],dp[i][i-1]+dp[i][j]);
        // cout<<dp[i][j]<<" ";
    }
    // cout<<endl;
   }
   return dp[n][n];
}

int main(){
    maker();
    cin>>n;v.resize(n+1);
    for(int i=1;i<=n;i++)cin>>v[i];
    cout<<make();
    return 0;
}