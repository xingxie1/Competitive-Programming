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
    int n,m,q;
    cin >> n >> m >> q;
    vt a(n),b(m);
    set<int> st;
    for (int i = 0;i < n;i++) cin >> a[i];
    for (int i = 0;i < m;i++) cin >> b[i];
    int j = 0;
    for (int i = 0;i < n;i++)
    {
        st.insert(a[i]);
        if (j == m) break;
        if (st.contains(b[j]))
        {
            while (j < m && st.contains(b[j])) j++;
        }
        else 
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