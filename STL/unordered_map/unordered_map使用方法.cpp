#include<bits/stdc++.h>
using namespace std;

// ���ܽ���unordered_map��һЩ�÷�

// ������ʽ

// ����һ��unordered_map����
unordered_map<int,int> has;

// ��Ҫ����ɢ�б���ص�֪ʶ
void introduce(){
    // unordered_map�ĵײ�ṹ�ǹ�ϣ��Ҳ��Ϊɢ�б�
    // unordered_mapʹ�ÿ�ɢ�з�ʽ�������ϣ��ͻ��Ҳ���ǹ�ϣֵ��ͬ�ķŵ�ͬһ���ڽ������д���
    // �����ϣ��ͻ�����ַ�ʽ
    // �ٱ�ɢ�з����ֳ�֮Ϊ���ŵ�ַ��������˼�壬���ÿ��ŵ�ַ������ɢ�г�ͻ��ɢ�б��У�һ��Ԫ�ؿ���λ��ɢ�б��ж��λ�õķ���
    // �ڿ�ɢ�з����ֳ�֮Ϊ��������Ҳ����unordered_map��ʹ�õĴ���ɢ�г�ͻ�ķ�����ɢ�б���ÿһ��λ�ò����洢������Ԫ�أ���������һ������
    // �����д洢�˹�ϣֵ��ͬ������Ԫ�ء�    
}

// ���Ԫ�صļ��ַ�ʽ
void add(){
    // ֱ�Ӳ�������
    has.insert({4,12});
    // ����һ��pair����
    has.insert(make_pair(39,23));
    // ֱ�����±귽ʽ��ʽ���Ԫ��
    has[7]=234;
    return ;
}

// �����ļ��ַ�ʽ
void traverse(){
    cout<<"ֵ���������ʽ��"<<endl;
    for(pair<int,int> k:has){
        cout<<k.first<<" "<<k.second<<endl;
    }
    for(auto k:has){
        cout<<k.first<<" "<<k.second<<endl;
    }
    cout<<"���ô��������ʽ��"<<endl;
    for(const pair<int,int>& k:has){// ��������Ҫʹ�ó����������������
        cout<<k.first<<" "<<k.second<<endl;
    }
    for(auto& x:has){
        cout<<x.first<<" "<<x.second<<endl;
    }
    cout<<"�����������ʽ�� "<<endl;
    for(unordered_map<int,int>::iterator iter=has.begin();iter!=has.end();++iter){
        cout<<iter->first<<" "<<iter->second<<endl;
    }
    for(auto iter=has.begin();iter!=has.end();++iter){
        cout<<iter->first<<" "<<iter->second<<endl;
    }
}

//  �ж�Ԫ���Ƿ����
void judge(){
    // �ж�Ԫ���Ƿ������Ҫ�����ַ�ʽ�����õ�����count�жϣ�count�ж��ǲ�������Ԫ��
    // ��ϣ�����г�ʼ����ֵ����0
    if(has.count(4)){
        cout<<"4�ڹ�ϣ�б���"<<endl;
    }else{
        cout<<"4���ڹ�ϣ�б���"<<endl;
    }
    if(has.find(3)!=has.end()){
        cout<<"3�ڹ�ϣ�б���"<<endl;
    }else{
        cout<<"3���ڹ�ϣ�б���"<<endl;
    }
    return ;
}

struct pair_hash{
    size_t operator () (const pair<int,int> &key) const{// ����+���ã����ٸ��ƹ���������Ż�����
        // ���ع�ϣ���������Զ���ṹ����߱���ת����һֱ�Ĺ�ϣ����������ͨ��Ϊ�˱����ϣ��ͻ��ת�����ַ�����ϣ����
        string str=to_string(key.first)+to_string(key.second);
        return hash<string>()(str);
    }
};
unordered_map<pair<int,int>,int,pair_hash> pa;

int main(){
    add();
    judge();
    traverse();
    // �Զ����ϣ����

    // �Զ����ϣ�����ļ������Ԫ�صķ�ʽ
    pa.insert({{1,2},1});
    pa.insert({make_pair(3,4),4});
    pa[make_pair(3,5)]=54;
    pa[{1,5}]=24523;
    // ����������ע���Զ������͵ı�����ʽ����Ҫ�Լ����������ʽ
    for(auto& k:pa){
        cout<<"<"<<k.first.first<<","<<k.first.second<<"> "<<k.second<<endl;
    }
    return 0;
}
