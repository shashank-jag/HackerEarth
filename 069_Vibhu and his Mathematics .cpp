#include <iostream>
#include <vector>
#define mod 1000000007
using namespace std;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int n,maxo=1000010;
    vector<long long > v;
    v.push_back(0);v.push_back(1);v.push_back(2);
    while(v.size()<maxo){
        v.push_back((v.back()+v[v.size()-2]*(v.size()-1))%mod);
        // cout<<v.back()<<" ";
    }
    cin>>n;
    while(n--){
        int i;cin>>i;cout<<v[i]<<endl;
    }
    return 0;
}