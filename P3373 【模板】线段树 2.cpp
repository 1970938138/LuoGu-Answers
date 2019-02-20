#include<cstdio>
#include<cstring>
#define ll long long
#define Maxn 100010
#define Maxm 100010

using namespace std;

ll mo,m,n,t,x,y,k,a[Maxn],ans[Maxn<<2],tag[Maxn<<2],tagmul[Maxn<<2];

inline ll ls(ll p){return p<<1;}
inline ll rs(ll p){return p<<1|1;}

inline void pushup(ll p){ans[p]=(ans[ls(p)]+ans[rs(p)])%mo;}

void build(ll l,ll r,ll p){
	tag[p]=0;
	tagmul[p]=1;
	if(l==r){ans[p]=a[l]%mo;return;}
	ll mid=(l+r)>>1;
	build(l,mid,ls(p));
	build(mid+1,r,rs(p));
	pushup(p);

	return;
}

inline void tager(ll l,ll r,ll p,ll k){
	tag[p]+=k;
	tag[p]%=mo;
	ans[p]+=(r-l+1)*k;
	ans[p]%=mo;

	return;
}

inline void tagermul(ll l,ll r,ll p,ll k){
	tag[p]*=k;
	tag[p]%=mo;
	tagmul[p]*=k;
	tagmul[p]%=mo;
	ans[p]*=k;
	ans[p]%=mo;

	return;
}

inline void pushdown(ll l,ll r,ll p){
	ll mid=(l+r)>>1;
	tagermul(l,mid,ls(p),tagmul[p]);
	tagermul(mid+1,r,rs(p),tagmul[p]);
	tager(l,mid,ls(p),tag[p]);
	tager(mid+1,r,rs(p),tag[p]);
	tag[p]=0;
	tagmul[p]=1;

	return;
}

void update(ll dl,ll dr,ll nl,ll nr,ll p,ll k){
	if(dl<=nl&&nr<=dr){
		tager(nl,nr,p,k);
		return;
	}
	pushdown(nl,nr,p);
	ll mid=(nl+nr)>>1;
	if(dl<=mid)update(dl,dr,nl,mid,ls(p),k);
	if(mid<dr)update(dl,dr,mid+1,nr,rs(p),k);
	pushup(p);
}

void updatemul(ll dl,ll dr,ll nl,ll nr,ll p,ll k){
	if(dl<=nl&&nr<=dr){
		tagermul(nl,nr,p,k);
		return;
	}
	pushdown(nl,nr,p);
	ll mid=(nl+nr)>>1;
	if(dl<=mid)updatemul(dl,dr,nl,mid,ls(p),k);
	if(mid<dr)updatemul(dl,dr,mid+1,nr,rs(p),k);
	pushup(p);
}

ll query(ll dl,ll dr,ll nl,ll nr,ll p){
	if(dl<=nl&&nr<=dr){
		return ans[p];
	}
	ll res=0,mid=(nl+nr)>>1;
	pushdown(nl,nr,p);
	if(dl<=mid)res+=query(dl,dr,nl,mid,ls(p));
	if(mid<dr)res+=query(dl,dr,mid+1,nr,rs(p));
	return res%mo;
}

inline void scan(){
	scanf("%lld%lld%lld",&n,&m,&mo);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}

	return;
}

int main(){
	scan();
	build(1,n,1);
	while(m--){
		scanf("%lld",&t);
		if(t==1){
			scanf("%lld%lld%lld",&x,&y,&k);
			updatemul(x,y,1,n,1,k);
		}
		else if(t==2){
			scanf("%lld%lld%lld",&x,&y,&k);
			update(x,y,1,n,1,k);
		}
		else{
			scanf("%lld%lld",&x,&y);
			printf("%lld\n",query(x,y,1,n,1));
		}
	}

	return 0;
}