#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	double p,q; scanf("%lf%lf",&p,&q);
	puts((1-p)<p*(1-q)?"YES":"NO");
	return 0;
}
