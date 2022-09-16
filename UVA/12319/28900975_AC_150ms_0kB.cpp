#include<bits/stdc++.h>
using namespace std;
int main()
{
	int node;
	int r[105][105];
	int nr[105][105];
    while(cin>> node && node != 0){
	    for(int i=0;i<=node;i++){
	    	for(int j=0;j<=node;j++){
	    		if(i==j){
	    			r[i][j] = 0;
	    			nr[i][j] = 0;
	    		}
	    		else{
	    			r[i][j] = 1e3;
	    			nr[i][j] = 1e3;
	    		}
	    	}
	    }
	    int go;
	    char hold;
	    for(int i=1;i<=node;i++){
	    	cin>> go;
	    	while(scanf("%d%c",&go,&hold)){
	    		r[i][go] = 1;
	    		if(hold == '\n')
	    			break;
	    	}
	    }

	    for(int i=1;i<=node;i++){
	    	cin>> go;
	    	while(scanf("%d%c",&go,&hold)){
	    		nr[i][go] = 1;
	    		if(hold == '\n')
	    			break;
	    	}
	    }
	    int a, b;
	    cin>> a>>b;
	    for(int mid = 1;mid<=node;mid++){
	    	for(int i=1;i<=node;i++){
		    	for(int j=1;j<=node;j++){
		    		r[i][j] = min(r[i][j], r[i][mid]+r[mid][j]);
		    		nr[i][j] = min(nr[i][j], nr[i][mid]+nr[mid][j]);
	    		}
	    	}
	    }

	    bool flag = true;
	    for(int i=1;i<=node;i++){
	    	for(int j=1;j<=node;j++){
	    		if(i==j)
	    			continue;
	    		if(a*r[i][j]+b < nr[i][j]){
	    			flag = false;
	    			break;
	    		}
	    	}
	    	if(!flag)
	    		break;
	    }
	    cout<<(flag?"Yes":"No")<<endl;
    }
    return 0;
}