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
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    vt cnt(n);
    int sum = k;
    for (int i = 0;i < n;i++)
    {
        if (sum == 0) break;
        if (k % 2)
        {
            if (s[i] == '1') 
            {
                cnt[i]++;
                sum--;
            }
        }
        else if (s[i] == '0') 
        {
            cnt[i]++;
            sum--;
        }
    }
    cnt[n - 1] += sum;
    for (int i = 0;i < n;i++) 
    {
        if ((k - cnt[i]) % 2 == 0) continue;
        else s[i] = ((s[i] - '0') ^ 1) + '0';
    }
    cout << s << endl;
    for (int x : cnt) cout << x << " ";
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