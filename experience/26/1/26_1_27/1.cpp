#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int n;
long long l,r;
string w;
int p[N];
vector<int>g[N];
long long num=0;
void dfs(int fa,long long val,int u,int len){
	if(val>r) return;
	if(val>=l && len>=2){
		num++;
	}
	for(int v:g[u]){
		if(v==fa) continue;
		dfs(u,val*2+p[v],v,len+1);
	}
}
int main(){
	cin>>n>>l>>r>>w;
	for(int i=1;i<=n;i++) p[i]=w[i-1]-'0';
	for(int i=1;i<=n-1;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i=1;i<=n;i++){
		dfs(0,p[i],i,1);
	}
	cout<<num;
}
