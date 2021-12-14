import java.io.*;
import java.util.Arrays;

public class Animal {

    private String nome_animal;
    private int idade_animal;
    private int sexo_animal;
    private static Especie especie;

    public Animal(String nome_animal, int idade_animal, int sexo_animal) {
        this.nome_animal = nome_animal;
        this.idade_animal = idade_animal;
        this.sexo_animal = sexo_animal;
    }

    public String getNome_animal() {
        return nome_animal;
    }

    public void setNome_animal(String nome_animal) {
        this.nome_animal = nome_animal;
    }

    public int getIdade_animal() {
        return idade_animal;
    }

    public void setIdade_animal(int idade_animal) {
        this.idade_animal = idade_animal;
    }

    public int getSexo_animal() {
        return sexo_animal;
    }

    public void setSexo_animal(int sexo_animal) {
        this.sexo_animal = sexo_animal;
    }

    public static Especie getEspecie() {
        return especie;
    }

    @Override
    public String toString() {
        return "Animal{" +
                "nome_animal='" + nome_animal + '\'' +
                ", idade_animal=" + idade_animal +
                ", sexo_animal=" + sexo_animal +
                '}';
    }

    // função consulta direto do txt
    void consultaTxtPets(){
        String filename = "C:\\Users\\laion\\IdeaProjects\\Luiz_HendlerT3Alg2\\src\\pets.txt";
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
