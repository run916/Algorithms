#include<bits/stdc++.h>
using namespace std;

// 简单总结了unordered_map的一些用法

// 遍历方式

// 声明一个unordered_map容器
unordered_map<int,int> has;

// 简要介绍散列表相关的知识
void introduce(){
    // unordered_map的底层结构是哈希表（也称为散列表）
    // unordered_map使用开散列方式来处理哈希冲突，也就是哈希值相同的放到同一个邻接链表中处理。
    // 处理哈希冲突有两种方式
    // ①闭散列法，又称之为开放地址法，顾名思义，采用开放地址法处理散列冲突的散列表中，一个元素可以位于散列表中多个位置的方法
    // ②开散列法，又称之为拉链法，也就是unordered_map中使用的处理散列冲突的方法，散列表中每一个位置并不存储真正的元素，而是拉出一个链表
    // 链表中存储了哈希值相同的所有元素。    
}

// 添加元素的几种方式
void add(){
    // 直接插入数组
    has.insert({4,12});
    // 插入一个pair对象
    has.insert(make_pair(39,23));
    // 直接用下标方式方式添加元素
    has[7]=234;
    return ;
}

// 遍历的几种方式
void traverse(){
    cout<<"值传递输出方式："<<endl;
    for(pair<int,int> k:has){
        cout<<k.first<<" "<<k.second<<endl;
    }
    for(auto k:has){
        cout<<k.first<<" "<<k.second<<endl;
    }
    cout<<"引用传递输出方式："<<endl;
    for(const pair<int,int>& k:has){// 引用这里要使用常量，避免更改数据
        cout<<k.first<<" "<<k.second<<endl;
    }
    for(auto& x:has){
        cout<<x.first<<" "<<x.second<<endl;
    }
    cout<<"迭代器输出方式： "<<endl;
    for(unordered_map<int,int>::iterator iter=has.begin();iter!=has.end();++iter){
        cout<<iter->first<<" "<<iter->second<<endl;
    }
    for(auto iter=has.begin();iter!=has.end();++iter){
        cout<<iter->first<<" "<<iter->second<<endl;
    }
}

struct pair_hash{
    size_t operator () (const pair<int,int> &key) const{// 常量+引用，减少复制构造次数，优化代码
        // 重载哈希函数，将自定义结构体或者变量转化到一直的哈希函数上来，通常为了避免哈希冲突会转化到字符串哈希上来
        string str=to_string(key.first)+to_string(key.second);
        return hash<string>()(str);
    }
};
unordered_map<pair<int,int>,int,pair_hash> pa;

int main(){
    add();
    traverse();
    // 自定义哈希函数

    // 自定义哈希函数的几种添加元素的方式
    pa.insert({{1,2},1});
    pa.insert({make_pair(3,4),4});
    pa[make_pair(3,5)]=54;
    pa[{1,5}]=24523;
    // 遍历，这里注意自定义类型的遍历方式，需要自己定义遍历方式
    for(auto& k:pa){
        cout<<"<"<<k.first.first<<","<<k.first.second<<"> "<<k.second<<endl;
    }
    return 0;
}
