import java.util.*;
class Main{
	public static void main(String[] args) {
		int arr[][] = new int[100050][5];
		int dp[][] = new int[100050][5];
		Scanner sc = new Scanner(System.in);
		while(sc.hasNext()){
			int n = sc.nextInt();
			for(int i=1;i<=n;i++){
				for(int j=1;j<=3;j++){
					arr[i][j] = sc.nextInt();
				}
			}
			dp[1][1] = arr[1][1];
			dp[1][2] = arr[1][2];
			dp[1][3] = arr[1][3];
			for(int i=2;i<=n;i++){
				dp[i][1] = Math.max(dp[i-1][2],dp[i-1][3]) + arr[i][1];
				dp[i][2] = Math.max(dp[i-1][1],dp[i-1][3]) + arr[i][2];
				dp[i][3] = Math.max(dp[i-1][1],dp[i-1][2]) + arr[i][3];
			}
			System.out.println(Math.max(Math.max(dp[n][1],dp[n][2]),dp[n][3]));
		}
	}
}