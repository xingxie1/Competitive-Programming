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
    ll n;
    string a;
    cin >> a >> n;
    set<int> st;
    for (int i = 0;i < n;i++) 
    {
        int x;
        cin >> x;
        st.insert(x);
    }
    int mn = *st.begin(),mx = *st.rbegin();
    int mxa = 0,mna = 10;
    for (char c : a) 
    {
        mxa = max(mxa,c - '0');
        mna = min(mna,c - '0');
    }
    ll ans = LLONG_MAX;

    int f = 0;// = < 
    ll x = 0;
    int isans = 1;
    for (int i = 0;i < a.size();i++)
    {
        if (!f)
        {
            int y = a[i] - '0';
            int flag = 0;
            if (st.contains(y)) 
            {
                x = x * 10 + y;
                continue;
            }
            for (int j = y - 1;j >= 0;j--) 
            {
                if (st.contains(j))
                {
                    x = x * 10 + j;
                    f = 1;
                    flag = 1;
                    break;
                }
            }
            if (flag) continue;
            isans = 0;
        }
        else 
        {
            int y = a[i] - '0';
            for (int j = 9;j >= 0;j--) 
            {
                if (st.contains(j))
                {
                    x = x * 10 + j;
                    break;
                }
            }
        }
        // cout << x << endl;
    }
    if (isans) 
    {
        ans = min(ans,abs(stoll(a) - x));
    }
    // cout << x << " " << ans << endl;
    
    if (1)
    {
        ll x = 0;
        for (int i = 1;i < a.size();i++) 
        {
            x = x * 10 + mx;
        }
        ans = min(ans,abs(x - stoll(a)));
    }

    f = 0;// = > 
    x = 0;
    isans = 1;
    for (int i = 0;i < a.size();i++) 
    {
        if (!f) 
        {
            int y = a[i] - '0';
            int flag = 0;
            if (st.contains(y)) 
            {
                x = x * 10 + y;
                continue;
            }
            for (int j = y;j <= 9;j++) 
            {
                if (st.contains(j))
                {
                    x = x * 10 + j;
                    f = 1;
                    flag = 1;
                    break;
                }
            }
            if (flag) continue;
            isans = 0;
        }
        else
        {
            int y = a[i] - '0';
            for (int j = 0;j <= 9;j++) 
            {
                if (st.contains(j))
                {
                    x = x * 10 + j;
                    break;
                }
            }
        }
        // cout << x << endl;
    }
    if (isans) ans = min(ans,abs(x - stoll(a)));
    
    if (1)
    {
        ll x = mn;
        if (x == 0) x = *(++st.begin());
        for (int i = 0;i < a.size();i++) 
        {
            x = x * 10 + mn;
        }
        ans = min(ans,abs(x - stoll(a)));
    }
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