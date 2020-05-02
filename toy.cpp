#include <iostream>
#include <vector>
using namespace std;
int main(){
    struct toy{
        int id;
        toy* next;
    };
    struct pos{
        int id;
        toy* next;
        toy* prev;
    };
    int n,m;
    int a,b;
    cin>> n>> m;
    vector<pos> vp;
    for(int i=0;i<n;i++){
		toy* q=new toy;
		vp.push_back({ (i + 1),q,q });
		vp[i].next->id = i + 1;
		vp[i].prev = vp[i].next;
		vp[i].next->next = NULL;
    }
    for(int i=0;i<m;i++){
		cin >> a >> b;
		a--; b--;
		if (a == b)continue;
		if (NULL == vp[b].prev)continue;
		if (NULL == vp[a].prev)vp[a].next = vp[b].next;
		else vp[a].prev->next = vp[b].next;
		vp[a].prev = vp[b].prev;
		vp[b].next = NULL;
		vp[b].prev = NULL;
    }
    toy* p=NULL;
    for(int i=0;i<n;i++){
        p=vp[i].next;
        while(p!=NULL){
            cout<< p->id<<" ";
            p=p->next;
        }
        cout<<endl;
    }
    return 0;
}