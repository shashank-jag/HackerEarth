#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;
struct worker{
	int t,x,y;
	worker(){}
	worker(int _t,int _x,int _y){
		t=_t;x=_x;y=_y;
	}
};

vector<worker> v;

bool way(worker &a,worker &b){
	if(a.t==b.t){
		if(a.y==b.y){
			return a.x<b.x;
		}
		return a.y>b.y;
	}
	return a.t<b.t;
}

int main(){
	int n,x,y,t;
	ll d;
	cin>>n>>d;
	for(int i=0;i<n;i++){
		cin>>t>>x>>y;
		v.push_back(worker(t,x,y));
	}
	sort(v.begin(),v.end(),way);
	ll area=0,best=0,cost=0,last=0;
	for(auto a:v){
		area+=(a.t-last)*(1ll)*best;
		if(area>=d)break;
		if(a.y>best){
			best=a.y;
			cost+=a.x;
		}
		last=a.t;
	}
	cout<<cost;
	return 0;
}