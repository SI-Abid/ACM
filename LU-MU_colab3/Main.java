import java.util.Scanner;

public class Main {
    static long f[] = new long[100001];
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        f[0] = 0;
        for(int i=1;i<=100000;i++) {
            f[i] = f[i-1]+ oddSum(i);
            // System.out.println(i+" "+f[i]);
        }
        int t = sc.nextInt();
        while(t-->0){
            int l = sc.nextInt();
            int r = sc.nextInt();
            System.out.println(f[r]-f[l-1]);
        }
        sc.close();
    }
    static long oddSum(int n) {
        long sum = 0;
        for (int i = 1; i*i <= n; i++) {
            if(n%i == 0) {
                if(i%2==1)
                    sum += i;
                if(i!=n/i && (n/i)%2==1) {
                    sum += n/i;
                }
            }
        }
        return sum;
    }
}