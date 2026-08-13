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
    vt b(2 * n);
    set<int> st;
    for (int i = 0;i < 2 * n;i++) 
    {
        cin >> b[i];
        st.insert(b[i]);
    }
    ranges::sort(b);
    ll sum = 0;
    for (int i = 2 * n - 1;i >= n - 1;i--) sum += b[i];
    for (int i = 0;i < n - 1;i++) sum -= b[i];
    vll a(2 * n + 1);
    int j = 2 * n - 1;
    for (int i = 0;i < 2 * n + 1;i+=2) a[i] = b[j--];
    a[1] = sum;
    for (int i = 3;i < 2 * n;i += 2) a[i] = b[j--];
    for (ll x : a) cout << x << " ";
    cout << endl;
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