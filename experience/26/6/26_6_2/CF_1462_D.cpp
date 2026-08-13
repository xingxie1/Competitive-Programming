// #include<bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// using vt = vector<int>;
// using vd = vector<double>;
// using vll = vector<long long>;
// using vvt = vector<vector<int>>;
// using vvd = vector<vector<double>>;
// using vvll = vector<vector<long long>>;
// using vvvt = vector<vector<vector<int>>>;
// using vvvll = vector<vector<vector<long long>>>;
// using pii = pair<int,int>;
// using pll = pair<ll,ll>;
// using pdd = pair<double,double>;
// using vpii = vector<pair<int,int>>;
// using vpll = vector<pair<ll,ll>>;
// using vpdd = vector<pair<double,double>>;
// using vvpii = vector<vector<pair<int,int>>>;
// using vvpll = vector<vector<pair<ll,ll>>>;
// #define YES cout << "Yes" << endl
// #define NO cout << "No" << endl
// #define fi first
// #define se second
// #define umap unordered_map
// #define uset unordered_set
// #define pqueue priority_queue
// #define mset multiset
// #define endl '\n'
//     // cout << fixed << setprecision(10);
// //const int MOD = 998244353;
// //const int MOD = (int)1e9+7;

// void solve()
// {
//     int n;
//     cin >> n;
//     vt a(n);
//     for (int i = 0;i < n;i++) cin >> a[i];
//     int t = 0,mx = 0;
//     for (int i = 0;i < n;i++) 
//     {
//         t += a[i];
//         int s = 0, f = 1;
//         int cnt = 0;
//         for (int j = i + 1;j < n;j++) 
//         {
//             if (s + a[j] > t) 
//             {
//                 f = 0;
//                 break;
//             }
//             else if (s + a[j] < t) s += a[j];
//             else 
//             {
//                 s = 0;
//                 cnt++;
//             }
//         }
//         if (f && s == 0) 
//         {
//             mx = max(mx,cnt + 1);
//         }
//     }
//     cout << n - mx << endl;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int _ = 1;
//     cin >> _;
//     while (_ --) solve();

//     return 0;
// }


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
    int n;
    cin >> n;
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    vll pre(n + 1);
    for (int i = 0;i < n;i++) pre[i + 1] = pre[i] + a[i];
    map<int,int> cnt;
    for (int i = 0;i < n;i++) 
    {
        for (int j = i;j < n;j++) 
        {
            int x = pre[j + 1] - pre[i];
            cnt[x]++;
        }
    }
    int mx = 0;
    for (auto& [y,c] : cnt) 
    {
        int s = 0;
        int cc = 0;
        int f = 1;
        for (int x : a) 
        {
            if (s + x < y) s += x;
            else if (s + x > y) 
            {
                f = 0;
                break;
            }
            else 
            {
                cc++;
                s = 0;
            }
        }
        if (f && s == 0) mx = max(mx,cc);
    }
    cout << n - mx << endl;
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