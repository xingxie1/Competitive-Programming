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
    int f = 1;
    int c0 = 0,c1 = 0,c2 = 0;
    for (int i = 1;i < n;i++) 
    {
        if (a[i] < a[i - 1]) f = 0;
    }
    if (f)
    {
        cout << 0 << endl;
        return ;
    }
    vt p0,p1,p2;
    for (int i = 0;i < n;i++)
    {
        int x = a[i];
        c0 += x == 0;
        c1 += x == 1;
        c2 += x == 2;
        if (x == 0) p0.push_back(i);
        if (x == 1) p1.push_back(i);
        if (x == 2) p2.push_back(i);
    }
    vpii ans;
    for (int i = n - 1;i >= n - c2;i--)
    {
        if (a[i] == 0)
        {
            while (!p1.empty() && p1.back() >= n - c2) p1.pop_back();
            int j = p1.back();
            p1.pop_back();
            p0.push_back(j);
            ans.push_back({i,j});
            a[j] = 0;
            a[i] = 1;
        }
        if (a[i] == 1)
        {
            while (!p2.empty() && p2.back() >= n - c2) p2.pop_back();
            int j = p2.back();
            p2.pop_back();
            p1.push_back(j);
            ans.push_back({i,j});
            a[j] = 1;
            a[i] = 2;
        }
    }
    p0.clear();
    p1.clear();
    p2.clear();
    for (int i = 0;i < n;i++)
    {
        if (a[i] == 0) p0.push_back(i);
        if (a[i] == 1) p1.push_back(i);
        if (a[i] == 2) p2.push_back(i);
    }
    for (int i = 0;i < c0;i++)
    {
        if (a[i] == 1)
        {
            while (!p0.empty() && p0.back() < c0) p0.pop_back();
            int j = p0.back();
            p0.pop_back();
            a[j] = 1;
            ans.push_back({i,j});
        }
    }
    cout << ans.size() << endl;
    for (auto&[l,r] : ans) cout << l + 1 << " " << r + 1 << endl;
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