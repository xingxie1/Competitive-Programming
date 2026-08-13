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
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
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
    string a(n,' '),b(n,' ');
    if (s[0] == '0' || s[n - 1] == '0') 
    {
        NO;
        return ;
    }
    int c1 = 0,c0 = 0;
    for (char c : s)
    {
        c1 += (c == '1');
        c0 += (c == '0');
    }
    if (c0 % 2) 
    {
        NO;
        return;
    }
    int s1 = 0;
    for (int i = 0;i < n;i++) 
    {
        if (s[i] == '1')
        {
            if (s1 < c1 / 2)
            {
                a[i] = b[i] = '(';
                s1++;
            }
            else 
            {
                a[i] = b[i] = ')';
                s1++;
            }
        }
    }
    s1 = 0;
    for (int i = 0;i < n;i++) 
    {
        if (s[i] == '0')
        {
            s1++;
            if (s1 % 2) 
            {
                a[i] = '(';
                b[i] = ')';
            }
            else 
            {
                a[i] = ')';
                b[i] = '(';
            }
        }
    }
    YES;
    cout << a << endl << b << endl;


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