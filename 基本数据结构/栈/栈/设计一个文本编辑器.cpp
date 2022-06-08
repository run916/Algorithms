#include<bits/stdc++.h>

using namespace std;

// https://leetcode.cn/problems/design-a-text-editor/

class TextEditor {
    public:
        // 考虑到数据范围中k的取值有限，所以主要在于插入和删除的时间复杂度如何降低。
        // 显然我们可以用链表的思想去做
        // 具体的，因为要维持当前光标的位置，所以我们很容易想到类似于中位数求解的一种思路
        // 这里我们可以用两个栈来模拟光标处的操作
        stack < char > s;
        stack < char > v;
        TextEditor() {

        }

        void addText(string text) {
            // 插入元素
            for (int i = 0; i < text.length(); i++) {
                s.push(text[i]);
            }
            return;
        }

        int deleteText(int k) {
            int l = s.size();
            while (!s.empty() && k) {
                k--;
                s.pop();
            }
            return l - s.size();
        }

        string cursorLeft(int k) {
            // 左移
            for (; k && !s.empty(); k--) {
                v.push(s.top());
                s.pop();
            }
            string ans = "";
            for (int i = 0; i < 10 && !s.empty(); i++) {
                ans = s.top() + ans;
                s.pop();
            }
            for (int i = 0; i < ans.length(); i++) {
                s.push(ans[i]);
            }
            return ans;
        }

        string cursorRight(int k) {
            // 右移
            for (; k && !v.empty(); k--) {
                s.push(v.top());
                v.pop();
            }
            string ans = "";
            for (int i = 0; i < 10 && !s.empty(); i++) {
                ans = s.top() + ans;
                s.pop();
            }
            for (int i = 0; i < ans.length(); i++) {
                s.push(ans[i]);
            }
            return ans;

        }
};