#include <iostream>
#include <string>
using namespace std;
void ans(string s){
    int car = 0;
    for(int i=0;i<s.size();i++){
        if(s[i]!='3' && s[i]!='5'){
            if(s[i]<'3')s[i]='3';
            else if(s[i]<'5')s[i]='5';
            else s[i]='3',car=1;
            i++;
            while(i<s.size())s[i++]='3';
        }
    }
    if(car)cout<<'3';cout<<s<<endl;
}
int main(){
    int t;cin>>t;
    string s;
    while(t--){
        cin>>s;cerr<<s<<" ";ans(s);
    }
    return 0;
}
