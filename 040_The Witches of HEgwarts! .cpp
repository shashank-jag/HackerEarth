#include <stdio.h>
#include <queue>
using namespace std;
int main(){
    int t;scanf("%d",&t);
    while(t--){
        int x,ti=0;
        scanf("%d",&x);
        if(x==1){printf("0\n");continue;}
        deque<int> de;de.push_back(x);
        while(de.size()>0){
            ti++;
            bool done=false;
            deque<int> d1;
            for(auto x:de){
                if(x==1){done=true;break;}
                if(x-1>0){d1.push_back(x-1);if(x-1==1){done=true;break;}}
                if((int(x/2))*2==x){d1.push_back(x/2);if(x/2==1){done=true;break;}}
                if((int(x/3))*3==x){d1.push_back(x/3);if(x/3==1){done=true;break;}}
            }
            if(done)break;
            de=d1;
        }
        printf("%d\n",ti);
    }
    return 0;
}