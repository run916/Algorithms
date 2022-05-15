#include<bits/stdc++.h>
// https://leetcode.cn/problems/count-integers-in-intervals/submissions/

using namespace std;

class CountIntervals {
    public:
        // map?
        map < int, int > tmap;
    int sum;
    CountIntervals() {
        sum = 0;
    }

    void add(int left, int right) {
        if (tmap.empty()) {
            tmap.emplace(left, right);
            sum += right - left + 1;
            return;
        }
        // 查找
        // 查找严格包含的区间，删除元素
        map < int, int > ::iterator l = tmap.upper_bound(left);
        map < int, int > ::iterator r = tmap.upper_bound(right);
        // 右边的区间右端点大于right，说明需要更新区间
        if (r != tmap.begin()) --r;
        // 判断是否在已有的区间内部，如果是则直接跳出
        if (r -> first <= left && r -> second >= right) {
            return;
        }
        // 如果r的右端点覆盖了right，则r也要删除
        if (r -> second <= right) ++r;
        for (; l != r;) {
            // 注意迭代器的删除
            sum -= (l -> second - l -> first + 1);
            auto x = l;
            ++l;
            tmap.erase(x);
        }
        // 更新新的区间
        l = tmap.upper_bound(left);
        r = tmap.upper_bound(right);
        // 新的区间左端点
        int a = left;
        if (l != tmap.begin()) {
            --l;
            // l的左端点一定小于left
            if (l -> second + 1 >= left && l -> first <= left) {
                sum -= l -> second - l -> first + 1;
                a = l -> first;
                tmap.erase(l);
            }
        }
        // 新的区间右端点
        int b = right;
        if (r != tmap.begin()) {
            --r;
            // r的左端点一定小于right
            if (r -> second >= right) {
                sum -= r->second - r -> first + 1;
                b = r -> second;
                tmap.erase(r);
            }
        }
        // 更新值
        sum += b - a + 1;
        // 插入区间
        tmap.emplace(a, b);
        return;
    }

    int count() {
        return sum;
    }
};