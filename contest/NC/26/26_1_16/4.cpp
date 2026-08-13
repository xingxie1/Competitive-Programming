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
    int n,m,k;
    cin >> n >> m >> k;
    string s;
    cin >> s;
    int r = 0,y = 0,w = 0;
    int left = 0,right = 0,ans = INT_MAX;
    if (k == 0)
    {
        cout << 1 << endl;
        return ;
    }
    while (right < n)
    {
        if (s[right] == 'r') r++;
        else if (s[right] == 'y') y++;
        else if (s[right] == 'w') w++;

        while (2 * min(m,w) + 2 * max(r,y) + min(r,y) >= k)
        {
            ans = min(ans,right - left + 1);
            if (s[left] == 'r') r--;
            else if (s[left] == 'y') y--;
            else if (s[left] == 'w') w--;
            left++;
        }
        right++;
    }
    if (ans == INT_MAX) cout << -1 << endl;
    else cout << ans << endl;
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