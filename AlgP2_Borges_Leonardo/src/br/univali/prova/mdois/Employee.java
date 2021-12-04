package br.univali.prova.mdois;

public class Employee {
    // Atributos
    private String name;
    private String department;
    private Float salary;

    // Metodos Especiais

    public Employee(String name, String department, Float salary) {
        this.name = name;
        this.department = department;
        this.salary = salary;
        //showInfo();
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getDepartment() {
        return department;
    }

    public void setDepartment(String department) {
        this.department = department;
    }

    public Float getSalary() {
        return salary;
    }

    public void setSalary(Float salary) {
        this.salary = salary;
    }

    @Override
    public String toString() {
        return "Employee{" +
                "name='" + name + '\'' +
                ", department='" + department + '\'' +
                ", salary=" + salary +
                '}';
    }
    // Metodos Publicos

    public void showInfo(){
        System.out.println(" info Employee: ");
        System.out.println(" Name: " + getName());
        System.out.println("Department: " + getDepartment());
        //System.out.println(getSalary()[0]);
    }

}
