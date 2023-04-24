public class Solution {
	
	public static int solution(String s) {
		int n = s.length();
		int total = 0, cntRight = 0;
		for( int i = 0 ; i < n ; i++ ) {
			char c = s.charAt(i);
			if( c == '<' )
				total += cntRight;
			else if( c == '>' )
				cntRight++;
		}
		return total*2;
	}
	
}
