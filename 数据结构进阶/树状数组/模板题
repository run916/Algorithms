#include <bits/stdc++.h>
using namespace std;

//树状数组模板
//树状数组只能用来统计和。
//例如求解小于某个值得元素的个数，在这个问题中，我们应该以元素值本身的大小
//作为树状数组中对应下标处的值。
const int N = 500010;
int arr[N];

//获取最低位的1
int lowbit(int x)
{
	return x & (-x);
}

//更新位置为x处的值
void update(int x, int v, int n)
{
	for (int i = x; i <= n; i += lowbit(i))
	{
		arr[i] += v;
	}
	return;
}
//查询函数
int query(int x)
{
	int ans = 0;
	//这里查询的元素x不能取值为1，所以树状数组中不能在位置0插入元素。
	for (int i = x; i; i -= lowbit(i))
	{
		ans += arr[i];
	}
	return ans;
}

int main()
{
	int n, m;
	cin >> n >> m;
	int a;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a);
		update(i + 1, a, N);
	}
	int b, c;
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &a);
		if (a == 1)
		{
			scanf("%d %d", &b, &c);
			update(b + 1, c, N);
		}
		else
		{
			scanf("%d %d", &b, &c);
			//为了避免query(0) 这里我们将所有元素都存储在第i+1位。
			cout << query(max(b, c) + 1) - query(min(b, c)) << endl;
		}
	}
	return 0;
}
