#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vvt = vector<vector<int>>;
using vll = vector<long long>;
using vvll = vector<vector<long long>>;
using pii = pair<int,int>;
using vpii = vector<pair<int,int>>;
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
const int mod = 998244353;
const int MOD = (int)1e9+7;

void solve()
{
    int n;
    cin >> n;
    auto check = [&](int q,int m)
    {
        ll s = 1;
        while (m--)
        {
            s = s * q;
            if (s >= 1LL * n * (q - 1)) return 1;
        }
        return 0;
    };
    for (int q = 1;q <= sqrt(n) + 1;q++)
    {
        int l = 2,r = 30;
        while (l + 1 < r)
        {
            int m = (l + r) / 2;
            if (check(q,m)) r = m;
            else l = m;
        }
        ll s = 1LL * (1 - pow(q,r)) / (1 - q);
        if (s == n) 
        {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
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