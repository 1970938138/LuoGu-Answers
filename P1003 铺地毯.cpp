#include<cstdio>
#include<vector>

using namespace std;

int ans=-1;
int n;

struct carpet{
	int x;
	int y;
	int lenx;
	int leny;
};

vector<carpet> input;

void judge(int point[2]){
	for(int i=0;i<n;i++){
		if(point[0]>=input[i].x && point[0]<=(input[i].x+input[i].lenx) && point[1]>=input[i].y && point[1]<=(input[i].y+input[i].leny)){
			ans=i+1;
		}
	}

	//没有覆盖地毯
}

int main(){
	
	scanf("%d",&n);

	carpet rawin;
	for(int i=0;i<n;i++){
		scanf("%d %d %d %d",&rawin.x,&rawin.y,&rawin.lenx,&rawin.leny);
		input.push_back(rawin);
	}

	int point[2];
	scanf("%d %d",&point[0],&point[1]);

	judge(point);

	printf("%d",ans);
}
