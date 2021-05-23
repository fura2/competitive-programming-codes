#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int p[3];
	rep(i,3) scanf("%d",&p[i]);

	sort(p,p+3);

	printf("%.15f\n",1.0*(p[1]+p[2])/(p[0]+p[1]+p[2]));

	return 0;
}
