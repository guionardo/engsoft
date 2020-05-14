package programa;

import java.time.LocalDate;

public class Data {

    protected int dia = 0;
    protected int mes = 0;
    protected int ano = 0;

    public Data(final int dia, final int mes, final int ano) throws Exception {
        this.validarData(dia, mes, ano);
        this.dia = dia;
        this.mes = mes;
        this.ano = ano;
    }

    public void validarData(final int dia, final int mes, final int ano) throws Exception {
        if (!(0 < dia && dia < 32)) {
            throw new Exception(String.format("Dia deve ser entre 1 e 31: %d", dia));
        }
        if (!(0 < mes && mes < 13)) {
            throw new Exception(String.format("Mês deve ser entre 1 e 12: %d", mes));
        }
        if (ano > LocalDate.now().getYear()) {
            throw new Exception(String.format("Ano deve ser anterior ao ano atual: %d", ano));
        }

        boolean diaCerto = false;

        if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
            diaCerto = dia <= 30;
        } else if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12) {
            diaCerto = dia <= 31;
        } else if (mes == 2) {
            diaCerto = (ano % 4 == 0) ? dia <= 29 : dia <= 28;
        }
        if (!diaCerto) {
            throw new Exception(String.format("Dia inválido: %d", dia));
        }
    }

    public float calculoIdade() {
        return this.dia == 0 ? 0
                : ((float) LocalDate.now().getYear() - this.ano)
                        + (float) (LocalDate.now().getMonthValue() - this.mes) / 12;

    }

}