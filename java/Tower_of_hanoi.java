public class Tower_of_hanoi {
    static int count;

    public static void towerOfHanoi(int n, String src, String help, String dest) {
        if (n == 1) {
            System.out.println("Move disk " + n + " from " + src + " to " + dest);
            count++;
            return;
        }
        towerOfHanoi(n - 1, src, dest, help);
        System.out.println("Move disk " + n + " from " + src + " to " + dest);
        count++;
        towerOfHanoi(n - 1, help, src, dest);
    }

    public static void main(String[] args) {
        String src = "S", help = "H", dest = "D";
        int n = 6;
        towerOfHanoi(n, src, help, dest);
        System.out.println(count);
    }
}