// #include <iostream>
// #include <stdlib.h>
// using namespace std;

// const int N =100010;
// void merge_sort(int *a, int l, int r){
//     if(l >= r) return;
//     int mid = l+r>>1;
//     merge_sort(a, l, mid);merge_sort(a, mid+1, r);
//     int i=l, j=mid+1,k=0;
//     int tmp[r-l+1];
//     while(i <= mid && j <= r){
//         if(a[i]<a[j]) tmp[k++] = a[i++];
//         else tmp[k++] = a[j++];
//     }
//     while(i <= mid) tmp[k++] = a[i++];
//     while(j <= r) tmp[k++] = a[j++];
//     for(i = l, k = 0;i <= r; i++, k++) a[i] = tmp[k];
// }
// int main(){
//     int n = 0;
//     scanf("%d", &n);
//     int arr[N];
//     for(int i = 0; i < n; i++)
//         scanf("%d", &arr[i]);
//     merge_sort(arr, 0, n-1);
//     for (int i = 0; i < n; i++)
//         printf("%d ", arr[i]);
//     return 0;
// }

#include <stdio.h>
#include <iostream>

using namespace std;

const int N = 100010;
void merge_sort(int a[], int l, int r){
    if(l >= r) return;
    int mid = l + r >> 1;
    int i = l, j = mid + 1;
    merge_sort(a, i, mid);merge_sort(a, j, r);
    int tmp[r-l+1];
    int k = 0;
    while(i <= mid && j <= r){
        if(a[i] < a[j]) tmp[k++] = a[i++];
        else tmp[k++] = a[j++];
    }
    while(i <= mid) tmp[k++] = a[i++];
    while(j <= r) tmp[k++] = a[j++];
    for(i = 0, j = l; j <= r; i++, j++) a[j] = tmp[i];
}

int main(){
    int a[N], n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    merge_sort(a, 0, n-1);
    for(int i = 0; i< n; i++){
        printf("%d ", a[i]);
    }
}