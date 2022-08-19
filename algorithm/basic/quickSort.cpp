// #include <stdio.h>
// using namespace std;
// const int N = 100010;
// void quick_sort(int *a, int l, int r){
//     if(l >= r) return;
//     int i = l-1,j = r+1;
//     int bm = a[i+j>>1];
//     while(i < j){
//         do i++; while(a[i]<bm);
//         do j--; while(a[j]>bm);
//         if(i < j){
//             int tmp = a[i];
//             a[i] = a[j];
//             a[j] = tmp;
//         }
//     }
//     quick_sort(a, l, j);quick_sort(a, j+1, r);

// }

// int main(){
//     int n = 0;
//     scanf("%d", &n);
//     int arr[N];
//     for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
//     quick_sort(arr, 0, n-1);
//     for(int i = 0; i < n; i++) printf("%d ", arr[i]);
// }

#include <stdio.h>

using namespace std;

const int N = 100010;
void quick_sort(int a[], int l, int r){
    if(l >= r) return;
    int i = l-1, j = r+1;
    int bm = a[l+r>>1];
    //为什么要先移动指针再比较，而不是先比较再移动指针?
    //答：因为先比较再移动指针时，当交换数据时，实际上是在交换最后一次比较后两个指针的下一个
    while(i < j){
        while(a[++i] < bm);
        while(a[--j] > bm);
        if(i < j){
            int tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
        }
    }
    quick_sort(a, l, j);
    quick_sort(a, j+1, r);
}
int main(){
    int arr[N], n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    quick_sort(arr, 0, n-1);
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
}