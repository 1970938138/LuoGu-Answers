#include<cstdio>
#include<cstring>

using namespace std;

int temp,temp2;

struct num{
	int position;
	int contain;
};

struct priqueue{
	int front,tail;
	num z[500000];

	priqueue(){
		front=0;
		tail=-1;
		//memset(z,0,sizeof(z));
	}

	void push(int x,int posi){
		while(front<=tail && x<=z[tail].contain){
			tail--;
		}
		tail++;
		z[tail].contain=x;
		z[tail].position=posi;
	}

	void pop(){
		front++;
	}

	/*
	int pop(){
		front++;
		return z[front-1];
	}
	*/

	int topposi(){
		return z[front].position;
	}

	int top(){
		return z[front].contain;
	}
}qmin,qmax;

int main(){
	int n=0,k=0;
	scanf("%d %d",&n,&k);

	int ansmin[n-k],ansmax[n-k];

	for(int i=0;i<k;i++){
		scanf("%d",&temp);
		qmin.push(temp,i);
		qmax.push(-temp,i);
	}
	ansmin[0]=qmin.top();
	ansmax[0]=-qmax.top();

	for(int i=k;i<n;i++){
		temp2=i-k;

		if(qmin.topposi()==temp2) qmin.pop();
		if(qmax.topposi()==temp2) qmax.pop();

		scanf("%d",&temp);
		qmin.push(temp,i);
		qmax.push(-temp,i);


		ansmin[temp2+1]=qmin.top();
		ansmax[temp2+1]=-qmax.top();
	}

	for(int i=0;i<=n-k;i++){
		printf("%d ",ansmin[i]);
	}
	printf("\n");
	for(int i=0;i<=n-k;i++){
		printf("%d ",ansmax[i]);
	}
	printf("\n");

	return 0;

}
