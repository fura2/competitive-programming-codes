#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,x; scanf("%d%d",&n,&x);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	int cnt=0,y=x;
	rep(i,n){
		if(a[i]==-1) cnt++;
		else         y^=a[i];
	}

	if(cnt==0){
		if(y!=0) puts("-1");
		else rep(i,n) printf("%d%c",a[i],i<n-1?' ':'\n');
	}
	else if(cnt==1){
		if(y>x) puts("-1");
		else rep(i,n) printf("%d%c",a[i]!=-1?a[i]:y,i<n-1?' ':'\n');
	}
	else{
		if((y&~x)>x) puts("-1");
		else{
			int c=0;
			rep(i,n){
				if(a[i]!=-1) printf("%d",a[i]);
				else{
					if     (c==0) printf("%d",y&x);
					else if(c==1) printf("%d",y&~x);
					else          printf("0");
					c++;
				}
				putchar(i<n-1?' ':'\n');
			}
		}
	}

	return 0;
}
