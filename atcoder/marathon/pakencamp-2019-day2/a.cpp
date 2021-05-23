#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n=100;

	rep(j,n) printf("1%c",j<n-1?' ':'\n');
	rep(j,n) printf("%d%c",j%6==3?1:2,j<n-1?' ':'\n');
	rep(j,n) printf("%d%c",j%6==3?1:j%6==2||j%6==4?2:3,j<n-1?' ':'\n');
	rep(i,n-6) rep(j,n) printf("%d%c",abs(j%6-3)+1,j<n-1?' ':'\n');
	rep(j,n) printf("%d%c",j%6==0?4:j%6==1||j%6==5?3:2,j<n-1?' ':'\n');
	rep(j,n) printf("%d%c",j%6==0?4:3,j<n-1?' ':'\n');
	rep(j,n) printf("4%c",j<n-1?' ':'\n');

	return 0;
}
