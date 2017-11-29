#include<iostream>
#include <algorithm>
#include <climits>
using namespace std;
int dp[550][550];
int inp[550];
int n;
void make(){
    for(int i=0;i<n;i++)for(int j=0;j<n;j++){if(i==j)dp[i][j]=1;else dp[i][j]=INT_MAX;}
    for(int win=1;win<n;win++){
        // cout<<win<<endl;
        for(int i=0;i+win<n;i++){
            if(inp[i]==inp[i+win] && win>1)dp[i][i+win]=dp[i+1][i+win-1];
            else if(inp[i]==inp[i+win] && win==1)dp[i][i+win]=0;
            else {
                for(int k=i;k<i+win;k++){
                    dp[i][i+win]=min(dp[i][i+win],dp[i][k]+dp[k+1][i+win]);
                }
            }
        }
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++)cout<<dp[i][j]<<" ";
    //     cout<<endl;
    // }
}
int main(){
    cin>>n;for(int i=0;i<n;i++)cin>>inp[i];
    make();
    cout<<dp[0][n-1];
    return 0;
}