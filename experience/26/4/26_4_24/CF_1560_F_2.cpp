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
using vvpii = vector<vector<pair<int,int>>>;
using vvpll = vector<vector<pair<ll,ll>>>;
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl
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
    string s;
    int k;
    cin >> s >> k;
    int n = s.size();
    vt cnt(10);
    int d = 0;
    for (char c : s)
    {
        if (cnt[c - '0'] == 0) d++;
        cnt[c - '0']++;
    }
    if (d <= k) 
    {
        cout << s << endl;
        return ;
    }
    for (int i = n - 1;i >= 0;i--)
    {
        cnt[s[i] - '0']--;
        if (cnt[s[i] - '0'] == 0) d--;
        int f = 0;
        for (char c = s[i] + 1;c <= '9';c++)
        {
            s[i] = c;
            int digit = c - '0';
            if (cnt[digit] == 0) d++;
            cnt[digit]++;
            if (d <= k) 
            {
                int v = 0;
                while (d == k && cnt[v] == 0) v++;
                for (int j = i + 1;j < s.size();j++) s[j] = '0' + v;
                f = 1;
                break;
            }
            cnt[digit]--;
            if (cnt[digit] == 0) d--;
        }
        if (f) break;
    }
    cout << s << endl;

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