#include <iostream>
using namespace std;

int main(){
    int n,m;
    cin>> n>> m;
    int *matrix1 = new int[n*m];
	int **matrix = new int *[n];
	for(int i=0;i<n;++i)
	matrix[i] = matrix1 + i*m;
    int *left = new int[n];
    int	*right = new int [m];
    for(int i=0;i<n;i++){
        left[i]=i;
    }//o(n)
    for(int i=0;i<m;i++){
        right[i]=i;
    }//o(m)
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>> matrix[i][j];
        }
    }//o(mn)
    int op,x,y,z,tmp;
    cin>> op;
    for(int i=0;i<op;i++){
        cin>> x>> y>> z;
        y--;z--;
        if(x){
            tmp=right[y];
            right[y]=right[z];
            right[z]=tmp;
        }
        else{
            tmp=left[y];
            left[y]=left[z];
            left[z]=tmp;
        }
    }//o(op)
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<matrix[left[i]][right[j]];
            if(m-1!=j){
                cout<<" ";
            }
        }
        cout<< endl;
    }//o(mn)
    return 0;
}