#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> speed;
vector<int> dur;
vector<int> strt;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n,s;cin>>n>>s;
    for(int i=0;i<n;i++){
        int x,y;cin>>x>>y;
        speed.push_back(y);strt.push_back(x);
    }
    for(int i=0;i<n-1;i++)dur.push_back(strt[i+1]-strt[i]);
    dur.push_back(1<<30);
    double ans=1<<30,a=-1,b=-1,p;
    
    for(int i=0;i<n;i++){
        int l=i,r=i,li=i,ri=i;
        int red=s,ti=0,ai,bi,prev;
        while(red){
            bool dir=false;

            // if(l>=0&&r<n){
            //     if(speed[l]>speed[r]){
            //         ai=red,bi=speed[l];
            //         prev=ti;
            //         ti+=min(red/speed[l],dur[l]);
            //         red-=min(red,speed[l]*dur[l]);
            //         l--;
            //     }
            //     else {
            //         ai=red,bi=speed[r];prev=ti;
            //         ti+=min(red/speed[r],dur[r]);
            //         red-=min(red,speed[r]*dur[r]);
            //         r++;
            //     }
            // } 

            while(l>=0&&r<n && speed[l]==speed[r] && dur[l]==dur[r])l--,r++;
            if(l<0&&r>=n)dir=false;
            else if(r>=n&&l>=0)dir=true;
            else if(r<n && l<0)dir=false;
            else if(l>=0 && r<n){
                if(speed[l]>speed[r])dir=true;
                else if(speed[l]<speed[r])dir=false;
                else {
                    if(dur[l]>dur[r])dir=true;
                    else dir=false;
                }
            }
            else dir=false;
            if(dir){
                ai=red,bi=speed[li];prev=ti;
                ti+=min(red/speed[li],dur[li]);
                red-=min(red,speed[li]*dur[li]);
                li--;
            }
            else {
                ai=red,bi=speed[ri];prev=ti;
                ti+=min(red/speed[ri],dur[ri]);
                red-=min(red,speed[ri]*dur[ri]);
                ri++;
            }
        }
        // cout<<ti<<" "<<ai<<" "<<bi<<" "<<prev<<"*****"<<l<<" "<<r<<endl;
        if(ti<ans){ans=ti,a=ai,b=bi,p=prev;}
    }
    // ans-=a/b;
    // ans*=b;ans+=a;
    // int g=__gcd(int(ans),int(b));ans/=g;b/=g;
    // cout<<p<<" "<<b<<" "<<a<<endl;
    p*=b;p+=a;
    int g=__gcd(int(p),int(b));p/=g;b/=g;
    cout<<p<<"/"<<b;
    return 0;
}
