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
    int n,q;
    cin >> n >> q;
    vt a(n);
    set<int> st;
    for (int i = 0;i < n;i++) 
    {
        cin >> a[i];
        if (a[i] >= 10) st.insert(i);
    }
    auto digitsum = [&](int x)
    {
        int ans = 0;
        while (x)
        {
            ans += x % 10;
            x /= 10;
        }
        return ans;
    };
    while (q--)
    {
        int op;
        cin >> op;
        if (op == 1) 
        {
            int l,r;
            cin >> l >> r;
            l--;
            r--;
            auto it = st.lower_bound(l);
            while (it != st.end() && *it <= r) 
            {
                int i = *it;
                a[i] = digitsum(a[i]);
                auto nxt = it;
                nxt++;
                if (a[i] < 10) st.erase(it);
                it = nxt;
            }
        }
        else 
        {
            int p;
            cin >> p;
            p--;
            cout << a[p] << endl;
        }
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