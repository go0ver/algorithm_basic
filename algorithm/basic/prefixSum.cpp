#include <stdio.h>
#include <iostream>
using namespace std;

const int N = 100010;
int main(){
    int n, q;
    cin >> n >> q;
    int arr[N], s[N];
    for(int i = 1; i <= n; i++)
        scanf("%d", &arr[i]);
    for(int i = 1; i <= n; i++)
        s[i] = s[i-1]+arr[i];
    while(q-- > 0){
        int l, r;
        cin >> l >> r;
        int res = s[r]-s[l-1];
        printf("%d\n", res);
    }
}