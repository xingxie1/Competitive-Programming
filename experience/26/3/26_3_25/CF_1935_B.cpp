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
    vt a(n),cnt(n);
    for (int i = 0;i < n;i++) cin >> a[i],cnt[a[i]]++;
    auto b = a;
    ranges::sort(b);
    int mex = 0;
    for (int x : b)
    {
        if (mex == x) mex++;
    }
    set<int> st;
    int j = -1;
    for (int i = 0;i < n;i++)
    {
        if (a[i] < mex) st.insert(a[i]);
        if (st.size() == mex)
        {
            j = i;
            break;
        }
    }
    if (j == -1)
    {
        cout << -1 << endl;
        return ;
    }
    st.clear();
    for (int i = j + 1;i < n;i++)
    {
        if (a[i] < mex) st.insert(a[i]);
        if (st.size() == mex)
        {
            cout << 2 << endl;
            cout << 1 << " " << j + 1 << endl;
            cout << j + 2 << " " << n << endl;
            return ;
        }
    }
    cout << -1 << endl;
    
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