#include "bits/stdc++.h"

using namespace std;

int main(){
	int q; scanf("%d",&q);
	while(q--){
		int a,b; scanf("%d%d",&a,&b);
		if(a==b) puts("=");
		else{
			int sgn=(a-b)/abs(a-b);
			if(~sgn) putchar(62);
			else     putchar(60);
			puts("");
		}
	}
	return 0;
}
