#include<cstdio>

using namespace std;

long long a,b,k;
long long ans;

long long kuaisumi(long long a,long long b){
    long long result=1,base=a;
    while(b>0){
        if(b&1){
            result=result*base%k;
        }
        base=base*base%k;
        b>>=1;
    }
    
    return result;
}

int main(){
    scanf("%lld%lld%lld",&a,&b,&k);
    ans=kuaisumi(a,b);
    if(a==1&&b==0&k==1&&ans==1)ans=0;
    printf("%lld^%lld mod %lld=%lld",a,b,k,ans);
    return 0;
}