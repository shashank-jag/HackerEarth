#include <iostream>
#include <string>

using namespace std;

void add(string &s){
    int car=1;
    for(int i=s.size()-1;i>=0;i--){
        s[i]+=car;
        if(s[i]>'9')s[i]='0',car=1;
        else car = 0;
    }
    if(car)s='1'+s;
}

void ruin(string &s,int i){
    for(;i<s.size();i++)s[i]='3';
}


void build(string &s,int i){
    if(i==-1)s='3'+s;
    else {
        while(i>=0&&s[i]!='3')s[i--]='3';
        if(i==-1)s='3'+s;
        else s[i]='5';
    }
}

void chk(string &s){
    int i;
    for(i=0;i<s.size();i++){
        if(s[i]!='3'&&s[i]!='5')break;
    }
    if(i==s.size())return ;
    if(s[i]>'5'){
        s[i]='3';
        ruin(s,i+1);
        build(s,i-1);
    }
    else if(s[i]<'3'){
        s[i]='3';
        ruin(s,i+1);
    }
    else {
        s[i]='5';
        ruin(s,i+1);
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    while(n--){
        string s;
        cin>>s;
        add(s);
        chk(s);
        cout<<s<<endl;
    }
    return 0;
}