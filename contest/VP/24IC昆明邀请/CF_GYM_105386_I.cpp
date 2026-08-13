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
// using vpii = vector<pair<int,int>>;
// using vpll = vector<pair<ll,ll>>;
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
//     string s;
//     cin >> s;   
//     int n = s.size();
//     string t;
//     int j = n - 1;
//     while (j >= 0 && s[j] == s[0])
//     {
//         t += s[j];
//         j--;
//     }
//     t += s.substr(0,j + 1);
//     char c = t[0];
//     t += c;
//     t.erase(0,1);
//     int cnt = 0;
//     j = 0;
//     while (j < n && s[j] == s[0]) 
//     {
//         cnt++;
//         j++;
//     }
//     if (s[0] == s[n - 1] && cnt % 2) 
//     {
//         int ans = 0;
//         for (int i = 1;i < n;i++) 
//         {
//             if (t[i] == t[i - 1]) 
//             {
//                 ans++;
//                 i++;
//             }
//         } 
//         cout << ans << endl;
//         return ;
//     }
//     int ans = 0;
//     for (int i = 1;i < n;i++) 
//     {
//         if (s[i] == s[i - 1]) 
//         {
//             ans++;
//             i++;
//         }
//     } 
//     int f = 0;
//     for (int i = 0;i < n;i++) 
//     {
//         int j = i;
//         while (s[j] == s[i]) j++;
//         if ((j - i) % 2 == 0) f = 1;
//         i = j - 1;
//     }
//     cout << max(0,ans - f) << endl;
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
using vpii = vector<pair<int,int>>;
using vpll = vector<pair<ll,ll>>;
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
    string s;
    cin >> s;
    int n = s.size();
    int j = n - 1;
    while (j >= 0 && s[j] == s[0]) j--;
    string t;
    if (j >= 0) 
    {
        t = s.substr(j + 1);
        string tmp = s.substr(0,j + 1);
        t = t + tmp;
        // cout << t << endl;
    }
    else 
    {
        t = s;
        cout << n / 2 << endl;
        return ;
    }
    int ans = 0;
    for (int i = 1;i < n;i++) 
    {
        if (t[i] == t[i - 1]) 
        {
            ans ++;
            i++;
        }
    }
    int f = 0;
    // cout << t << endl;
    for (int i = 0;i < n;i++) 
    {
        int j = i;
        while (j < n && t[j] == t[i]) 
        {
            j++;
        }
        if ((j - i) % 2 == 0) f = 1;
        i = j - 1;
    }
    cout << max(0,ans - f) << endl;
    
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