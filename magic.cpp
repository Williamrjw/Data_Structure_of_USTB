#include <iostream>
#include <stdlib.h>
using namespace std;
//Mr. garlic: Is your brain worst?
//分析结果：对于每一个出栈的元素，比它先入栈的如果在它后面出栈，一定是逆序排列的。
int main(){
    int n;
    int threshold;
    bool f=true;
    cin>>n;
    int *num=new int[n];
    for(int i=0;i<n;i++){
        cin>> num[i];
    }
    int i,j;
    for(i=0;i<n;i++){
        threshold=num[i];
        for(j=i+1;j<n;j++){
            if(num[i]>num[j]){
                if(threshold<num[j]){
                    f=false;
                }
                threshold=num[j];
            }
        }
    }
    if(f){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
	return 0;
}