#include<bits/stdc++.h>
using namespace std;
int dp[25][205]; 
int price[25][25];
int obj[25];

int main()
{
    int n, m, c; 
    while ( cin>> n ){
        while ( n-- ) {
            cin>> m>> c;
            for (int i = 1 ; i <= c ; ++ i) {
                cin>> obj[i];
                for ( int j = 1 ; j <= obj[i] ; ++ j )
                    cin>> price[i][j];
            }
            
            for(int i = 0; i <= c; i++)
                for(int j = 0; j <= m; j++)
                    dp[i][j] = 0;

            dp[0][0] = 1;
            for ( int i = 1 ; i <= c ; ++ i )
                for ( int j = 0 ; j <= m ; ++ j )
                    if ( dp[i-1][j] )
                        for ( int k = 1 ; k <= obj[i] ; ++k )
                            if ( j+price[i][k] <= m )
                                dp[i][ j + price[i][k] ] = 1;
            
            int max = 0;
            for ( int i = m ; i >= 1 ; -- i ){
                if ( dp[c][i] ) {
                    max = i;
                    break;
                }
            }
            if (max) 
                cout<<max<<endl;
            else
                puts("no solution");
        }
    }
    return 0;
}
