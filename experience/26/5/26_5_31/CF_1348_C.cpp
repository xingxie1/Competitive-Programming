#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vd = vector<double>;
using vll = vector<long long>;
using vvt = vector<vector<int>>;
using vvd = vector<vector<double>>;
using vvll = vector<vector<long long>>;
using vvvt = vector<vector<vector<int>>>;
using vvvll = vector<vector<vector<long long>>>;
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
#define uset unordered_set
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
    // cout << fixed << setprecision(10);
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

void solve()
{
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<string> a(k);
    vt cnt(26);
    for (char c : s) cnt[c - 'a'] ++;
    int j = 0;
    while (j < 26 && cnt[j] == 0) j++;
    while (j < 26) 
    {
        for (int i = 0;i < k;i++) 
        {
            a[i] += 'a' + j;
            cnt[j]--;
            while (j < 26 && cnt[j] == 0) j++;
            if (j == 26) break;
        }
    }
    string ans = a[0];
    for (string& s : a) ans = max(ans,s);
    cout << ans << endl;
    // cout << endl;
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