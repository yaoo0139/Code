import java.util.*;
class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int arr[][] = new int[1025][1025];
		int t = sc.nextInt();
		while(t>0){
			t--;
			int n = sc.nextInt();
			int rat = sc.nextInt();
			for(int i=0;i<1025;i++){
				for(int j=0;j<1025;j++){
					arr[i][j] = 0;
				}
			}
			while(rat>0){
				rat--;
				int x = sc.nextInt();
				int y = sc.nextInt();
				int r = sc.nextInt();
				for(int i=x-n;i<=x+n;i++){
					for(int j=y-n;j<=y+n;j++){
						if(i>=0&&i<=1024&&j>=0&&j<=1024){
							arr[i][j]+=r;
						}
					}
				}
			}
			int nowx=0,nowy=0,nowr=0;
			for(int i=0;i<=1024;i++){
				for(int j=0;j<=1024;j++){
					if(arr[i][j]>nowr){
						nowr = arr[i][j];
						nowx = i;
						nowy = j;
					}
				}
			}
			System.out.println(nowx + " " + nowy + " " + nowr );
		}
	}
}