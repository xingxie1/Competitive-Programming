#include<bits/stdc++.h>
using namespace std;
using vt = vector<int>;
using vll = vector<long long>;

void solve()
{
    int n;
    cin >> n;
    int sum = 0;
    while (n)
    {
        int x = n % 10;
        sum += x;
        n /= 10;
    }
    cout << sum % 9;
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