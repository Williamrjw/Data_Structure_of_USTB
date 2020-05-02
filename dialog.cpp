#include <iostream>
//#include <cstring>
using namespace std;
int main(){
    struct diagLog{
        int type;
        long long int tel;
    };
    diagLog log[10];
    for(int i=0;i<10;i++){
        cin>>log[i].type;
        cin>>log[i].tel;
    }
	long long int log0[10]={0};
    long long int log1[10]={0};
	long long int log2[10]={0};
    int j=0,k=0,l=0;
    for(int i=0;i<10;i++){
        switch(log[i].type){
            case 0:
                log0[j++]=log[i].tel;
                break;
            case 1:
                log1[k++]=log[i].tel;
                break;
            case 2:
                log2[l++]=log[i].tel;
                break;
        }
    }
    for(int i=0;i<10;i++){
        cout<<log0[i]<<" "<<log1[i]<<" "<<log2[i];
    	if(i!=9)cout<<endl;
    }
    return 0;
}