#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,q; scanf("%d%d",&n,&q);

	bool A[100][100]={};
	rep(_,q){
		int t; scanf("%d",&t);
		if(t==1){
			int a,b; scanf("%d%d",&a,&b); a--; b--;
			A[a][b]=true;
		}
		else if(t==2){
			int a; scanf("%d",&a); a--;
			rep(i,n) if(A[i][a]) A[a][i]=true;
		}
		else{
			int a; scanf("%d",&a); a--;
			bool A2[100]={};
			rep(i,n) if(A[a][i]) rep(j,n) if(j!=a && A[i][j]) A2[j]=true;
			rep(i,n) if(A2[i]) A[a][i]=true;
		}
	}

	rep(i,n){ rep(j,n) putchar(A[i][j]?'Y':'N'); puts(""); }

	return 0;
}
