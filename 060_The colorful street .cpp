#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> in(3);
        vector<int> pres(3,0);
        while(n--){
            cin>>in[0]>>in[1]>>in[2];
            for(int i=0;i<3;i++)in[i]+=min(pres[(i+1)%3],pres[(i+2)%3]);
            pres=in;
        }
        for(int i=1;i<3;i++)if(pres[i]>pres[i-1])pres[i]=pres[i-1];
        cout<<pres[2]<<endl;
    }
    return 0;
}