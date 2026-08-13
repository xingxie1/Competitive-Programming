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
//     int n,m,k;
//     cin >> n >> m >> k;
//     vvt a(n,vt(m + 2));
//     for (int i = 0;i < n;i++) 
//     {
//         cin >> a[i][0];
//         for (int j = 1;j <= m;j++) cin >> a[i][j];
//         a[i][m + 1] = i;
//     }
//     ranges::sort(a,{},[&](auto& b){
//         return b[0];
//     });
//     // for (int i = 0;i < n;i++) cout << a[i][0] << endl; 
//     vll sum(n);
//     vt cnt(n);
//     for (int i = 0;i < n;i++) 
//     {
//         int c = 0;
//         for (int j = 1;j <= m;j++) 
//         {
//             if (a[i][j] >= 0) sum[i] += a[i][j];
//             else c++;
//         }
//         cnt[i] = c;
//     }
//     vt aaa;
//     ll lasts = -1;
//     for (int i = 0;i < n;i++)
//     {
//         int j = i;
//         ll mx = 0;
//         while (j < n && a[j][0] == a[i][0]) 
//         {   
//             ll s = sum[j];
//             int c = cnt[j];
//             if (s > lasts) 
//             {
//                 while (c--) 
//                 {
//                     aaa.push_back(0);
//                 }
//                 mx = max(mx,s);
//             }
//             else 
//             {
//                 ll t = lasts + 1;
//                 ll d = t - s;
//                 if (1LL * c * k < d) 
//                 {
//                     cout << "No" << endl;
//                     return ;
//                 }
//                 else 
//                 {
//                     while (c--) 
//                     {
//                         if (d >= k)
//                         {
//                             d -= k;
//                             aaa.push_back(k);
//                         }
//                         else 
//                         {
//                             if (d) aaa.push_back(d);
//                             else aaa.push_back(0);
//                             d = 0;
//                         }
//                     }
//                     mx = max(mx,t);
//                 }
//             }
//             j++;
//         }
//         lasts = mx;
//         i = j - 1;
//     } 
//     int jjj = 0;
//     for (int i = 0;i < n;i++) 
//     {
//         for (int j = 1;j <= m;j++) 
//         {
//             if (a[i][j] == -1) 
//             {
//                 a[i][j] = aaa[jjj++];
//             }
//         }
//     }
//     cout << "Yes" << endl;
//     ranges::sort(a,{},[&](auto& c){
//         return c[m + 1];
//     });
//     for (int i = 0;i < n;i++) 
//     {
//         for (int j = 1;j <= m;j++) cout << a[i][j] << " ";
//         cout << endl;
//     }
//     // for (int j = 1;j < b.size();j++)
//     // {
//     //     int lasti = b[j - 1];
//     //     int curi = b[j];
//     //     ll nexts = INT_MAX;
//     //     ll lasts = 0;
//     //     if (lasti != -1) lasts = sum[lasti];
//     //     if (curi != n) nexts = sum[curi];
//     //     if (lasts >= nexts) 
//     //     {
//     //         cout << "No" << endl;
//     //         return ;
//     //     }
//     //     for (int i = lasti + 1;i < curi;i++) 
//     //     {
//     //         int c = cnt[i];
//     //         ll s = sum[i];
//     //         int j = i;
//     //         while (j < curi && )
//     //         int f = 0;
//     //         if (i - 1 >= 0 && a[i][0] == a[i - 1][0]) f = 1;
//     //         if (f)
//     //         {

//     //         }
//     //         else 
//     //         {
//     //             if (s > lasts) 
//     //             {
//     //                 lasts = s;
//     //                 while (c--) aaa.push_back(0);
//     //             }
//     //             else 
//     //             {
//     //                 ll t = lasts + 1;
//     //                 ll d = t - s;
//     //                 if (c * k < d) 
//     //                 {
//     //                     cout << "No" << endl;
//     //                     return ;
//     //                 }
//     //                 while (c--) 
//     //                 {
//     //                     if (d >= k) 
//     //                     {
//     //                         d -= k;
//     //                         aaa.push_back(k);
//     //                     }
//     //                     else 
//     //                     {
//     //                         if (d)
//     //                         {
//     //                             aaa.push_back(d);
//     //                             d = 0;
//     //                         }
//     //                         else aaa.push_back(d);
//     //                     }
//     //                 }
//     //                 lasts = t;
//     //             }
//     //         }
//     //         if (lasts >= nexts) 
//     //         {
//     //             cout << "No" << endl;
//     //             return ;
//     //         }
//     //     }
//     // }
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
    int n,m,k;
    cin >> n >> m >> k;
    vvt a(n,vt(m + 2));
    for (int i = 0;i < n;i++) 
    {
        cin >> a[i][0];
        for (int j = 1;j <= m;j++) cin >> a[i][j];
        a[i][m + 1] = i;
    }
    ranges::sort(a,{},[&](auto& b){
        return b[0];
    });
    // for (int i = 0;i < n;i++) cout << a[i][0] << endl; 
    vll sum(n);
    vt cnt(n);
    vt b = {-1};
    for (int i = 0;i < n;i++) 
    {
        int c = 0;
        for (int j = 1;j <= m;j++) 
        {
            if (a[i][j] >= 0) sum[i] += a[i][j];
            else c++;
        }
        if (c == 0) b.push_back(i);
        cnt[i] = c;
    }
    b.push_back(n);
    vt aaa;
    for (int j = 1;j < b.size();j++)
    {
        int lasti = b[j - 1];
        int curi = b[j];
        ll lasts = 0;
        ll nexts = INT_MAX;
        if (lasti != -1) lasts = sum[lasti];
        if (curi != n) nexts = sum[curi];
        if (lasts >= nexts) 
        {
            cout << "No" << endl;
            return ;
        }
        for (int i = lasti + 1;i < curi;i++) 
        {
            int c = cnt[i];
            ll s = sum[i];
            if (s > lasts) 
            {
                lasts = s;
                while (c--) aaa.push_back(0);
            }
            else 
            {
                ll t = lasts + 1;
                ll d = t - s;
                if (1LL * c * k < d) 
                {
                    cout << "No" << endl;
                    return ;
                }
                while (c--) 
                {
                    if (d >= k) 
                    {
                        d -= k;
                        aaa.push_back(k);
                    }
                    else 
                    {
                        if (d)
                        {
                            aaa.push_back(d);
                            d = 0;
                        }
                        else aaa.push_back(d);
                    }
                }
                lasts = t;
            }
            if (lasts >= nexts) 
            {
                cout << "No" << endl;
                return ;
            }
        }
    }
    int jjj = 0;
    for (int i = 0;i < n;i++) 
    {
        for (int j = 1;j <= m;j++) 
        {
            if (a[i][j] == -1) 
            {
                a[i][j] = aaa[jjj++];
            }
        }
    }
    cout << "Yes" << endl;
    ranges::sort(a,{},[&](auto& c){
        return c[m + 1];
    });
    for (int i = 0;i < n;i++) 
    {
        for (int j = 1;j <= m;j++) cout << a[i][j] << " ";
        cout << endl;
    }
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