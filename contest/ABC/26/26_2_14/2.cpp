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
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    int mx = 0;
    for (string s : a)
    {
        mx = max(mx,(int)s.size());
    }
    for (string s : a)
    {
        if (s.size() < mx)
        {
            for (int i = 0;i < (mx - s.size()) / 2;i++) cout << ".";
            cout << s;
            for (int i = 0;i < (mx - s.size()) / 2;i++) cout << ".";
        }
        else cout << s;
        cout << endl;
    }
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