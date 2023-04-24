import java.util.ArrayList;

public class Solution {
	
	public static class Frac {
		long num, den;
		Frac(long num, long den) {
			this.num = num;
			this.den = den;
			if(den < 0) {
				num = -num;
				den = -den;
			}
		}
		Frac(Frac frac, boolean isMinus) {
			this.num = frac.num;
			this.den = frac.den;
			if(isMinus)
				num = -num;
			if(den < 0) {
				num = -num;
				den = -den;
			}
		}
	}
	
	public static long gcd(long x, long y) {
		if(y == 0)
			return x;
		return gcd(y, x%y);
	}
	
	public static void simplifyFrac(Frac frac) {
		long num = Math.abs(frac.num);
		long den = Math.abs(frac.den);
		long gcdValue = gcd(num, den);
		frac.num /= gcdValue;
		frac.den /= gcdValue;
	}
	
	public static Frac multiplyFracs(Frac a, Frac b) {
		Frac c = new Frac(a.num*b.num, a.den*b.den);
		simplifyFrac(c);
		return c;
	}
	
	public static Frac addFracs(Frac a, Frac b) {
		Frac c = new Frac(a.num*b.den+a.den*b.num, a.den*b.den);
		simplifyFrac(c);
		return c;
	}
	
	public static Frac subtractFracs(Frac a, Frac b) {
		Frac c = new Frac(a.num*b.den-a.den*b.num, a.den*b.den);
		simplifyFrac(c);
		return c;
	}
	
	public static Frac[][] multiplyMatrices(Frac[][] a, Frac[][] b) {
		int n1 = a.length;
		int n2 = b[0].length;
		int n3 = a[0].length;
		Frac[][] c = new Frac[n1][n2];
		for( int i = 0 ; i < n1 ; i++ )
			for( int j = 0 ; j < n2 ; j++ ) {
				Frac sum = new Frac(0,1);
				for( int k = 0 ; k < n3 ; k++ ) {
					Frac temp = multiplyFracs(a[i][k], b[k][j]);
					sum = addFracs(sum, temp);
				}
				c[i][j] = sum;
			}
		return c;
	}
	
	public static Frac[][] copyFracMatrix(Frac[][] inpFrac) {
		int n = inpFrac.length;
		int m = inpFrac[0].length;
		Frac[][] outFrac = new Frac[n][m];
		for( int i = 0 ; i < n ; i++ )
			for( int j = 0 ; j < m ; j++ )
				outFrac[i][j] = new Frac(inpFrac[i][j], false);
		return outFrac;
	}
	
	public static Frac[][] addSourceRow2TargetRow(Frac[][] inpFrac, int srcRow, int destRow, Frac k) {
		Frac[][] outFrac = copyFracMatrix(inpFrac);
		int n = inpFrac[0].length;
		for( int i = 0 ; i < n ; i++ ) {
			Frac temp = new Frac(inpFrac[srcRow][i], false);
			temp = multiplyFracs(temp, k);
			outFrac[destRow][i] = addFracs(temp, inpFrac[destRow][i]);
		}
		return outFrac;
	}
	
	public static Frac[][] multiplyRowByK(Frac[][] inpFrac, int row, Frac k) {
		Frac[][] outFrac = copyFracMatrix(inpFrac);
		int n = inpFrac[0].length;
		for( int i = 0 ; i < n ; i++ )
			outFrac[row][i] = multiplyFracs(outFrac[row][i], k);
		return outFrac;
	}
	
	public static long lcm(long x, long y) {
		return x*y / gcd(x,y);
	}
	
	public static long lcmOfNums(long[] nums) {
		long len = nums.length;
		long lcmValue = nums[0];
		for( int i = 1 ; i < len ; i++ )
			lcmValue = lcm( lcmValue , nums[i] );
		return lcmValue;
	}
	
	public static Frac[][] computeFracMat(int[][] mat, ArrayList<Integer> absorbingVertices, ArrayList<Integer> nonAbsorbingVertices) {
		int n = mat.length;
		Frac[][] matFrac = new Frac[n][n];
    	for( int i = 0 ; i < n ; i++ ) {
    		long total = 0;
    		for( int j = 0 ; j < n ; j++ )
    			total = total + mat[i][j];
    		if(mat[i][i] == total) {
    			absorbingVertices.add(i);
    			for( int j = 0 ; j < n ; j++ ) {
    				if(i == j)
    					matFrac[i][i] = new Frac(1,1);
    				else
    					matFrac[i][j] = new Frac(0,1);
    			}
    		}
    		else {
    			nonAbsorbingVertices.add(i);
    			for( int j = 0 ; j < n ; j++ ) {
    				matFrac[i][j] = new Frac(mat[i][j], total);
    				simplifyFrac(matFrac[i][j]);
    			}
    		}
    	}
		return matFrac;
	}
	
