#include<cstdio>
#define Maxn 10000001
#define Maxm 100001
#define ll long long

using namespace std;

bool notpr[Maxn];
ll n,m,prime[Maxn],cc,t;

void solve(){
	for(ll i=2;i<=Maxn;i++){
		if(!notpr[i])prime[++cc]=i;
		for(ll j=1;j<=cc&&i*prime[j]<=Maxn;j++){
			notpr[i*prime[j]]=1;
			if(i%prime[j]==0)break;
		}
	}
}

int main(){
	notpr[0]=1;
	notpr[1]=1;
	solve();
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=m;i++){
		scanf("%lld",&t);
		if(notpr[t])printf("No\n");
		else printf("Yes\n");
	}

	return 0;
}