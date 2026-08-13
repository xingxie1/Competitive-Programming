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
    int n;
    cin >> n;
    vt a(n);
    if (n <= 3) 
    {
        cout << -1 << endl;
        return ;
    }
    else if (n == 4) 
    {
        cout << "3 1 4 2" << endl;
        return ;
    }
    else if (n == 5) 
    {
        cout << "1 3 5 2 4" << endl;
        return ;
    }
    for (int i = 0;2 * i + 1 <= n;i++) a[i] = 2 * i + 1;
    int j = 0;
    for (int i = 0;i < n;i++) 
    {
        if (!a[i]) 
        {
            j = i;
            break;
        }
    }
    if (n % 2 == 0)
    {
        a[j++] = n - 4;
        a[j++] = n;
        a[j++] = n - 2;
    }
    else 
    {
        a[j++] = n - 3;
        a[j++] = n - 1;
        a[j++] = n - 5;
    }
    int x = n - 6;
    x -= (n % 2);
    for (int i = j;i < n;i++) 
    {
        a[i] = x;
        x -= 2;
    }
    for (int x : a) cout << x << " ";
    cout << endl;
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