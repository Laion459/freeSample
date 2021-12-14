import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.Date;

public class Tratamento {

    private Date data_inicio;
    private Date data_final;
    private String tratamento_descricao;

    public Tratamento(Date data_inicio, Date data_final, String tratamento_descricao) {
        this.data_inicio = data_inicio;
        this.data_final = data_final;
        this.tratamento_descricao = tratamento_descricao;
    }

    public Date getData_inicio() {
        return data_inicio;
    }

    public void setData_inicio(Date data_inicio) {
        this.data_inicio = data_inicio;
    }

    public Date getData_final() {
        return data_final;
    }

    public void setData_final(Date data_final) {
        this.data_final = data_final;
    }

    public String getTratamento_descricao() {
        return tratamento_descricao;
    }

    public void setTratamento_descricao(String tratamento_descricao) {
        this.tratamento_descricao = tratamento_descricao;
    }

    @Override
    public String toString() {
        return "Tratamento{" +
                "data_inicio=" + data_inicio +
                ", data_final=" + data_final +
                ", tratamento_descricao='" + tratamento_descricao + '\'' +
                '}';
    }

    // função consulta direto do txt
    void consultaTratamento(){
        String filename = "C:\\Users\\laion\\IdeaProjects\\Luiz_HendlerT3Alg2\\src\\tratamentos.txt";
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
