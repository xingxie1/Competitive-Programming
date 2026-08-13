#include<bits/stdc++.h>
using namespace std;
using vt = vector<int>;
using vll = vector<long long>;

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> a(3);
    for (int i = 1;i <= n;i++)
    {
        if (i % 2 == 0) a[0].push_back(i);
        else if (i % 3 == 0) a[1].push_back(i);
        else a[2].push_back(i);
    }
    while (a[2].size() && a[0].size() >= 2)
    {
        cout << a[2].back() << " ";
        a[2].pop_back();
        cout << a[0].back() << " ";
        a[0].pop_back();
        cout << a[0].back() << " ";
        a[0].pop_back();
        
    }
    while (a[2].size() && a[1].size() >= 2)
    {
        cout << a[2].back() << " ";
        a[2].pop_back();
        cout << a[1].back() << " ";
        a[1].pop_back();
        cout << a[1].back() << " ";
        a[1].pop_back();
        
    }
    while (!a[0].empty()) 
    {
        cout << a[0].back() << " ";
        a[0].pop_back();
    }
    while (!a[1].empty()) 
    {
        cout << a[1].back() << " ";
        a[1].pop_back();
    }
    while (!a[2].empty()) 
    {
        cout << a[2].back() << " ";
        a[2].pop_back();
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