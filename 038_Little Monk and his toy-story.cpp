#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> v;
bool chk(int lvl){
    long long  prev=1,sum=0;
    prev=prev<<60;
    int i=0,j=0;
    for(i=lvl,j=0;i>=1;i--){
    	sum=0;
        for(int k=j;k<j+i;k++){
        	sum+=v[k];
        }
        if(prev<=sum)return false;
        prev=sum;
        j+=i;
    }
    return true;
}
int main(){
    int n,lvl=0;
    cin>>n;
    v.resize(n);for(int i=0;i<n;i++)cin>>v[i];
    sort(v.rbegin(),v.rend());
    for(int s=0;s<=n;lvl++){
    	s+=lvl;
    }
    lvl-=2;
	while((!chk(lvl))){
    	lvl--;
    }
    cout<<lvl;
    return 0;
}