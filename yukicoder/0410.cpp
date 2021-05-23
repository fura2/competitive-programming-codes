#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int x1,y1,x2,y2; cin>>x1>>y1>>x2>>y2;
	printf("%.9f\n",(abs(x2-x1)+abs(y2-y1))/2.0);
	return 0;
}
