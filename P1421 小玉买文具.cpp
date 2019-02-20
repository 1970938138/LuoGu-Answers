#include<cstdio>
#include<cmath>

using namespace std;

int main(){
	int y,j;
	scanf("%d %d",&y,&j);

	double money;
	money=y+(double)j/10;

	int ans;
	ans=floor(money/1.9);
	printf("%d",ans);

	return 0;
}
