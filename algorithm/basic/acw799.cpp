# include <iostream>
using namespace std;

const int N = 100010;
int a[N], s[N];

int main(){
    int n, r = 0;
    cin >> n;
    for (int i = 0, j = 0; i < n; i++){
        cin >> a[i];
        s[a[i]]++;
        while(s[a[i]] > 1) s[a[j++]]--;
        r = max(r, i-j+1);
    }
    cout << r;
    return 0;
}