#include<bits/stdc++.h>
using namespace std;
using vt = vector<int>;
using vll = vector<long long>;

void solve()
{
    int n;
    cin >> n;
    priority_queue<int> q;
    for (int i = 0;i < n;i++)
    {
        int x;
        cin >> x;
        q.push(x);
    }
    long long ans = 0,cnt = 0;
    while (!q.empty())
    {
        if (q.top() - cnt > 0)
            ans += q.top() - cnt;
        else break;
        q.pop();
        cnt++;
    }
    cout << ans;

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int _ = 1;
    // cin >> _;
    while (_ --) solve();

    return 0;
}