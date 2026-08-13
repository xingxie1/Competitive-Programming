#include<bits/stdc++.h>
using namespace std;
using vt = vector<int>;
using vll = vector<long long>;

void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    long long ans = 0;
    for (int i = 0;i < n - 1;i++)
    {
        if (s[i + 1] == s[i])
        {
            int cnt = 1;
            int last = i;
            int flag = 0;
            for (int j = i + 1;j < n;j++)
            {
                if (s[j] == s[i] && flag == 0) 
                {
                    cnt++;
                    last = j;
                }
                else if (s[j] - s[i] == 1 && cnt > 0)
                {
                    ans++;
                    cnt--;
                    flag = 1;
                }
                else 
                {
                    break;
                }
            }
            i = last;
        }
        else if (s[i + 1] - s[i] == 1) ans++;
    }
    cout << ans;
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