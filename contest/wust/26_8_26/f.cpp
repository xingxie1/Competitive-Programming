#include<bits/stdc++.h>
using namespace std;
using vt = vector<int>;

class FenwickTree 
{
    vt tr;
public:
    FenwickTree(int n) : tr(n + 1) {}

    void update(int i, int v) 
    {
        for (; i < tr.size(); i += i & -i) tr[i] += v;
    }

    int pre(int i) 
    {
        int res = 0;
        for (; i > 0; i &= i - 1) res += tr[i];
        return res;
    }

    int query(int l, int r) 
    {
        if (r < l) return 0;
        return pre(r) - pre(l - 1);
    }
};

void solve()
{
    int n;
    cin >> n;
    vt a(n + 1),b(n + 1);
    for (int i = 1;i <= n;i++) cin >> a[i];
    for (int i = 1;i <= n;i++) cin >> b[i];
    FenwickTree tr1(n),tr2(n);
    vt last(n + 1);
    vt ans(n + 1);
    set<int> st;
    for (int i = 1;i <= n;i++)
    {
        if (a[i] == b[i])
        {
            ans[a[i]] = st.size();
            last[a[i]] = i;
            tr1.update(i,1);
            tr2.update(i,1);
            st.insert(a[i]);
            continue;
        }
        if (last[a[i]]) 
        {
            ans[a[i]] = last[a[i]] - 1 + i - 1 - tr2.query(1,last[a[i]]);
            tr2.update(last[a[i]],1);
            tr1.update(i,1);
        }
        else last[a[i]] = i;
        if (last[b[i]]) 
        {
            ans[b[i]] = last[b[i]] - 1 + i - 1 - tr1.query(1,last[b[i]]);
            tr1.update(last[b[i]],1);
            tr2.update(i,1);
        }
        else last[b[i]] = i;
        st.insert(a[i]);
        st.insert(b[i]);
        // for (int i = 1;i <= n;i++) cout << tr1.query(i,i) << " ";
        // cout << endl;
        // for (int i = 1;i <= n;i++) cout << tr2.query(i,i) << " ";
        // cout << endl;
    }
    for (int i = 1;i <= n;i++) cout << ans[i] << " ";
    cout << endl;
}

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int _ = 1;
    cin >> _;
    while (_--) solve();

}