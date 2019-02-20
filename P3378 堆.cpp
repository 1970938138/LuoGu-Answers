#include<cstdio>
#include<queue>

using namespace std;

priority_queue<int> q;

int anscc=0;
int ans[1000000];

int main(){
	int n=0;
	scanf("%d",&n);

	int temp=0;
	for(int i=0;i<n;i++){
		scanf("%d",&temp);
		if(temp==1){
			scanf("%d",&temp);
			q.push(-temp);
		}
		else if(temp==2)
			ans[anscc++]=-q.top();
			
		else if(temp==3)
			q.pop();
	}

	for(int i=0;i<anscc;i++){
		printf("%d\n",ans[i]);
	}

	return 0;
}
