

    #include <iostream>
    #include <vector>
    #include <utility>
    #include <queue>
    #include <algorithm>
    #define mp make_pair
    #define pii pair<int,pair<int,int> > 
    #define ff first
    #define ss second
    using namespace std;
     
    vector<int> par(100010);
     
    int find_(int x){
        if(par[x]==x)return x;
        par[x]=find_(par[x]);
        return par[x];
    }
     
    bool union_(int x,int y){
        int a=find_(x),b=find_(y);
        if(a==b)return false;
        par[a]=par[b];
        find_(x);
        return true;
    }
     
    int main(){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        vector<pii> v;
        int n,m;cin>>n>>m;
        for(int i=0;i<=n;i++)par[i]=i;
        for(int i=0;i<m;i++){
            int x,y,z;cin>>x>>y>>z;
            v.push_back(mp(z,mp(x,y)));
        }
        priority_queue<int> used;
        vector<int> extra;
        int q;cin>>q;
        for(int i=0;i<n;i++){
            int x;cin>>x;extra.push_back(x);
        }
        sort(extra.begin(),extra.end());
        sort(v.begin(),v.end());
        long long ans=0;
        for(auto x:v){
            if(union_(x.ss.ff,x.ss.ss)){ans+=x.ff;used.push(x.ff);}
        }
        int i=0;
        while((!used.empty())&&i<q){
            if(extra[i]<used.top()){
                ans-=used.top();ans+=extra[i];i++;used.pop();
            }
            else break;
        }
        cout<<ans<<endl;
        return 0;
    }

Language: C++
