#include<bits/stdc++.h>
using namespace std;
using vt = vector<int>;
using vll = vector<long long>;

void solve()
{
    long long n,k,x;
    cin >> n >> k >> x;
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    k %= x;
    reverse(a.begin() + x - k,a.begin() + x);
    reverse(a.begin(),a.begin() + x - k);
    reverse(a.begin(),a.begin() + x);
    for (int i = 0;i < n;i++)
    {
        cout << a[i] << " " ;
    }
}

int main()
{
    int t = 1;
    // cin >> t;
    while (t --) solve();
    return 0;
}