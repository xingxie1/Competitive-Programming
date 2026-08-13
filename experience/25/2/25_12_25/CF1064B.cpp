// https://codeforces.com/problemset/problem/1064/B
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vll = vector<long long>;
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
int mod = 998244353;
int MOD = (int)1e9+7;

void solve()
{
    int a;
    cin >> a;
    int cnt = 0;
    while (a)
    {
        if (a % 2) cnt++;
        a /= 2;
    }
    int ans = (int)pow(2,cnt);
    cout << ans << endl;
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