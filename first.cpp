#include <iostream>
#include <set>
using namespace std;

int main(){
    int n;
    int tmp;
    cin>>n;
    set<int> si;
    for(int i=0;i<n;i++){
        cin>>tmp;
        if(tmp>0){
            si.insert(tmp);
        }
    }
    int i=1;
    set<int>::iterator it = si.begin();
    while( it != si.end() && *it==i)    
    {
        i++;it++;
    }
    cout<<i;
    return 0;
}