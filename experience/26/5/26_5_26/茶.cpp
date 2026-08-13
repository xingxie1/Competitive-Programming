#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
#define endl '\n'

void solve()
{
    int n, d;
    cin >> n >> d;

    if (d == 0) d = 1e9;

    map<int, vt> g;

    for (int i = 0; i < n; i++)
    {
        int v;
        cin >> v;
        g[v % d].push_back(v);
    }

    if (d == 1e9)
    {
        cout << n - (int)g.size() << endl;
        return;
    }

    int ans = n;

    for (auto &[_, a] : g)
    {
        sort(a.begin(), a.end());

        int f0 = 0, f1 = 0;
        int cnt = 0;

        for (int i = 0; i < (int)a.size(); i++)
        {
            int v = a[i];
            cnt++;

            if (i == (int)a.size() - 1 || a[i + 1] - v == d)
            {
                int nf0 = f1;
                int nf1 = max(f1, f0 + cnt);
                f0 = nf0;
                f1 = nf1;
                cnt = 0;
            }
            else if (a[i + 1] > v)
            {
                ans -= max(f1, f0 + cnt);
                f0 = f1 = 0;
                cnt = 0;
            }
        }

        ans -= f1;
    }

    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}