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
    int n,m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    int ans = 0;
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < m;j++)
        {
            if (j + 1 < m && i + 1 < n)
            {
                set<char> st;
                st.insert(a[i][j]);
                st.insert(a[i][j + 1]);
                st.insert(a[i + 1][j]);
                if (st.size() == 3) ans++;
                st.clear();
                st.insert(a[i][j]);
                st.insert(a[i][j + 1]);
                st.insert(a[i + 1][j + 1]);
                if (st.size() == 3) ans++;
                st.clear();
                st.insert(a[i + 1][j]);
                st.insert(a[i + 1][j + 1]);
                st.insert(a[i][j]);
                if (st.size() == 3) ans++;
                st.clear();
                st.insert(a[i][j + 1]);
                st.insert(a[i + 1][j + 1]);
                st.insert(a[i + 1][j]);
                if (st.size() == 3) ans++;
                st.clear();
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
    // cin >> _;
    while (_ --) solve();

    return 0;
}