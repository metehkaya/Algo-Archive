import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.BigInteger;

class Main {
	
	public static void main (String[] args) throws java.lang.Exception {
	    
	    int T,n;
	    
		final int N = 22001;
		
		BigInteger[] fib = new BigInteger[N];
		
		fib[0] = BigInteger.ONE;
		fib[1] = BigInteger.ONE;
		for( int i = 2 ; i < N ; i++ )
		    fib[i] = fib[i-1].add( fib[i-2] );
		
	    Scanner in = new Scanner(System.in);
	    T = in.nextInt();
		
		for( int i = 0 ; i < T ; i++ ) {
		    n = in.nextInt();
		    System.out.println( fib[n] );
		}
		
	}
	
}