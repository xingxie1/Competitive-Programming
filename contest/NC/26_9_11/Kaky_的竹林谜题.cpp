#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
using i128 = __int128_t;
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
using tri = tuple<int,int,int>;
using trl = tuple<ll,ll,ll>;
using vtri = vector<tuple<int,int,int>>;
using vtrl = vector<tuple<ll,ll,ll>>;
#define YES cout << "YES" << endl
#define Yes cout << "Yes" << endl
#define NO cout << "NO" << endl
#define No cout << "No" << endl
#define fi first
#define se second
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

void solve()
{
    int n;
    cin >> n;
    if (n <= 5) 
    {
        No;
        return ;
    }
    vt a1(n),a2(n);
    Yes;
    if (n % 2 == 0)
    {
        for (int i = 0;i < n / 2;i++) a1[i] = 2 * i + 2;
        for (int i = n / 2;i < n;i++) a1[i] = 2 * (i - n / 2) + 1;
        a2[n / 2 - 1] = n / 2;
        a2[n / 2] = n;
        for (int i = n / 2 + 1;i < n;i++) a2[i] = 2 * (i - n / 2);
        for (int i = 0;i < n / 2 - 1;i++) 
        {
            a2[i] = 2 * i + 1;
            if (a2[i] >= n / 2) a2[i] += 2;
        }
        if ((n / 2) % 2 == 0)
        {
            swap(a1[n / 2 - 2],a1[n / 2 - 1]);
            a2[n / 2 - 1] = (n - 2) / 2;
            a2[n / 2] = n - 2;
            for (int i = n / 2 + 1;i < n;i++) 
            {
                a2[i] = 2 * (i - n / 2);
                if (a2[i] >= n - 2) a2[i] += 2;
            }
            for (int i = 0;i < n / 2 - 1;i++)
            {
                a2[i] = 2 * i + 1;
                if (a2[i] >= n / 2 - 2) a2[i] += 2;
            }
        }
    }
    else 
    {
        for (int i = 0;i < n / 2;i++) a1[i] = 2 * i + 2;
        for (int i = n / 2 + 1;i < n;i++) 
        {
            a1[i] = 2 * (i - n / 2 - 1) + 1;
            if (a1[i] >= n / 2) a1[i] += 2;
        }
        a1[n / 2] = n / 2;
        a2[n / 2] = n / 2;
        a2[n / 2 + 1] = n - 1;
        for (int i = n / 2 + 2;i < n;i++) a2[i] = 2 * (i - n / 2 - 1);
        for (int i = 0;i < n / 2;i++) 
        {
            a2[i] = 2 * i + 1;
            if (a2[i] >= n / 2) a2[i]+=2;
        }
        if ((n - 1) / 2 % 2 == 0)
        {
            a1[n / 2] --;
            swap(a1[n / 2 - 1],a1[n / 2 - 2]);
            a2[n / 2] --;
            a2[n / 2 + 1] = a2[n / 2] * 2;
            for (int i = n / 2 + 2;i < n;i++) 
            {
                a2[i] = 2 * (i - n / 2 - 1);
                if (a2[i] >= n - 3) a2[i] += 2;
            }
            for (int i = n / 2 + 1;i < n;i++) 
            {
                a1[i] = 2 * (i - n / 2 - 1) + 1;
                if (a1[i] >= (n - 2) / 2) a1[i] += 2;
            }
            for (int i = 0;i < n / 2;i++) 
            {
                a2[i] = 2 * i + 1;
                if (a2[i] >= (n - 2) / 2) a2[i] += 2;
            }
        }
    }
    
    for (int x : a1) cout << x << " ";
    cout << endl;
    for (int x : a2) cout << x << " ";
    cout << endl;

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << fixed << setprecision(15);
    int _ = 1;
    cin >> _;
    while (_ --) solve();

    return 0;
}