#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int make(deque<int> &v){
	cerr<<"Enter ****************"<<endl;
	deque<int> d;
	d.push_back(v[0]);
	int i=1,ans=0;
	while(1){
		if(v.size()==1){
			return ans+v[0];
		}
		int n=v.size();
		for(;i<n-1;i++){
			if(v[i]>=d.back()){
				ans+=v[i];
				d.pop_back();
				d.push_back(v[i]);
			}
			else{
				if(max(d.back(),v[i+1])==d.back()){
					ans+=v[i+1];
					d.push_back(v[i+1]);
					i+=1;
				}
			}
			for(auto x:d)cerr<<x<<" ";cerr<<endl;cerr<<ans<<endl;
		}
		while((!d.empty())&&d.back()<=v[n-1]){
			d.pop_back();ans+=v[n-1];
		}
		if(d.empty())d.push_back(v[n-1]);
		else ans+=d.back();
		v=d;
		d.clear();
		d.push_back(v[0]);
	}
	return -1;
}
int main(){
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		deque<int>v(n);
		for(int i=0;i<n;i++)cin>>v[i];
		cout<<make(v)<<endl;
	}
	return 0;
}