import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {
    static class Node implements Comparable<Node> {
        int data;
        long cost;
        Node(int data, long cost) {
            this.data = data;
            this.cost = cost;
        }
        @Override
        public int compareTo(Main.Node o) {
            return Long.compare(this.cost, o.cost);
        }
        
    }
    static class Graph {
        int V;
        ArrayList<ArrayList<Node>> forward_edges;
        ArrayList<ArrayList<Node>> backward_edges;
        public Graph(int V) {
            this.V = V;
            forward_edges = new ArrayList<ArrayList<Node>>();
            backward_edges = new ArrayList<ArrayList<Node>>();
            for (int i = 0; i < V; i++) {
                forward_edges.add(new ArrayList<Node>());
                backward_edges.add(new ArrayList<Node>());
            }
        }
        public void addEdge(int u, int v, long w) {
            forward_edges.get(u).add(new Node(v, w));
            backward_edges.get(v).add(new Node(u, w));
        }
        public long[] getDistFromS(int s) {
            long[] dist1 = new long[V];
            for (int i = 0; i < V; i++) {
                dist1[i] = Long.MAX_VALUE;
            }
            dist1[s] = 0;
            PriorityQueue<Node> pq = new PriorityQueue<Node>();
            pq.add(new Node(s, 0));
            while (!pq.isEmpty()) {
                Node curr = pq.poll();
                int u = curr.data;
                long du = curr.cost;
                for (Node n : forward_edges.get(u)) {
                    int v = n.data;
                    long dv = n.cost;
                    if (dist1[v] > du + dv) {
                        dist1[v] = du + dv;
                        pq.add(new Node(v, dist1[v]));
                    }
                }
            }
            return dist1;
        }
        public long[] getDistFromT(int t) {
            long[] dist2 = new long[V];
            for (int i = 0; i < V; i++) {
                dist2[i] = Long.MAX_VALUE;
            }
            dist2[t] = 0;
            PriorityQueue<Node> pq = new PriorityQueue<Node>();
            pq.add(new Node(t, 0));
            while (!pq.isEmpty()) {
                Node curr = pq.poll();
                int u = curr.data;
                long du = curr.cost;
                for (Node n : backward_edges.get(u)) {
                    int v = n.data;
                    long dv = n.cost;
                    if (dist2[v] > du + dv) {
                        dist2[v] = du + dv;
                        pq.add(new Node(v, dist2[v]));
                    }
                }
            }
            return dist2;
        }
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int tc = scanner.nextInt();
        while(tc-- > 0) {
            int n,m,k,s,t;
            n = scanner.nextInt();
            m = scanner.nextInt();
            k = scanner.nextInt();
            s = scanner.nextInt();
            t = scanner.nextInt();
            Graph graph = new Graph(n+1);
            for (int i = 0; i < m; i++) {
                int u = scanner.nextInt();
                int v = scanner.nextInt();
                long w = scanner.nextLong();
                graph.addEdge(u, v, w);
            }
            long[] dist1 = graph.getDistFromS(s);
            long[] dist2 = graph.getDistFromT(t);
            long ans = Long.MAX_VALUE;
            // loop till k
            int u,v,w;
            for (int i = 0; i < k; i++) {
                u = scanner.nextInt();
                v = scanner.nextInt();
                w = scanner.nextInt();
                ans = Math.min(ans, dist1[u] + dist2[v] + w);
                ans = Math.min(ans, dist1[v] + dist2[u] + w);
            }
            System.out.println(ans);
        }
        scanner.close();
    }
}