#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int c; scanf("%d",&c);
	for(int a=1;;a++) if(c%a==0) return printf("%d %d\n",a,c/a),0;
}
