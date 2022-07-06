#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/my-calendar-i/

class MyCalendar
{
public:
    // 需要注意low_bound()以及upper_bound()函数的使用方法。
    set<pair<int, int>> mset;
    MyCalendar()
    {
    }
    bool book(int start, int end)
    {
        set<pair<int, int>>::iterator iter = mset.upper_bound({start, start});
        if (iter != mset.end() && iter->first < end)
        {
            return false;
        }
        if (iter != mset.begin())
        {
            --iter;
            if (iter->second > start)
            {
                return false;
            }
        }
        mset.insert({start, end});
        return true;
    }
};