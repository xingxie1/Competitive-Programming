#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using vt = vector<int>;
using vvt = vector<vt>;
using vll = vector<ll>;

void solve()
{
    int n;
    while (cin >> n) 
    {
        map<set<int>,int> cnt;
        for (int i = 0;i < n;i++)
        {
            set<int> st;
            int x;
            cin >> x;
            string s = to_string(x);
            for (int i = 0;i < s.size();i++) 
            {
                st.insert(s[i] - '0');
            }
            cnt[st]++;
        }
        cout << cnt.size() << endl;
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