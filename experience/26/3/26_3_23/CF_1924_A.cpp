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
    int n,k,m;
    cin >> n >> k >> m;
    string s;
    cin >> s;
    set<char> st;
    string ans;
    for (int i = 0;i < m;i++)
    {
        if (s[i] - 'a' >= k) continue;
        st.insert(s[i]);
        if (st.size() == k)
        {
            st.clear();
            ans += s[i];
        }
    }
    if (ans.size() >= n) cout << "YES" << endl;
    else 
    {
        cout << "NO" << endl;
        for (int i = 0;i < k;i++)
        {
            if (!st.contains('a' + i)) 
            {
                ans.insert(ans.end(),n - ans.size(),'a' + i);
                break;
            }
        }
        cout << ans << endl;
    }
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