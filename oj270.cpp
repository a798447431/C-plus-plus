/*************************************************************************
	> File Name: oj270.cpp
	> Author: szt
	> Mail: 253604653@qq.com
	> Created Time: 2019年08月14日 星期三 16时38分12秒
 ************************************************************************/

#include<iostream>
using namespace std;

#define MAX_N 300000
int arr[MAX_N + 5];

int q[MAX_N + 5], head, tail;

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> arr[i], arr[i] += arr[i - 1];
    head =  tail = 0;
    q[tail++] = 0;
    int ans = arr[0];
    for (int i = 1; i <= n; i++) {
        if (arr[i] - arr[q[head]] > ans) ans = arr[i] - arr[q[head]];
        while (tail - head && arr[q[tail] - 1] > arr[i]) tail--;
        q[tail++] = i;
        if (i - q[head] >= m) head++;
    }
    cout << ans << endl;
    return 0;
}
