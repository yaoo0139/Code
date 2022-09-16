import java.util.*;
class Main{
	static boolean flag;
	static int n, g;
	public static void dfs(int now, int dis){
		if(flag)
			return;
		if(now == g){
			flag = true;
			return;
		}
		if(now + dis <= n){
			dfs(now+dis, dis+2);
		}
		if(now - dis > 0)
			dfs(now-dis, dis+2);
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		while(sc.hasNext()){
			flag = false;
			n=sc.nextInt();
			g=sc.nextInt();
			if(g==0 && n==0)
				break;
			if(n>=49)
				flag = true;
			dfs(1, 3);
			if(!flag)
				System.out.println("Don't make fun of me!");
			else
				System.out.println("Let me try!");
		}
	}
}