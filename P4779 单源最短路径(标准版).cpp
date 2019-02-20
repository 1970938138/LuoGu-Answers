#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>

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

struct rec{
	int p,dist;
	rec();
	rec(int a,int b){
		p=a;
		dist=b;
	}
};

priority_queue<rec> q;

bool operator<(const rec &a,const rec &b){
	return a.dist>b.dist;
}

void add(int s,int e,int d){
	en++;
	ed[en].next=point[s];
	point[s]=en;
	ed[en].length=d;
	ed[en].end=e;
}

void dijkstra_heap(int s){
	memset(dist,0x3f,sizeof(dist));
	dist[s]=0;

	for(int a=1;a<=n;a++){
		q.push(rec(a,dist[a]));
	}

	for(int a=1;a<=n;a++){
		while(use[q.top().p]) q.pop();

		rec now=q.top();
		q.pop();
		int p=now.p;
		use[p]=true;

		for(int b=point[p];b;b=ed[b].next){
			if(dist[ed[b].end]>dist[p]+ed[b].length){
				dist[ed[b].end]=dist[p]+ed[b].length;
				q.push(rec(ed[b].end,dist[ed[b].end]));
			}
			
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

	dijkstra_heap(start);

	for(int i=1;i<=n;i++){
		if(dist[i]==1061109567) printf("2147483647 ");
		else printf("%d ",dist[i]);
	}

	return 0;
}
