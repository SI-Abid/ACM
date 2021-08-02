package S2E18;

import java.util.Scanner;

public class b {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        int k = sc.nextInt();
        for (int i = 0; i < k; i++) {
            if(n%200 == 0) {
                n/=200;
            } else {
                String nString = Long.toString(n).concat("200");
                n = Long.parseLong(nString);
            }
        }
        System.out.println(n);
        sc.close();
    }
}
