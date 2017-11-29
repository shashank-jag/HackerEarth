#include <iostream>
#include <vector>
#include <string>
#define ll long long

using namespace std;

vector<ll> dp((1<<20)+10,0);
vector<bool> trav((1<<20)+10,0);
vector<ll> d1,d2;
ll n;

bool trueChk(ll mask,ll p1){
	// cerr<<p1<<"-";
	for(ll i=0;i<n;i++){
		if(mask&(1<<i)){
			if(((i+1)&(1+p1))==(p1+1))return false;
		}
	}
	// cerr<<".";
	return true;
}

string bin(ll i){
	string ret;
	while(i){
		if(i&1)ret = '1' + ret;
		else ret = '0' + ret;
		i/=2;
	}
	return ret;
}

ll bfs(){
	for(ll i=0;i<n;i++){
		d1.push_back(1<<i);
		dp[1<<i]++;
		trav[1<<i]=1;
	}
	while(d1.size()){
		// for(auto x:d1){
		// 	cerr<<bin(x)<<"-->"<<dp[x]<<" ";
		// }
		// cerr<<endl;
		for(auto mask:d1){
			// cerr<<bin(mask)<<"<--- ";
			if(mask==(1<<n)-1)return d1.size();
			for(ll p1=0;p1<n;p1++){
				if(!((1<<p1)&mask)){
					if(trueChk(mask,p1)){
						// cerr<<"add "<<(p1+1)<<" ";
						dp[mask+(1<<p1)]+=dp[mask];
						if(!trav[mask+(1<<p1)]){
							d2.push_back(mask+(1<<p1));
							trav[mask+(1<<p1)]=1;
						}
					}
				}
			}
			// cerr<<endl;//<<"\tfinal sum "<<dp[mask]<<endl;
		}
		d1=d2;d2.clear();
	}
	return 0;
}

int main(){
	cin>>n;
	cerr<<bfs()<<endl;
	cout<<dp[(1<<n)-1];
	return 0;
}