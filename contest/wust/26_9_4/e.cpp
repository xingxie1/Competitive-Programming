#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
using ll = long long;
using vt = vector<int>;
using vll = vector<ll>;
using pii = pair<int,int>;
using vpii = vector<pii>;

pair<vt,vt> f(vll& a)
{
    int n = a.size();
    vt left(n);
    vt st = {-1};
    for (int i = 0;i < n;i++) 
    {
        int x = a[i];
        while (st.size() > 1 && a[st.back()] <= x) st.pop_back();
        left[i] = st.back();
        st.push_back(i);
    }
    vt right(n);
    st = {n};
    for (int i = n - 1;i >= 0;i--)
    {
        int x = a[i];
        while (st.size() > 1 && a[st.back()] <= x) st.pop_back();
        right[i] = st.back();
        st.push_back(i);
    }
    return {left,right};
}
void solve()
{
    int n;
    cin >> n;
    vll a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    auto [L,R] = f(a);
    ll ans1 = 0,ans2 = 1;
    for (int i = 0;i < n;i++)
    {
        ll l = L[i];
        ll lr = l + 1;
        if (l != -1 && lr != i)
        {
            ll x = i - lr;
            ll fm = a[l] - a[lr];
            ll fz = a[i] - a[lr];
            ll g = gcd(fm,fz);
            fm /= g;
            fz /= g;
            fz += fm * x;
            if (1.0 * fz / fm > 1.0 * ans1 / ans2) 
            {
                ans1 = fz;
                ans2 = fm;
                // cout << i << endl;
            }
        }
        ll r = R[i];
        ll rl = r - 1;
        if (r != n && rl != i)
        {
            ll x = rl - i;
            ll fm = a[r] - a[rl];
            ll fz = a[i] - a[rl];
            ll g = gcd(fm,fz);
            fm /= g;
            fz /= g;
            fz += fm * x;
            if (1.0 * fz / fm > 1.0 * ans1 / ans2) 
            {
                ans1 = fz;
                ans2 = fm;
                // cout << i << endl;
            } 
        }
    }
    ll g = gcd(ans1,ans2);
    ans1 /= g;
    ans2 /= g;
    if (ans1 == 0) cout << 0 << endl;
    else if (ans2 == 1) cout << ans1 << endl;
    else cout << ans1 << "/" << ans2 << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int _ = 1;
    // cin >> _;
    while (_--) solve();

}