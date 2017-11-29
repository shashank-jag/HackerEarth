#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(){
	int n,ans=0,ct=0;string s;
	cin>>n>>s;
	vector<int> v;
	for(auto x:s){
		if(x=='('){
			if(v.empty()||v.back()==1)v.push_back(1);
			else {
				ans+=v.size();
				v.pop_back();
			}
		}
		else {
			if(v.empty()||v.back()==-1)v.push_back(-1);
			else if(v.back()==1)v.pop_back();
		}
		for(auto a:v)cerr<<a<<" ";cerr<<endl;
			cerr<<ans<<"********"<<endl;
	}
	cout<<ans;
	return 0;
}