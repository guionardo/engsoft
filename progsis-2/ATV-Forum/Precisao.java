import java.math.BigDecimal;
import java.math.BigInteger;

class Precisao {

    public static void main(String[] args) {
        System.out.println("*** Teste de precisão ***");

        long n1 = 100000000;
        long n2 = 7;
        System.out.printf("n1 = %d\n", n1);
        System.out.printf("n2 = %d\n", n2);
        System.out.printf("Operação = %d / %d\n\n", n1, n2);

        float v1 = (float) n1 / (float) n2;
        double v2 = (double) n1 / (double) n2;
        BigDecimal v3 = new BigDecimal((double) n1 / (double) n2);

        System.out.println("# Resultados");
        System.out.printf("Float      = %10.20f -> %10.2f\n", v1, v1);
        System.out.printf("Double     = %10.20f -> %10.2f\n", v2, v2);
        System.out.printf("BigDecimal = %10.20f -> %10.2f\n", v3, v3);

        float s1 = 0;
        double s2 = 0;
        BigDecimal s3 = new BigDecimal(0);
        int acumulador = 100000;
        System.out.printf("\n#Soma por repetição * %d\n", acumulador);
        for (int i = 0; i < acumulador; i++) {
            s1 += v1;
            s2 += v2;
            s3 = s3.add(v3);
        }
        System.out.printf("Float      = %10.20f -> %10.2f\n", s1, s1);
        System.out.printf("Double     = %10.20f -> %10.2f\n", s2, s2);
        System.out.printf("BigDecimal = %10.20f -> %10.2f\n", s3, s3);

        System.out.printf("\n#Multiplicação * %d\n", acumulador);

        s1 = v1 * acumulador;
        s2 = v2 * acumulador;
        s3 = v3.multiply(new BigDecimal(acumulador));
        System.out.printf("Float      = %10.20f -> %10.2f\n", s1, s1);
        System.out.printf("Double     = %10.20f -> %10.2f\n", s2, s2);
        System.out.printf("BigDecimal = %10.20f -> %10.2f\n", s3, s3);

    }
}