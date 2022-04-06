#include <queue>
#include <iostream>

using namespace std;

// 关联容器，C++STL的一种，底层容器是vector
// priority_queue称为优先级队列，又称之为堆

struct A{
    int x;
    int y;
    A(int a, int b):x(a), y(b){};

    // 在结构体内部重载比较函数
    // 成员函数可以使用const 
    // 在重载比较符的时候，参与比较的两个对象必须是常量，也即意味着重载方法中形式参数是常量，同时该方法是常函数。
    bool operator < (const A &a) const{
        return y < a.y;
    }
    // 必须同时重载大于和小于两个操作符
    bool operator > (const A &a) const{
        return y > a.y;
    }
};

struct B{
    int x;
    int y;
    B(int a, int b) : x(a), y(b){};
};

// 在结构体外面定义比较两个对象的函数
// 非成员函数上不允许使用const，常函数必须是类的，因为类才有自己的成员，别的没有。
bool operator < (const B &b1,const B &b2){
    return b1.x < b2.x;
}

bool operator > (const B &b1,const B &b2){
    return b1.x > b2.x;
} 

// 第三种重载方式
struct cmp{
    size_t operator () (const pair<int,int> &a,const pair<int,int> &b)const{
        return a.first < b.first;
    }
};

int main(){
    // 缺省构造模式
    priority_queue<int> que1;
    que1.push(1);
    que1.push(323);
    que1.push(32);
    // 缺省构造的优先级队列是一个大根堆
    cout << "默认优先级队列测试：" << endl;
    while(!que1.empty()){
        // 需要注意的是优先级队列中的元素都是常量，不能修改，所以想要修改需要删除后将修改的值插入。
        cout << que1.top() << " ";
        que1.pop();
    }
    cout << endl;

    // 完整构造模式为priority_queue<数据类型，vector<数据类型>, 比较函数>
    priority_queue<int, vector<int>, greater<int>> que2;//
    priority_queue<int, vector<int>, less<int>> que3;

    int a[] = {3, 45, 234, 234, 523, 26, 23, 4};
    for (int i = 0;i < 6; i ++) {
        que2.push(a[i]);
        que3.push(a[i]);
    }
    // 测试样例
    cout << "greater比较函数测试：" << endl;
    while(!que2.empty()){
        cout << que2.top() << " ";
        que2.pop();
    }
    cout << endl;

    cout << "less比较函数测试：" << endl;
    while(!que3.empty()){
        cout << que3.top() << " ";
        que3.pop();
    }
    cout << endl;

    // 自定义类型比较
    A a1(1, 55);
    A a2(34, 435);
    A a3(23, 1);
    priority_queue<A, vector<A>, greater<A>> que4;
    que4.push(a1);
    que4.push(a2);
    que4.push(a3);
    cout << "自定义结构体实现小根堆：" << endl;
    while(!que4.empty()){
        cout << que4.top().x << " " << que4.top().y << endl;
        que4.pop();
    }
    cout << endl;

    priority_queue<A, vector<A>, less<A>> que5;
    que5.push(a1);
    que5.push(a2);
    que5.push(a3);
    cout << "自定义结构体实现大根堆：" << endl;
    while(!que5.empty()){
        cout << que5.top().x << " " << que5.top().y << endl;
        que5.pop();
    }
    cout << endl;

    // 类外定义结构体对象比较函数的方式

    B b1(234, 1);
    B b2(23, 34);
    B b3(123, 4);
    priority_queue<B, vector<B>, greater<B>> que6;
    que6.push(b1);
    que6.push(b2);
    que6.push(b3);
    cout << "自定义结构体实现比较的第二种方式：" << endl;
    while(!que6.empty()){
        cout << que6.top().x << " " << que6.top().y << endl;
        que6.pop();
    }
    cout << endl;

    // 系统内置类型比较函数重载方法
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que7;
    que7.emplace(3, 4);
    que7.emplace(6, 34);
    que7.emplace(1, 234);
    cout << "系统内置函数默认比较函数测试：" << endl;
    while(!que7.empty()){
        cout << que7.top().first << " " << que7.top().second << endl;
        que7.pop();
    }
    cout << endl;

    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> que8;
    que8.emplace(234, 2);
    que8.emplace(23, 45);
    que8.emplace(345, 234);
    cout << "重载比较函数测试：" << endl;
    while(!que8.empty()){
        cout << que8.top().first << " " << que8.top().second << endl;
        que8.pop();
    }
    cout << endl;



    return 0;
}