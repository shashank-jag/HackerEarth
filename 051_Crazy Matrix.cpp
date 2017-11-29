#include <iostream>
#include <vector>
using namespace std;
vector<int> v[110];
int n;
bool valid(int i,int j){
    if(i>=0 && i<n && j>=0 && j<n)return true;
    return false;
}

bool dfs_1(int i,int j){
    if((!valid(i,j)))return false;
    if(v[i][j]!=1)return false;
    v[i][j]=0;
    if(i==n-1)return true;
    return dfs_1(i+1,j-1) | dfs_1(i+1,j) | dfs_1(i+1,j+1) | dfs_1(i,j+1) | dfs_1(i,j-1)|dfs_1(i-1,j-1)|dfs_1(i-1,j)|dfs_1(i-1,j+1);
}

bool chk_1(){
    int i=0;
    for(i=0;i<n;i++)if(v[0][i]==1&&dfs_1(0,i))return true;
    return false;
}

bool dfs_2(int i,int j){
    if((!valid(i,j)))return false;
    if(v[i][j]!=2)return false;
    v[i][j]=0;
    if(j==n-1)return true;
    return dfs_2(i+1,j-1) | dfs_2(i+1,j) | dfs_2(i+1,j+1) | dfs_2(i,j+1) | dfs_2(i,j-1)|dfs_2(i-1,j-1)|dfs_2(i-1,j)|dfs_2(i-1,j+1);
}

bool chk_2(){
    int i=0;
    for(i=0;i<n;i++)if(v[i][0]==2&&dfs_2(i,0))return true;;
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0,x;j<n;j++){
            cin>>x;v[i].push_back(x);
        }
    }
    bool o=chk_1(),t=chk_2();
    if(o&&t)cout<<"AMBIGUOUS";
    else if(o)cout<<1;
    else if(t)cout<<2;
    else cout<<0;
    return 0;
}