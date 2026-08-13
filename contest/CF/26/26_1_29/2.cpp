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
    int n;
    cin >> n;
    string s;
    cin >> s;
    ll ans = 0;
    for (int i = 0;i < n;i++)
    {
        if (s[i] == '1') ans++;
        else 
        {
            int j = i;
            while (j < n && s[j] == '0') j++;
            if (i == 0 && j == n)
            {
                if (n == 3) ans = 1;
                else ans += (j - i + 2) / 3;
            }
            else if ((i != 0 && j == n) || (i == 0 && j != n))
            {
                ans += (j - i + 1) / 3;
            }
            else if (i != 0 && j != n)
            {
                ans += (j - i) / 3;
            }
            i = j - 1;
        }
    }
    cout << ans << endl;
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