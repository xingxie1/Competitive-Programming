#include<bits/stdc++.h>
using namespace std;
using vt = vector<int>;
using vll = vector<long long>;

void solve()
{
    int n;
    cin >> n;
    vt a(n);
    int cnt = 0,flag = 0;
    for (int i = 0;i < n;i++)
    {
        cin >> a[i];
        if (a[i] == 0) cnt++;
        else if (a[i] < 0) flag ++;
    }
    if (flag % 2 == 1) cnt+=2;
    cout << cnt << endl;
}

int main()
{
    int t = 1;
    cin >> t;
    while (t --) solve();
    return 0;
}