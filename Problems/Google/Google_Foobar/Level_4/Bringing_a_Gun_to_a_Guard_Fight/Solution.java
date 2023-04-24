import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

public class Solution {

	public static class Point {
		int x, y;
		Point(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}
	
	public static class Slope {
		int diffX, diffY;
		Slope(int diffX, int diffY) {
			this.diffX = diffX;
			this.diffY = diffY;
		}
		public String toString() {
			return Integer.toString(diffX) + "-" + Integer.toString(diffY);
		}
	}
	
	public static int gcd(int x, int y) {
		if(y == 0)
			return x;
		return gcd(y, x%y);
	}
	
	public static Slope simplify(int x, int y) {
		if(x != 0 || y != 0) {
			int g = gcd(Math.abs(x), Math.abs(y));
			x /= g;
			y /= g;
		}
		return new Slope(x, y);
	}
	
	public static int calcDist1D(int x1, int x2) {
		return Math.abs(x1-x2);
	}
	
	public static int calcDist2D(int x1, int y1, int x2, int y2) {
		return (x1-x2) * (x1-x2) + (y1-y2) * (y1-y2);
	}
	
	public static int nextPoint(int x, int dim, int dir) {
		if(dir == 0)
			return -x;
		return 2*dim - x;
	}
	
	public static ArrayList<Integer> getPoints(int src, int dest, int dim, int mxDist) {
		ArrayList<Integer> list = new ArrayList<>();
		for( int dir = 0 ; dir < 2 ; dir++ ) {
			int curr = dest;
			int currDir = dir;
			while( calcDist1D(curr, src) <= mxDist ) {
				list.add(curr);
				curr = nextPoint(curr, dim, currDir);
				currDir = 1 - currDir;
			}
		}
		return list;
	}
	
	public static ArrayList<Point> getReflections(int[] src, int[] dest, int[] dims, int mxDist) {
		ArrayList<Point> points = new ArrayList<>();
		ArrayList<Integer> xs = getPoints(src[0], dest[0], dims[0], mxDist);
		ArrayList<Integer> ys = getPoints(src[1], dest[1], dims[1], mxDist);
		int srcX = src[0], srcY = src[1];
		int nx = xs.size(), ny = ys.size();
		for( int i = 0 ; i < nx ; i++ )
			for( int j = 0 ; j < ny ; j++ ) {
				int destX = xs.get(i);
				int destY = ys.get(j);
				if(calcDist2D(srcX, srcY, destX, destY) <= mxDist * mxDist)
					points.add( new Point( destX , destY ) );
			}
		return points;
	}
	
	public static Map<String,Integer> getSlopes(int[] src, int[] dest, int[] dims, int mxDist) {
		Map<String,Integer> slopes = new HashMap<String,Integer>();
		ArrayList<Point> points = getReflections(src, dest, dims, mxDist);
		int np = points.size();
		for( int i = 0 ; i < np ; i++ ) {
			Point p = points.get(i);
			int dist = calcDist2D( src[0] , src[1] , p.x , p.y );
			Slope s = simplify( p.x - src[0] , p.y - src[1] );
			String key = s.toString();
			if( !slopes.containsKey(key) )
				slopes.put(key, dist);
			else if( dist < slopes.get(key) ) {
				slopes.remove(key);
				slopes.put(key, dist);
			}
		}
		return slopes;
	}
	
    public static int solution(int[] dims, int[] myPos, int[] guardPos, int mxDist) {
    	int ans = 0;
    	Map<String,Integer> mySlopes = getSlopes(myPos, myPos, dims, mxDist);
    	Map<String,Integer> guardsSlopes = getSlopes(myPos, guardPos, dims, mxDist);
    	for( Map.Entry<String,Integer> entry : guardsSlopes.entrySet() ) {
    		String s = entry.getKey();
    		Integer dist = entry.getValue();
    		if( !mySlopes.containsKey(s) )
    			ans++;
    		else if( dist < mySlopes.get(s) )
    			ans++;
    	}
    	return ans;
    }
	
}
