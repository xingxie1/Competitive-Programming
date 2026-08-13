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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int mx = 0,fi = n;
    vt pre(n + 1),suf(n + 1);
    for (int i = 0;i < n;i++)
    {
        pre[i + 1] = pre[i] + (s[i] == '(');
    }
    for (int i = n - 1;i >= 0;i--)
    {
        suf[i] = suf[i + 1] + (s[i] == ')');
        if (s[i] == ')') fi = i;
    }
    for (int i = 0;i < n;i++)
    {
        int mn = min(pre[i],suf[i]);
        mx = max(mx,mn);
    }
    int ans = -1;
    if (mx >= fi + 1)
    {
        ans = n - 2;
    }
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