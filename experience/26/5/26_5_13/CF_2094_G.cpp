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
    int q;
    cin >> q;
    ll ans = 0,sum = 0;
    bool rev = 0;
    deque<int> a;
    while (q--)
    {
        int op;
        cin >> op;
        if (op == 1) 
        {
            if (!rev)
            {
                ans += sum - 1LL * a.size() * a.back();
                int x = a.back();
                a.pop_back();
                a.push_front(x);
            }
            else 
            {
                ans += sum - 1LL * a.size() * a.front();
                int x = a.front();
                a.pop_front();
                a.push_back(x);
            }
        }
        else if (op == 2) 
        {
            ans = 1LL * (a.size() + 1) * sum - ans;
            rev ^= 1;
        }
        else 
        {
            int x;
            cin >> x;
            sum += x;
            ans += 1LL * (a.size() + 1) * x;
            if (!rev) a.push_back(x);
            else a.push_front(x);
        }
        cout << ans << endl;
    }
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