#include<bits/stdc++.h>

using namespace std;

struct node {
    int val;
    // 建议写实现结构体时，将指针的值初始化，避免指针值不为空
    node * next = nullptr;
    // 构造函数
    node(int x): val(x) {};
    node(int x, node * p): val(x), next(p) {};
};

int main() {
    // 测试
    // 建立一个链表
    node *root = new node(2);
    node *head = root;
    node *p = new node(4);
    head -> next = p;
    for (node *i = root; i != nullptr; i = i -> next) {
        cout << i -> val << endl;
    }
    return 0;
}