package long3;

import java.util.Arrays;
import java.util.Scanner;

class Sieve {
    public static boolean[] isPrime;
    public static boolean[] primeList;
    public static void sieve(int n) {
        isPrime = new boolean[n + 5];
        isPrime[0] = isPrime[1] = false;
        Arrays.fill(isPrime, true); // fill all true

        for (int i = 4; i <= n; i+=2)
            isPrime[i] = false;

        for (int i = 3; i*i <= n; i+=2) {
            if (isPrime[i]) {
                for (int j = i * i; j <= n; j += i*2)
                    isPrime[j] = false;
            }
        }
    }
    public static boolean[] segmentedSieve(long l, long r) {
        if (l > r) {
            long t = l;
            l = r;
            r = t;
        }
        int size = (int)(r - l + 5);
        // System.out.println(size);
        primeList = new boolean[size];
        Arrays.fill(primeList, true);
        primeList[0] = primeList[1] = false;
        int q = (int) java.lang.Math.sqrt(r)+1;
        sieve(q);
        for(int i=2; i<=q; i++) {
            if(isPrime[i]) {
                long cp = ((l+i-1)/i)*i;
                // System.out.println(cp);
                for(long j=cp; j<=r; j+=i) {
                    // System.out.println(j-l);
                    primeList[(int)(j-l)] = false;
                }
                if(i==cp)
                    primeList[(int)(cp-l)] = true;
            }
        }
        return primeList;
    }
}
public class k {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        while(t-- > 0) {
            long l = in.nextLong();
            long r = in.nextLong();
            boolean[] primeList = Sieve.segmentedSieve(l, r);
            // int cnt=0;
            for(int i=0; i<r-l+1; i++) {
                if(primeList[i]) {
                    System.out.println(l+i);
                    // cnt++;
                }
            }
            System.out.println();
        }
        // System.out.println(cnt);
        in.close();
    }
}
