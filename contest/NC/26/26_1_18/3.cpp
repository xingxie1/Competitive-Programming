#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vll = vector<long long>;
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
int mod = 998244353;
int MOD = (int)1e9+7;

void solve()
{
    string s;
    cin >> s;
    int flag = 0;
    int n = s.size();
    string ans;
    for (int i = 0;i < n;i++)
    {
        char c = s[i];
        if (c >= '5')
        {
            int ret = n - i;
            if (i == 0)
            {
                ans += '1'; 
            }
            else 
            {
                char ch = ans.back();
                ans.pop_back();
                ch ++;
                ans += ch;
            }
            while (ret--) ans += '0';
            cout << ans << endl;
            return ;
        }
        ans += s[i];
    }
    char ch = ans.back();
    ans.pop_back();
    ch = '0';
    ans += ch;
    cout << ans << endl;
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