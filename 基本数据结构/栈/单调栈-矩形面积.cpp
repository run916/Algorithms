#include<bits/stdc++.h>
using namespace std;
int main() {
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;
        long long h[n + 1];
        for (int i = 0; i < n; i++) scanf("%lld", & h[i]);
        h[n] = 0;
        stack < int > stack;
        stack.push(0);
        long long ans = 0;
        for (int i = 1; i <= n; i++) {
            if (h[stack.top()] < h[i]) {
                stack.push(i);
            } else {
                for (; !stack.empty() && h[stack.top()] >= h[i];) {
                    int k = stack.top();
                    stack.pop();
                    if (stack.empty()) ans = max(ans, h[k] * i);
                    else ans = max(ans, h[k] * (i - stack.top() - 1));
                }
                stack.push(i);
            }
        }
        cout << ans << endl;
    }
    return 0;
}