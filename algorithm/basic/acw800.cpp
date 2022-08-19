#include <iostream>
#include <stdio.h>
using namespace std;

const int N = 100010;

int main(){
    int n, m, x;
    int A[N], B[N];
    scanf("%d%d%d", &n, &m, &x);
    for(int i = 0; i < n; i++) scanf("%d", &A[i]);
    for(int j = 0; j < m; j++) scanf("%d", &B[j]);
    int i = 0, j = m-1;
    //指针不会回退，因此时间复杂度为o(n)
    for(i; i < n; i++){
        while(j > 0 && A[i]+B[j] > x){ j--; }
        if(A[i]+B[j] == x) printf("%d %d", i, j);
    }
    return 0;
}
