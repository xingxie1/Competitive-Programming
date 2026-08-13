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
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    ranges::sort(a);
    a.erase(unique(a.begin(),a.end()),a.end());
    if (a[0] >= 2) 
    {
        cout << "Alice" << endl;
    }
    else 
    {
        int j = 0,cnt = 0;
        while (j < a.size() && a[j] - cnt == 1) 
        {
            j++;
            cnt++;
        }
        if (cnt == a.size())
        {
            if (cnt & 1) cout << "Alice" << endl;
            else cout << "Bob" << endl;
        }
        else if (cnt % 2 == 1) cout << "Bob" << endl;
        else cout << "Alice" << endl;
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