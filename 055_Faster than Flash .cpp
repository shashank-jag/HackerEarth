#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int getCount(vector<int> &v){
    int ans=-1,pre=0;
    for(int i=0;i<v.size();i++){
        if(v[i]){
            ans=max(i-pre+1,ans);
            pre=i;
        }
    }
    ans=max((int)v.size()-pre,ans);
    return ans;
}

int getOdd(string &s){
    vector<int> v(s.size(),0);
    for(int i=1;i<s.size()-1;i++){
        if(s[i-1]==s[i+1])v[i]=1;
    }
    return getCount(v);
}

int getEven(string &s){
    vector<int> v(s.size(),0);
    for(int i=1;i<s.size()-1;i++){
        if(s[i-1]==s[i]){v[i]=1;v[i-1]=1;}
    }
    return getCount(v);
}


int main()
{
    ios_base::sync_with_stdio(false);
    int t;cin>>t;
    while(t--){
        string s;cin>>s;
        if(s.size()==1){cout<<-1<<endl;continue;}
        int odd=getOdd(s);
        int eve=getEven(s);
        cout<<min(odd,eve)<<endl;
    }
    return 0;
}
