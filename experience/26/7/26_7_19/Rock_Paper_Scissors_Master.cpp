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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    //0R 1S 2P
    vvt hand;
    vvvt id(4,vvt(4,vt(4,-1))); //手牌映射为0~9
    for (int r = 0;r <= 3;r++) 
    {
        for (int s = 0;r + s <= 3;s++)
        {
            int p = 3 - r - s;
            id[r][s][p] = hand.size();
            hand.push_back({r,s,p});
        }
    }

    vector<vvvt> nxt(100,vvvt(3,vvt(3,vt(9)))); //双方手牌联合状态 a打出的牌 b打出的牌 双方补牌
    for (int as = 0;as < 10;as++)
    {
        for (int bs = 0;bs < 10;bs++)
        {
            int state = as * 10 + bs;
            for (int a = 0;a < 3;a++)
            {
                for (int b = 0;b < 3;b++)
                {
                    if (hand[as][a] == 0 || hand[bs][b] == 0) continue;
                    int q = 0;
                    for (int na = 0;na < 3;na++)
                    {
                        for (int nb = 0;nb < 3;nb++)
                        {
                            auto A = hand[as];
                            auto B = hand[bs];
                            A[a]--;
                            B[b]--;
                            A[na]++;
                            B[nb]++;
                            int nA = id[A[0]][A[1]][A[2]];
                            int nB = id[B[0]][B[1]][B[2]];
                            nxt[state][a][b][q++] = nA * 10 + nB;
                        }
                    }
                }
            }
        }
    }
    vvt reward(3,vt(3));
    for (int a = 0;a < 3;a++)
    {
        for (int b = 0;b < 3;b++)
        {
            if (a == b) reward[a][b] = 1;
            else if ((a == 0 && b == 1) || (a == 1 && b == 2) || (a == 2 && b == 0)) reward[a][b] = 3;
            else reward[a][b] = 0;
        }
    }

    int N = 1e4;
    vvd dp(N + 1,vd(100)); //当前状态为state还剩t轮时最优期望
    for (int t = 1;t <= N;t++)
    {
        for (int state = 0;state < 100;state++)
        {
            int as = state / 10;
            int bs = state % 10;
            double mx = -1e60;
            for (int a = 0;a < 3;a++)
            {
                if (hand[as][a] == 0) continue;
                double mn = 1e60;
                for (int b = 0;b < 3;b++)
                {
                    if (hand[bs][b] == 0) continue;
                    double sum = 0.0;
                    for (int q = 0;q < 9;q++)
                    {
                        int nst = nxt[state][a][b][q];
                        sum += dp[t - 1][nst];
                    }
                    double v = reward[a][b] + sum / 9.0;
                    mn = min(mn,v);
                }
                mx = max(mx,mn);
            }
            dp[t][state] = mx;
        }
    }

    double g = 0.0;
    for (int state = 0;state < 100;state++)
    {
        g += dp[N][state] - dp[N - 1][state];
    }
    g /= 100;
    auto gethandid = [&](string& s) 
    {
        vt cnt(3);
        for (char c : s) 
        {
            if (c == 'R') cnt[0]++;
            else if (c == 'S') cnt[1]++;
            else cnt[2]++;
        }
        return id[cnt[0]][cnt[1]][cnt[2]];
    };

    int _ = 1;
    cin >> _;
    cout << fixed << setprecision(10);
    while (_ --) 
    {
        ll k;
        string a,b;
        cin >> k >> a >> b;
        int as = gethandid(a);
        int bs = gethandid(b);
        int state = as * 10 + bs;
        double ans = 0.0;
        if (k <= N) ans = dp[k][state];
        else ans = dp[N][state] + 1.0 * (k - N) * g;
        cout << ans << endl;
    }

    return 0;
}