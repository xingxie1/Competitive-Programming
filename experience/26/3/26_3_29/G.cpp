#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vvt = vector<vector<int>>;
using vll = vector<long long>;
using vvll = vector<vector<long long>>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vpii = vector<pair<int,int>>;
using vpll = vector<pair<ll,ll>>;
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
//cout << fixed << setprecision(10);
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

void solve()
{
    ll n,k;
    cin >> n >> k;
    int ans = 0;
    int cnt = 0;
    if (k == 0)
    {
        cout << 0 << endl;
        return ;
    }
    for (int i = 0;i < bit_width(1ull * n);i++)
    {
        if (!(n >> i & 1)) cnt++;
    }
    if (k > cnt)
    {
        k -= (cnt + 1);
        ans = bit_width(1ull * n) + k;
    }
    else 
    {
        string s;
        while (n)
        {
            char c = '0' + n % 2;
            s += c;
            n /= 2;
        }
        ranges::reverse(s);
        cout << s << endl;
        n = s.size();
        if (k == 1)
        {
            int mx = 0;
            for (int i = 0;i < n;i++)
            {
                if (s[i] == '1')
                {
                    int cnt = 1;
                    int j = i + 1;
                    for (;j < n;j++)
                    {
                        if (s[j] == '1') cnt++;
                        else break;
                    }
                    i = j - 1;
                    mx = max(mx,cnt);
                }
            }
            ans = mx;
        }
        else 
        {
            int mx = 0;
            for (int i = 0;i < n;i++)
            {
                int cnt = 0,sum = 0;
                for (int j = i;j < n;j++)
                {
                    if (s[j] == '1') cnt++;
                    else 
                    {
                        if (sum + 1 > k - 1) break;
                        else 
                        {
                            sum++;
                            cnt++;
                        }
                    }
                }
                ans = max(ans,cnt);
            }
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