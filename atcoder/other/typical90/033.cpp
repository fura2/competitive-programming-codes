#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int h,w; scanf("%d%d",&h,&w);
	if(h==1 || w==1){
		printf("%d\n",max(h,w));
	}
	else{
		printf("%d\n",((h+1)/2)*((w+1)/2));
	}
	return 0;
}
