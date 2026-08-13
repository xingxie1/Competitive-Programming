#include<bits/stdc++.h>
using namespace std;
using vt = vector<int>;
using vll = vector<long long>;

void solve()
{
    int n;
    string s;
    cin >> n;
    cin >> s;
    unordered_map<int,int> cnt1;
    for (int i = 0;i < n;i++)
    {
        cnt1[s[i] - '0']++;
    }
    if (cnt1[1] < 1 || cnt1[2] < 1 || cnt1[3] < 1)
    {
        cout << -1 << endl;
    }
    else 
    {
        vt cnt(4);
        int l = 0,r = 0,flag = 0;
        while (r < n)
        {
            cnt[s[r] - '0']++;
            if (r - l + 1 == 3)
            {
                if (cnt[1] == 1 && cnt[2] == 1 && cnt[3] == 1)
                {
                    cout << 0 << endl;
                    flag = 1;
                    break;
                }
                cnt[s[l] - '0']--;
                l++;
            }
            r++;
        }
        if (!flag)
        {
            cout << 1 << endl;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int _ = 1;
    cin >> _;
    while (_ --) solve();

    return 0;
}