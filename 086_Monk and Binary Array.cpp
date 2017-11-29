#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v,in;
int n;

int chk(){
	vector<int>  zeros(2,0);
	int ptr=0,run1=0;
	int ones=0;
	int sum = 0;
	// for(auto x:v)cerr<<x<<" ";cerr<<endl;
	for(int i=0;i<n;i++){
		if(v[i]){
			sum++;
			ones++;
			sum += zeros[1-(ones%2)];
			sum += (ones-1)/2;
		}
		else {
			zeros[ones%2]++;
			sum += ((ones+1)/2);
			sum += zeros[1-(ones%2)];
		}
		// cerr<<sum<<" ";
	}
	// cerr<<endl;
	// cerr<<"**************"<<endl;
	return sum;
}

int main(){
	ios::sync_with_stdio(false);
    cin>>n;
    v.resize(n);for(auto &x:v)cin>>x;
    int ans=0;
    in=v;
    for(int i=0;i<n;i++){
        v=in;
        v[i]=1-v[i];
        ans = max(ans , chk());
    }
    cout<<ans;
    return 0;
}