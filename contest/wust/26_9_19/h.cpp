#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define fi first
#define se second
using vt = vector<int>;
using vvt = vector<vector<int>>;
using vll = vector<ll>;

void solve1()
{
    int n;
    cin >> n;
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    vt A(n);
    vvt ans;
    vvt t1,t2;
    int f1 = 0,f2 = 0,ffff = 0;
    for (int i = 0;i < n;i++) A[i] = i + 1;
    if (a == A) ffff = 1;
    do 
    {
        if (t1.size() < n)
        {
            t1.push_back(A);
            if (A == a) f1 = 1;
        }
        else 
        {   
            t2.push_back(A);
            if (A == a) f2 = 1;
            if (t2.size() == 2) break;
        }
    }while (next_permutation(A.begin(),A.end()));
    if (f1)
    {
        if (ffff) 
        {
            ans.push_back(t1[0]);
            for (int i = 2;i < n;i++) ans.push_back(t1[i]);
            ans.push_back(t2[0]);
        }
        else 
        {
            t1.push_back(t2[0]);
            t1.push_back(t2[1]);
            for (int i = 0;i < n + 2;i++)
            {
                if (t1[i] == a) 
                {
                    ans.pop_back();
                    ans.push_back(t1[i]);
                    i++;
                }
                else ans.push_back(t1[i]);
            }
        }
    }
    else 
    {
        for (int i = 0;i < n - 1;i++) ans.push_back(t1[i]);
        ans.push_back(a);
    }
    for (int i = 0;i < n;i++) 
    {
        for (int x : ans[i]) cout << x << " ";
        cout << endl;
    }
}
void solve2()
{
    int n;
    cin >> n;
    vvt a(n,vt(n));
    for (int i = 0;i < n;i++) 
    {
        for (int j = 0;j < n;j++) cin >> a[i][j];
    }
    sort(a.begin(),a.end());
    vt A(n);
    for (int i = 0;i < n;i++) A[i] = i + 1;
    map<vt,int> p;
    int id = 1;
    do
    {
        p[A] = id++;
        if (p.size() == n + 2) break;
    } while (next_permutation(A.begin(),A.end()));
    vt idx(n);
    for (int i = 0;i < n;i++) 
    {
        idx[i] = p[a[i]];
    }
    if (idx[1] == 3 && idx[n - 1] == n + 1) 
    {
        for (int x : a[0]) cout << x << " ";
        cout << endl;
        return ;
    }
    if (idx[0] == 2 && idx[1] != 3)
    {
        auto it = p.begin();
        it++;
        for (int x : it->fi) cout << x << " ";
        cout << endl;
        return ;
    }
    auto it = p.begin();
    it++;
    it++;
    for (int i = 1;i < n - 1;i++) 
    {
        // cout << i << " " << idx[i] << " " << idx[i - 1] << " " << idx[i + 1] << endl;
        if (idx[i] == i + 2 && idx[i + 1] == i + 4 && idx[i - 1] == i) 
        {
            for (int x : it->fi) cout << x << " ";
            cout << endl;
            return ;
        } 
        it++;
    }
    for (int x : a[n - 1]) cout << x << " ";
    cout << endl;
}
void solve()
{
    string op;
    cin >> op;
    if (op == "first") solve1();
    else solve2();
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int _ = 1;
    // cin >> _;
    while (_--) solve();

    return 0;
}