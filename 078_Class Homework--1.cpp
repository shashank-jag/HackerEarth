#include <iostream>
#include <vector>
#include <string>
#define ll long long 
using namespace std;
int main(){
    int t;cin>>t;
    for(int ctr=1;ctr<=t;ctr++){
        vector<vector<ll> > two(21,vector<ll> (21,-1));
        vector<vector<ll> > one(21,vector<ll> (21,-1));
        string s;cin>>s;
        // cout<<ctr<<"*"<<s<<" ";
        int n=s.size();
        if(n<4){
            cout<<"unlucky"<<endl;
            continue;
        }
        for(int i=0;i<n;i++){
            one[i][i]=s[i]-'0';
            // if(one[i][i]==0)one[i][i]=-1;
        }


        for(int i=0,j;i<n;i++){
            ll sum=0;
            if(s[i]=='0')continue;
            for(j=i;j<n && j<i+12;j++){
                sum*=10;
                sum+=s[j]-'0';
                one[i][j]=sum;
            }
            sum*=10;
            if(j<n)if(sum+s[j]-'0'==1000000000000)one[i][j]=sum+s[j]-'0';
        }




        for(int win=1;win<n;win++){
            for(int i=0,j=win;j<n;j++,i++){
                for(int k=i;k<=j-1;k++){
                    if(one[i][k] !=-1 && one[k+1][j]!=-1 ){
                    // if(one[i][k]>0 && one[k+1][j]>0 ){
                        two[i][j]=max(two[i][j],one[i][k]+one[k+1][j]);
                        // cout<<one[i][k]<<" "<<one[k+1][j]<<"*"<<k<<" "<<one[i][k]+one[k+1][j]<<endl;
                    }
                    //one[i][k]>0 && one[k+1][j]!=-1 &&
                //     if( one[i][k]!=-1 && one[k+1][j]!=-1 && one[i][j]==-1){
                //         // cout<<one[i][k] << one[k+1][j]<<one[i][j]<<"**"<<endl;
                //         if(one[i][k]==0 && one[k+1][j]==0){one[i][j]=0;}
                //         else {
                //             one[i][j] = one[i][k];
                //             // while(t){
                //             //     one[i][j]*=10;
                //             //     one[i][j]+=t%10;
                //             //     t/=10;
                //             // } 
                //             for(int te=k+1;te<=j;te++){
                //                 one[i][j]*=10;
                //             }
                //             one[i][j]+=one[k+1][j];
                //         }
                //     }
                //     // cout<<i<<" "<<j<<"*"<<one[i][j]<<endl;
                //     // cout<<i<<" "<<j<<"^"<<two[i][j]<<endl;
                // }
                // if(win>=12){
                //     one[i][j]=-1;
                //     continue;
                }
                // cout<<"**********"<<endl;
                // if(one[i][j-1]!=0)one[i][j]=one[i][j-1]*10+((one[j][j]==-1)?0:one[j][j]);
                
            }

        }
        
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<one[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<"*************"<<endl;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<two[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        ll ret = -1 ;
        for(int i=0;i<n;i++){
            // cout<<i<<"-"<<two[0][i]<<" "<<two[i+1][n-1]<<endl;
            if(two[0][i] == -1 || two[i+1][n-1] == -1 )continue;
            // cout<<i<<"*"<<two[0][i] + two[i+1][n-1]<<endl;
            ret = max(ret , two[0][i] + two[i+1][n-1]);
        }
        
        if(ret!=-1)cout<<ret<<endl;
        else cout<<"unlucky"<<endl;
    }
    return 0;
}