	public static Frac[][] getSubmatrix(Frac[][] matFrac, ArrayList<Integer> firstGroup, ArrayList<Integer> secondGroup) {
		int n = firstGroup.size();
		int m = secondGroup.size();
		Frac[][] mat = new Frac[n][m];
		for( int i = 0 ; i < n ; i++ ) {
			int id1 = firstGroup.get(i);
			for( int j = 0 ; j < m ; j++ ) {
				int id2 = secondGroup.get(j);
				mat[i][j] = new Frac(matFrac[id1][id2], false);
			}
		}
		return mat;
	}
	
	public static Frac[][] getIdentityMatrix(int n) {
		Frac[][] I = new Frac[n][n];
		for( int i = 0 ; i < n ; i++ )
			for( int j = 0 ; j < n ; j++ ) {
				if(i == j)
					I[i][j] = new Frac(1,1);
				else
					I[i][j] = new Frac(0,1);
			}
		return I;
	}
	
	public static Frac[][] subtractMatrices(Frac[][] a, Frac[][] b) {
		int n = a.length;
		int m = a[0].length;
		Frac[][] c = new Frac[n][m];
		for( int i = 0 ; i < n ; i++ )
			for( int j = 0 ; j < m ; j++ )
				c[i][j] = subtractFracs(a[i][j], b[i][j]);
		return c;
	}
	
	public static Frac[][] calcInverse(Frac[][] fracMat) {
		int n = fracMat.length;
		Frac[][] invMat = getIdentityMatrix(n);
		for( int srcRow = 0 ; srcRow < n ; srcRow++ ) {
			Frac k = new Frac( fracMat[srcRow][srcRow].den , fracMat[srcRow][srcRow].num );
			fracMat = multiplyRowByK(fracMat, srcRow, k);
			invMat = multiplyRowByK(invMat, srcRow, k);
			for( int destRow = 0 ; destRow < n ; destRow++ )
				if( srcRow != destRow ) {
					k = new Frac(fracMat[destRow][srcRow], true);
					fracMat = addSourceRow2TargetRow(fracMat, srcRow, destRow, k);
					invMat = addSourceRow2TargetRow(invMat, srcRow, destRow, k);
				}
		}
		return invMat;
	}
	
	public static Frac[][] computeMatrixF(Frac[][] matQ) {
		Frac[][] Ir = getIdentityMatrix(matQ.length);
		Frac[][] temp = subtractMatrices(Ir, matQ);
		Frac[][] matF = calcInverse(temp);
		return matF;
	}
	
	public static long[] calcRes(Frac[][] matFR) {
		int n = matFR[0].length;
		long[] denList = new long[n];
		for( int i = 0 ; i < n ; i++ )
			denList[i] = matFR[0][i].den;
		long den = lcmOfNums(denList);
		long[] res = new long[n+1];
		for( int i = 0 ; i < n ; i++ ) {
			long mult = den / denList[i];
			res[i] = matFR[0][i].num * mult;
		}
		res[n] = den;
		return res;
	}
	
    public static int[] solution(int[][] mat) {
    	
    	long[] res = null;
    	
    	ArrayList<Integer> absorbingVertices = new ArrayList<Integer>();
    	ArrayList<Integer> nonAbsorbingVertices = new ArrayList<Integer>();
    	
    	Frac[][] matFrac = computeFracMat(mat, absorbingVertices, nonAbsorbingVertices);
    	
    	if(absorbingVertices.get(0) == 0) {
    		int n = absorbingVertices.size();
    		res = new long[n+1];
    		res[0] = res[n] = 1;
    		for( int i = 1 ; i < n ; i++ )
    			res[i] = 0;
    	}
    	else {
        	Frac[][] matQ = getSubmatrix(matFrac, nonAbsorbingVertices, nonAbsorbingVertices);
        	Frac[][] matR = getSubmatrix(matFrac, nonAbsorbingVertices, absorbingVertices);
        	Frac[][] matF = computeMatrixF(matQ);
        	Frac[][] matFR = multiplyMatrices(matF, matR);
        	res = calcRes(matFR);
    	}
    	
    	int[] ans = new int[res.length];
    	for( int i = 0 ; i < ans.length ; i++ )
    		ans[i] = (int) res[i];
    	
    	return ans;
    	
    }
    
}
