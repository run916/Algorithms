#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    long long maximumBeauty(vector<int>& flowers, long long newFlowers, int target, int full, int partial) {
        long long n = flowers.size();
        vector<int> num;
        // 先将不影响结果的值排除
        long long ans = 0;
        for (int i = 0; i < n; i ++){
            if(flowers[i]>=target){
                ans += full;
            }else{
                num.push_back(flowers[i]);
            }
        }
        // 将预处理后的数组排序，便于后续二分查找
        n = num.size();
        if(n==0){
            return ans;
        }
        sort(num.begin(), num.end());
        long long sum[n + 1];
        sum[0] = 0;
        for (int i = 0;i<n;i++){
            sum[i + 1] = sum[i] + num[i];
        }
        // 将花朵数目从最少到最多开始遍历
        long long tmp = 0;
        for (int i = num[0]; i < target; i++){
            // 先二分查找，找到num数组中第一个大于i的值
            int l = 0, r = n - 1;
            while(l<=r){
                int m = (l + r) / 2;
                if(num[m]>=i){
                    r = m - 1;
                }else{
                    l = m + 1;
                }
            }
            // 计算出将num数组中最小值变成i最少需要种多少花
            long long a = (long long)newFlowers - (long long)i * l + sum[l];
            // 如果剩余可种的花数目小于0，那么不需要继续往下做了
            if(a<0){
                break;
            }
            int cnt = l;
            l = 0, r = n - 1;
            while(l<=r){
                int m = (l + r) / 2;
                long long v = (m <= cnt ? sum[n] - sum[cnt] + (long long)(cnt - m) * i + a:sum[n]-sum[m]+a);
                if(v>=(long long)(n-m)*target){
                    r = m - 1;
                }else{
                    l = m + 1;
                }
            }
            // 求解这花园种的花朵数目最小值为i时，花园的最大魅力值。
            tmp = max(tmp, (long long)i * partial + (l == 0 ? (long long)(n - 1) : (long long)(n - l)) * full);      
        }
        // 最后考虑每一个花园的花朵数目都大于等于target的情况
        if (sum[n] + newFlowers >= (long long)n * target){
            tmp = max(tmp, (long long)n * full);
        }
        return ans + tmp;
    }

};