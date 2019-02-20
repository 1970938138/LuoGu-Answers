#include<cstdio>

using namespace std;

double solve(int n){
	if(n<=150){
		return (double)n*0.4463;
	}
	else if(151<=n && n<=400){
		return (double)((double)((n-150)*0.4663)+66.945);
	}
	else{
		return (double)((double)((n-400)*0.5663)+183.52);
	}
}

int main(){
	int n;
	double ans;
	scanf("%d",&n);
	ans=solve(n);
	printf("%.1f",ans);

	return 0;
}
