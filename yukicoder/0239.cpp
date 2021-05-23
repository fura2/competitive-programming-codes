#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	string a[100][100];
	rep(i,n) rep(j,n) cin>>a[i][j];

	int ans=-1;
	rep(j,n){
		bool ok=true;
		rep(i,n) if(i!=j && a[i][j]!="nyanpass") ok=false;
		if(ok){
			if(ans==-1) ans=j+1;
			else return puts("-1"),0;
		} 
	}
	printf("%d\n",ans);

	return 0;
}
