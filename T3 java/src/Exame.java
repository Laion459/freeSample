public class Exame {

    private String des_exame;
    private int codigo_exame;

    public Exame(String des_exame, int codigo_exame) {
        this.des_exame = des_exame;
        this.codigo_exame = codigo_exame;
    }

    public String getDes_exame() {
        return des_exame;
    }

    public void setDes_exame(String des_exame) {
        this.des_exame = des_exame;
    }

    public int getCodigo_exame() {
        return codigo_exame;
    }

    public void setCodigo_exame(int codigo_exame) {
        this.codigo_exame = codigo_exame;
    }

    @Override
    public String toString() {
        return "Exame{" +
                "des_exame='" + des_exame + '\'' +
                ", codigo_exame=" + codigo_exame +
                '}';
    }
}
