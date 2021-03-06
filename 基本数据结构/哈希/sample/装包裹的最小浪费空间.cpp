class Solution
{
public:
    int minWastedSpace(vector<int> &packages, vector<vector<int>> &boxes)
    {
        // 将所有箱子和货物放在一起排序，second为0表示货物，不为0表示供货商的编号
        vector<pair<int, int>> all;
        for (int i = 0; i < boxes.size(); i++)
            for (auto &j : boxes[i])
                all.emplace_back(j, i + 1);
        for (auto i : packages)
            all.emplace_back(i, 0);
        sort(all.begin(), all.end());

        int last[100010];                                                        // 记录遍历过程中上一次遇到供货商i时的下标
        long long ans[100010] = {0}, s_pack[200010] = {0}, s_item[200010] = {0}; // 分别为供货商的总剩余空间，货物重量的前缀和，货物数量的前缀和
        for (int i = 1; i <= boxes.size(); i++)
            last[i] = -1;
        for (int i = 0; i < all.size(); i++)
        {
            int val = all[i].first, k = all[i].second;
            s_pack[i + 1] = s_pack[i];
            s_item[i + 1] = s_item[i];
            if (k == 0)
            {
                // 遍历到的是货物，更新前缀和
                s_pack[i + 1] += val;
                s_item[i + 1]++;
            }
            else
            {
                // 遍历到的是箱子，更新此供货商的剩余空间，此箱子需要存放的货物范围为all[last[k] + 1] ~ all[i]
                // 注意，0~i的前缀和存放在s[i + 1]中
                ans[k] += (s_item[i + 1] - s_item[last[k] + 1]) * val - (s_pack[i + 1] - s_pack[last[k] + 1]);
                last[k] = i;
            }
        }

        // 统计答案。为了处理货物太大装不下的情况，倒着遍历all数组直至找到最大的货物
        long long res = 999999999999999LL;
        for (int i = all.size() - 1; i >= 0; i--)
        {
            if (all[i].second == 0)
                break;
            res = min(res, ans[all[i].second]);
        }
        if (res == 999999999999999LL)
            res = -1;
        return res % 1000000007;
    }
};
