#include <iostream>
using namespace std;
int arr[505][505];
int n,m;
int get(int i,int j){
    if(i<0 || j<0 || i>=n || j>=m)return 0;
    return arr[i][j];
}
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)cin>>arr[i][j];
    for(int i=0;i<n;i++){
        for(int j=1;j<m;j++){
            arr[i][j]+=arr[i][j-1];
        }
        if(i)for(int j=0;j<m;j++)arr[i][j]+=arr[i-1][j];
    }
   // for(int i=0;i<n;i++){for(int j=0;j<m;j++)cout<<arr[i][j];cout<<endl;}
    int total=arr[n-1][m-1],ans=-1,i_,j_;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int k=0;
            int pres = get(i-1,j-1);
            // cout<<i<<j<<pres<<"*"<<endl;
            while(i+k<n&&j+k<m){
                int p = pres + get(i+k,j+k) - get(i-1,j+k) - get(i+k,j-1);
                // cout<<pres <<get(i+k,j+k)<< get(i-1,j+k) <<get(i+k,j-1)<<'&'<<endl;
                k++;int a = total - p + (k * k) - p ;
                if(a >= ans){
                    ans = a ;
                    i_=i,j_=j;
                }
                // cout<<k<<"-"<<a<<" "<<p<<" "<<total<<" "<<endl;
            }
            // cout<<endl;
        }
    }
    cout<<ans;
    return 0;
}