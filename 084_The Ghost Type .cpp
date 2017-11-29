#include <iostream>
#include <vector>
using namespace std;
int main(){
	int n;cin>>n;
	vector<int> dp ((1<<n),0);
	dp[0]=1;
	for(int mask = 1 ; mask < (1<<n) ; mask++){
		cerr<<mask<<"*****"<<endl;
		for(int pos1=0;pos1<n;pos1++){
			
			if(!((1<<pos1)&mask))continue;
			int mask2 = mask ^ (1<<pos1);
			bool fl = true;

			for(int pos2=0;pos2<n;pos2++){
				if(!((1<<pos2)&mask2))continue;
				if( (pos1+1) & (pos2+1) == (pos1+1))fl=false;
				cerr<<( (pos1+1) & (pos2+1) == (pos1+1))<<" "<<((pos1+1) & (pos2+1))<<" -*- "<<(pos1+1) <<"&"<< (pos2+1)<<endl;
			}
			if(fl){
				cerr<<"add "<<pos1<<endl;
				dp[mask] += dp[mask2];}
		}
		cerr<<mask<<" "<<dp[mask]<<endl;
		cerr<<"*********************"<<endl;
	}
	cout<<dp.back();
	return 0;
}

// 1 2 3 4
// 1 2 4 3
// 1 4 2 3
// 2 1 3 4
// 2 1 4 3
// 2 4 1 3
// 4 1 2 3
// 4 2 1 3 