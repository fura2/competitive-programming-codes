#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int r=1,h=0;
	while(r<=100){
		int w=0;
		while(r<=100 && w+2*r<=1500){
			printf("%d %d\n",w+r,h+r);
			w+=2*r;
			r++;
		}
		h+=2*(r-1);
	}
	return 0;
}
