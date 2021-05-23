#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	puts(n%400==0||n%100!=0&&n%4==0?"Yes":"No");
	return 0;
}
