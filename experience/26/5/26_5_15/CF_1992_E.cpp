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
#define endl '\n'
//cout << fixed << setprecision(10);
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

void solve()
{
    int n;
    cin >> n;
    string s = to_string(n);
    int len =  s.size();
    string t;
    while (t.size() < 10) t += s;
    vpii ans;
    for (int a = 1;a <= 10000;a++) 
    {
        for (int c = 1;c <= 6 && c <= len * a;c++) 
        {
            int b = len * a - c;
            if (b < 1) continue;
            if (b > 10000) continue;
            if (b > n * a) continue;
            int x = 0;
            for (int i = 0;i < c;i++) 
            {
                x = x * 10 + (t[i] - '0');
            }
            int real = a * n - b;
            if (x == real) ans.push_back({a,b});
        }
    }
    cout << ans.size() << endl;
    for (auto& [l,r] : ans) cout << l << " " << r << endl;
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