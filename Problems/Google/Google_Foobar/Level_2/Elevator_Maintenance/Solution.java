import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;

public class Solution {
	
	public static String[] solution(String[] l) {
		Arrays.sort(l, new Comparator<String>() {
			public ArrayList<Integer> getVersion(String s) {
				int len = s.length();
				ArrayList<Integer> ver = new ArrayList<Integer>();
				int num = 0;
				for( int i = 0 ; i < len ; i++ ) {
					char c = s.charAt(i);
					if(c == '.') {
						ver.add(num);
						num = 0;
					}
					else {
						int dig = c - '0';
						num = num * 10 + dig;
					}
				}
				ver.add(num);
				return ver;
			}
			@Override
			public int compare(String s1, String s2) {
				ArrayList<Integer> ver1 = getVersion(s1);
				ArrayList<Integer> ver2 = getVersion(s2);
				int n1 = ver1.size();
				int n2 = ver2.size();
				for( int i = 0 ; i < n1 && i < n2 ; i++ )
					if( ver1.get(i) < ver2.get(i) )
						return -1;
					else if( ver1.get(i) > ver2.get(i) )
						return +1;
				if(n1 < n2)
					return -1;
				else if(n1 > n2)
					return +1;
				return 0;
			}
		});
		return l;
	}
	
}
