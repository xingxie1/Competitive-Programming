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
    int n;
    cin >> n;
    string s;
    cin >> s;
    vt a(n);
    vector<pair<int,int>> re;
    for (int i = 0;i < n;i++) a[i] = i + 1;
    for (int i = 0;i < n;i++)
    {
        if (s[i] == '1')
        {
            if (i == 1 && s[0] == '0') 
            {
                cout << "NO" << endl;
                return ;
            }
            else 
            {
                int j = i;
                while (j < n && s[j] == '1')
                {
                    j++;
                }
                if (j + 1 < n && s[j + 1] == '1') 
                {
                    cout << "NO" << endl;
                    return ;
                }
                i = j - 1;
            }
        }
        else 
        {
            int j = i;
            while (j < n && s[j] == '0') j++;
            re.push_back({i, j});
            i = j - 1;
        }
    }
    if (s[n - 2] == '1' && s[n - 1] == '0')
    {
        cout << "NO" << endl;
        return ;
    }
    for (auto& [b, e] : re)
    {
        reverse(a.begin() + b,a.begin() + e);
    }
    cout << "YES" << endl;
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