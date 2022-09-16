import java.util.*;
class Main{
	static int arr[] = new int[100005];
	static int bit[] = new int[100005];
	static int ls[] = new int[100005];
	static int rs[] = new int[100005];
	public static int lowbit(int x){
		return x&-x;
	}
	public static void add(int i, int value){
		while(i<=100005){
			bit[i] += value;
			 i += lowbit(i);
		}
	}
	public static int query(int i){
		int sum = 0;
		while(i>0){
			sum += bit[i];
			i -= lowbit(i);
		}
		return sum;
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t>0){
			t--;
			Arrays.fill(bit, 0);
			int n = sc.nextInt();
			for(int i=1;i<=n;i++){
				arr[i] = sc.nextInt();
				ls[i] = query(arr[i]);
				add(arr[i], 1);
			}
			Arrays.fill(bit, 0);
			long sum = 0;
			for(int i=n;i>0;i--){
				rs[i] = query(arr[i]);
				add(arr[i], 1);
				sum += ls[i] * (n - i -rs[i]) +  (i - 1 - ls[i]) * rs[i];
			}
			System.out.println(sum);
		}
	}
}
