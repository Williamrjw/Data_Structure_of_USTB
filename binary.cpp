//ruo'zhi'suan'tou'jun
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
string read_str(string str,int a,int b){
    string ret="";
    for(int i=a;i<b;i++){
        ret=ret+str[i];
    }
    return ret;
}
int index_str(string str,char c){
    for(int i=0;i<str.length();i++){
        if(c==str[i])return i;
    }
    return -1;
}
string handle_str1(string pre,string in){
    if(pre.length()<=1)return pre;/////////////////////shabicaozuo///////////////////
    int index=index_str(in,pre[0]);
    return handle_str1(read_str(pre,1,index+1),read_str(in,0,index))+
        handle_str1(read_str(pre,index+1,pre.length()),read_str(in,index+1,in.length()))+
        pre[0];
}
string handle_str2(string pre,string in){
    if(pre.length()<=1)return pre;/////////////////////shabicaozuo///////////////////
    int index=index_str(in,pre[0]);
    return handle_str2(read_str(pre,index+1,pre.length()),read_str(in,index+1,in.length()))+
        handle_str2(read_str(pre,1,index+1),read_str(in,0,index))+ 
        pre[0];
}
int main() {
	string pre_str, in_str;
	cin >> pre_str;
	cin >> in_str;
	cout<< handle_str1(pre_str,in_str)<<endl;
    cout<< handle_str2(pre_str,in_str);
	return 0;
}