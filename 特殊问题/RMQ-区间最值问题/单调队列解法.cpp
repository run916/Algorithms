#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector < int > num(n);
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    // 滑动窗口求解区间最值
    deque < int > maxque;
    deque < int > minque;
    for (int i = 0; i < n; i++) {
        // 插入元素前有两个操作，假设单调队列中维持的区间最优值在头部
        // 把下标不符合要求的元素删除
        for (; !maxque.empty() && maxque.front() <= i - k;) {
            maxque.pop_front();
        }
        for (; !minque.empty() && minque.front() <= i - k;) {
            minque.pop_front();
        }
        // 插入之前要把尾部不满足单调性约束的下标删除
        for (; !maxque.empty() && num[maxque.back()] < num[i];) {
            maxque.pop_back();
        }
        for (; !minque.empty() && num[minque.back()] > num[i];) {
            minque.pop_back();
        }
        // 插入元素
        maxque.push_back(i);
        minque.push_back(i);
        if (i >= k - 1) {
            cout << num[maxque.front()] << " ";
            cout << num[minque.front()] << endl;
        }
    }
    return 0;
}