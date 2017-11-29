#include <iostream>
#define inf 1000000
using namespace std;
int total[210][100010];
int amt[210];
int a,n;
int chk(){
    for(int i=0;i<=a;i++)total[0][i]=inf;
    for(int i=0;i<=n;i++)total[i][0]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=a;j++){
            total[i][j]=total[i-1][j];
            if(j>=amt[i])total[i][j]=min(total[i][j],total[i][j-amt[i]]+1);
        }
    }
    return total[n][a];
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    while(t--){
        // cout<<t<<" ";
        cin>>a>>n;
        for(int i=1;i<=n;i++)cin>>amt[i];
        int ct=chk();
        if(ct<inf)cout<<ct<<endl;
        else cout<<"No solution"<<endl;
    }
    return 0;
}