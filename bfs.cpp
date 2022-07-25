#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
int n,m,total=0;
char a[105][105];
struct node 
{
	int a,b;
};
void bfs(int x,int y)
{
	queue<node>t;
	node o,p;
	p.a=x,p.b=y;
	t.push(p);
	while(!t.empty())
	{
		o=t.front();
		t.pop();
		a[o.a][o.b]='.';
		for(int i=-1;i<=1;i++)
			for(int j=-1;j<=1;j++)
			{
				p.a=o.a+i;
				p.b=o.b+j;
				if(p.a>=0&&p.a<n&&p.b>=0&&p.b<m&&a[p.a][p.b]=='W')
				t.push(p);
			} 
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
    scanf("%s",a[i]);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(a[i][j]=='W')
			{
				bfs(i,j);
				total++;
			}
	cout<<total;
}
