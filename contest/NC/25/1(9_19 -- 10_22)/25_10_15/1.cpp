#include<bits/stdc++.h>
using namespace std;
using vt = vector<int>;
using vll = vector<long long>;

void solve()
{
    int n;
    cin >> n;
    long long sum = 1LL*(n+1)*n/2;
    for (int i = 0;i < n-1;i++)
    {
        int x;
        cin >> x;
        sum -= x;
    }
    cout << sum;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int _ = 1;
    // cin >> _;
    while (_ --) solve();

    return 0;
}