#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a0,a1,a2; scanf("%d%d%d",&a0,&a1,&a2);
	double r=1.0*(a2-a1)/(a1-a0);
	double d=a1-r*a0;
	printf("%.0f\n",r*a2+d);
	return 0;
}
