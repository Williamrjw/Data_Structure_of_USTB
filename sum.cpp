#include <iostream>
using namespace std;

int main(){
    int n,i1,i2,target;
    cin>>n;
    int num[500];
    for(int i=0;i<n;i++){
        cin>>num[i];
    }
    cin>>target;
    //i1=0;i2=n-1;
    //while(i1<i2&&target!=num[i1]+num[i2]){
    //   if(target>num[i1]+num[i2])i2--;
    //    else if(target<num[i1]+num[i2])i1++;
    //}
    for(i1=0;i1<n;i1++)
        for(i2=i1+1;i2<n;i2++)
            if(num[i1]+num[i2]==target&&num[i1]!=0&&num[i2]!=0)cout<<i1+1<<" "<<i2+1;
    return 0;
}