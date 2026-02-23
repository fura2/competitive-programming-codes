#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int dx[]={0,-1,0,1},dy[]={1,0,-1,0};

int main(){
	int n; scanf("%d",&n);
	char B[9][10];
	rep(i,n) scanf("%s",B[i]);

	int i=1,j=1,next=4;
	while(1){
		printf("%c\n","RULD-"[next]);
		fflush(stdout);

		int x,y; scanf("%d%d",&x,&y);
		if(x>0){
			x--; y--;
			int k;
			for(k=0;k<4;k++){
				if(x==i+dx[k] && y==j+dy[k]) break;
			}
			if(k==4){
				next=4;
			}
			else{
				next=-1;
				rep(k2,4){
					int i2=i+dx[k2],j2=j+dy[k2];
					if(0<=i2 && i2<n && 0<=j2 && j2<n && B[i2][j2]=='.' && k2!=k) next=k2;
				}
				assert(next!=-1);
				i+=dx[next];
				j+=dy[next];
			}
		}
		else if(x==-1){
			next=4;
		}
		else if(x==-2){
			return -1;
		}
		else{
			break;
		}
	}

	return 0;
}
