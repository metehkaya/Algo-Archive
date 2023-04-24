import java.util.Arrays;

public class Solution {
	
	static int pwr2;
	static int[][] dp;
	
	public static boolean checkIfBitIs1(int bmask, int i) {
		return ( bmask & (1 << i) ) > 0;
	}
	
	public static boolean check( int leftCol , int rightCol , boolean[][] mat , int colID , int n ) {
		for( int i = 0 ; i < n ; i++ ) {
			int total = 0;
			if( checkIfBitIs1( leftCol , i ) )
				total++;
			if( checkIfBitIs1( leftCol , i+1 ) )
				total++;
			if( checkIfBitIs1( rightCol , i ) )
				total++;
			if( checkIfBitIs1( rightCol , i+1 ) )
				total++;
			if(total > 1)
				total = 0;
			int required = mat[i][colID] ? 1 : 0;
			if(total != required)
				return false;
		}
		return true;
	}
	
	public static int f( int colID , int prevCol , boolean[][] mat , int n , int m ) {
		if(colID == m)
			return 1;
		if(dp[colID][prevCol] != -1)
			return dp[colID][prevCol];
		dp[colID][prevCol] = 0;
		for( int bmask = 0 ; bmask < pwr2 ; bmask++ )
			if( check( prevCol , bmask , mat , colID , n ) )
				dp[colID][prevCol] += f( colID + 1 , bmask , mat , n , m );
		return dp[colID][prevCol];
	}
	
    public static int solution(boolean[][] mat) {
    	int n = mat.length;
    	int m = mat[0].length;
    	pwr2 = (1 << (n+1));
    	dp = new int[m][pwr2];
    	for( int[] row : dp )
    		Arrays.fill(row, -1);
    	int total = 0;
    	for( int i = 0 ; i < pwr2 ; i++ )
    		total += f( 0 , i , mat , n , m );
    	return total;
    }
	
}
