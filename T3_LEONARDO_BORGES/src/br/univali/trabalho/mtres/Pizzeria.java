package br.univali.trabalho.mtres;

public class Pizzeria {

    // Atributos
    private String name;
    private Integer id = 0;

    // Metodos publicos
    public Pizzeria(String name, Integer id) {
        this.name = name;
        this.id = id++;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public Integer getId() {
        return id;
    }

    public void setId(Integer id) {
        this.id = id;
    }
}
