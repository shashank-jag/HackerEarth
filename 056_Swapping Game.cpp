#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string swap(string s){
    string st,en;
    for(int i=0;i<s.size();i++){
        if(i%2){
            en=s[i]+en;
        }
        else st+=s[i];
    }
    // reverse(en.begin(),en.end());
    return st+en;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int i;string s,x;
    cin>>i>>s;
    int j=1;x=swap(s);
    while(x!=s){
        // cout<<x<<endl;
        x=swap(x);j++;
    }
    // cout<<x<<" "<<s<<endl;
    // cout<<j<<endl;
    i%=(j);
    while(i--)s=swap(s);
    cout<<s;
    return 0;
}