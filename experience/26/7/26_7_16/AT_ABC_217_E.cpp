#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

using vtrl = vector<tuple<ll,ll,ll>>;
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
using vd = vector<double>;
using vll = vector<long long>;
using vvt = vector<vector<int>>;
using vvd = vector<vector<double>>;
using vvll = vector<vector<long long>>;
using i128 = __int128_t;
using vt = vector<int>;

using pii = pair<int,int>;
using vtri = vector<tuple<int,int,int>>;
using vvvt = vector<vector<vector<int>>>;
using vvvll = vector<vector<vector<long long>>>;
using pll = pair<ll,ll>;
using pdd = pair<double,double>;
using vpii = vector<pair<int,int>>;
using vpll = vector<pair<ll,ll>>;
using vpdd = vector<pair<double,double>>;
using vvpii = vector<vector<pair<int,int>>>;
using vvpll = vector<vector<pair<ll,ll>>>;
using tri = tuple<int,int,int>;
using trl = tuple<ll,ll,ll>;void solve()
{
    int q;
    cin >> q;
    mset<int> st;
    vt b;
    int last = 0;
    while (q--)
    {
        int op;
        cin >> op;
        if (op == 1) 
        {
            int x;
            cin >> x;
            b.push_back(x);
        }
        else if (op == 2) 
        {
            if (!st.empty()) 
            {
                cout << *st.begin() << endl;
                st.erase(st.begin());
            }
            else 
            {
                cout << b[last++] << endl;
            }
        }
        else 
        {
            for (int i = last;i < b.size();i++) st.insert(b[i]);
            b.clear();
            last = 0;
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