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
    int n;
    cin >> n;
    string s;
    cin >> s;
    ll q = 0,qc = 0,qcj = 0,qcjj = 0;
    ll qca = 0,qcay = 0;
    for (char c : s) 
    {
        if (c == 'q') q++;
        else if (c == 'c') qc += q;
        else if (c == 'a') qca += qc;
        else if (c == 'y') qcay += qca;
        else if (c == 'j') 
        {
            qcjj += qcj;
            qcj += qc;
        }
    }
    if (qcjj >= qcay) cout << "qcjj" << endl;
    else cout << "qcay" << endl;
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