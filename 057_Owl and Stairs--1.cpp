#include <iostream>
#include <climits>
using namespace std;
int inp[110][110];
int dp[110][110];
int vis[110][110];
int n,m,k;

bool is_valid(int i,int j){
    if(i<0 || j<0 || i>=n || j>=m || vis[i][j]==0)return false;
    return true;
}

int make(int lev){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            dp[i][j]=inp[i][j];
            if(i>=lev && i<lev+m && dp[i][j]<0)dp[i][j]=0;
        }
    }
    if(dp[0][k-1]>=0)vis[0][k-1]=1;
    if(k-2>=0 && dp[0][k-2]>=0)vis[0][k-2]=1;
    if(k<m && dp[0][k]>=0)vis[0][k]=1;
    // for(int in=0;in<n;in++){
    //    for(int j=0;j<m;j++)cout<<vis[in][j];
    //     cout<<endl;
    // }
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            int val=dp[i][j];dp[i][j]=INT_MIN;
            bool fl=false;
            if(is_valid(i-1,j-1)){
                dp[i][j]=max(dp[i][j],dp[i-1][j-1]+val);
                fl=true;
            }
            if(is_valid(i-1,j)){
                dp[i][j]=max(dp[i][j],dp[i-1][j]+val);
                fl=true;
            }
            if(is_valid(i-1,j+1)){
                dp[i][j]=max(dp[i][j],dp[i-1][j+1]+val);
                fl=true;
            }
            // if(i==2&&j==2)cout<<is_valid(i-1,j+1)<<is_valid(i-1,j)<<is_valid(i-1,j-1)<<"*******"<<n<<m<<endl;
            if(dp[i][j]<0)vis[i][j]=0;
            else if(fl) vis[i][j]=1;
        }
    }
    // cout<<lev<<endl;
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<dp[i][j]<<" "<<vis[i][j]<<"*";
    //     }
    //     cout<<endl;
    // }
    // cout<<"*********"<<endl;
    int ret=INT_MIN;
    for(int i=0;i<m;i++)if(vis[n-1][i])ret=max(ret,dp[n-1][i]);
    return ret;
}

int main(){
    int t;cin>>t;
    while(t--){
        cin>>n>>m>>k;
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<m;j++)cin>>inp[i][j];
        }
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            for(int in=0;in<n;in++)for(int j=0;j<m;j++)vis[in][j]=0;
            ans=max(ans,make(i));
        }
        if(ans==INT_MIN)cout<<-1<<endl;
        else cout<<ans<<endl;
    }
    return 0;
}