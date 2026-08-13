#include<bits/stdc++.h>
using namespace std;
using vt = vector<int>;
using vll = vector<long long>;

void solve()
{
    int n;
    cin >> n;
    int mn = INT_MAX;
    int mx = INT_MIN;
    vt a(n);
    for (int i = 0;i < n;i++) 
    {
        cin >> a[i];
        mn = min(mn,a[i]);
        mx = max(mx,a[i]);
    }
    cout << mx - mn << endl;

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