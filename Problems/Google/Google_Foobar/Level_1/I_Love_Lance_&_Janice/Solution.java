public class Solution {
	
	public static String solution(String s) {
		int n = s.length();
		String ans = "";
		for( int i = 0 ; i < n ; i++ ) {
			char c = s.charAt(i);
			int k = c - 'a';
			if(k >= 0 && k < 26) {
				k = 26 - k - 1;
				char cNew = (char) ('a' + k);
				ans += cNew;
			}
			else
				ans += c;
		}
		return ans;
	}
	
}
