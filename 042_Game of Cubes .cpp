#include <iostream>
#include <vector>
#include <string>
using namespace std;

string v[110],rep;
int r,c;
set<pair<int,int> > se;

bool is_valid(int i,int j){
    if(i>=0 && i<r && j>=0 && j<c)return true;
    return false;
}

int calc(int i,int j){
    if(!is_valid(i,j))return 0;
    if(v[i][j]=='.')return 0;
    return 1+calc(i-1,j)+calc(i+1,j)+calc(i,j-1)+calc(i,j+1);
}

int dfs(){
    se.clear();
    int i,j;
    for(i=0;i<110;i++){
        for(j=0;j<v[i].size();j++)if(v[i][j]=='x')break;
        if(j<v[i].size())break;
    }
    return calc(i,j);
}

void bal(int k){
    for(;k>0;k--)v[k]=v[k-1];
    v[0]=rep;
}

int main(){
    cin>>r>>c;
    for(int i=0;i<r;i++)cin>>v[i];
    for(int i=0;i<c;i++)rep+='.';
    int q;cin>>q;
    for(int i=0,x;i<n;i++){
        cin>>x;x=r-x+1;
        if(i%2==0){
               int k;
               for(k=0;k<v[x].size();k++)if(v[i][k]=='x')break;
               if(k==v[x].size())bal(x);
               else v[x][k]='.';
        }
        else{
            int k;
            for(k=v.size()-1;k>=0;k--)if(v[i][k]=='x')break;
            if(k==-1)bal(x);
            else v[x][k]='.';
        }
    }
    for(int i=0;i<r;i++)cout<<v[i]<<endl;
    return 0;
}