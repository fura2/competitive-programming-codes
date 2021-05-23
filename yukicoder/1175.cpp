#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	double a,b,c,d,e,f;
	cin>>a>>b>>e>>c>>d>>f;

	double D=a*d-b*c;
	printf("%.15f %.15f\n",(d*e-b*f)/D,(-c*e+a*f)/D);

	return 0;
}
