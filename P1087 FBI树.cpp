#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>

using namespace std;

char s[1026];
int n,l,r;
int tree[4100],a[1026];

int judge(int l,int r){
	bool f1=0,f2=0;
	for(int i=l;i<=r;i++){
		if(a[i]==1)f1=1;
		else f2=1;
		if(f1&&f2)return 2;
	}
	if(f1)return 1;
	else return 0;
}

void build(int l,int r,int cc){
	if(l>r||l<=0||r<=0)return;
	tree[cc]=judge(l,r);
	int mid=(l+r)>>1;
	if(l==r)return;
	build(l,mid,cc<<1);
	build(mid+1,r,(cc<<1)+1);
}

void back(int cc){
	int t=cc<<1;
	if(tree[t]!=-1)back(t);
	t++;
	if(tree[t]!=-1)back(t);
	char ans;
	if(tree[cc]==1)ans='I';
	else if(tree[cc]==0)ans='B';
	else ans='F';
	putchar(ans);
}

int main(){
	memset(tree,-1,sizeof(tree));
	scanf("%d",&n);
	scanf("%s",s);
	
	r=1<<n;
	int i=0;
	while(i<r){
		if(s[i]=='0')a[++i]=0;
		else a[++i]=1;
	}


	build(1,r,1);
	back(1);

	return 0;
}