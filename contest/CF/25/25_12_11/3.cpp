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
    vt a,b;
    for (int i = 0;i < n;i++) 
    {
        int x;
        cin >> x;
        if (x % 2)
        {
            a.push_back(x);
        }
        else b.push_back(x);
    }
    int n0 = b.size(),n1 = a.size();
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    vll suf0(n0 + 1),suf1(n1 + 1);
    for (int i = n0 - 1;i >= 0;i--)
    {
        suf0[i] = suf0[i + 1] + b[i];
    }
    ll s;
    if (a.size()) s = a[n1 - 1];
    else s = 0;
    int j = n0 - 1;
    ll mx = 0;
    for (int i = 1;i <= n;i++)
    {
        if (i <= n0 + 1)
        {
            if (i == 1) cout << s << " ";
            else 
            {
                if (s % 2 == 0)
                {
                    cout << s << " ";
                    continue;
                }
                s += b[j--];
                cout << s << " ";
                mx = max(mx,s);
            }
        }
        else 
        {
            if ((i - n0) & 1)
            {
                s = a.back() + suf0[0];
            }
            else 
            {
                if (n1 >= i - n0 + 1)
                {
                    if (b.size())
                        s = a.back() + suf0[1];
                    else s = 0;
                }
                else s = 0;
            }
            cout << s << " ";
        }
    }
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