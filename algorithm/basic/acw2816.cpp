#include<stdio.h>
#include<iostream>
using namespace std;

int N = 100010;
int main(){
    int a[N], b[N], n, m;
    int i = 0, j = 0;
    cin >> n >> m;
    for(i; i < n; i++)
        cin >> a[i];
    for(j; j < m; j++)
        cin >> b[j];
    i = 0, j = 0;
    for(j; j < m&&i < n; j++){
        if(a[i] == b[j]){
            i++;
        }
    }
    if(i == n)
        cout << "Yes";
    else
        cout << "No";
}