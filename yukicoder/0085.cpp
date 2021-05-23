#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int h,w; scanf("%d%d",&h,&w);
	puts(h*w==2||(h>1&&w>1&&h*w%2==0)?"YES":"NO");
	return 0;
}
