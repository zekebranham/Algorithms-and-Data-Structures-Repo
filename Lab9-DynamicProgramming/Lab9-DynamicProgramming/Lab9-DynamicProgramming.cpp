#include <iostream>
#include <string>
#include <limits.h>
using namespace std;

int** allocate2DArray(int rows, int cols) {
    int** array = new int*[rows];
    for (int i = 0; i < rows; i++) {
        array[i] = new int[cols];
    }
    return array;
}

void deallocate2DArray(int** array, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] array[i];
    }
    delete[] array;
}


void print_opt_parens(int** s,int i,int j, char &name){
    if (i==j){
        cout<< name++;
        return;
    }
    cout<<"(";
    print_opt_parens(s,i,s[i][j],name);
    print_opt_parens(s,s[i][j]+1,j,name);
    cout<<")";
    return;
}

void matrix_chain_order(int p[], int n, int** m, int** s){
    //initialize matrix m and s
    for (int i=0; i<n; i++){
        m[i][i] = 0;
    }
    for (int L=2; L<n; L++){
        for (int i=0; i<((n-L));i++){
            int j = (i+L)-1;
            m[i][j] = INT_MAX;
            for (int k=i; k<=(j-1);k++){
                int q = m[i][k] + m[k + 1][j] + (p[i] * p[k + 1] * p[j + 1]);
                if (q<m[i][j]){
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
}

int main()
{
    int p[] = {10,20,30,40,20};
    int n = sizeof(p) / sizeof(p[0]);
    // int** m;
    // int** s;
    int** m = allocate2DArray(n, n);
    int** s = allocate2DArray(n, n);
    matrix_chain_order(p,n,m,s);
    char name = 'A';
    cout<<endl;
    cout<<"Optimal Parenthesization: ";
    print_opt_parens(s,0,n-2,name);
    cout<< " Optimal Cost: "<<m[0][n-2]<<endl;
    cout<<endl;
    deallocate2DArray(m, n);
    deallocate2DArray(s, n);


    return 0;
}

