import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        BigInteger N = in.nextBigInteger();
        // if N is divisible by 4 print 4 else print 0
        if (N.mod(new BigInteger("4")).equals(new BigInteger("0"))) {
            System.out.println("4");
        } else {
            System.out.println("0");
        }
        in.close();
    }
}
