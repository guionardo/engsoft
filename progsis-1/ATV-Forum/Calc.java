class Calc {
    static int a = 2147483647;
    static int ra = 1650466;

    public static void main(String[] args) {
        System.out.printf("a = %d\n", a);
        System.out.printf("ra = %d\n", ra);
        System.out.printf("1. a + ra = %d\n", a + ra);
        System.out.printf("2. a * ra = %d\n", a * ra);
        System.out.printf("3. 2a + ra = %d\n", 2 * a + ra);
    }

}