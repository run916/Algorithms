#include<bits/stdc++.h>
using namespace std;

//树结构
const int N = 100010;
int edge[N];
int nest[N];
int last[N];
int cnt;

//建立字典树
int trie[N * 20][2];
int cmt;        //字典树根节点为1
int en[N * 20]; //确定经过该点的字符串数目
class Solution
{
public:
    //构建树结构
    void add(int u, int v)
    {
        edge[cnt] = v;
        nest[cnt] = last[u];
        last[u] = cnt;
        cnt++;
        return;
    }
    //字典树插入
    void insert(int n)
    {
        bitset<20> t = n;
        int p = 1;
        for (int i = 19; i >= 0; i--)
        {
            int ch = t[i];
            if (trie[p][ch] == 0)
            {
                trie[p][ch] = ++cmt;
            }
            p = trie[p][ch];
            en[p]++;
        }
        return;
    }
    //字典树删除
    void del(int n)
    {
        bitset<20> t = n;
        int p = 1;
        for (int i = 19; i >= 0; i--)
        {
            int ch = t[i];
            p = trie[p][ch];
            en[p] -= 1;
        }
        return;
    }
    //查询最大值
    int query(int n)
    {
        bitset<20> t = n ^ ((1 << 20) - 1);
        int p = 1;
        bitset<20> ans;
        for (int i = 19; i >= 0; i--)
        {
            int ch = t[i];
            if (trie[p][ch] && en[trie[p][ch]])
            {
                ans[i] = ch;
                p = trie[p][ch];
            }
            else
            {
                ans[i] = ch ^ 1;
                p = trie[p][ch ^ 1];
            }
        }
        return ans.to_ulong();
    }
    vector<int> ans;                  //答案数组
    vector<vector<pair<int, int>>> q; //查询数组
    void dfs(int k)
    {
        insert(k); //先插入节点
        for (int i = 0; i < q[k].size(); i++)
        {
            ans[q[k][i].first] = query(q[k][i].second) ^ q[k][i].second;
        }
        //遍历
        for (int i = last[k]; i; i = nest[i])
        {
            dfs(edge[i]);
        }
        del(k); //查询结束后，顺便删除元素
        return;
    }
    vector<int> maxGeneticDifference(vector<int> &parents, vector<vector<int>> &queries)
    {
        //dfs+字典树
        cnt = 1;
        cmt = 1;
        memset(trie, 0, sizeof(trie));
        memset(en, 0, sizeof(en));
        memset(last, 0, sizeof(last));
        int n = parents.size();
        int root;
        for (int i = 0; i < n; i++)
        {
            if (parents[i] == -1)
            {
                root = i;
                continue;
            }
            else
            {
                add(parents[i], i);
            }
        }
        int m = queries.size();
        ans = vector<int>(m);
        q = vector<vector<pair<int, int>>>(n);
        for (int i = 0; i < m; i++)
        {
            q[queries[i][0]].emplace_back(i, queries[i][1]);
        }
        dfs(root);
        return ans;
    }
};