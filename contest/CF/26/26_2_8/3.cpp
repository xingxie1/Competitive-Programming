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
    int n,k;
    cin >> n >> k;
    vector<string> a(k);
    umap<int,set<char>> p;
    for (int i = 0;i < k;i++) cin >> a[i];
    for (int j = 0;j < n;j++)
    {
        for (int i = 0;i < k;i++)
        {
            p[j].insert(a[i][j]);
        }
    }
    vt b;
    for (int i = 1;i <= n;i++)
    {
        if (n % i == 0) b.push_back(i);
    }
    string ans;
    auto check = [&](int x)
    {
        string tmp;
        for (int i = 0;i < x;i++)
        {
            for (int l = 0;l < 26;l++)
            {
                char c = l + 'a';
                int flag = 1;
                for (int j = i;j < n;j += x)
                {
                    if (!p[j].count(c)) 
                    {
                        flag = 0;
                        break;
                    }
                }
                if (flag) 
                {
                    tmp += c;
                    break;
                }
            }
        }
        if (tmp.size() == x) 
        {
            ans = tmp;
            return 1;
        }
        else return 0;
        
    };
    for (int x : b)
    {
        if (check(x))
        {
            break;
        }
    }
    string ttt = ans;
    while (ans.size() < n) ans += ttt;
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