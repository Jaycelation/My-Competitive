import java.math.BigInteger;
import java.util.*;

public class A {
    public static char[] mang = {'+', '-', '*'};
    public static int n,cnt;
    public static BigInteger m;
    public static BigInteger[] a;
    public static void Try(int t, char[] c) {
        for (int i = 0; i <= 2; ++i) {
            c[t] = mang[i];
            if (t==n-2) {
                if(check(c)) cnt++;
            } else Try(t+1,c);
        }
    }
    public static boolean check(char[] c){
        ArrayList<BigInteger> h = new ArrayList<>();
        h.add(a[0]);
        for(int i=0;i<n-1;i++){
            if(c[i]=='+') h.add(a[i+1]);
            else if(c[i]=='-') h.add(a[i+1].multiply(new BigInteger("-1")));
            else h.set(h.size()-1,h.getLast().multiply(a[i+1]));
        }
        BigInteger sum = new BigInteger("0");
        for(BigInteger x:h){
            sum=sum.add(x);
        }
        sum=sum.mod(m);
        if(sum.compareTo(new BigInteger("0"))==0) return true;
        return false;
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        while (t-- > 0) {
            n = scanner.nextInt();
            m = new BigInteger(scanner.next());
            a = new BigInteger[n];
            for(int i = 0;i<n;i++){
                a[i] = new BigInteger(scanner.next());
            }
            cnt=0;

            char []c = new char[n-1];
            Try(0, c);
            System.out.println(cnt);

        }
    }
}
