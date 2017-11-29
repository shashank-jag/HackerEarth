#include <iostream>
#include <set>
#include <stack>
#include <deque>
#include <algorithm>

#define ll long long

using namespace std;

int main(){
	ll n;cin>>n;
	deque<ll> de[12];
	stack <ll> stk;
	ll a,x;cin>>a;
	
	while(a--){
		cin>>x;
		de[1].push_back(x);
		if(stk.empty() || stk.top()>=x)stk.push(x);
	}

	for(ll i=2;i<=n;i++){
		ll a;cin>>a;
		while(a--){
			ll x;cin>>x;
			de[i].push_back(x);
		}
	}

	ll q;cin>>q;
	while(q--){
		ll ty;cin>>ty;
		if(ty==0){
			ll rde;cin>>rde;
			if(rde==1){
				if(stk.top()==de[1].back())stk.pop();
			}
			de[rde].pop_back();
		}
		else if(ty==1){
			ll pde,val;cin>>pde>>val;
			if(pde==1){
				if(val<=stk.top())stk.push(val);
			}
			de[pde].push_back(val);
		}
		else {
			bool chk=true;
			ll mi=stk.top();
			for(ll i=2;i<=n && chk;i++){
				auto x = upper_bound(de[i].begin(),de[i].end(),mi) - de[i].begin();
				if(x==de[i].size())chk=false;
				else mi=de[i][x];
			}
			if(chk)cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
	}
	return 0;
}