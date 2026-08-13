#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vvt = vector<vector<int>>;
using vll = vector<long long>;
using vvll = vector<vector<long long>>;
using pii = pair<int,int>;
using vpii = vector<pair<int,int>>;
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
#define endl '\n'
const int mod = 998244353;
const int MOD = (int)1e9+7;

void solve()
{
    int n;
    string s;
    cin >> n >> s;
    vt suf(n + 1);
    for (int i = n - 1;i >= 0;i--) 
    {
        if (s[i] == '(') suf[i] = suf[i + 1] + 1;
        else suf[i] = suf[i + 1];
    }
    for (int i = 0;i < n;i++)
    {
        if (s[i] == ')' && suf[i + 1] >= 2) 
        {
            cout << n - 2 << endl;
            return ;
        }
    }
    cout << -1 << '\n';


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