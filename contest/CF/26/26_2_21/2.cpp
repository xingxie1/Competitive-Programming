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
#define mset multiset
#define endl '\n'
const int mod = 998244353;
const int MOD = (int)1e9+7;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt0 = 0,cnt1 = 0;
    for (char c : s)
    {
        cnt0 += c == '0';
        cnt1 += c == '1';
    }
    if (cnt0 == n)
    {
        cout << 0 << endl;
        return ;
    }
    else 
    {
        if (cnt0 % 2 == 1) 
        {
            cout << cnt0 << endl;
            for (int i = 0;i < n;i++)
            {
                if (s[i] == '0') cout << i + 1 << " ";
            }
            cout << endl;
        }
        else 
        {
            if (cnt1 % 2 == 0)
            {
                cout << cnt1 << endl;
                for (int i = 0;i < n;i++)
                {
                    if (s[i] == '1') cout << i + 1 << " ";
                }
                cout << endl;
            }
            else cout << -1 << endl;
        }
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