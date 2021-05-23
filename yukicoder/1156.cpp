#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
/*
	int p[]={0,1,2,3,4,5,6,7,8,9};
	do{
		int a=p[0];
		int b=p[1];
		int c=p[2];
		int d=p[3];
		int e=p[4];
		int f=p[5];
		int g=p[6];
		int h=p[7];
		int i=p[8];
		int j=p[9];
		if(100*a+10*b+c+100*d+10*e+f==1000*b+100*g+10*c+b)
			printf("%d\n",1000*b+100*g+10*c+b);
		if(1000*a+100*a+10*b+c+1000*d+100*e+10*f+g==10000*h+1000*i+100*b+10*c+j)
			printf("%d\n",10000*h+1000*i+100*b+10*c+j);
		if(100000*a+10000*b+1000*c+100*d+10*e+f+10000*g+1000*d+100*f+10*h+i==100000*b+10000*d+1000*j+100*e+10*d+j)
			printf("%d\n",100000*b+10000*d+1000*j+100*e+10*d+j);
	}while(next_permutation(p,p+10));
*/
	int n; scanf("%d",&n);
	puts(n==1?"1051":n==2?"10947":"841341");
	return 0;
}
