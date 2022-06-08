#include <bits/stdc++.h>
using namespace std;

// 最经典的链表模拟
// 需要设置为双向链表
struct node
{
    char val;
    // 结构体里面初始化以后，避免了初始化时指针为随机值
    node *left = nullptr;
    node *right = nullptr;
    node(char x) : val(x){};
};
class TextEditor
{
public:
    // 虚拟头结点，避免边界判断
    node *root;
    // now指向待插入位置的前一个字符
    node *now;
    TextEditor()
    {
        root = new node('#');
        now = root;
    }

    void addText(string text)
    {
        // 插入
        for (int i = 0; i < text.size(); i++)
        {
            // 新建节点存储字符值
            node *p = new node(text[i]);
            p->right = now->right;
            now->right = p;
            if (p->right != nullptr)
            {
                p->right->left = p;
            }
            p->left = now;
            now = p;
        }
        return;
    }

    int deleteText(int k)
    {
        int d = k;
        for (; now != root && k; k--)
        {
            now->left->right = now->right;

            if (now->right != nullptr)
            {
                now->right->left = now->left;
            }
            node *p = now;
            now = now->left;
            delete p;
        }
        return d - k;
    }

    string cursorLeft(int k)
    {
        // 左移
        while (now != root && k)
        {
            now = now->left;
            k--;
        }
        // 输出结果
        node *p = now;
        string ans = "";
        for (int i = 10; p != root && i; i--, p = p->left)
        {
            ans = p->val + ans;
        }
        return ans;
    }

    string cursorRight(int k)
    {
        // 右移
        while (now->right != nullptr && k)
        {
            now = now->right;
            k--;
        }
        // 输出结果
        node *p = now;
        string ans = "";
        for (int i = 10; p != root && i; i--, p = p->left)
        {
            ans = p->val + ans;
        }
        return ans;
    }
};