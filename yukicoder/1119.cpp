#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int x,y,z; scanf("%d%d%d",&x,&y,&z);
	x%=3;
	y%=3;
	z%=3;
	puts(x*y*z%3==0?"Yes":"No");
	return 0;
}
