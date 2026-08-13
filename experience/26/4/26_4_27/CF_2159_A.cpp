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
using vvpii = vector<vector<pair<int,int>>>;
using vvpll = vector<vector<pair<ll,ll>>>;
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
#define mset multiset
// #define endl '\n'
//cout << fixed << setprecision(10);
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

void solve()
{
    int n;
    cin >> n;
    vt ans(2 * n);
    vt b = {1,2};
    int j = 3;
    vt vis(2 * n + 1);
    vt c;
    auto query = [&](auto& q) -> void
    {
        cout << "? " << q.size() << " ";
        for (int x : q) cout << x << " ";
        cout << endl;
        int x;
        cin >> x;
        if (x)
        {
            ans[q.back() - 1] = x;
            c.push_back(q.back());
            q.pop_back();
        }
        q.push_back(j++);
    };
    while (j <= 2 * n + 1)
    {
        query(b);
    }
    b.pop_back();
    for (int x : b) 
    {
        cout << "? " << n + 1 << " " << x << " ";
        for (int y : c) cout << y << " ";
        cout << endl;
        int ret;
        cin >> ret;
        ans[x - 1] = ret;
    }
    cout << "! ";
    for (int x : ans) cout << x << " ";
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