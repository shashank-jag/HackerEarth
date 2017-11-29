#include <iostream>
#include <vector>
using namespace std;
int n,m,k;
vector<vector<int> > inp(101,vector<int> (101));
int sum(vector<int> v){
    if(v[2]==5)cerr<<"here"<<endl;
    for(auto x:v)cerr<<x<<" ";
    int ans=0,pre=0,j=0,ret=-1;
    for(auto x:v)ans+=x;
    for(j=0;j<k&&j<m;j++)if(v[j]<0)pre+=v[j];
    for(int i=0;j<v.size();j++){
        if(j-i==k){
            ret=max(ret,ans-pre);
            if(v[i]<0)pre-=v[i];
            if(v[j]<0)pre+=v[j];
            i++;
        }
    }
    cerr<<"***"<<ret<<endl;
    ret=max(ret,ans-pre);
    return ret;
}

int dfs(int i,int j,vector<int> v){
    if(i<0 || i>=n || j<0 || j>=m ){
        cerr<<"*****"<<i<<" "<<j<<" "<<n<<m<<endl;
        return -1;
    }
    v.push_back(inp[i][j]);
    if(i==0){
        return sum(v);
    }
    return max(dfs(i-1,j-1,v),max(dfs(i-1,j,v),dfs(i-1,j+1,v)));
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t;cin>>t;
    while(t--){
        cin>>n>>m>>k;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>inp[i][j];
            }
        }
        vector<int> v;
        cout<<max(dfs(n-1,k-2,v),max(dfs(n-1,k-1,v),dfs(n-1,k,v)))<<endl;
        cerr<<"*************"<<endl;
    }
    return 0;
}