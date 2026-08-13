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
    int n;
    cin >> n;
    string a,b;
    cin >> a >> b;
    int ans = 0;
    for (int i = 0;i < (n + 1) / 2;i++)
    {
        map<char,int> cnt,cnt1;
        cnt[a[i]]++;
        cnt1[b[i]]++;
        cnt[a[n - i - 1]]++;
        cnt1[b[n - i - 1]]++;
        if (n % 2 && i == n / 2)
        {
            if (a[i] != b[i]) ans++;
            continue;
        }
        if (cnt1.size() == 1)
        {
            if (cnt.size() == 1) {}
            else if (cnt.size() == 2) ans++;
        }
        else
        {
            char c1 = cnt1.begin()-> fi;
            char c2 = (++cnt1.begin())-> fi;
            if (cnt.size() == 1) 
            {
                char c = cnt.begin()-> fi;
                if (cnt1.count(c)) ans++;
                else ans += 2;
            }
            else 
            {
                if (cnt == cnt1) {}
                else if (cnt.count(c1) || cnt.count(c2)) ans++;
                else ans += 2;
            }
        }
        // cout << ans << endl;
    }
    cout << ans << endl;
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