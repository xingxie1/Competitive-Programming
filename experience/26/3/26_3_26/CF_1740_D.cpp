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
    int n,m,k;
    cin >> n >> m >> k;
    vt a(k);
    for (int i = 0;i < k;i++) cin >> a[i];
    int res = n * m - 3;
    int t = k;
    set<int> st;
    for (int x : a)
    {
        if (x == t) 
        {
            t--;
            while (!st.empty() && st.contains(t))
            {
                st.erase(t--);
            }
            continue;
        }
        st.insert(x);
        if (st.size() >= res) 
        {
            cout << "TIDAK" << endl;
            return ;
        }
    }

    cout << "YA" << endl;
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