#include<bits/stdc++.h>
using namespace std;

const int N = 500010;
int arr[N];
long long sum = 0;

void com(int l, int r){
    int m = (l + r) / 2;
    int i = l;
    int j = m + 1;
    int tmp[r - l + 1];
    int k = 0;
    for (; i <= m && j <= r;){
        if (arr[i] < arr[j]){
            tmp[k++] = arr[i++];
        }else{
            tmp[k++] = arr[j++];
        }
    }
    for (; i <= m; i++)
        tmp[k++] = arr[i];
    for (; j <= r; j++)
        tmp[k++] = arr[j];
    k = 0;
    for (; k < r - l + 1; k++){
        arr[l + k] = tmp[k];
    }
    return;
}

void merge(int l, int r){
    if(l == r)
        return;
    int m = (l + r) / 2;
    merge(l, m);
    merge(m + 1, r);
    int later = m + 1;
    for (int i = l; i <= m; i++){
        for(; later <= r && arr[later] < arr[i]; later++);
        sum += later - m - 1;
    }
    //合并两个有序数组
    com(l, r);
    return;
}


int main(){
    int n;
    cin >> n;
    memset(arr, 0, sizeof(arr));
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    merge(0, n - 1);
    cout << sum;
    return 0;
}