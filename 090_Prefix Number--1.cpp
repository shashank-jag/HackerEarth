#include <iostream>
#include <string>
#include <vector>

using namespace std;

int conv(string s){
    int ret=0;
    for(char c:s)ret=ret*10+(c-'0');
    return ret;
}

int pow_(int no,int p){
    int ret=1;
    while(p){
        if(p&1)ret*=no;
        p/=2;
        no*=no;
    }
    return ret;
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	string s;cin>>s;
	if(s[0]=='0')return cout<<0,0;
	int len=s.size();
	int nums[2];nums[0]=conv(s);nums[1]=0;
	int ans=0;
	for(int i=0;i<len;i++){
		int l=nums[0]/10;
		int r=(nums[0]%10)*pow_(10,i) + nums[1];
		int give=nums[0]%10;
		nums[0]=l;nums[1]=r;
		cout<<l<<" "<<r<<endl;
		if(!give)continue;
		if(l==0 || r==0)continue;
		if(l>r)swap(l,r);
		while(r>l)r/=10;
		if(l==r)ans++;
		cout<<ans<<"*"<<endl;
	}
	cout<<ans;
	return 0;
}