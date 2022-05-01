#include<bits/stdc++.h>
// https://leetcode-cn.com/problems/minimum-consecutive-cards-to-pick-up/
using namespace std;

// 简单来说，我们用一个哈希数组记录前一个相同元素所在的位置，这样我们就可以快速求解出可以快速找到相邻相同元素所在的区间。
// 最优性结构保证了，最小的区间一定包括在所有区间内，我们只需要比较当期最小与现在遍历区间中的较小值作为当前最小值即可。

class Solution {
    public:
        int minimumCardPickup(vector < int > & cards) {
            // 滑动窗口
            int vise[1000010];
            memset(vise, -1, sizeof(vise));
            int ans = INT_MAX;
            int n = cards.size();
            for (int i = 0; i < n; i++) {
                if (vise[cards[i]] >= 0) {
                    ans = min(ans, i - vise[cards[i]] + 1);

                }
                vise[cards[i]] = i;
            }
            if (ans > 1e8) {
                return -1;
            }
            return ans;

        }
};