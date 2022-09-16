import java.util.*;
class Main{
	static Long SG(Long x){
		if(x%2==0)
			return x/2;
		else
			return SG(x/2);
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t>0){
			t--;
			int n = sc.nextInt();
			Long ans = sc.nextLong();
			ans = SG(ans);
			n--;
			while(n>0){
				n--;
				Long x = sc.nextLong();
				x = SG(x);
				ans = ans ^ x;
			}
			if(ans == 0)
				System.out.println("NO");
			else
				System.out.println("YES");
		}
	}
}
