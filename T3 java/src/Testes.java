import java.text.SimpleDateFormat;
import java.util.Date;


public class Testes {
    public static void main(String[] args) {

        // Testes
        System.out.println("--------------------------------------------------------");
        System.out.println("------                 TESTES                       ----");
        System.out.println("--------------------------------------------------------");
        System.out.println();

        // Teste das classes
        System.out.println(" **** Teste Clases **** ");

        // Teste classe Animal
        System.out.println("**** Teste classe Animal *****");
        Animal animal = new Animal("Spyke",2, 10);
        System.out.println(animal);
        System.out.println("Nome do animal: " + animal.getNome_animal());
        System.out.println("Idade do animal: " + animal.getIdade_animal());
        System.out.println("Sexo do animal: " + animal.getSexo_animal());
        System.out.println();

        // Teste cliente
        System.out.println("**** Teste classe Cliente: ****");
        Cliente cliente = new Cliente("Luiz","Canasvieras","48 999-999", 888888,"exemplo@onix.com");
        System.out.println(cliente);
        System.out.println("Nome cliente: " + cliente.getNome_cliente());
        System.out.println("Endereço do cliente: " + cliente.getEndereco_cliente());
        System.out.println();

        // Teste classe Consulta
        System.out.println("**** Teste classe Consulta ****");
        SimpleDateFormat x = new SimpleDateFormat("10/03/2010");
        Consulta consulta = new Consulta(x.get2DigitYearStart(), "Não tem ainda","Pedro");
        System.out.println(consulta);

        // Teste classe Especie
        System.out.println("**** Teste classe Especie: ****");
        Especie especie = new Especie("beagle");
        System.out.println(especie);
        System.out.println("Especie: " + especie.getNome_especie());
        System.out.println();

        // Teste classe Exame
        System.out.println("**** Teste classe Exame: ****");
        Exame exame = new Exame("exame, exemplo",44);
        Exame exame1 = new Exame("exame 2, exemplo 2",0);
        System.out.println(exame);
        System.out.println(exame1);
        System.out.println("Descrição exame: " + exame.getDes_exame());
        System.out.println();


        // Teste dos relatórios
        System.out.println("#### Teste relatórios ####");

        // Teste relatório consultas feitas pelo veterinário
        System.out.println("**** Consultas feitas pelo veterinario: ****");
        Controlador_veterinario controlador_veterinario = new Controlador_veterinario();
        controlador_veterinario.consultas_feitas_pelo_veterinario();
        System.out.println();

        // Relatorio pets
        controlador_veterinario.cadastroAnimal(animal.getNome_animal(), animal.getIdade_animal(), animal.getSexo_animal());
        // Cadastra novo animal aproveitando o teste da classe animal, dentro do relatório txt pets.
        animal.consultaTxtPets();
        System.out.println();


        // Teste cadastros
        System.out.println("++++ Teste cadastros ++++");

        // Teste novo cadastro cliente
        System.out.println("**** Teste Novo cadastro de cliente: ****");
        controlador_veterinario.cadastroCliente("Manoel", "Estrada Onildo", "898989", 88058700, "banana.com");
        consulta.consultaTxt();
        System.out.println();

        // Test tratamento
        System.out.println("---- Test tratamento ----");
        Tratamento tratamento = new Tratamento(new Date(),new Date(),"descrição teste");
        tratamento.consultaTratamento();


        // Teste menú
        //controlador_veterinario.menu();
    }
}
