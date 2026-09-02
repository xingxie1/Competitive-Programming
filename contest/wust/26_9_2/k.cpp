#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fi first
#define se second
using ll = long long;
using vt = vector<int>;
using vll = vector<ll>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using i128 = __int128_t;

struct node{
    string str;
    int start;
    int len;

    bool operator < (const node& other) const
    {
        if (str == other.str) 
        {
            if (start == other.start) 
            {
                return len < other.len;
            }
            return start < other.start;
        }
        return str < other.str;
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    map<node, int> cnt;
    for (int i = 0;i < n - 1;i++)
    {
        int m = a[i].size();
        // cout << "m: " << m << endl;
        for (int j = i + 1;j < n;j++)
        {
            int m2 = a[j].size();
            if (m != m2) continue;
            
            vt dif;
            for(int x = 0; x < m; x++) {
                if(a[i][x] != a[j][x]) {
                    dif.push_back(x);
                }
            }

            if((dif.size() == 2) && (dif[0] == dif[1] - 1)) {
                int w = dif[0];
                string s1 = a[i].substr(w, 2) + a[j].substr(w, 2);
                string s2 = a[j].substr(w, 2) + a[i].substr(w, 2);
                node n1 = {s1, w, m};
                node n2 = {s2, w, m};
                cnt[n1]++;
                cnt[n2]++;
                // cout << s1 << " " << w << " " << m << endl;
                // cout << s2 << " " << w << " " << m << endl;
                // cout << n1.str << " " << n1.start << " " << n1.len << endl;
                // cout << n2.str << " " << n2.start << " " << n2.len << endl;
            }
            
        }
    }
    int ans = 0;
    for (auto& [s,c] : cnt)
    {
        // cout << s.str << ' ' << s.len << ' ' << s.start << ' ' << c <<  endl;
        if (c == 1) ans++;
    }
    cout << ans / 2 << endl;
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int _ = 1;
    // cin >> _;
    while (_--) solve();
}