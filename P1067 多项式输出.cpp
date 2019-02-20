#include<cstdio>
using namespace std;
int main(){
    int n,a;
    scanf("%d",&n);
    for(int i=n;i>=0;i--){
        scanf("%d",&a);
        if(a){
            if(i!=n&&a>0)printf("+");
            if(a>1||a<-1||i==0)printf("%d",a);
            if(a==-1&&i)printf("-");
            if(i>1)printf("x^%d",i);
            if(i==1)printf("x");
        }
    }
}
