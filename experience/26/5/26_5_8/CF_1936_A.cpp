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
// #define endl '\n'
//cout << fixed << setprecision(10);
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

void solve()
{
    int n;
    cin >> n;
    auto query = [&](int a,int b,int c,int d) 
    {
        cout << "? " << a << " " << b << " " << c << " " << d << endl;
        char ch;
        cin >> ch;
        return ch;
    };
    int mxi = 0;
    for (int i = 1;i < n;i++) 
    {
        char c = query (mxi,mxi,i,i);
        if (c == '<') mxi = i;
    }
    int mx = 0,mxi2 = 0;
    vt b;
    for (int i = 0;i < n;i++) 
    {
        if (i == mxi) continue;
        char c = query(mxi,i,mxi,mxi2);
        if (c == '>') 
        {
            b.clear();
            b.push_back(i);
            mxi2 = i;
        }
        else if (c == '=')
        {
            b.push_back(i);
        }
    }
    int mni = b[0];
    for (int j : b) 
    {
        char c = query(j,j,mni,mni);
        if (c == '<') mni = j;
    }
    cout << "! " << mni << " " << mxi << endl;
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