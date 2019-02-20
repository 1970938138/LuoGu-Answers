#include<cstdio>

using namespace std;

int main(){
	int a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	if(d<b){
		c--;
		d=d+60;
	}
	printf("%d %d",c-a,d-b);

	return 0;
}
