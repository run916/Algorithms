class Solution
{
public:
    long long maxPoints(vector<vector<int>> &points)
    {
        int n = points.size();
        int m = points[0].size();
        long long dp[n][m];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < m; i++)
        {
            dp[0][i] = points[0][i];
        }
        stack<int> s1;
        for (int i = 1; i < n; i++)
        {
            //首先预处理处[0,m]上的单调队列维持的最大值
            for (int j = m - 1; j >= 0; j--)
            {
                if (s1.empty())
                {
                    s1.push(j);
                }
                else
                {
                    if (dp[i - 1][s1.top()] - s1.top() < dp[i - 1][j] - j)
                    {
                        s1.push(j);
                    }
                }
            }
            long long now = dp[i - 1][0] + 0;
            for (int j = 0; j < m; j++)
            {
                //优化，当j>k时，有dp[i-1][k]+k-j，此时只要确定dp[i-1][k]+k的最大值即可
                dp[i][j] = max(dp[i][j], now - j + points[i][j]);
                if (now < dp[i - 1][j] + j)
                    now = dp[i - 1][j] + j;
                //当j<k时，此时有dp[i-1][k]-k+j，此时只需要确定dp[i-1][k]-k的最大值即可。
                //这种情况可以用单调栈维持
                dp[i][j] = max(dp[i][j], dp[i - 1][s1.top()] - s1.top() + j + points[i][j]);
                if (s1.top() <= j)
                    s1.pop();
            }
        }
        long long ans = 0;
        for (int i = 0; i < m; i++)
            ans = max(ans, dp[n - 1][i]);
        return ans;
    }
};