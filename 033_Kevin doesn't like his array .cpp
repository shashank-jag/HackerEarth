#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;
int main(){
    int n;cin>>n;vector<int> v(n);
    priority_queue<int> pq;
    for(int i=0;i<n;i++)cin>>v[i];
    for(int i=0,pre=0;i<n;i++){
        int ct=0;
        while(i<n && v[i]==v[pre]){i++;}
        pq.push(i-pre);
        pre=i;
    }
    int ans=0;
    while(!pq.empty()){
        if(pq.top()<=1)break;
        cerr<<pq.top()<<endl;
        ans++;
        pq.push(ceil((double)pq.top()/2));
        pq.push(floor((double)pq.top()/2));
        pq.pop();
        pq.push(ceil((double)pq.top()/2));
        pq.push(floor((double)pq.top()/2));
        pq.pop();
    }
    cout<<ans;
    return 0;
}