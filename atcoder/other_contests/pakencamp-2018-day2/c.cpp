#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	int T;
	for(T=1;;T++){
		bool ok=true;
		rep(i,T){
			int color=0;
			for(int j=i;j<n;j+=T){
				if(a[j]!=0 && color!=0 && a[j]!=color) ok=false;
				if(color==0) color=a[j];
			}
		}
		if(ok) break;
	}
	printf("%d\n",T);

	return 0;
}
