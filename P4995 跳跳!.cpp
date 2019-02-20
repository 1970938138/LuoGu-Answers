#include<cstdio>
#include<algorithm>

using namespace std;

int n,h[333],head,tail,temp;
unsigned long long ans;

int main(){
	scanf("%d",&n);
	ans=0;
	h[0]=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&h[i]);
	}
	sort(h,h+n+1);
	head=0;tail=n;

	for(int i=1;i<=n;i++){
		temp=h[tail]-h[head];
		ans+=temp*temp;
		if(i%2)head++;
		else tail--;
	}

	printf("%lld",ans);

	return 0;
}