import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.Date;
import java.util.Objects;

public class Consulta {

    private Date data_consulta;
    private String historico;
    private String nome_veterinario;

    public Consulta(Date data_consulta, String historico, String nome_veterinario) {
        this.data_consulta = data_consulta;
        this.historico = historico;
        this.nome_veterinario = nome_veterinario;
    }

    public Date getData_consulta() {
        return data_consulta;
    }

    public void setData_consulta(Date data_consulta) {
        this.data_consulta = data_consulta;
    }

    public String getHistorico() {
        return historico;
    }

    public void setHistorico(String historico) {
        this.historico = historico;
    }

    public String getNome_veterinario() {
        return nome_veterinario;
    }

    public void setNome_veterinario(String nome_veterinario) {
        this.nome_veterinario = nome_veterinario;
    }

    @Override
    public String toString() {
        return "Consulta{" +
                "data_consulta=" + data_consulta +
                ", historico='" + historico + '\'' +
                ", nome_veterinario='" + nome_veterinario + '\'' +
                '}';
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof Consulta)) return false;
        Consulta consulta = (Consulta) o;
        return Objects.equals(getData_consulta(), consulta.getData_consulta()) && Objects.equals(getHistorico(), consulta.getHistorico()) && Objects.equals(getNome_veterinario(), consulta.getNome_veterinario());
    }

    @Override
    public int hashCode() {
        return Objects.hash(getData_consulta(), getHistorico(), getNome_veterinario());
    }

    // Métodos públicos

    // função consulta direto do txt
    void consultaTxt(){
        String filename = "C:\\Users\\laion\\IdeaProjects\\Luiz_HendlerT3Alg2\\src\\Consultas feitas pelo veterinario";
        String row;
        try (BufferedReader reader = new BufferedReader(new FileReader(filename))) {
            while ((row = reader.readLine()) != null) {
                String[] data = row.split(",");
                Arrays.stream(data).forEach(System.out::println);
                System.out.println("-----------------");
            }
        } catch (FileNotFoundException e) {
            System.out.println("Erro na abertura do arquivo...");// erro na abertura do arquivo
        } catch (IOException e) {
            System.out.println("Erro na leitura do arquivo...");// erro na leitura do arquivo
        }
    }
}
