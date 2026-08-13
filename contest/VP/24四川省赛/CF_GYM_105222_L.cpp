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
using pdd = pair<double,double>;
using vpii = vector<pair<int,int>>;
using vpll = vector<pair<ll,ll>>;
using vpdd = vector<pair<double,double>>;
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
    int n;
    cin >> n;
    vpii a,b;
    for (int i = 0;i < n;i++) 
    {
        int x,y,c,d;
        cin >> x >> y >> c >> d;
        if (c == 1 && d == 1) 
        {
            if (x < y) a.push_back({x,i + 1});
            else b.push_back({y,i + 1});
        }
        else if (c == 1) a.push_back({x,i + 1});
        else b.push_back({y,i + 1});
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    cout << a.size() << " ";
    for (auto& [x,i] : a) cout << i << " ";
    cout << endl;
    cout << b.size() << " ";
    for (auto& [x,i] : b) cout << i << " ";
    cout << endl; 
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