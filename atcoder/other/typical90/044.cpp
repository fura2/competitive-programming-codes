#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,q; scanf("%d%d",&n,&q);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	int offset=0;
	rep(_,q){
		int type,x,y; scanf("%d%d%d",&type,&x,&y);
		if(type==1){
			x--; y--;
			swap(a[(x-offset+n)%n],a[(y-offset+n)%n]);
		}
		else if(type==2){
			offset=(offset+1)%n;
		}
		else{
			x--;
			printf("%d\n",a[(x-offset+n)%n]);
		}
	}

	return 0;
}
