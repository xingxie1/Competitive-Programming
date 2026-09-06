#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
using ll = long long;
using vt = vector<int>;
using vll = vector<ll>;
using pii = pair<int,int>;
using vpii = vector<pii>;

struct node
{
    string name;
    int x;
    int id;
};
void solve()
{
    int n;
    cin >> n;
    vector<node> a(n);
    for (int i = 0;i < n;i++)
    {
        cin >> a[i].name;
        int p;
        cin >> p;
        int s = p * 10;
        int mx = 0,mn = 10;
        for (int j = 0;j < 6;j++)
        {
            int x;
            cin >> x;
            mx = max(mx,x);
            mn = min(mn,x);
            s += x;
        }
        s -= mx;
        s -= mn;
        a[i].x = s;
        a[i].id = i;
    }
    ranges::sort(a,{},[&](auto& b){
        return pair{-b.x,b.id};
    });
    int cnt = 0, cc = 0;
    for (int i = 0;i < n;i++) 
    {
        int j = i;
        if (cnt >= 3 || cc >= 1000) return ;
        while (j < n && cc < 1000 && a[j].x == a[i].x) 
        {
            cout << a[j].name << " " << a[j].x << endl;
            cc++;
            cnt++;
            j++;
        }
        i = j - 1;
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int _ = 1;
    // cin >> _;
    while (_--) solve();

}