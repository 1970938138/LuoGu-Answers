#include<cstdio>

using namespace std;

long long n,k,x,m,base,res;

int main(){
	scanf("%lld%lld%lld%lld",&n,&m,&k,&x);
	base=10;res=1;
	while(k>0){
		if(k&1){
			res=(res*base)%n;
		}
		base=(base*base)%n;
		k>>=1;
	}

	base=res*m+x;
	if(base>n)base%=n;
	printf("%lld",base);	

	return 0;
	
}