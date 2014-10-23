import java.io.IOException;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {

	public static ArrayList<BigInteger> fibs = new ArrayList<BigInteger>(5001);

	public static void f() {
		BigInteger last = new BigInteger("0");
		BigInteger n = new BigInteger("1");

		for (int i = 1; i <= 5001; i++) {
			fibs.add(last);

			BigInteger next = last.add(n);
			last = n;
			n = next;
		}
	}

	public static void main(String[] args) throws IOException {
		f();

		Scanner in = new Scanner(System.in);

		do {
			int l = in.nextInt();
			System.out.println("The Fibonacci number for " + l + " is "
					+ fibs.get(l));
		} while (in.hasNextInt());

		in.close();
	}

}
