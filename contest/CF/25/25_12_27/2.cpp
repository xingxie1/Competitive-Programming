#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vll = vector<long long>;
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
int mod = 998244353;
int MOD = (int)1e9+7;

void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    int cnt = 0;
    if (s[0] == 'u')
    {
        cnt++;
        s[0] = 's';
    }
    for (int i = 1;i < n - 1;i++)
    {
        if (s[i] == 'u')
        {
            if (s[i - 1] == 'u') 
            {
                cnt++;
                s[i - 1] = 's';
            }
            if (s[i + 1] == 'u')
            {
                cnt++;
                s[i + 1] = 's';
            }
        }
    }
    if (s[n - 1] == 'u')
    {
        s[n - 1] = 's';
        cnt++;
    }
    cout << cnt << endl;
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