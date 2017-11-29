#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <math.h>
#define ll long long
using namespace std;
ll dp[1010][2505];

ll n,m,amt;

int main(){
	int t;scanf("%d",&t);
	while(t--){
		scanf("%lld%lld%lld",&m,&n,&amt);
		if(amt > m*n || amt < m){
			printf("0.000 0\n");
			continue;
		}
		memset(dp,0,sizeof(dp));
		double ans=0;
		// for(int i=1;i<n;i++){
		// 	dp[1][i]=1;
		// }
		int k=amt;
		// for(int i=2;i<=m;i++){
		// 	for(int j=1;j<=amt;j++){
		// 		for(int k=1;k<j && k<=n;k++){
		// 			dp[i][j]=dp[i][j]+dp[i-1][j-k];
		// 		}
		// 	}
		// }
		for(int i=1;i<=n;i++)
				dp[1][i]=1;
		for(int i=2;i<=m;i++)
		{
			for(int j=1;j<=k;j++)
			{
				for(int x=1;x<j && x<=n;x++)
					dp[i][j] += dp[i-1][j-x];
			}
		}
		ans=dp[m][amt];for(int i=1;i<=m;i++)ans/=(double)n;
		int i=0;
		while(ans>0 && ans<1)ans*=10,i++;
		printf("%.3lf %d\n",ans,i);
	}
	return 0;
}