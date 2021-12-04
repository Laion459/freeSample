package br.univali.prova.mdois;

public class TestCompany {
    public static void main(String[] args) {

        Company company = new Company("ELETRONS AMESTRADOS",4);
        System.out.println("Compania: *"+company.getName()+"* ");


        Employee[] employees = new Employee[company.getCapacity()];
        employees[0] = new Employee("Leonardo", "CEO", 1500000f);
        employees[1] = new Employee("Bruna", "CEO", 2300000f);

        for (int i = 0; i < employees.length; i++){
            //company.setEmployees(employees);
        }

        //company.showArrayEmployees(employees);

        //System.out.println("----------------------------------------");
        //System.out.println("Funcionario: " + employee.getName());
        //System.out.println("Departamento: " + employee.getDepartment());
        //System.out.println("Salario: " + employee.getSalary());
        //System.out.println("----------------------------------------");

        //System.out.println("Salario maximo: " + company.getMaxSalary());

        //company.employees[0] = employee;
        //company.employees[1] = employee2;

        //System.out.println(company.employees[0].getName());
        //System.out.println(company.employees[1]);
    }
}
