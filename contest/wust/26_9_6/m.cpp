#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
using ll = long long;
using vt = vector<int>;
using vvt = vector<vt>;
using vll = vector<ll>;
using pii = pair<int,int>;

void solve()
{
    set<string> st;
    int n,m;
    cin >> n >> m;
    for (int i = 0;i < n;i++)
    {
        string s;
        cin >> s;
        st.insert(s);
    }
    set<string> vis;
    while (m--)
    {
        string s;
        cin >> s;
        if (st.count(s) && !vis.count(s)) cout << "OK" << endl;
        else if (!st.count(s)) cout << "WRONG" << endl;
        else if (st.count(s) && vis.count(s)) cout << "REPEAT" << endl;
        if (st.count(s)) vis.insert(s);
    }
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int _ = 1;
    // cin >> _;
    while (_--) solve();
}