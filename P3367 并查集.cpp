#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

char ans[200000];
int anscc=0;
int set[10000];

int query(int x){
	if(set[x]==x)
		return x;
	else
		return set[x]=query(set[x]);
}

void merge(int x,int y){
	int f1=query(x),f2=query(y);
	if(f1!=f2){
		if(rand()%2)
			set[f1]=f2;
		else
			set[f2]=f1;
	}
}



int main(){
	srand((unsigned)time(NULL));

	int n,m;
	scanf("%d %d",&n,&m);

	for(int i=0;i<n;i++){
		set[i]=i;
	}

	int xi,yi,zi;
	for(int i=0;i<m;i++){
		scanf("%d %d %d",&zi,&xi,&yi);
		if(zi==1){
			merge(xi,yi);
		}
		else{
			if(query(xi)==query(yi)){
				ans[anscc++]='Y';
			}
			else
				ans[anscc++]='N';

		}
	}

	for(int i=0;i<anscc;i++){
		putchar(ans[i]);
		putchar('\n');
	}

	return 0;
}
