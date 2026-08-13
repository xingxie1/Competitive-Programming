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
    int n, m;
    cin >> n >> m;
    int t = n / m;
    vll a(n);
    vvt pos(m,vt());
    for (int i = 0;i < n;i++)
    {
        cin >> a[i];
        pos[a[i] % m].push_back(i);
    }
    stack<int> st;
    ll ans = 0;
    for (int i = 0;i < 2 * m - 1;i++)
    {
        int cur = i % m;
        if (pos[cur].size() > t) 
        {
            while (pos[cur].size() > t) 
            {
                st.push(pos[cur].back());
                pos[cur].pop_back();
            }
        }
        else if (pos[cur].size() < t)
        {
            while (!st.empty() && pos[cur].size() < t)
            {
                int j = st.top();
                st.pop();
                int d = (cur - a[j] % m + m) % m;
                a[j] += d;
                ans += d;
                pos[a[j] % m].push_back(j);
            }
        }
    }
    cout << ans << endl;
    for (int x : a) cout << x << " ";
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