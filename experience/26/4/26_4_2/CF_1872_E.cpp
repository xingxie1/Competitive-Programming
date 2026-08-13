#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vvt = vector<vector<int>>;
using vll = vector<long long>;
using vvll = vector<vector<long long>>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vpii = vector<pair<int,int>>;
using vpll = vector<pair<ll,ll>>;
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
//cout << fixed << setprecision(10);
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

void solve()
{
    int n;
    cin >> n;
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    string s;
    cin >> s;
    int q;
    cin >> q;
    vt d(n + 1);
    vt pre(n + 1);
    for (int i = 0;i < n;i++) pre[i + 1] = pre[i] ^ a[i];
    int s0 = 0,s1 = 0;
    for (int i = 0;i < n;i++)
    {
        if (s[i] == '0') s0 ^= a[i];
        else s1 ^= a[i];
    }
    while (q--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int l,r;
            cin >> l >> r;
            l--;r--;
            s0 ^= pre[r + 1] ^ pre[l];
            s1 ^= pre[r + 1] ^ pre[l];
        }
        else 
        {
            char g;
            cin >> g;
            if (g == '0') cout << s0 << " ";
            else cout << s1 << " ";
        }
    }
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