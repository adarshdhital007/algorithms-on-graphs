import java.util.*;

public class Bipartite {

    private static boolean bfs(int start, ArrayList<Integer>[] adj, int[] colors) {
        Queue<Integer> q = new LinkedList<>();
        q.offer(start);               // push into queue
        colors[start] = 0;            // assign first color

        while (!q.isEmpty()) {
            int node = q.poll();      // remove from queue

            for (int neighbor : adj[node]) {
                if (colors[neighbor] == -1) {
                    colors[neighbor] = 1 - colors[node];  // opposite color
                    q.offer(neighbor);
                } 
                else if (colors[neighbor] == colors[node]) {
                    return false;     // same color conflict
                }
            }
        }
        return true;
    }

    private static int bipartite(ArrayList<Integer>[] adj) {
        int n = adj.length;
        int[] colors = new int[n];

        Arrays.fill(colors, -1);   

        for (int i = 0; i < n; i++) {
            if (colors[i] == -1) {
                if (!bfs(i, adj, colors)) {
                    return 0;
                }
            }
        }
        return 1;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();

        ArrayList<Integer>[] adj = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            adj[i] = new ArrayList<>();
        }

        for (int i = 0; i < m; i++) {
            int x = scanner.nextInt();
            int y = scanner.nextInt();

            adj[x - 1].add(y - 1);
            adj[y - 1].add(x - 1);
        }

        System.out.println(bipartite(adj));
    }
}