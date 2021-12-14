public class Cliente {

    private String nome_cliente;
    private String endereco_cliente;
    private String telefone_cliente;
    private long cep_cliente;
    private String email_cliente;

    // Métodos Privados

    public Cliente(String nome_cliente, String endereco_cliente, String telefone_cliente, long cep_cliente, String email_cliente) {
        this.nome_cliente = nome_cliente;
        this.endereco_cliente = endereco_cliente;
        this.telefone_cliente = telefone_cliente;
        this.cep_cliente = cep_cliente;
        this.email_cliente = email_cliente;
    }

    public String getNome_cliente() {
        return nome_cliente;
    }

    public void setNome_cliente(String nome_cliente) {
        this.nome_cliente = nome_cliente;
    }

    public String getEndereco_cliente() {
        return endereco_cliente;
    }

    public void setEndereco_cliente(String endereco_cliente) {
        this.endereco_cliente = endereco_cliente;
    }

    public String getTelefone_cliente() {
        return telefone_cliente;
    }

    public void setTelefone_cliente(String telefone_cliente) {
        this.telefone_cliente = telefone_cliente;
    }

    public long getCep_cliente() {
        return cep_cliente;
    }

    public void setCep_cliente(long cep_cliente) {
        this.cep_cliente = cep_cliente;
    }

    public String getEmail_cliente() {
        return email_cliente;
    }

    public void setEmail_cliente(String email_cliente) {
        this.email_cliente = email_cliente;
    }

    @Override
    public String toString() {
        return "Cliente{" +
                "nome_cliente='" + nome_cliente + '\'' +
                ", endereco_cliente='" + endereco_cliente + '\'' +
                ", telefone_cliente='" + telefone_cliente + '\'' +
                ", cep_cliente=" + cep_cliente +
                ", email_cliente='" + email_cliente + '\'' +
                '}';
    }

    // Métodos Públicos
}
