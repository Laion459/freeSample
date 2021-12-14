import java.io.*;
import java.util.Arrays;
import java.util.Date;
import java.util.Scanner;

public class Controlador_veterinario {

    // arquivos de controles?
    public void consultas_feitas_pelo_veterinario() {
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

    // Cadastro cliente
    void cadastroCliente(String nome_cliente, String endereco_cliente, String telefone_cliente, long cep_cliente, String email_cliente) {
        Cliente novo = new Cliente(nome_cliente, endereco_cliente, telefone_cliente, cep_cliente, email_cliente);
        //System.out.println(novo);

        String fileName = "C:\\Users\\laion\\IdeaProjects\\Luiz_HendlerT3Alg2\\src\\Consultas feitas pelo veterinario";
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(fileName, true))) {
            writer.write(novo.toString());
        } catch (FileNotFoundException e) {
            System.out.println("Erro na abertura do arquivo");
        } catch (IOException e) {
            System.out.println("Erro de escrita no arquivo");
        }
    }

    // Cadastro animal
    void cadastroAnimal(String nome_animal, int idade_animal, int sexo_animal){
        Animal novoAnimal = new Animal(nome_animal, idade_animal, sexo_animal);
        //System.out.println(novoAnimal);

        String fileName = "C:\\Users\\laion\\IdeaProjects\\Luiz_HendlerT3Alg2\\src\\pets.txt";
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(fileName, true))) {
            writer.write(novoAnimal.toString());
        } catch (FileNotFoundException e) {
            System.out.println("Erro na abertura do arquivo");
        } catch (IOException e) {
            System.out.println("Erro de escrita no arquivo");
        }
    }

    // cadastro tratamento de animais
    void tratamentoAnimal(){
        Tratamento novoTratamento = new Tratamento(new Date(),new Date(),"dor de dente, dipirona.");
        //System.out.println(novoTratamento);

        String fileName = "C:\\Users\\laion\\IdeaProjects\\Luiz_HendlerT3Alg2\\src\\tratamentos.txt";
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(fileName, true))) {
            writer.write(novoTratamento.toString());
        } catch (FileNotFoundException e) {
            System.out.println("Erro na abertura do arquivo");
        } catch (IOException e) {
            System.out.println("Erro de escrita no arquivo");
        }
    }

    public void menu(){
        Scanner entrada = new Scanner(System.in);

        System.out.println("****** MENÙ ****");
        System.out.println(" Escolha sua opção digitando o número: ");
        System.out.println("1 Cadastrar cliente. ");
        System.out.println("2 Marcar consulta.");

        int n = entrada.nextInt();

        switch (n){
            case 1:
                //cadastrar cliente
                System.out.println("cadastrar cliente");
                break;
            case 2:
                // marcar consulta
                System.out.println("marcar consulta");
                break;
            default:
                System.out.println("Erro de opção!");
        }
    }
}
