#include <iostream>
#include <vector>
#define ll long long
using namespace std;

ll seg[2][200010],a[200010],n,k,t;

void make(ll s,ll e,ll pos,ll ind,ll val){
	if(s==e){
		seg[0][pos]=seg[1][pos]=val;
		return;
	}
	ll mid=(s+e)/2;
	if(ind<=mid)
		make(s,mid,2*pos+1,ind,val);
	else
		make(mid+1,e,2*pos+1,ind,val);
	seg[0][pos]=max(seg[0][2*pos+1],seg[0][2*pos+2]);
	seg[1][pos]=min(seg[1][2*pos+1],seg[1][2*pos+2]);
}

ll qry(ll pos , ll s, ll e, ll qs, ll qe){
	cerr<<s<<" "<<e<<" "<<qs<<" "<<qe<<endl;
	if(qe<s || qs>e || s>e )return 0;
	if(qe>=e && qs<=s)return seg[0][pos];
	ll mid=(s+e)/2;
	ll p1=qry(2*pos+1,s,mid,qs,qe);
	ll p2=qry(2*pos+2,mid+1,e,qs,qe);
	return max(p1,p2);
}

ll qry1(ll pos , ll s, ll e, ll qs, ll qe){
	if(qe<s || qs>e || s>e )return 10000000;
	if(qe>=e && qs<=s)return seg[1][pos];
	ll mid=(s+e)/2;
	ll p1=qry(2*pos+1,s,mid,qs,qe);
	ll p2=qry(2*pos+2,mid+1,e,qs,qe);
	return min(p1,p2);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	while(t--){
		ll ans=0;
		cin>>n>>k;
		memset(seg[0],0,sizeof seg[0]);
		memset(seg[1],1000000,sizeof seg[1]);
		for(int i=0;i<n;i++){
			int j;cin>>j;a[j]=i;
		}
		for(int i=0;i<n;i++){
			ll maxi=qry(0,0,n-1,1,a[i]-k);
			ll mini=qry(0,0,n-1,a[i]+k,n);
			if(maxi!=0){
				maxi=abs(maxi-a[i]);
			}
			else maxi=10000000;
			if(mini<n){
				mini=abs(mini-a[i]);
			}
			else mini=10000000;
			if(maxi!=10000000 || mini!=10000000)ans+=min(maxi,mini);
			make(1,n,0,a[i],a[i]);
		}
		cout<<ans<<"*"<<endl;
	}
	return 0;
}