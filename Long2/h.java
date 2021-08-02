package Long2;

import java.util.Scanner;

class Prime {
    
    static Boolean[] prime = new Boolean[101];
    static String[] primeS = new String[101];
    
    // seive 
    static {
        prime[0] = false;
        prime[1] = false;
        for (int i = 2; i < prime.length; i++) {
            prime[i] = true;
            // primeS[i] = "" + i;
        }
        for (int i = 2; i < prime.length; i++) {
            for (int j = i * i; j < prime.length; j += i) {
                prime[j] = false;
            }
        }
    }
    
    static int[] primeDivisors(int n, int[] a) {
        // int[] a = new int[n + 1];
        for (int i = 2; i <= n; i++) {
            // System.out.println(n);
            if (prime[i] == true && n % i == 0) {
                // System.out.print(i + " ");
                while(n % i == 0) {
                    a[i]++;
                    n /= i;
                }
            }
        }
        if (n > 1)
            a[n]++;
        
        return a;
    }
    static void stringify() {
        int[] a = new int[101];
        for (int i = 2; i <= 100; i++) {
            a = primeDivisors(i, a);
            primeS[i] = String.format("2 (%d)", a[2]);
            for (int j = 3; j <= 100; j++)
                if (a[j] > 0)
                    primeS[i] = primeS[i].concat(String.format(" * %d (%d)", j, a[j]));
            // System.out.println(primeS[i]);
        }
    }
}   // end Prime

public class h {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        // Prime.seive();
        Prime.stringify();
        // for (int i = 0; i < 101; i++) {
        //     if (Prime.prime[i] == true)
        //         System.out.print(i + " ");        
        // }
        // System.out.println();
        for (int a0 = 1; a0 <= t; a0++) {
            int n = in.nextInt();
            System.out.print("Case "+a0+": "+n+" = ");
            System.out.println(Prime.primeS[n]);
        }
        in.close();    
    }
}
