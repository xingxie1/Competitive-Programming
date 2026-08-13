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
    int a,b,k;
    cin >> a >> b >> k;
    queue<pii> q;
    q.push({a,0});
    unordered_set<int> vis;
    vis.insert(a);
    auto re = [&](int n)
    {
        if (n % 10 == 0) return n;
        int ret = 0;
        while (n)
        {
            ret = ret * 10 + n % 10;
            n /= 10;
        }
        return ret;
    };
    auto len = [&](int x)
    {
        int ret = 0;
        while (x)
        {
            x /= 10;
            ret++;
        }
        return ret;
    };
    while (!q.empty())
    {
        auto [x,d] = q.front();
        q.pop();
        if (x == b)
        {
            cout << d << endl;
            return ;
        }
        if (!vis.contains(re(x)))
        {
            vis.insert(re(x));
            q.push({re(x),d + 1});
        }
        if (!vis.contains(x + k))
        {
            if (len(x + k) > len(b)) continue;
            vis.insert(x + k);
            q.push({x + k,d + 1});
        }
    }
    cout << -1 << endl;
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