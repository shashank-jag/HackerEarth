#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int getCount(vector<int> &v,string s){
    int ans=-1,pre=0;
    for(int i=0;i<v.size();i++){
        if(v[i]){
            ans=max(i-pre+((s[i]==s[pre]&&i==pre+1)?0:1),ans);
            pre=i;
        }
    }
    ans=max((int)v.size()-pre,ans);
    return ans;
}

int getPalin(string s){
    vector<int> v(s.size(),0);
    for(int i=1;i<s.size()-1;i++){
        if(s[i-1]==s[i+1])v[i]=1;
    }
    for(int i=1;i<s.size();i++){
        if(s[i-1]==s[i]){v[i]=1;v[i-1]=1;}
    }
    return getCount(v,s);
}

int main()
{
    ios_base::sync_with_stdio(false);
    int t;cin>>t;
    while(t--){
        string s;cin>>s;
        if(s.size()==1){cout<<-1<<endl;continue;}
        // int odd=getOdd(s);
        // int eve=getEven(s);
        int getPalinCount=getPalin(s);
        cout<<getPalinCount<<endl;
    }
    return 0;
}
