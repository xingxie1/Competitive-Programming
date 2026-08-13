#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vll = vector<long long>;
#define fi first
#define se second
int mod = 998244353;
int MOD = (int)1e9+7;

void solve()
{
    int n;
    cin >> n;
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    int ans = 0;
    stack<int> st;
    st.push(0);
    ans++;
    for (int i = 1;i < n;i++)
    {
        int j = st.top();
        if (st.top() + a[j] - 1 < i) break;
        if (i + a[i] >= j + a[j]) st.push(i);
        ans++;
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