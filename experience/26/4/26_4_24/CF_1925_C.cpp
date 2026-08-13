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
    int n,k,m;
    cin >> n >> k >> m;
    string s;
    cin >> s;
    set<char> st;
    int cnt = 0;
    string ans;
    for (int i = 0;i < m;i++)
    {
        st.insert(s[i]);
        if (st.size() == k)
        {
            st.clear();
            ans += s[i];
            cnt++;
        }
    }
    if (cnt >= n) YES;
    else 
    {
        NO;
        for (char c = 'a';c < 'a' + k;c++)
        {
            if (!st.contains(c)) 
            {
                ans += c;
                break;
            }
        }
        ans.insert(ans.end(),n - ans.size(),'a');
        cout << ans << endl;
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