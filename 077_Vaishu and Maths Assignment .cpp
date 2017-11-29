#include <iostream>
#include <vector>
using namespace std;
int mx = 10100;
bool dp[110][10100]={0};
vector<int> vals;
int l,n,x,y;

bool get(int i,int j){
    if(i>n || j>=mx || i<0 ||j<0)return false;
    return dp[i][j];
}

void make(){
    dp[0][l]=true;
    for(int i=1;i<=n;i++){
        for(int j=x ; j<=y ;j++){
            if( get(i-1,j-vals[i]) || get(i-1,j+vals[i]))dp[i][j]=true;
        }
    }
    
}
int main(){
    vals.push_back(0);
    cin>>l>>n>>x>>y;
    for(int i=0;i<n;i++){
        int x;cin>>x;vals.push_back(x);
    }
    make();
    int t;cin>>t;
    while(t--){
    char qt;int q;
    cin>>qt>>q;
    // cout<<" "<<qt<<" "<<q<<endl;
    int ct=0;
    if(qt=='<'){
        for(int i=x;i<min(y+1,q);i++)if(dp[n][i])ct++;
    }
    else {
        for(int i=max(q+1,0);i<=y;i++)if(dp[n][i])ct++;
    }
    if(ct)cout<<"YES";
    else cout<<"NO";cout<<endl;
    }
    return 0;
}