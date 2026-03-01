import java.util.ArrayList;
import java.util.Scanner;

public class Acyclicity {
    static boolean dfs(ArrayList<Integer>[] adj, int node, boolean[] visited, boolean[] recStack) {
        if (recStack[node])
            return true;
        if (visited[node])
            return false;

        recStack[node] = true;
        visited[node] = true;

        for (int neighbor : adj[node]) {
            if (dfs(adj, neighbor, visited, recStack)) {
                return true;
            }
        }
        recStack[node] = false;
        return false;
    }

    private static int acyclic(ArrayList<Integer>[] adj) {
        // write your code here
        int n = adj.length;
        boolean[] recStack = new boolean[n];
        boolean[] visited = new boolean[n];

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                if (dfs(adj, i, visited, recStack)) {
                    return 1;
                }
            }
        }
        return 0;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        ArrayList<Integer>[] adj = (ArrayList<Integer>[]) new ArrayList[n];
        for (int i = 0; i < n; i++) {
            adj[i] = new ArrayList<Integer>();
        }
        for (int i = 0; i < m; i++) {
            int x, y;
            x = scanner.nextInt();
            y = scanner.nextInt();
            adj[x - 1].add(y - 1);
        }
        System.out.println(acyclic(adj));
    }
}
