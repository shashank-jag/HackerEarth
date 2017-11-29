#include <iostream>
#include <vector>
#define ll long long
using namespace std;
int main(){
	int t;cin>>t;
	while(t--){
		ll n,ans=0,x;cin>>n;
		vector<int> v,d;
		for(int i=0;i<n;i++){
			cin>>x;
			v.push_back(x);
		}
		while(v.size()>1){
			for(int i=0;i<n;){
				if(d.empty())d.push_back(v[i]);
				else if(d.back()<v[i]){
					ans+=v[i];
					d.pop_back();
					d.push_back(v[i]);
				}
				else{
					if(i+1<n){
						if(v[i+1]<d.back()){ans+=v[i+1];}
						else ans+=d.back();
					}
					else ans+=d.back();
				}
				i++;
			}
			v=d;d.clear();
		}
		cout<<ans<<endl;
	}
	return 0;
}