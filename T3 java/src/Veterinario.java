public class Veterinario {

    private String nome_veterinario;
    private String endereco_veterinario;
    private String telefone_veterinario;

    public Veterinario(String nome_veterinario, String endereco_veterinario, String telefone_veterinario) {
        this.nome_veterinario = nome_veterinario;
        this.endereco_veterinario = endereco_veterinario;
        this.telefone_veterinario = telefone_veterinario;
    }

    public String getNome_veterinario() {
        return nome_veterinario;
    }

    public void setNome_veterinario(String nome_veterinario) {
        this.nome_veterinario = nome_veterinario;
    }

    public String getEndereco_veterinario() {
        return endereco_veterinario;
    }

    public void setEndereco_veterinario(String endereco_veterinario) {
        this.endereco_veterinario = endereco_veterinario;
    }

    public String getTelefone_veterinario() {
        return telefone_veterinario;
    }

    public void setTelefone_veterinario(String telefone_veterinario) {
        this.telefone_veterinario = telefone_veterinario;
    }

    @Override
    public String toString() {
        return "Veterinario{" +
                "nome_veterinario='" + nome_veterinario + '\'' +
                ", endereco_veterinario='" + endereco_veterinario + '\'' +
                ", telefone_veterinario='" + telefone_veterinario + '\'' +
                '}';
    }
}
