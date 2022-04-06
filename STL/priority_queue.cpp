#include <queue>
#include <iostream>

using namespace std;

// ����������C++STL��һ�֣��ײ�������vector
// priority_queue��Ϊ���ȼ����У��ֳ�֮Ϊ��

struct A{
    int x;
    int y;
    A(int a, int b):x(a), y(b){};

    // �ڽṹ���ڲ����رȽϺ���
    // ��Ա��������ʹ��const 
    // �����رȽϷ���ʱ�򣬲���Ƚϵ�������������ǳ�����Ҳ����ζ�����ط�������ʽ�����ǳ�����ͬʱ�÷����ǳ�������
    bool operator < (const A &a) const{
        return y < a.y;
    }
    // ����ͬʱ���ش��ں�С������������
    bool operator > (const A &a) const{
        return y > a.y;
    }
};

struct B{
    int x;
    int y;
    B(int a, int b) : x(a), y(b){};
};

// �ڽṹ�����涨��Ƚ���������ĺ���
// �ǳ�Ա�����ϲ�����ʹ��const����������������ģ���Ϊ������Լ��ĳ�Ա�����û�С�
bool operator < (const B &b1,const B &b2){
    return b1.x < b2.x;
}

bool operator > (const B &b1,const B &b2){
    return b1.x > b2.x;
} 

// ���������ط�ʽ
struct cmp{
    size_t operator () (const pair<int,int> &a,const pair<int,int> &b)const{
        return a.first < b.first;
    }
};

int main(){
    // ȱʡ����ģʽ
    priority_queue<int> que1;
    que1.push(1);
    que1.push(323);
    que1.push(32);
    // ȱʡ��������ȼ�������һ�������
    cout << "Ĭ�����ȼ����в��ԣ�" << endl;
    while(!que1.empty()){
        // ��Ҫע��������ȼ������е�Ԫ�ض��ǳ����������޸ģ�������Ҫ�޸���Ҫɾ�����޸ĵ�ֵ���롣
        cout << que1.top() << " ";
        que1.pop();
    }
    cout << endl;

    // ��������ģʽΪpriority_queue<�������ͣ�vector<��������>, �ȽϺ���>
    priority_queue<int, vector<int>, greater<int>> que2;//
    priority_queue<int, vector<int>, less<int>> que3;

    int a[] = {3, 45, 234, 234, 523, 26, 23, 4};
    for (int i = 0;i < 6; i ++) {
        que2.push(a[i]);
        que3.push(a[i]);
    }
    // ��������
    cout << "greater�ȽϺ������ԣ�" << endl;
    while(!que2.empty()){
        cout << que2.top() << " ";
        que2.pop();
    }
    cout << endl;

    cout << "less�ȽϺ������ԣ�" << endl;
    while(!que3.empty()){
        cout << que3.top() << " ";
        que3.pop();
    }
    cout << endl;

    // �Զ������ͱȽ�
    A a1(1, 55);
    A a2(34, 435);
    A a3(23, 1);
    priority_queue<A, vector<A>, greater<A>> que4;
    que4.push(a1);
    que4.push(a2);
    que4.push(a3);
    cout << "�Զ���ṹ��ʵ��С���ѣ�" << endl;
    while(!que4.empty()){
        cout << que4.top().x << " " << que4.top().y << endl;
        que4.pop();
    }
    cout << endl;

    priority_queue<A, vector<A>, less<A>> que5;
    que5.push(a1);
    que5.push(a2);
    que5.push(a3);
    cout << "�Զ���ṹ��ʵ�ִ���ѣ�" << endl;
    while(!que5.empty()){
        cout << que5.top().x << " " << que5.top().y << endl;
        que5.pop();
    }
    cout << endl;

    // ���ⶨ��ṹ�����ȽϺ����ķ�ʽ

    B b1(234, 1);
    B b2(23, 34);
    B b3(123, 4);
    priority_queue<B, vector<B>, greater<B>> que6;
    que6.push(b1);
    que6.push(b2);
    que6.push(b3);
    cout << "�Զ���ṹ��ʵ�ֱȽϵĵڶ��ַ�ʽ��" << endl;
    while(!que6.empty()){
        cout << que6.top().x << " " << que6.top().y << endl;
        que6.pop();
    }
    cout << endl;

    // ϵͳ�������ͱȽϺ������ط���
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que7;
    que7.emplace(3, 4);
    que7.emplace(6, 34);
    que7.emplace(1, 234);
    cout << "ϵͳ���ú���Ĭ�ϱȽϺ������ԣ�" << endl;
    while(!que7.empty()){
        cout << que7.top().first << " " << que7.top().second << endl;
        que7.pop();
    }
    cout << endl;

    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> que8;
    que8.emplace(234, 2);
    que8.emplace(23, 45);
    que8.emplace(345, 234);
    cout << "���رȽϺ������ԣ�" << endl;
    while(!que8.empty()){
        cout << que8.top().first << " " << que8.top().second << endl;
        que8.pop();
    }
    cout << endl;



    return 0;
}