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
const int mod = 998244353;
const int MOD = (int)1e9+7;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (n == 1) 
    {
        cout << 1 << endl;
        return;
    }
    stack<int> st;
    for (int i = 0;i < n;i++)
    {
        if (s[i] == '0') st.push(i);
    }
    ll ans = 1LL * n * (n + 1) / 2;
    vt used(n);
    int last = 0;
    for (int i = n - 1;i >= 0;i--)
    {
        if (s[i] == '0' || used[i]) continue;
        while (!st.empty() && st.top() > i) st.pop();
        if (!st.empty()) 
        {
            ans -= i + 1;
            st.pop();
        }
        else 
        {
            while (last < i && (s[last] == '0' || used[last])) last++;
            if (last < i) 
            {
                used[last] = 1;
                ans -= i + 1;
            }
        }

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