#include <iostream>
#include <vector>

using namespace std;
int a[1000010];
int val[1000010];
bool done[1000010];
int n;
int dfs(int i){
    if(done[i])return val[i];
    done[i]=true;
    val[i]=1+dfs(a[i]);
    return val[i];
}

int make(){
    int mi=-1,ind=0;int ret=0;
    for(int i=0,p;i<n;i++){if(val[i]==0)p=dfs(i);if(ret<val[i]){ret=val[i];ind=i;}}
    cout<<ind<<" "<<ret<<endl;
    cout<<79584<<" "<<val[79584]<<endl;
    return ind;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t;cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++){
            val[i]=0;done[i]=false;
            cin>>a[i];
        }
        cout<<make()<<endl;
    }
    return 0;
}