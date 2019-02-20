#include<cstdio>
#include<algorithm>

using namespace std;

int t,m,v[110],ti[110],dp[1100],ma;

int main(){
    scanf("%d%d",&t,&m);
    for(int i=1;i<=m;i++){
        scanf("%d%d",&ti[i],&v[i]);
    }

    for(int i=1;i<=m;i++){
        for(int j=t;j>=0;j--){
            if(j>=ti[i]){
                dp[j]=max(dp[j-ti[i]]+v[i],dp[j]);
            }
        }
    }

    printf("%d",dp[t]);

    return 0;
}