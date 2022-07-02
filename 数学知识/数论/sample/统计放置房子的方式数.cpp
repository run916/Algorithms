#include<bits/stdc++.h>

using namespace std;

// https://leetcode.cn/problems/count-number-of-ways-to-place-houses/

class Solution {
    public:
        int mod = 1e9 + 7;
    long long fac[10010];
    // 快速幂
    long long pow(long long a, long long b, long long mod) {
        long long ans = 1;
        for (; b; b >>= 1) {
            if (b & 1) {
                ans = ans * a % mod;
            }
            a = a * a % mod;
        }
        return ans % mod;
    }
    // 求解组合数时要用到费马小定理，也即快速求解乘法逆元
    // 乘法逆元为
    int C(int n, int k) {
        return fac[n] * pow(fac[k] * fac[n - k] % mod, mod - 2, mod) % mod;
    }
    int countHousePlacements(int n) {
        // 排列组合，我们分配考虑选取0,1,2...n/2个元素时的数目
        fac[0] = 1;
        for (int i = 1; i < 10010; i++) {
            fac[i] = fac[i - 1] * i % mod;
        }
        // 求解
        long long ans = 0;
        for (int i = 0; i <= (n + 1) / 2; i++) {
            ans += C(n - i + 1, i);
            ans %= mod;
        }
        return ans * ans % mod;
    }
};