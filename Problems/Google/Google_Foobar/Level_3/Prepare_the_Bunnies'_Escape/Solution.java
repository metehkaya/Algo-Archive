import java.util.Queue;
import java.util.LinkedList;

public class Solution {
	
	public static class Position {
		int row, col;
		boolean removedWall;
		Position(int row, int col, boolean removedWall) {
			this.row = row;
			this.col = col;
			this.removedWall = removedWall;
		}
	}
	
	final static int[][] DIR = { {0,1} , {0,-1} , {1,0} , {-1,0} };
	
	public static int[] bfs(int[][] map) {
		
		int n = map.length;
		int m = map[0].length;
		Queue<Position> q = new LinkedList<>();
		
		int[][][] dist = new int[n][m][2];
		for( int i = 0 ; i < n ; i++ )
			for( int j = 0 ; j < m ; j++ )
				for( int k = 0 ; k < 2 ; k++ )
					dist[i][j][k] = -1;
		
		dist[0][0][0] = 1;
		q.add( new Position(0,0,false) );
		
		while(!q.isEmpty()) {
			Position p = q.peek();
			q.remove();
			int row = p.row;
			int col = p.col;
			boolean removedWall = p.removedWall;
			for( int i = 0 ; i < 4 ; i++ ) {
				int row2 = row + DIR[i][0];
				int col2 = col + DIR[i][1];
				if(row2 >= 0 && row2 < n && col2 >= 0 && col2 < m) {
					if(map[row2][col2] == 0) {
						int state = removedWall ? 1 : 0;
						if(dist[row2][col2][state] == -1) {
							q.add( new Position(row2,col2,removedWall) );
							dist[row2][col2][state] = dist[row][col][state] + 1;
						}
					}
					else if(!removedWall && dist[row2][col2][1] == -1) {
						q.add( new Position(row2,col2,true) );
						dist[row2][col2][1] = dist[row][col][0] + 1;
					}
				}
			}
		}
		
		int[] dist2Exit = { dist[n-1][m-1][0] , dist[n-1][m-1][1] };
		return dist2Exit;
		
	}
	
    public static int solution(int[][] map) {
    	int[] dist = bfs(map);
    	int minDist = map.length * map[0].length;
    	for( int i = 0 ; i < 2 ; i++ )
    		if( dist[i] != -1 )
    			minDist = Math.min(minDist, dist[i]);
    	return minDist;
    }
	
}
