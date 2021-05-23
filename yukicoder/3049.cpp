#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	rep(c2,128) rep(c3,128) if(isprint(c2) && isprint(c3)) {
		if(char('Y'+c2+c3)=='1' && char('Y'^c2^c3)=='O'){
			printf("Y%c%c\n",c2,c3);
			return 0;
		}
	}
	return 0;
}
