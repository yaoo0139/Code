import java.util.*;
import java.math.*;
class Main{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		BigInteger f[] = new BigInteger[2005];
		f[1]=BigInteger.valueOf(1);
		f[2]=BigInteger.valueOf(3);
		for(int i=3;i<=2000;i++){
			f[i]=BigInteger.valueOf(3).multiply(f[i-1]).subtract(f[i-2]);
		}
		int n;
		while(sc.hasNext()){
			n = sc.nextInt();
			if(n==0)break;
			else{
				System.out.println(f[n]);
			}
		}
	}
}