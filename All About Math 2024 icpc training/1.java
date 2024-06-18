import java.io.*;
import java.util.*;

public class Main {

    public static void naharMarjana(int p1, FastReader reader) {
        long p = reader.nextLong();
        long l = reader.nextLong();

        if (l * 2 >= p) {
            System.out.println("Case " + p1 + ": impossible");
            return;
        }

        long left = p - l;
        List<Long> divisors = new ArrayList<>();

        for (long i = 1; i <= Math.sqrt(left); ++i) {
            if (left % i == 0) {
                if (i > l) {
                    divisors.add(i);
                }
                if (left / i > l && i != left / i) {
                    divisors.add(left / i);
                }
            }
        }

        Collections.sort(divisors);
        System.out.print("Case " + p1 + ": ");
        for (long n : divisors) {
            System.out.print(n + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        FastReader reader = new FastReader();
        int t = reader.nextInt();
        for (int p = 1; p <= t; p++) {
            naharMarjana(p, reader);
        }
    }

    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }
    }
}
