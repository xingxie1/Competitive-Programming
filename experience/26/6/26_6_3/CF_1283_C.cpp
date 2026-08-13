#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vvt = vector<vector<int>>;
using pii = pair<int,int>;

#define endl '\n'

void solve()
{
    int n;
    cin >> n;

    vt a(n);
    vt used(n, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i]--;
        if (a[i] != -1)
        {
            used[a[i]] = 1;
        }
    }

    vt pos, miss;

    for (int i = 0; i < n; i++)
    {
        if (a[i] == -1)
        {
            pos.push_back(i);
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (!used[i])
        {
            miss.push_back(i);
        }
    }

    int m = pos.size();

    for (int i = 0; i < m; i++)
    {
        a[pos[i]] = miss[i];
    }

    vt bad;
    for (int i = 0; i < m; i++)
    {
        if (pos[i] == miss[i])
        {
            bad.push_back(i);
        }
    }

    if ((int)bad.size() == 1)
    {
        int x = bad[0];
        int y = 0;
        if (y == x) y = 1;

        swap(a[pos[x]], a[pos[y]]);
    }
    else
    {
        int k = bad.size();
        for (int i = 0; i < k; i++)
        {
            int cur = bad[i];
            int nxt = bad[(i + 1) % k];

            a[pos[cur]] = miss[nxt];
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << a[i] + 1 << " ";
    }
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int _ = 1;
    while (_--) solve();

    return 0;
}