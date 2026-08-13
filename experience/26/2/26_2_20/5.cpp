#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vvt = vector<vector<int>>;
using vll = vector<long long>;
using vvll = vector<vector<long long>>;
using pii = pair<int,int>;
using vpii = vector<pair<int,int>>;
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
const int mod = 998244353;
const int MOD = (int)1e9+7;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int x = 0,y = 0;
    for (char c : s)
    {
        if (c == 'W') x--;
        else if (c == 'E') x++;
        else if (c == 'N') y++;
        else y--;
    }   
    if (x % 2 || y % 2)
    {
        cout << "NO" << endl;
        return ;
    }
    int tx = x / 2,ty = y / 2;
    int sx = 0,sy = 0;
    string ans(n,'0');
    ans[0] = 'R';
    if (s[0] == 'W') sx--;
    else if (s[0] == 'E') sx++;
    else if (s[0] == 'N') sy++;
    else sy--;
    for (int i = 0;i < n;i++)
    {
        if (ans[i] != '0') continue;
        if (s[i] == 'W') 
        {
            if (sx > tx) 
            {
                sx--;
                ans[i] = 'R';
            }
            else ans[i] = 'H';
        }
        else if (s[i] == 'E')
        {
            if (sx < tx)
            {
                sx++;
                ans[i] = 'R';
            }
            else ans[i] = 'H';
        }
        else if (s[i] == 'N')
        {
            if (sy < ty)
            {
                sy++;
                ans[i] = 'R';
            }
            else ans[i] = 'H';
        }
        else 
        {
            if (sy > ty)
            {
                sy--;
                ans[i] = 'R';
            }
            else ans[i] = 'H';
        }
    }
    int flag = 0;
    for (int i = 1;i < n;i++)
    {
        if (ans[i] != ans[0]) flag = 1;
    }
    if (flag) cout << ans << endl;
    else cout << "NO" << endl;
    // cout << ans << endl;
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