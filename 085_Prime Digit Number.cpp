#include <string>
#include <iostream>

using namespace std ;

int main(){
    while(1){
    string s;cin>>s;
    cout<<s<<" ";
    string n;
    for(int i=0;i<(int)s.size()-2;i++){n+="7";cerr<<n;}
    cerr<<"***";
    if(s.size()==1) {
        if(s[1]=='0') cout<<7;
        else if(s[1]<'3') cout<<11;
        else if(s[1]<'5') cout<<13;
        else if(s[1]<'7') cout<<15;
        else cout<<17;
    }
    else if(s[0]=='1'){
        if(s[1]=='0') cout<<7;
        else if(s[1]<'3') cout<<11;
        else if(s[1]<'5') cout<<13;
        else if(s[1]<'7') cout<<15;
        else cout<<17;
    }
    else if(s[0]<'3') cout<<17;
    else if(s[0]<'5') cout<<37;
    else if(s[0]<'7') cout<<57;
    else cout<<77;
    cout<<n;
    cerr<<"***";
    cout<<endl;
    }
    return 0;
}