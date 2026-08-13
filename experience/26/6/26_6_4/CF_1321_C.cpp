#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    string s;
    cin >> n >> s;

    int ans = 0;

    while (true)
    {
        int pos = -1;
        char mx = 'a';

        for (int i = 0;i < (int)s.size();i++)
        {
            bool ok = false;

            if (i > 0 && s[i - 1] == s[i] - 1) ok = true;
            if (i + 1 < (int)s.size() && s[i + 1] == s[i] - 1) ok = true;

            if (ok && s[i] > mx)
            {
                mx = s[i];
                pos = i;
            }
        }

        if (pos == -1) break;

        s.erase(s.begin() + pos);
        ans++;
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