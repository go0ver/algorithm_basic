#include <iostream>
#include <stdio.h>

using namespace std;

const int N = 100010;

void binary_search(int a[], int k, int n){
    //要找到不小于k的第一个值和最后一个值
    int l = 0, r = n-1, mid;
    while(l < r){
        mid = l + r >> 1;
        if(a[mid] < k){
            //更新l的判断条件，由于是找左边界，因此只要mid值小于k就更新l
            //如果小于等于还继续查找会不停向右移动区间最后找到右边界
            //边界条件：当l和r距离差1的时候，可能会出现指针不更新的情况，使l永远小于r，死循环
            l = mid + 1;
        } else {
            //r的值是l+r >> 1向下取整，r和l相差1的时候能保证r的值更新
            r = mid;
        }
    }
    if(a[l] != k){
        printf("-1 -1\n");
    }
    else{
        printf("%d ", l);
        l = 0, r = n-1;
        while(l < r){
            mid = l + r + 1 >> 1;
            if(a[mid] > k) {
                r = mid - 1;
            }
            else{
                //l的值会更新成 l + r >> 1向上取整，r和l相差1的时候能保证l的值更新
                l = mid;
            }
        }
        printf("%d\n", r);
    }
}

int main(){
    //数组长度,搜索次数,搜索关键字
    int n, q, k;
    int a[N];
    scanf("%d%d", &n, &q);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for(int i = 0; i < q; i++){
        scanf("%d", &k);
        binary_search(a, k, n);
    }
}