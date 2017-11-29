#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#define inf 1000000
using namespace std;

set<int> primeNo;
int n;
vector<int> v;
int dp[510][510]={inf};

void maker(){
    vector<int> sei(1000010,1);
    for(int i=2;i<1000010;i++){
        if(sei[i])for(int j=2;j*i<1000010;j++)sei[i*j]=0;
    }
    for(int i=2;i<n;i++)if(sei[i])primeNo.insert(i);
}

int mino(int ind){
    int ret=inf;
    for(int i=0;i<=n;i++)if(ret>dp[i][ind])ret=dp[i][ind];
    return ret;
}

int calc(int n1,int n2){
    auto x=lower_bound(primeNo.begin(),primeNo.end(),n2);
    int ret=(*x)-n2;x--;ret+=(*x)-n1;return ret;
}

int make(){
    for(int i=1;i<=n;i++){
        for(int p1=1,p2=i+1;p2<n;p1++,p2++){
            if(p1==p2+1)dp[p1][p2]=calc(v[p1],v[p2]);
            else{
                dp[p1][p2]=dp[p1+1][p2-1]+calc(v[p1],v[p2]);
            }
            dp[p1][p2]=min(dp[p1][p2],dp[p1-1][p2]);
            if(p1>1)dp[p1][p2]+=mino(p1-1);
        }
    }
    int mini=inf;for(int i=1;i<=n;i++)if(dp[i][n]<mini)mini=dp[i][n];
    return mini;
}

int main(){
    maker();
    cin>>n;v.resize(n+1);
    for(int i=1;i<=n;i++)cin>>v[i];
    cout<<make();
    return 0;
}