#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int maxn=500050;
int n,m,start;
int en=0;
int point[maxn];
int dist[maxn];
bool use[maxn];
struct edge{
	int next;
	int length,end;
	edge(){
		next=0;
	}
}ed[maxn];

void add(int s,int e,int d){
	en++;
	ed[en].next=point[s];
	point[s]=en;
	ed[en].length=d;
	ed[en].end=e;
}

void dijkstra(int s){
	memset(dist,0x3f,sizeof(dist));
	dist[s]=0;

	/*
	for(int a=s;a<=n;a++){
		int p=0;
		for(int b=1;b<=n;b++){
			if(!use[b] && (p==0 || dist[b]<dist[p])) p=b;
		}
		use[p]=true;

		for(int b=point[p];b;b=ed[b].next){
			dist[ed[b].end]=min(dist[ed[b].end],dist[p]+ed[b].length);
		}
	}

	for(int a=1;a<=s;a++){
		int p=0;
		for(int b=1;b<=n;b++){
			if(!use[b] && (p==0 || dist[b]<dist[p])) p=b;
		}
		use[p]=true;

		for(int b=point[p];b;b=ed[b].next){
			dist[ed[b].end]=min(dist[ed[b].end],dist[p]+ed[b].length);
		}
	}
	*/
	for(int a=1;a<=n;a++){
		int p=0;
		for(int b=1;b<=n;b++){
			if(!use[b] && (p==0 || dist[b]<dist[p])) p=b;
		}
		use[p]=true;

		for(int b=point[p];b;b=ed[b].next){
			dist[ed[b].end]=min(dist[ed[b].end],dist[p]+ed[b].length);
		}
	}
}

int main(){
	scanf("%d%d%d",&n,&m,&start);
	int s,e,d;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&s,&e,&d);
		add(s,e,d);
	}

	dijkstra(start);

	for(int i=1;i<=n;i++){
		if(dist[i]==1061109567) printf("2147483647 ");
		else printf("%d ",dist[i]);
	}

	return 0;
}
