#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;
unordered_map<string , int > mp;
vector<int> par;
vector<int> anto;
vector<int> rnk;

int _find(int i){
	if(i==-1)return -1;
	if(par[i]==i)return i;
	return par[i]=_find(par[i]);
}

void _union(int a,int b){
	if(a==-1 || b==-1)return;
	int p1=_find(a),p2=_find(b);
	if(rnk[p1]>rnk[p2]){
		par[p2]=p1;
	}
	else if(rnk[p1]<rnk[p2]){
		par[p1]=p2;
	}
	else {
		par[p1]=p2;
		rnk[p2]++;
	}
}

int main(){
	int n,pairs,query;cin>>n>>pairs>>query;
	par.resize(n,0);anto.resize(n,-1);rnk.resize(n,0);
	string in;
	for(int i=0;i<n;i++){
		cin>>in;
		mp[in]=i;
		par[i]=i;
	}
	while(pairs--){
		int ch;cin>>ch;
		string a,b;cin>>a>>b;
		int NOde1=_find(mp[a]),NOde2=_find(mp[b]);
		if(ch==1){
			if(NOde1==NOde2)cout<<"YES"<<endl;
			else {
				if(anto[NOde1]==NOde2)cout<<"NO"<<endl;
				else {
					cout<<"YES"<<endl;
					_union(NOde1,NOde2);
					_union(anto[NOde1],anto[NOde2]);
					int head = _find(NOde1);
					int anto1 = _find(anto[NOde1]);
					int anto2 = _find(anto[NOde2]);
					if(anto1 == -1){
						anto[head]=anto2;
					}
					else anto[head]=anto1;
					if(anto[head]!=-1){
						anto[anto[head]]=head;
					}
				}
			}
		}
		else {
			if(anto[NOde1]==NOde2)cout<<"YES"<<endl;
			else if(NOde1==NOde2)cout<<"NO"<<endl;
			else{
				cout<<"YES"<<endl;
				_union(anto[NOde1],NOde2);
				_union(NOde1,anto[NOde2]);
				int h1 = _find(NOde2);
				int h2 = _find(NOde1);
				anto[h1]=h2;
				anto[h2]=h1;
			}
		}
	}
	while(query--){
		string a,b;cin>>a>>b;
		int NOde1=_find(mp[a]),NOde2=_find(mp[b]);
		if(NOde1==NOde2){
			cout<<"1\n";
		}
		else if(anto[NOde1]==NOde2){
			cout<<"2\n";
		}
		else cout<<"3\n";
	}
	return 0;
}