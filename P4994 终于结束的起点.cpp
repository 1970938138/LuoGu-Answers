#include<cstdio>

using namespace std;

unsigned long long n,m,fiba,fibb,fibc,fib[100];

int main(){
	scanf("%lld",&m);
	fib[0]=0;
	fib[1]=1;
	fib[2]=1;
	n=2;

	while(1){
		fib[3]=(fib[2]%m+fib[1]%m)%m;
		if(fib[3]==1&&fib[2]==0){
			printf("%lld",n);
			break;
		}
		fib[1]=fib[2];
		fib[2]=fib[3];
		n++;
	}

	return 0;
}