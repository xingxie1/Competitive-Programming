#include<bits/stdc++.h>
using namespace std;
using vt = vector<int>;
using vll = vector<long long>;

void solve()
{
    int n;
    cin >> n;
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];

    if (a[0] == -1 && a[n - 1] == -1) a[0] = a[n - 1] = 0;
    else if (a[0] == -1) a[0] = a[n - 1];
    else if (a[n - 1] == -1) a[n - 1] = a[0];

    for (int i = 1;i < n - 1;i++)
    {
        if (a[i] == -1)
        {
            a[i] = 0;
        }
    }
    cout << abs(a[n - 1] - a[0]) << endl;
    for (int i = 0;i < n;i++) cout << a[i] << " ";
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int _ = 1;
    cin >> _;
    while (_ --) solve();

    return 0;
}