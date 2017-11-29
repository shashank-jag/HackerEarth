#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <stack>
#define pii pair<int,int>
using namespace std;
vector<int> ltree,rtree;
vector<pii> inp;

void lupdate(int pos,int l,int r,int ind,int val){
	//cout<<pos<<"lu"<<l<<" "<<r<<" "<<ind<<" "<<val<<" "<<ltree[pos]<<endl;
	if (ind>r || ind < l ) return;
	if(l==r){ltree[pos] = max(ltree[pos],val);return;}
	int mid=(l+r)/2;
	lupdate(pos*2,l,mid,ind,val);
	lupdate(pos*2+1,mid+1,r,ind,val);
	ltree[pos]=max(ltree[pos*2],ltree[pos*2+1]);
	//cout<<pos<<"lu"<<l<<" "<<r<<" "<<ind<<" "<<val<<" "<<ltree[pos]<<endl;
}

void rupdate(int pos,int l,int r,int ind,int val){
	//cout<<pos<<"ru"<<l<<" "<<r<<" "<<ind<<" "<<val<<" "<<rtree[pos]<<endl;
	if (ind>r || ind < l ) return;
	if(l==r){rtree[pos] = max(rtree[pos],val);return;}
	int mid=(l+r)/2;
	rupdate(pos*2,l,mid,ind,val);
	rupdate(pos*2+1,mid+1,r,ind,val);
	rtree[pos]=max(rtree[pos*2],rtree[pos*2+1]);
	//cout<<pos<<"ru"<<l<<" "<<r<<" "<<ind<<" "<<val<<" "<<rtree[pos]<<endl;
}

int rquery(int pos , int l, int r,int ql,int qr){
	//cout<<'r'<<" "<<pos<<" "<<l<<" "<<r<<" "<<ql<<" "<<qr<<" "<<endl;
	if(qr<l || ql>r)return -1;
	if(ql<=l && r<=qr)return rtree[pos];
	int mid=(l+r)/2;
	return max(rquery(2*pos,l,mid,ql,qr),rquery(2*pos+1,mid+1,r,ql,qr));
}

int lquery(int pos , int l, int r,int ql,int qr){
	//cout<<'l'<<" "<<pos<<" "<<l<<" "<<r<<" "<<ql<<" "<<qr<<" "<<endl;
	if(qr<l || ql>r)return -1;
	if(ql<=l && r<=qr)return ltree[pos];
	int mid=(l+r)/2;
	return max(lquery(2*pos,l,mid,ql,qr),lquery(2*pos+1,mid+1,r,ql,qr));
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int n,h;cin>>n>>h;
	inp.resize(n);rtree.resize(h*4,-1);ltree.resize(h*4,-1);
	for(auto &x:inp)cin>>x.first>>x.second;
	sort(inp.begin(),inp.end());
	stack <pii> stk;
	int prev=-1,top,val,maxo,ans=0;
	for(int i=0;i<n;i++){
		if(inp[i].first!=prev){
			while(!stk.empty()){
				top=stk.top().first;
				val=stk.top().second;
				stk.pop();
				//cout<<top<<" "<<val<<endl;
				if(top<0)lupdate(1,0,h,-top,val);
				else rupdate(1,0,h,top,val);
			}
			//cout<<'l';for(auto x:ltree)//cout<<x<<" ";//cout<<endl;
			//cout<<'r';for(auto x:rtree)//cout<<x<<" ";//cout<<endl;
		}
		maxo=0;
		if(inp[i].second<0){
			int dist=inp[i].second+h;
			if(dist<=0)maxo=0;
			else {
				//cout<<"rquery"<<dist<<endl;
				maxo=1+rquery(1,0,h,0,dist);
			}
		}
		else {
			int dist=h-inp[i].second;
			if(dist<=0)maxo=0;
			else {
				//cout<<"lquery"<<dist<<endl;
				maxo=1+lquery(1,0,h,0,dist);
			}
		}
		//cout<<maxo<<endl;
		ans=max(ans,maxo);
		stk.push(make_pair(inp[i].second,maxo));
		prev=inp[i].first;
	}
	cout<<ans<<endl;
	return 0;
}