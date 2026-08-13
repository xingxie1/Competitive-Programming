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
    int n;
    cin >> n;
    vector<set<int>> a(n);
    set<int> s;
    for (int i = 0;i < n;i++)
    {
        int k;
        cin >> k;
        for (int j = 0;j < k;j++)
        {
            int x;
            cin >> x;
            a[i].insert(x);
            s.insert(x);
        }
    }
    int ans = 0;
    for (int x : s)
    {
        set<int> st;
        for (int i = 0;i < n;i++)
        {
            if (!a[i].contains(x))
            {
                for (int y : a[i]) st.insert(y);
            }
        }
        ans = max(ans,(int)st.size());
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