package programa;

import java.time.LocalDate;
import java.time.Period;

public class Data2 {

    private LocalDate data;

    public Data2(final int dia, final int mes, final int ano) {
        this.data = LocalDate.of(ano, mes, dia);
    }

    public float calculoIdade() {
        if (data == null) {
            return 0;
        }
        Period periodo = Period.between(this.data, LocalDate.now());
        return (float) periodo.getYears() + periodo.getMonths() / (float) 12;
    }

}