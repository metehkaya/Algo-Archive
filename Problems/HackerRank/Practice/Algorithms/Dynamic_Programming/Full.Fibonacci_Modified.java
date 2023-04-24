import java.math.BigInteger;
import java.util.Scanner;

public class FibonacciModified {

	static int f1,f2,n;
	static BigInteger v1,v2;
	static BigInteger[] values;

	public static void main( String[] args ) {
		Scanner sc = new Scanner(System.in);
		f1 = sc.nextInt();
		f2 = sc.nextInt();
		n = sc.nextInt();
		values = new BigInteger[n];
		values[0] = BigInteger.valueOf(f1);
		values[1] = BigInteger.valueOf(f2);
		for( int i = 2 ; i < n ; i++ ) {
			v1 = values[i-2];
			v2 = values[i-1];
			v2 = v2.multiply(v2);
			values[i] = v1.add(v2);
		}
		System.out.println(values[n-1]);
	}
	
}