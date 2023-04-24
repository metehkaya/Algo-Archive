import java.util.ArrayList;

public class Solution {
	
	static int combCnt = 0;
	static ArrayList<Integer> comb;
	static ArrayList<ArrayList<Integer>> lockLists;
	
	public static void initLists(int n) {
		comb = new ArrayList<Integer>();
		lockLists = new ArrayList<ArrayList<Integer>>();
		for( int i = 0 ; i < n ; i++ )
			lockLists.add( new ArrayList<Integer>() );
	}
	
	public static void addLocks(int k) {
		for( int i = 0 ; i < k ; i++ )
			lockLists.get( comb.get(i) ).add( combCnt );
		combCnt++;
	}
	
	public static void calcCombs(int curr, int chosen, int n, int k) {
		if(chosen == k) {
			addLocks(k);
			return;
		}
		comb.add(curr);
		calcCombs(curr+1, chosen+1, n, k);
		comb.remove(chosen);
		if(n-curr > k-chosen)
			calcCombs(curr+1, chosen, n, k);
	}
	
    public static int[][] solution(int nBunnies, int nRequired) {
    	int n = nBunnies;
    	int k = nBunnies - nRequired + 1;
    	initLists(n);
    	calcCombs(0, 0, n, k);
    	int m = lockLists.get(0).size();
    	int[][] locks = new int[n][m];
    	for( int i = 0 ; i < n ; i++ )
    		for( int j = 0 ; j < m ; j++ )
    			locks[i][j] = lockLists.get(i).get(j);
    	return locks;
    }
	
}
