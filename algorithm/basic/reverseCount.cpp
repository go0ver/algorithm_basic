#include <stdio.h>

using namespace std;
//如果左半边最小的这个元素（最左边）都比右半边元素中的某个要大，则说明从 左半边这个元素到mid为止的所有元素都比右边要大
const int N = 100010;
unsigned long res = 0;//记录结果
void reverseCount(int a[], int l, int r){
    if(l >= r) return;
    int mid = l + r >> 1;
    int i = l, j = mid + 1, k = 0;
    int tmp[r-l+1];
    reverseCount(a, i, mid);reverseCount(a, j, r);
    while(i <= mid && j <= r){
        if(a[i] <= a[j]) 
            tmp[k++] = a[i++];
        else {
            tmp[k++] = a[j++];
            //归并排序时左右两半边都已经有序且统计完毕，所以不用考虑单独左边的逆序对情况
            res += mid-i+1;
        }
    }
    while(i <= mid) tmp[k++] = a[i++];
    while(j <= r) tmp[k++] = a[j++];
    for(k = 0, i = l; i <= r; i++, k++){
        a[i] = tmp[k];
    }
    
}
int main() {
    int n = 0;
    int a[N];
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    reverseCount(a, 0, n-1);
    printf("%lld", res);
}