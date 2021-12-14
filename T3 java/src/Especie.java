public class Especie {

    private String nome_especie;

    public Especie(String nome_especie) {
        this.nome_especie = nome_especie;
    }

    public String getNome_especie() {
        return nome_especie;
    }

    public void setNome_especie(String nome_especie) {
        this.nome_especie = nome_especie;
    }

    @Override
    public String toString() {
        return "Especie{" +
                "nome_especie='" + nome_especie + '\'' +
                '}';
    }
}
