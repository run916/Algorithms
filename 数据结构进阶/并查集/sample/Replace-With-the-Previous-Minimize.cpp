// https://codeforces.com/contest/1675/problem/E
#include<bits/stdc++.h>

using namespace std;

const int N = 200100;
int fa[N];

int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) {
        return;
    }
    fa[x] = y;
    return;
}

int main() {
    int t;
    cin >> t;
    string s;
    while (t--) {
        int n, k;
        cin >> n >> k;
        cin >> s;
        if (k >= 26) {
            string str(s.length(), 'a');
            cout << str << endl;
            continue;
        }
        // initial
        for (int i = 0; i < s.length(); i++) {
            int d = s[i] - 'a';
            fa[i] = 200010 + d;
        }
        for (int i = 200010; i < 200010 + 26; i++) {
            fa[i] = i;
        }
        // modify
        for (int i = 0; i < n; i++) {
            int d = s[i] - 'a';
            char c = s[i];
            while (d) {
                if (find(200010 + d) == 200010) {
                    break;
                }
                fa[200010 + d] = find(200010 + d - 1);
                d--;
                k--;
                if (k == 0) {
                    break;
                }
            }
            if (k == 0) {
                break;
            }
        }
        // print
        for (int i = 0; i < n; i++) {
            s[i] = find(i) - 200010 + 'a';
        }
        cout << s << endl;
    }
}