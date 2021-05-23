#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	double vl,vr,d,w;
	scanf("%lf%lf%lf%lf",&vl,&vr,&d,&w);
	printf("%.9f\n",w*d/(vl+vr));
	return 0;
}
