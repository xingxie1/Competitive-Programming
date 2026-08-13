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
    vector<string> a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    string ans;
    for (int i = 0;i < n;i++)
    {
        string tmp = ans;
        string t1 = tmp + a[i];
        string t2 = a[i] + tmp;
        ans = min(t1,t2);
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