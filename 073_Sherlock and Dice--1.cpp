#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <math.h>
#define ll unsigned long long
using namespace std;
ll ct[1010][2505];

int n,m,k;

ll pow (int no , int p){
	ll ret=1;
	while(p>0){
		if(p&1){
			ret*=no;
		}
		no*=no;p/=2;
	}
	return ret;
}

ll f(int ind,int sum){
	// printf("%d %d\n",ind,sum);
	// if(m-ind==sum)return 1;
	// if(m-ind>sum)return 0;
	// if(sum<=0)return 0;
	if(ind==m-1 && sum > 0 && sum<=n){printf("%d*\n",sum);return 1;}
	else if(ind==m-1)return 0;
	if(ct[ind][sum]!=-1){printf("return ct %d\n",ct[ind][sum]);return ct[ind][sum];}
	ll ret=0;
	for(int i=1;i<=min(sum,n);i++){
		printf("%d %d %d*_*\n",ind,sum,i );
		ret+=f(ind+1,sum-i);
	}
	return ct[ind][sum]=ret;
}

int main(){
	int t;scanf("%d",&t);
	while(t--){
		memset(ct,-1,sizeof(ct));
		printf("**************\n");
		scanf("%d%d%d",&m,&n,&k);
		if(k>m*n){
			printf("0.000 0\n");
			continue;
		}
		printf("%d %d %d\n",m,n,k);
		ll total = pow(n,m);
		ll comb = f(0,k);
		int i = 0;
		printf("%lld*****%lld\n",total,comb);
		while(comb > 0 && comb<total)comb*=10,i++;
		// while(ans<1 && ans > 0)i++,ans*=10;
		// printf("*****\n");
		printf("%.3f %d\n",((double)comb)/total,i);
	}
	return 0;
}