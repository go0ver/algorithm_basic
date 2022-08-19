#include <stdio.h>
#include <iostream>

using namespace std;
int N = 100010;
int main(void){
    int a[N], s[N], n, m;
    int l, r, c;
    a[0] = 0;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        s[i] = a[i]-a[i-1];
    }
    for(int k = 0; k < m; k++){
        scanf("%d%d%d", &l, &r, &c);
        s[l]+=c;s[r+1]-=c;
    }
    for(int j = 1; j <= n; j++){
        s[j] = s[j]+s[j-1];
        printf("%d ", s[j]);
    }
}