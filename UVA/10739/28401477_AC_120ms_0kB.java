import java.util.*;
class Main{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String str;
		int t = sc.nextInt();
		int dp[][] = new int[1005][1005];
		int counter = 0;
		while(t>0){
			counter++;
			t--;
			str = sc.next();
			for(int x = 1; x<str.length();x++){
				for(int i=0,j=i+x;j<str.length();i++,j++){
					if(str.charAt(i) == str.charAt(j))
						dp[i][j] = dp[i+1][j-1];
					else
						dp[i][j] = Math.min(Math.min(dp[i+1][j],dp[i][j-1]),dp[i+1][j-1])+1;
				}
			}
			System.out.println("Case " + counter +": " + dp[0][str.length()-1]);
		}
	}
}