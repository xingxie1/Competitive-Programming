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
    int a,b;
    cin >> a >> b;
    int n = a + b;
    string s(n,'1');
    if (a == 0)
    {
        cout << s << endl;
        return;
    }
    else 
    {
        if (b >= a)
        {
            int d = b / (a + 1);
            int res = b % (a + 1);
            for (int i = d;i < n;i += d + 1) 
            {
                if (res > 0)
                {
                    i++;
                    res--;
                }
                s[i] = '0';
            }
        }
        else 
        {
            string t(n,'0');
            s = t;
            if (b == 0) 
            {
                cout << s << endl;
                return ;
            }
            int d = a / (b + 1);
            int res = a % (b + 1);
            for (int i = d;i < n;i += d + 1)
            {
                if (res > 0)
                {
                    res--;
                    i++;
                }
                s[i] = '1';
            }
        }
    }
    cout << s << endl;
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