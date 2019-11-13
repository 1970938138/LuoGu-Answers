#include <algorithm>
#include <cstdio>

using namespace std;
long long n,t,r,h;
struct nlnl
{
 long long x,y,z;       
}nl[120000];

int fa[120000];

int find(int x)
{
    if(fa[x]==x)  return x;
    else
    return fa[x]=find(fa[x]);        
}

void hb(int a,int b)
{
     fa[a]=b;    
}

bool cmp(nlnl a,nlnl b)
{
 return a.z<b.z;     
}

int main()
{
 int i,j;
 scanf("%lld",&t);
 while(t--)
 {
  scanf("%lld%lld%lld",&n,&h,&r); 
  for(j=1;j<=n;j++)
  {
   nl[j].x=0;
   nl[j].y=0;
   nl[j].z=0;                 
  }
  for(j=1;j<=n;j++)
   scanf("%lld%lld%lld",&nl[j].x,&nl[j].y,&nl[j].z);  
  for(j=1;j<=n+2;j++)
   fa[j]=j;
  sort(nl+1,nl+n+1,cmp);  
   for(i=1;i<=n;i++)
   {
       if(nl[i].z<=r)
       hb(find(n+2),find(i));					
   }   
   for(i=1;i<=n;i++)
   {
       if(nl[i].z+r>=h)
       hb(find(n+1),find(i));					
   }
   for(i=1;i<=n;i++)
       for(j=1;j<=n;j++)
       {
           long long q=(nl[i].x-nl[j].x)*(nl[i].x-nl[j].x)+(nl[i].y-nl[j].y)*(nl[i].y-nl[j].y)+(nl[i].z-nl[j].z)*(nl[i].z-nl[j].z);
           long long p=r*r*4;
           if(q<=p&&find(i)!=find(j))
           hb(find(i),find(j));					  
       }
   if(find(n+2)==find(n+1))
   printf("Yes\n");
   else
   printf("No\n");
 }    
 //system ("pause");
 return 0;
} 
