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
    for(int j=0;j<510;j++)dp[i][j]=0;
}

int calc(int n1,int n2){
    auto x=lower_bound(primeNo.begin(),primeNo.end(),max(v[n2],v[n1]))-primeNo.begin();
    while(x==0 || primeNo[x-1]<v[n1] || primeNo[x]<v[n2]){x++;}
    int ret=(primeNo[x])-v[n2];x--;ret+=(primeNo[x])-v[n1];
    return ret;
}

int make(){
    dp[0][0]=0;
   // int n,i,l,st,ed;

  //  for(l=2;l<=n;l+=2) {
  //   for(ed=l-1;ed<n;ed++) {
  //     st=ed - l + 1;
  //     // cout<<"subarray: "<<st<<' '<<ed<<": ";
  //     dp[st][ed]=1e9;
  //     for(i=ed-1;i>=st;i-=2) {
  //       // cout<<"cost of "<<a[i]<<", "<<a[ed]<<"="<<cost(a[i],a[ed])<<'\n';
  //       dp[st][ed] = min(dp[st][ed],dp[i+1][ed-1] + calc(i+1,ed+1) + dp[st][i-1]);
  //       // dbg(dp[st][ed]);
  //     }
  //     // cout<<dp[st][ed]<<endl;
  //   }
  // }
    
    for(int wind=2;wind<=n;wind+=2){
      for(int r=wind;r<=n;r++){
        int l=r-wind+1;
        dp[l][r]=inf;
        // cerr<<l<<" "<<r<<" ";
        for(int k=l;k<=r-1;k+=2){
          dp[l][r]=min(dp[l][r],dp[k+1][r-1] + calc(k,r) + 1 + dp[l][k-1]);
          // cerr<<l<<"-"<<k<<"-"<<r<<" "<<dp[l][k]<<"*"<<dp[k+1][r]<<endl;
        }
        // cerr<<dp[l][r]<<"*"<<endl;;
      }
      // cerr<<"-*-"<<endl;
    }

   // for(auto x:v)cout<<x<<"*";cout<<endl;
   // for(int i=0;i<=n;i++){
   //  for(int j=0;j<=n;j++){
   //      cout<<dp[i][j]<<" ";
   //  }cout<<endl;
   // }
   // for(int i=0;i<=n;i++){
   //  for(int j=0;j<=n;j++){
   //      // dp[i][j]=min(dp[i-1][j],dp[i][j]);
   //      cout<<dp[i][j]<<" ";
   //  }
   //  cout<<endl;
   // }
   return dp[1][n];
}

int main(){
    maker();
    cin>>n;v.resize(n+1);
    for(int i=1;i<=n;i++)cin>>v[i];
    cout<<make();
    return 0;
}