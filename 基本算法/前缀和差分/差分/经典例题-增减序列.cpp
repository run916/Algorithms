// https://www.acwing.com/problem/content/102/
#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int b[n];
    for (int i = 1; i < n; i++) {
        b[i] = a[i] - a[i - 1];
    }
    // 分别统计差分值为正数和负数的两个位置，然后操作
    long long negative = 0;
    long long positive = 0;
    for (int i = 1; i < n; i++) {
        if (b[i] < 0) {
            negative += b[i];
        } else {
            positive += b[i];
        }
    }
    // 两者里面的较大值就是要调整的次数
    cout << max(positive, -negative) << endl;
    // 两者的差值绝对值加1就是最终结果
    cout << abs(positive + negative) + 1 << endl;
    return 0;
}