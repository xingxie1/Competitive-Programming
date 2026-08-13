#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vvt = vector<vector<int>>;
using vll = vector<long long>;
using vvll = vector<vector<long long>>;
using pii = pair<int,int>;
using vpii = vector<pair<int,int>>;
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
#define endl '\n'
const int mod = 998244353;
const int MOD = (int)1e9+7;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool ok = true;
	bool curr = (s[0] == '1');
	int cnt = 0;
	for (int i = 0; i < n; i++) 
    {
		if (s[i] == '0') cnt++;
		if (i == 0) continue;
		if (s[i] == s[i-1] && s[i] == '0') curr = false;
		if (s[i] == s[i-1] && s[i] == '1') 
        {
			if (curr && cnt % 2 == 1) ok = false;
			curr = true;
			cnt = 0;
		}
	}
	
	if (curr && cnt % 2 == 1 && s[n-1] == '1') ok = false;
		
	cout << (ok ? "YES" : "NO") << "\n";
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