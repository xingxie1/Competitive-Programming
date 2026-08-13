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
    string s;
    ll pos;
    cin >> s >> pos;
    int n = s.size();
    int N = n;
    pos--;
    int cnt = 0;
    while (pos >= n)
    {
        pos -= n--;
        cnt++;
    }
    string t;
    t += s[0];
    for (int i = 1;i < N;i++)
    {
        if (cnt > 0)
        {
            while (cnt > 0 && !t.empty() && s[i] < t.back())
            {
                t.pop_back();
                cnt--;
            }
        }
        t += s[i];
    }
    cout << t[pos];
    // cout << t << endl;
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