#include <iostream>
#include <vector>
#include <utility>
#define pii pair<int,int>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
using namespace std;
int N = 210031;
vector<pii> order;
int n,j,a[N],x[N],dp[N];

int answ;

int t[N*4];

void update(int v,int tl,int tl,int ps,val){
	if(tl==tr){
		t[v]=max(t[v],val);
		return;
	}
	int tm=tl+tr;tm/=2;
	if(ps<=tm){
		update(v*2+1,tl,tm,ps,val);
	}
	else update(v*2+2,tm,tr,ps,val);
	t[v]=max(t[v*2+1],t[v*2+2]);
}

int get(int pos,int tl,int tr,int l,int r){
	if(l>r)return 0;
	if(tl==l && tr==r)return t[pos];
	int mid=(l+r)/2;
	return max(get(pos*2+1,tl,tr,l,min(mid,r)),get(pos*2+1,tl,tr,max(l,mid+1),r);
}


int main(){
	int n,k;cin>>n>>k;
	for(int i=0;i<n;i++){
		int x,y;cin>>x>>y;
		y+=100000;
		order.pb(mp(x,y));
	}
	sort(order.begin(),order.end());
	
	return 0;
}