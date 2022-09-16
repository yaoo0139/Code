import java.util.*;
class Main{
	public static long gcd(long a,long b){
		if(b==0)
			return a;
		else
			return gcd(b, a%b);
	}
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int counter = 1;
		while(sc.hasNext()){
			long lcm = sc.nextLong();
			if(lcm==0)
				break;
			System.out.println("Scenario "+ counter+":");
			counter++;
			boolean flag = false;
			for(long i = 1;i<=lcm && i<=1000000;i++){
			if(lcm % i > 0)
				continue;

				for(long j = i+1;j <= i+25; j++){
					if(lcm % j > 0)
						continue;

					long tmp = (i * j) / gcd(i, j);
					for(long k = j+1;k <= i+25 && k<=1000000; k++){
						if(lcm % k > 0)
							continue;

						long ans = (tmp *  k ) / gcd(tmp, k);
						if(ans == lcm){
							System.out.println(i+" "+j+" "+k);
							flag = true;
						}
					}
				}
			}
			if(!flag)
				System.out.println("Such bells don't exist");
			System.out.println("");
		}
	}
}