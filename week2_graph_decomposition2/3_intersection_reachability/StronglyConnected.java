import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class StronglyConnected {
    // we need two dfs for kosaraju's algorithm
    private static void dfs1(ArrayList<Integer>[] adj, int node, boolean[] visited, ArrayList<Integer> order) {
        visited[node] = true;
        for (int neighbor : adj[node]) {
            if (!visited[neighbor])
                dfs1(adj, neighbor, visited, order);
        }
        order.add(node);
    }

    private static void dfs2(ArrayList<Integer>[] adj, int node, boolean[] visited) {
        visited[node] = true;
        for (int neighbor : adj[node]) {
            if (!visited[neighbor])
                dfs2(adj, neighbor, visited);
        }
    }

    private static int numberOfStronglyConnectedComponents(ArrayList<Integer>[] adj) {
        // write your code here
        int n = adj.length;

        boolean[] visited = new boolean[n];
        ArrayList<Integer> order = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs1(adj, i, visited, order);
            }
        }

        ArrayList<Integer>[] rev = (ArrayList<Integer>[]) new ArrayList[n];
        for (int i = 0; i < n; i++) {
            rev[i] = new ArrayList<>();
        }

        for (int i = 0; i < n; i++) {
            for (int neighbor : adj[i]) {
                rev[neighbor].add(i);
            }
        }

        // reset
        visited = new boolean[n];
        Collections.reverse(order);

        int count = 0;
        for (int node : order) {
            if (!visited[node]) {
                dfs2(rev, node, visited);
                count++;
            }
        }

        return count;
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
        System.out.println(numberOfStronglyConnectedComponents(adj));
    }
}
