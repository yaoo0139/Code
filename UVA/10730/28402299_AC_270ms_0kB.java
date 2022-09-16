import java.util.*;
class Main{
	static int num[] = new int[10010];
	static int pos[] = new int[10010];
	static int n;
	public static boolean solve(){
		for(int i = 0 ; i < n ; i++){
	        for(int j = 0 ; j < i ; j++){
	            int value = 2 * num[i] - num[j];  
	            if(value >= 0 && value < n && pos[value] > i)   
	             	return true; 
	        }
	    }
	    return false;
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String str;
		while(sc.hasNext()){
			str = sc.next();
			str = str.substring(0,str.length()-1);
			try{
				n = Integer.valueOf(str);
			}catch(NumberFormatException e){
				n = 0;
			}
			if(n==0)
				break;
			for(int i=0;i<n;i++){
				num[i] = sc.nextInt();
				pos[num[i]] = i;
			}
			if(solve())
				System.out.println("no");
			else
				System.out.println("yes");
		}
	}
}