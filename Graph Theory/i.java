import java.io.*;
import java.util.Scanner;
import java.util.Vector;

class Graph {
    Vector<Vector<Integer>> adj = new Vector<Vector<Integer>>();
    boolean[] visited = new boolean[100];

    public Graph() {
        for (int i = 1; i < 100; i++) {
            adj.add(new Vector<Integer>());
        }
        for (int i = 1; i < 100; i++) {
            visited[i] = false;
        }
    }

    public void addEdge(int u, int v) {
        adj.get(u).add(v);
        adj.get(v).add(u);
    }
    
    public void dfs(int u) {
        visited[u] = true;
        for (int v : adj.get(u)) 
            if (!visited[v]) 
                dfs(v);
            
    }
}

public class i {
    public static void main(String[] args) {
        Scanner in = getIO(args);
        try {
            int t = Integer.parseInt(in.nextLine());
            in.nextLine();
            while(t-- > 0) {
                int n = in.nextLine().charAt(0)-'A';
                int cnt = 0;
                Graph g = new Graph();
                while(in.hasNextLine()) {
                    char[] tokens = in.nextLine().toCharArray();
                    if(tokens.length == 0)  break;
                    int u = tokens[0]-'A'+1;
                    int v = tokens[1]-'A'+1;
                    g.addEdge(u, v);
                }
                for (int i = 1; i <= n+1; i++) {
                    if (!g.visited[i]) {
                        g.dfs(i);
                        cnt++;
                    }
                }
                System.out.println(cnt);
                if(t != 0)  System.out.println(); 
            }
            in.close();
        } catch (Exception e) {
            System.out.println(e);
        }
    }
    static Scanner getIO(String[] args) {
        if(args.length == 1) {
            try {
                return new Scanner(new FileReader(args[0]));
            } catch (Exception e) {
                System.out.println("Error: " + e.getMessage());
            }
        }
        return new Scanner(new InputStreamReader(System.in));
    }
}