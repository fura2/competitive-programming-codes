#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int x,y,z; scanf("%d%d%d",&x,&y,&z);
	while(z>0){
		if(x<y) x++, z--;
		else    y++, z--;
	}
	printf("%d\n",min(x,y));
	return 0;
}
