#include <iostream>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    bool*graph=new bool[n*n];
    int follower,followee;
    for(int i=0;i<m;i++){
        cin>>follower>>followee;
        *(graph+n*follower+followee)=true;
    }
    int smart;
    for(int i=0;i<n;i++){
        smart=0;
        for(int j=0;j<n;j++){
            smart+=(*(graph+i+j*n)-*(graph+j+i*n));
        }
        cout<<smart<<endl;
    }
    return 0;
}