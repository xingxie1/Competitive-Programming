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
const int mod = 998244353;
const int MOD = (int)1e9+7;

void solve()
{
    string s;
    cin >> s;
    vt b;
    int n = s.size(),cnt = 0;
    for (int i = 0;i < n;i++)
    {
        if (s[i] == 'A')
        {
            int j = i;
            while (j < n && s[j] == 'A') j++;
            b.push_back(j - i);
            i = j - 1;
        }
        else 
        {
            int j = i;
            while (j < n && s[j] == 'B')
            {
                j++;
                cnt++;
            }
            i = j - 1;
        }
    }
    int ans = accumulate(b.begin(),b.end(),0);
    if (cnt == 0)
    {
        cout << 0 << endl;
        return ;
    }
    if (cnt < b.size())
    {
        ranges::sort(b);
        ans -= b[0];
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