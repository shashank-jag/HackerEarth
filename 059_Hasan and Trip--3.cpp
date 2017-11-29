#include <iostream>
#include <stdio.h>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

double x[3100],y[3100],hap[3100],score[3100];

double dist(int i,int j){
	return sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int n;cin>>n;
	for(int i=0;i<n;i++)//{scanf("%fd %fd %fd ",x+i,y+i,hap+i);}
		cin>>x[i]>>y[i]>>hap[i];
	for(int i=1;i<n;i++)score[i]=hap[0]-dist(0,i);
	for(int i=1;i<n;i++){
		for(int j=i+1;j<n;j++){
			score[j]=max(score[j],score[i]+hap[i]-dist(i,j));
		}
	}
	score[n-1]+=hap[n-1];
// 	long long x = ceil(score[n-1]*1000000);
// 	score[n-1]=((double(x))/1000000);
	cout << fixed << setprecision(6) << score[n-1];
	return 0;
}