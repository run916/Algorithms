// 简单介绍一下题意
// 对于一个数组，求解其第k大的子区间的和。
// 例如对于区间[1 2 3]来说，其子区间分别是[1] [2] [3] [1 2] [2 3] [1 2 3]对应的子区间的和分别是1 2 3 3 5 6，对于给定的k找到对应的元素即可

// 本题的思路是采用二分+滑动窗口的思想求解，需要仔细体会该技巧的一些细节。
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int num[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }
    //二分值，滑动窗口动态调整，滑动窗口变化的过程中统计小于当前二分的值的数目。
    long long l = 1;
    long long r = 10000000000;
    // 需要注意如果单个元素大于二分的元素时的情况
    while (l <= r) {
        int m = (l + r) / 2;
        long long sum = 0;
        long long now = 0;
        int pre = -1;
        // 哪里出了点问题呢？
        for (int i = 0; i < n; i++) {
            // 先将窗口左端点右移
            while (now + num[i] > m && now != 0) {
                now -= num[pre + 1];
                pre++;
            }
            // 这里要考虑什么问题呢？
            // 如果now==0；
            if (now == 0) {
                // 分两种情况，单个元素满足条件和单个元素不满足条件
                if (now + num[i] > m) {
                    pre++;
                } else {
                    now += num[i];
                }
            } else {
                now += num[i];
            }
            sum += i - pre;
        }
        if (sum < k) {
            // 如果小于m的值小于k个，此时应该扩大m
            l = m + 1;
        } else {
            // 如果小于m的值大于等于k个，此时应该缩小m
            r = m - 1;
        }
    }
    cout << l;
    return 0;
}

// 堆实现的验证方法，可以用来验证二分+判定思想的实现是否是正确的

void check() {
    int n, k;
    cin >> n >> k;
    priority_queue<pair<int, int>> que;
    int num[n];
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    for (int i = 0; i < n; i++) {
        que.emplace(-num[i], i * 1000 + i);
    }
    while (!que.empty()) {
        if (k == 1)
            break;
        k--;
        int l = que.top().second / 1000;
        int r = que.top().second % 1000;
        int now = que.top().first;
        cout << -now << " ";
        que.pop();
        if (l - 1 >= 0) {
            que.emplace(now - num[l - 1], (l - 1) * 1000 + r);
        }
    }
    cout << -que.top().first;
    return;
}