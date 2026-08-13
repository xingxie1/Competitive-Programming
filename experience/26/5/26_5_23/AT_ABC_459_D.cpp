#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vd = vector<double>;
using vll = vector<long long>;
using vvt = vector<vector<int>>;
using vvd = vector<vector<double>>;
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
#define uset unordered_set
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
    // cout << fixed << setprecision(10);
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    pqueue<pii> pq;
    vt cnt(26);
    for (char c : s) cnt[c - 'a']++;
    for (int i = 0;i < 26;i++) if (cnt[i]) pq.push({cnt[i],i});
    int last = -1;
    string ans;
    while (!pq.empty()) 
    {
        auto [c,ch] = pq.top();
        pq.pop();
        if (ch == last) 
        {
            if (pq.empty()) 
            {
                NO;
                return ;
            }
            auto [c1,ch1] = pq.top();
            pq.pop();
            last = ch1;
            ans += 'a' + ch1;
            c1--;
            if (c1) pq.push({c1,ch1});
        }
        last = ch;
        ans += 'a' + ch;
        c--;
        if (c) pq.push({c,ch});
    }
    YES;
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