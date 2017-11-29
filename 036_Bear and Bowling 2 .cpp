#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <utility>
#define ff first
#define ss second
using namespace std;
int main(){
	vector<int> v,poss;
	vector<pair<int,int> > a;
	int n;cin>>n;
	poss.resize(n);
	for(int i=0,x;i<n;i++){
		cin>>x;v.push_back(x);
		a.push_back(make_pair(x,i+1));
	}
	int ct=0;
	for(int i=0;i<n;){
		int pre=i,cnt=1;i++;
		while(i<n&&v[i]==v[pre]){cnt++;i++;}
		ct=max(cnt,ct);
	}
	// cerr<<"==="<<ct<<endl;
	for(int i=0;i<ct;i++)poss[i]=1;
	set<int> s;
	sort(a.rbegin(),a.rend());
	for(auto x:a){
		// cerr<<x.ss<<" "<<x.ff<<endl;
		s.insert(x.ss);
		int f=*(s.begin());
		set<int> :: iterator t=s.end();--t;
		int e=*t;
		// cerr<<"_____"<<f<<" "<<e<<" "<<s.size()<<endl;
		if(e-f+1==s.size()){
			poss[s.size()-1]=1;
			// cerr<<"****"<<s.size()-1<<endl;
		}
	}
	for(auto x:poss)cout<<x;
	return 0;
}

// 8745987789
