#include<cstdio>

using namespace std;

int m,n,smemo=0,ememo=1;
int ans=0;
int memory[1010];
int input[1010];
bool flag=0;


int main(){
	scanf("%d%d",&m,&n);

	for(int i=0;i<n;i++){
		scanf("%d",&input[i]);
	}

	memory[0]=input[0];
	ans++;
	for(int i=1;i<n;i++){
		for(int j=smemo;j<ememo;j++){
			if(memory[j]==input[i]){
				break;
			}
			if(j==ememo-1){
				flag=1;
			}
		}
		if(flag==1){
			memory[ememo++]=input[i];
			flag=0;
			ans++;
		}
		if(ememo-smemo==m+1){
			smemo++;
		}
	}
	printf("%d",ans);

	return 0;
}