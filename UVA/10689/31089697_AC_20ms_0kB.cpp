#include<bits/stdc++.h>
using namespace std;
int mod[5] = {0, 10, 100, 1000, 10000};
int t, a, b, n, m;
struct Mat
{
    int mat[4][4];
};

Mat operator *(Mat a, Mat b)
{
    Mat c;
    memset(c.mat, 0, sizeof(c.mat));
    for(int i = 0; i < 2; ++i){
        for(int k = 0; k < 2; ++k){
            if(a.mat[i][k]){
                for(int j = 0; j < 2; ++j){
                    if(b.mat[k][j]){
                        c.mat[i][j] = (a.mat[i][k] * b.mat[k][j] + c.mat[i][j]) % mod[m];
                    }
                }
            }
        }
    }
    return c;
}

Mat operator ^(Mat a, int k)
{
    Mat c;
    memset(c.mat, 0, sizeof(c.mat));
    for(int i = 0; i < 2; ++i)
        c.mat[i][i]=1;
    while(k)
    {
        if(k & 1)
            c = c * a;
        a = a * a;

        k >>= 1;
    }

    return c;
}

int main()
{
    cin>> t;
    while(t--)
    {
        cin>> a>> b>> n>> m;
        if(n == 0)
        {
            printf("%d\n", a % mod[m]);
            continue;
        }
        Mat A;
        A.mat[0][0] = 1, A.mat[0][1] = 1;
        A.mat[1][0] = 1, A.mat[1][1] = 0;

        A = A ^ (n-1);

        printf("%d\n", (A.mat[0][0] * b + A.mat[0][1] * a) % mod[m]);
    }
    return 0;
}