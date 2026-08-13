#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vll = vector<long long>;
using pii = pair<int,int>;
using vpii = vector<pair<int,int>>;
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
int mod = 998244353;
int MOD = (int)1e9+7;

void solve()
{
    int n, m;
    cin >> n >> m;
    vt a(n),b(m);
    for (int i = 0;i < n;i++) cin >> a[i];
    for (int i = 0;i < m;i++) cin >> b[i];
    map<int,int> cnt;
    for (int x : a)cnt[x]++;
    int op = n - m;
    auto check = [&](this auto&& self,int x) -> bool
    {
        if (x == 0 || op < 0) return 0;
        if (cnt[x] > 0) 
        {
            cnt[x]--;
            return 1;
        }
        op--;
        int r1 = x / 2,r2 = (x + 1) / 2;
        bool f1 = self(r1);
        bool f2 = self(r2);
        return f1 && f2;
    };
    for (int x : b)
    {
        if (!check(x)) 
        {
            cout << "NO" << endl;
            return ;
        }
    }
    if (op == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
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