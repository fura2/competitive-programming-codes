#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m; scanf("%d%d",&n,&m);

	static int g[490][160001]; // g[i][j] = (a+b+c=i, a^2+ab+ac+b^2+bc+c^2=j となる (a,b,c) の個数)
	rep(a,m+1){
		int x=a*a;
		if(x>n) break;
		rep(b,m+1){
			int y=(a+b)*b;
			if(x+y>n) break;
			rep(c,m+1){
				int z=(a+b+c)*c;
				if(x+y+z>n) break;
				g[a+b+c][x+y+z]++;

			}
		}
	}

	vector<int> ans(n+1);
	rep(i,490) rep(j,n+1) if(g[i][j]>0) {
		rep(d,m+1){
			int w=(i+d)*d;
			if(j+w>n) break;
			ans[j+w]+=g[i][j];
		}
	}
	rep(i,n+1) printf("%d\n",ans[i]);

	return 0;
}
