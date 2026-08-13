#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vd = vector<double>;
using vll = vector<long long>;
using vvt = vector<vector<int>>;
using vvd = vector<vector<double>>;
using vvll = vector<vector<long long>>;
using vvvt = vector<vector<vector<int>>>;
using vvvll = vector<vector<vector<long long>>>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using pdd = pair<double,double>;
using vpii = vector<pair<int,int>>;
using vpll = vector<pair<ll,ll>>;
using vpdd = vector<pair<double,double>>;
using vvpii = vector<vector<pair<int,int>>>;
using vvpll = vector<vector<pair<ll,ll>>>;
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl
#define fi first
#define se second
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
    // cout << fixed << setprecision(10);
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

void solve()
{
    int n,h;
    cin >> n >> h;
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    ranges::sort(a);
    int c1 = 2,c2 = 1;
    vll s(3,h);
    vt cnt(3);
    vt f(3);
    for (int x : a) 
    {
        if (s[0] > x) 
        {
            s[0] += x / 2;
            cnt[0]++;
        }
        else
        {
            if (f[0] == 0) 
            {
                f[0] = 1;
                s[0] *= 2;
                if (s[0] > x) 
                {
                    s[0] += x / 2;
                    cnt[0]++;
                }
                else 
                {
                    s[0] *= 2;
                    f[0] = 2;
                    if (s[0] > x) 
                    {
                        s[0] += x / 2;
                        cnt[0]++;
                    }
                    else 
                    {
                        f[0] = 3;
                        s[0] *= 3;
                        if (s[0] > x) 
                        {
                            s[0] += x / 2;
                            cnt[0]++; 
                        }
                    }
                }
            }
            else if (f[0] == 1) 
            {
                f[0] = 2;
                s[0] *= 2;
                if (s[0] > x) 
                {
                    s[0] += x / 2;
                    cnt[0]++;
                }
                else 
                {
                    f[0] = 3;
                    s[0] *= 3;
                    if (s[0] > x) 
                    {
                        s[0] += x / 2;
                        cnt[0]++; 
                    }
                }
            }
            else if (f[0] == 2) 
            {
                f[0] = 3;
                s[0] *= 3;
                if (s[0] > x) 
                {
                    s[0] += x / 2;
                    cnt[0]++; 
                }
            }
        }
        if (s[1] > x) 
        {
            s[1] += x / 2;
            cnt[1]++;
        }
        else 
        {
            if (f[1] == 0) 
            {
                f[1] = 1;
                s[1] *= 2;
                if (s[1] > x) 
                {
                    s[1] += x / 2;
                    cnt[1]++;
                }
                else 
                {
                    s[1] *= 3;
                    f[1] = 2;
                    if (s[1] > x) 
                    {
                        s[1] += x / 2;
                        cnt[1]++;
                    }
                    else 
                    {
                        f[1] = 3;
                        s[1] *= 2;
                        if (s[1] > x) 
                        {
                            s[1] += x / 2;
                            cnt[1]++; 
                        }
                    }
                }
            }
            else if (f[1] == 1) 
            {
                f[1] = 2;
                s[1] *= 3;
                if (s[1] > x) 
                {
                    s[1] += x / 2;
                    cnt[1]++;
                }
                else 
                {
                    f[1] = 3;
                    s[1] *= 2;
                    if (s[1] > x) 
                    {
                        s[1] += x / 2;
                        cnt[1]++; 
                    }
                }
            }
            else if (f[1] == 2) 
            {
                f[1] = 3;
                s[1] *= 2;
                if (s[1] > x) 
                {
                    s[1] += x / 2;
                    cnt[1]++; 
                }
            }
        }
        if (s[2] > x) 
        {
            s[2] += x / 2;
            cnt[2]++;
        }
        else 
        {
            if (f[2] == 0) 
            {
                f[2] = 1;
                s[2] *= 3;
                if (s[2] > x) 
                {
                    s[2] += x / 2;
                    cnt[2]++;
                }
                else 
                {
                    s[2] *= 2;
                    f[2] = 2;
                    if (s[2] > x) 
                    {
                        s[2] += x / 2;
                        cnt[2]++;
                    }
                    else 
                    {
                        f[2] = 3;
                        s[2] *= 2;
                        if (s[2] > x) 
                        {
                            s[2] += x / 2;
                            cnt[2]++; 
                        }
                    }
                }
            }
            else if (f[2] == 1) 
            {
                f[2] = 2;
                s[2] *= 2;
                if (s[2] > x) 
                {
                    s[2] += x / 2;
                    cnt[2]++;
                }
                else 
                {
                    f[2] = 3;
                    s[2] *= 2;
                    if (s[2] > x) 
                    {
                        s[2] += x / 2;
                        cnt[2]++; 
                    }
                }
            }
            else if (f[2] == 2) 
            {
                f[2] = 3;
                s[2] *= 2;
                if (s[2] > x) 
                {
                    s[2] += x / 2;
                    cnt[2]++; 
                }
            }
        }
    }
    // cout << s[0] << " " << s[1] << " " << s[2] << endl;
    cout << ranges::max(cnt) << endl;
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