#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, a, b, i, counter, a1, b1, p, l=0;
    while(scanf("%d", &N)!=EOF){
    	if(N == 0){
    		break;
    	}
    	p=1;
    	if(l)
    		printf("\n");
    	l=1;
    	for (a = 10000; a <= 99999; a++){
    		
    		if(a % N == 0){
    			b = a / N;
    		}
    		else if(a % N != 0){
    			continue;
    		}
    		for(i = 0;i <= 9; i++){
    			counter = 0;
    			a1 = a;
    			b1 = b;
    			while(a1 != 0 || b1 != 0){
    				if(a1 % 10 == i){
    					counter++;	
    				}
    				if(b1 % 10 == i){
    					counter++;
    				}
    				if(counter > 1){
    					break;
    				}
    				a1 /= 10;
    				b1 /= 10;
    			}
    			if(counter > 1){
    				break;
    			}
    		}
    		if(b < 10000 && counter <= 1){
				printf("%d / 0%d = %d\n", a, b, N);
				p=0;
			}
			else if(b >= 10000 && counter <= 1){
				printf("%d / %d = %d\n", a, b, N);
				p=0;
			}
    	}
		if(p)
			printf("There are no solutions for %d.\n", N);
	}
   	return 0;
}