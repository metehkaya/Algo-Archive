import java.util.*;

public class Main {

	static int N,M,K;

    static int[][] table;
    static int[][] preTable;
    
    static ArrayList<int[][]> list;

    public static int f() {
        for (int i = 0; i < list.size(); i++) {
            if (Arrays.deepEquals(list.get(i), table)) {
                return i;
            }
        }
        return -1;
    }
    
    public static int[][] cpytable(int[][] the_board, int i, int j) {
        int[][] cpyTable = new int[i][j];
        for (int k = 0; k < i;k++)
            for(int m = 0; m < j; m++){
                cpyTable[k][m] = the_board[k][m];
            }
        return cpyTable;
    }
    
    public static void main(String[] args) {
        
		Scanner scan = new Scanner(System.in);
        
		N = scan.nextInt();
        M = scan.nextInt();
        K = scan.nextInt();
		
		list = new ArrayList<int[][]>();
        
        table = new int[N][M];
        preTable = new int[N][M];
        
        
        scan.nextLine();
        for (int i = 0; i < N; i++){
            String line = scan.nextLine();
            line = line.replace("*", "1");
            line = line.replace("-", "0");
            for (int j = 0; j < line.length(); j++) {
                table[i][j] = Integer.parseInt(line.substring(j, j+1));
                preTable[i][j] = Integer.parseInt(line.substring(j, j+1));
            }
        }
        
        int ind = -1;
        boolean found = false;
        
        for (int cnt = 0; cnt < K; cnt++) {
            for (int i = 0; i < table.length; i++) {
                for (int j = 0; j < table[0].length; j++) {
                    if (get(i, j, preTable) == 1) {
                        if (getcost(i, j, preTable) < 2) {
                            table[i][j] = 0;
                        } else if (getcost(i, j, preTable) == 2 || getcost(i, j, preTable) == 3) {
                        } else if (getcost(i, j, preTable) > 3) {
                            table[i][j] = 0;
                        }
                    } else {
                        if (getcost(i, j, preTable) == 3) {
                            table[i][j] = 1;
                        }
                    }
                }
            }
            
            if (!found) {
                ind = f();
            }
            if (ind != -1) {
                int mod = cnt - ind;
                K = cnt + (K % mod);
                if (K== cnt + 1)
                    break;
                found = true;
                list = null;
                ind = -1;
            }
            preTable = cpytable(table, table.length, table[0].length);
            if (!found) {
                list.add(cpytable(table, table.length, table[0].length));
            }
        }
        
        for (int i = 0; i < table.length; i++) {
            for (int j = 0; j < table[i].length; j++) {
                System.out.print(table[i][j] == 1 ? "*" : "-");
            }
            System.out.println();
        }
    }

    public static int getcost(int i, int j, int[][] myTable) {
        int cost = 0;
        cost += get(i + 1, j, myTable);
        cost += get(i - 1, j, myTable);
        cost += get(i - 1, j + 1, myTable);
        cost += get(i + 1, j + 1, myTable);
        cost += get(i - 1, j - 1, myTable);
        cost += get(i, j - 1, myTable);
        cost += get(i, j + 1, myTable);
        cost += get(i + 1, j - 1, myTable);
        return cost;
    }

    public static int get(int i, int j, int[][] myTable) {
        int k = (myTable.length + i) % myTable.length;
        int p = (myTable[0].length + j) % myTable[0].length;
        return myTable[k][p];
    }

}