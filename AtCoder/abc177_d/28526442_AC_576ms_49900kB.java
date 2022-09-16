import java.util.*;
class Main{
	static int fa[] = new int[200050];
	public static int findroo(int x){
		if(fa[x]<0)
			return x;
		fa[x] = findroo(fa[x]);
		return fa[x];
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		while(sc.hasNext()){
			int n = sc.nextInt();
			int m = sc.nextInt();
			for(int i=1;i<=n;i++)
				fa[i] = -1;
			for(int i=0;i<m;i++){
				int a = sc.nextInt();
				int b = sc.nextInt();
				a = findroo(a);
				b = findroo(b);
				if(a!=b){
					fa[a] += fa[b];
					fa[b] = a;
				}
			}
			int ma = -1;
			for(int i=1;i<=n;i++)
				ma = Math.min(ma, fa[i]);
			System.out.println(Math.abs(ma));
		}
	}
}