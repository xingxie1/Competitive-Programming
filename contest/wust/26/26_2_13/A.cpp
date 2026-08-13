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
#define endl '\n'
const int mod = 998244353;
const int MOD = (int)1e9+7;

void solve()
{
    int n,w;
    cin >> n >> w;
    auto cmp = [](const pair<ll,ll>& a,const pair<ll,ll>& b)
    {
        ll x1 = a.fi,y1 = a.se;
        ll x2 = b.fi,y2 = b.se;
        double s1 = sqrt(x1 * x1 + y1 * y1 - 2 * y1 + 1) + sqrt(x2 * x2 + y2 * y2);
        double s2 = sqrt(x2 * x2 + y2 * y2 - 2 * y2 + 1) + sqrt(x1 * x1 + y1 * y1);
        return s1 > s2;
    };
    pqueue<pair<ll,ll>,vector<pair<ll,ll>>,decltype(cmp)> pq;
    for (int i = 0;i < n;i++)
    {
        ll x,y;
        cin >> x >> y;
        pq.push({x,y});
    }
    while (w--)
    {
        auto [x,y] = pq.top();
        if (y == 0) break;
        pq.pop();
        pq.push({x,y - 1});
    }
    double s = 0;
    while (!pq.empty())
    {
        auto [x,y] = pq.top();
        s += sqrt(x * x + y * y);
        pq.pop();
    }
    printf("%.8lf\n",s);
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