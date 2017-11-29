#include <iostream>
using namespace std;
bool v[110][100010];
int no[110];
int n,x;

void make(){
    for(int i=0;i<=x;i++)v[0][i]=false;
    for(int i=0;i<=n;i++)v[i][0]=true;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=x;j++){
            v[i][j]=v[i-1][j];
            if(no[i]<=j)v[i][j] |= v[i-1][j-no[i]];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=x;j++){cout<<v[i][j]<<" ";}
        cout<<endl;}
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    while(t--){
        int sum=0,i;
        cin>>n>>x;for(int i=1;i<=n;i++){cin>>no[i];sum+=no[i];}
        if(sum<=x){
            cout<<"YES"<<endl;continue;
        }
        else if(sum<x/2){
            cout<<"NO"<<endl;continue;
        }
        make();
        bool fl=false;
        for(i=x;i>0;i--){
            if(v[n][i]){cout<<"YES"<<endl;fl=true;cout<<i;}
        }
        cout<<fl<<sum<<" "<<i<<endl;
        if(fl)continue;
        cout<<"NO"<<endl;
    }
    return 0;
}