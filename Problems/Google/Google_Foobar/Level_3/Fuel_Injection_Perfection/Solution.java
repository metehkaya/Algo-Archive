import java.math.BigInteger;
import java.util.HashMap;
import java.util.Map;

public class Solution {
	
	final static BigInteger ONE = new BigInteger("1");
	final static BigInteger TWO = new BigInteger("2");
	
	static Map<BigInteger,Integer> hashMap;
	
	public static int calcMoves(BigInteger n) {
		if(hashMap.containsKey(n))
			return hashMap.get(n);
		int res = -1;
		if(n.mod(TWO).equals(BigInteger.ZERO))
			res = calcMoves(n.divide(TWO)) + 1;
		else {
			BigInteger nPlus = n.add(ONE);
			BigInteger nMinus = n.subtract(ONE);
			res = Math.min(calcMoves(nPlus), calcMoves(nMinus)) + 1;
		}
		hashMap.put(n, res);
		return res;
	}
	
	public static int solution(String s) {
		hashMap = new HashMap<BigInteger,Integer>();
		hashMap.put(ONE, 0);
		BigInteger n = new BigInteger(s);
		return calcMoves(n);
	}
	
}
