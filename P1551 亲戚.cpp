#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

int m,n,p;
int a,b;

int relation[5233];
bool ans[5233];

int query(int x){
	if(relation[x]==x)
		return x;
	else
		return relation[x]=query(relation[x]);
}

void merge(int x,int y){
	int f1=query(x);int f2=query(y);
	if(f1==f2)
		return;
	else{
		if(rand()%2)
			relation[f1]=f2;
		else
			relation[f2]=f1;
	}
}

int main(){
	srand((unsigned)time(NULL));

	scanf("%d%d%d",&n,&m,&p);

	for(int i=1;i<=n;i++){
		relation[i]=i;
	}

	for(int i=1;i<=m;i++){
		scanf("%d%d",&a,&b);
		merge(a,b);
	}

	for(int i=0;i<p;i++){
		scanf("%d%d",&a,&b);
		if(query(a)==query(b)){
			ans[i]=true;
		}
		else
			ans[i]=false;
	}

	for(int i=0;i<p;i++){
		if(ans[i]) printf("Yes\n");
		else printf("No\n");
	}
}
