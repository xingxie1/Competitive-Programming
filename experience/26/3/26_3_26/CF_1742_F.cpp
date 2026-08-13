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
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
//cout << fixed << setprecision(10);
const int mod = 998244353;
const int MOD = (int)1e9+7;

void solve()
{
    int q;
    cin >> q;
    map<char,ll> cnt1,cnt2;
    cnt1['a'] = cnt2['a'] = 1;
    while (q--)
    {
        int d,k;
        cin >> d >> k;
        string x;
        cin >> x;
        if (d == 1) for (char c : x) cnt1[c] += k;
        else for (char c : x) cnt2[c] += k;
        auto check = [&] ()
        {
            int j = -1;
            for (int i = 0;i < 26;i++)
            {
                char c = 'a' + i;
                if (cnt1.count(c)) 
                {
                    j = i;
                    break;
                }
            }
            for (int i = j + 1;i < 26;i++) 
            {
                if (cnt2.count('a' + i)) 
                {
                    return 1;
                }
            }
            char c = 'a' + j;
            if (cnt2[c] > cnt1[c]) 
            {
                for (int i = j + 1;i < 26;i++)
                {
                    char ch = 'a' + i;
                    if (cnt1.count(ch)) return 0;
                }
                return 1;
            }
            return 0;
        };
        if (check()) cout << "YES" << endl;
        else cout << "NO" << endl;
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