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
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
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
    int m;
    cin >> m;
    vt cnt(30);
    while (m--) 
    {
        int op;
        cin >> op;
        if (op == 1) 
        {
            int x;
            cin >> x;
            cnt[x]++;
        }
        else 
        {
            int x;
            cin >> x;
            int f = 1;
            for (int j = 29;j >= 0;j--) 
            {
                if (cnt[j]) 
                {
                    int c = cnt[j];
                    while (c && x >= (1 << j)) 
                    {
                        x -= (1 << j);
                        c--;
                    }
                }
            }
            if (x == 0) YES;
            else NO;
        }
    }

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