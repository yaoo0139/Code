#include<stdio.h>
#include<stdlib.h> 
int main()
{
	int p,n,c,i,j,blank,print;
	scanf("%d",&p);
	while(p!=0){
		c=1;
		n=4;
		print=1;
		while(n<p){
			c++;
			n=c*4;
		}
		blank=n-p;
		printf("Printing order for %d pages:\n",p);
		if (p==1)
			printf("Sheet 1, front: Blank, 1\n");
		else{
			for (i=1;i<=c;i++){
				for (j=1;j<=2;j++){
					if (j==1){
						if (blank>0){
							printf ("Sheet %d, front: Blank, %d\n",i,print);
							blank--;
						}
						else if (blank==0){
							printf ("Sheet %d, front: %d, %d\n",i,p,print);
							p--;
						}
						print++;
					}
					if (j==2){
						if (blank>0){
							printf ("Sheet %d, back : %d, Blank\n",i,print);
							blank--;
						}
						else if (blank==0){
							printf ("Sheet %d, back : %d, %d\n",i,print,p);
							p--;
						}
						print++;
					}
				}
			}
		}
		scanf("%d",&p);
	}
	return 0;
}
