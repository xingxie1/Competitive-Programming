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
    string a,b;
    cin >> a >> b;
    auto f = [&](string s)
    {
        int n = s.size();
        string ans;
        for (int i = 0;i < n;i++)
        {
            int l = i - 2,r = i + 1;
            if (s[i] == 'x' && !ans.empty() && ans.back() == 'x')
            {
                ans.pop_back();
                while (l >= 0 && r < n)
                {
                    if (s[l] == '(' && s[r] == ')') 
                    {
                        l--;
                        r++;
                        ans.pop_back();
                    }
                    else break;
                }
                ans += 'x';
            }
            ans += s[i];
            i = r - 1;
        }
        return ans;
    };
    // cout << f(a) << endl;
    // cout << f(a) << "  " << f(b) << endl;
    if (f(a) == f(b)) YES;
    else NO;
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