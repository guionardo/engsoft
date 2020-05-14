import programa.Data;
import programa.Data2;

public class Main {

    public static void main(String[] args) {
        int[][] dados = { { 5, 7, 1977 }, { 5, 2, 1977 }, { 30, 12, 2008 }, { 7, 2, 2014 }, { 13, 13, 2014 },
                { 65, 12, 1977 } };

        int d, m, a;
        for (int n = 0; n < dados.length; n++) {
            d = dados[n][0];
            m = dados[n][1];
            a = dados[n][2];
            System.out.printf("\nTestando data #%d: %d/%d/%d\n", n + 1, d, m, a);
            try {
                System.out.println("Data:");
                Data d1 = new Data(d, m, a);
                System.out.printf("Idade: %f\n", d1.calculoIdade());
            } catch (Exception exc) {
                System.out.printf("ERRO: %s\n\n", exc.getMessage());
            }
            try {
                System.out.println("Data2:");
                Data2 d2 = new Data2(d, m, a);
                System.out.printf("Idade: %f\n", d2.calculoIdade());
            } catch (Exception exc) {
                System.out.printf("ERRO: %s\n\n", exc.getMessage());
            }

        }
    }

}