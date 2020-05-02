#include <iostream>
#include <cstring>
using namespace std;
int main(){
    char str[100]={};
    char rstr[100]={};
    int i=0;
    while (true){
        cin>>str[i];
        if(str[i]!='@')
        	i++;
        else{
            str[i]='\0';
            break;
        }
    }
    for(int j=0;j<i;j++){
        rstr[j]=str[i-j-1];
    }
    rstr[i]='\0';
    if(strcmp(str,rstr)==0)
        cout<<"true";
    else cout<<"false";
    return 0;
}