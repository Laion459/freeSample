package br.univali.prova.mdois;

import java.util.Arrays;

public class Company {
    // Atributos
    private String name;                                // nome da compania
    public  Employee[] employees;                       // empregados
    public  float[] payCheck;                           // contracheque
    private static String[] department;                 // departamento
    private static Float bruteSalary;                   // salario bruto 2*****
    private static Float baseSalary = 5000f;                    // salario base
    private static Float netSalary;                     // salario liquido
    private static Float hoursWorked = 188f;                   // horas trabalhadas
    private static final Integer workingHours = 160;    // jornada de trabalho
    private static Integer overTime;                    // hora extra
    private static Float inss;                          // inss
    private Float maxSalary;                       // salario maximo
    private int capacity;
    private int slotIndex;

// Metodos Especiais
    public Company(String name, int capacity) {
        this.name = name;
        this.capacity = capacity;
        this.slotIndex++;
        this.payCheck = new float[capacity];
        this.employees = new Employee[capacity];
        this.slotIndex = 0;
        runMonths(1);
        game();
    }

    public void add(Float item) {
        this.payCheck[slotIndex++] = item;
    }
    public float get(int itemIndex) {
        return payCheck[itemIndex];
    }
    public int size() {
        return slotIndex;
    }
    public void add2(Employee item) {
        this.employees[slotIndex++] = item;
    }
    public Employee get2(int itemIndex) {
        return employees[itemIndex];
    }


    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public Employee[] getEmployees() {
        return employees;
    }

    public void setEmployees(Employee[] employees) {
        this.employees = employees;
    }

    public float[] getPayCheck() {
        return payCheck;
    }

    public void setPayCheck(float[] payCheck) {
        this.payCheck = payCheck;
    }

    public static String[] getDepartment() {
        return department;
    }

    public static void setDepartment(String[] department) {
        Company.department = department;
    }

    public static Float getBruteSalary() {
        return bruteSalary;
    }

    public static void setBruteSalary(Float bruteSalary) {
        Company.bruteSalary = bruteSalary;
    }

    public static Float getBaseSalary() {
        return baseSalary;
    }

    public static void setBaseSalary(Float baseSalary) {
        Company.baseSalary = baseSalary;
    }

    public static Float getNetSalary() {
        return netSalary;
    }

    public static void setNetSalary(Float netSalary) {
        Company.netSalary = netSalary;
    }

    public static Float getHoursWorked() {
        return hoursWorked;
    }

    public static void setHoursWorked(Float hoursWorked) {
        Company.hoursWorked = hoursWorked;
    }

    public static Integer getWorkingHours() {
        return workingHours;
    }

    public static Integer getOverTime() {
        return overTime;
    }

    public static void setOverTime(Integer overTime) {
        Company.overTime = overTime;
    }

    public static Float getInss() {
        return inss;
    }

    public static void setInss(Float inss) {
        Company.inss = inss;
    }

    public Float getMaxSalary() {
        return maxSalary;
    }

    public void setMaxSalary(Float maxSalary) {
        this.maxSalary = maxSalary;
    }

    public int getCapacity() {
        return capacity;
    }

    public void setCapacity(int capacity) {
        this.capacity = capacity;
    }

    public int getSlotIndex() {
        return slotIndex;
    }

    public void setSlotIndex(int slotIndex) {
        this.slotIndex = slotIndex;
    }

    @Override
    public String toString() {
        return "Company{" +
                "name='" + name + '\'' +
                ", employees=" + Arrays.toString(employees) +
                ", payCheck=" + Arrays.toString(payCheck) +
                ", maxSalary=" + maxSalary +
                ", capacity=" + capacity +
                ", slotIndex=" + slotIndex +
                '}';
    }

    // Metodos Publicos
    /*
    Valida numero, classe Float menor que um mostra erro e aborta o programa.
     */
    private void validate(Float number){
        if (number < 1){
            System.out.println("Erro!");
            //exit(0);
        }
    }

    public void game(){

    }                                    // ***

    private boolean validateSalary(Float salary){   // valida salario
        if (salary < 0){
            System.out.println("Error! Salario invalido.");
            //abort(); exit(0);
            return false;
        }
        return true;
    }

    /**
     * Desconto de imposto de renda.
     * @param netSalary salario liquido.
     * @return salario liquido menos porcentagem desconto IR.
     */
    public Float incomeTax(Float netSalary){
        setNetSalary(getBaseSalary());
        validateSalary(netSalary);

        if (netSalary <= 1499.15){
            setNetSalary(netSalary);
        }

        if (netSalary <= 2246.75){
            setNetSalary(netSalary - ((netSalary * 7.5f) /100) );
        }

        if (netSalary <= 2995.7){
            setNetSalary(netSalary - ((netSalary * 15.0f) /100) );
        }

        if (netSalary <= 3743.19){
            setNetSalary(netSalary - ((netSalary * 22.5f) /100) );
        }else {
            setNetSalary(netSalary - ((netSalary * 27f) /100) );
        }

        return netSalary;
    }

    /**
     * Calcula o desconto do INSS sobre o salario liquido.
     * @param netSalary salario liquido.
     * @return salario liquido menos desconto inss.
     */
    public Float socialInsurance(Float netSalary) {
        if (netSalary <= 482.93){
            setNetSalary(netSalary - ((netSalary * 11) /100) );
        }else {
            setNetSalary(netSalary - 23.1223f);
        }
        return inss;
    }

    /**
     * salva dados de folha de pagamentos.
     * @param employee funcionario a ser guradado.
     * @param hoursWorked horas trabalhadas pelo empregado.
     */
    public void payroll(Employee employee, Float hoursWorked){
        calculateNetSalary(getBaseSalary(),employee);
        addEmployee(employee);
        addPayCheck(getNetSalary());



        //add2(employee);
        //this.employees[slotIndex] = employee;
        //employee.setSalary(employee.getSalary() + calculateSalaryBase(hoursWorked, employee.getSalary()) - (incomeTax(employee.getSalary()) + socialInsurance(employee.getSalary())));
        //add(employee.getSalary());
        //this.payCheck[slotIndex] = employee.getSalary();

        //maxSalaryValidate(employee.getSalary());
    }
    public void calculateNetSalary(Float baseSalary, Employee employee){
        Float aux = 0f;
        setBaseSalary(calculateSalaryBase(hoursWorked,baseSalary));
        aux = incomeTax(baseSalary) + socialInsurance(baseSalary);
        setNetSalary(getBaseSalary() - aux);
        addEmployee(employee);
        addPayCheck(getNetSalary());

        maxSalaryValidate(getNetSalary());
    }
    public void addEmployee(Employee employee){
        employees[slotIndex] = employee;
    }
    public void addPayCheck(Float money){
        payCheck[slotIndex] = money;
    }
    /*
    salva o salario maximo.
     */
    private void maxSalaryValidate(Float salaryEmployee){
        if ( salaryEmployee > maxSalary){
            setMaxSalary(salaryEmployee);
        }
    }
    public void runMonths(int time){    // Roda meses para testes

        for (int i = 0; i < time; i++){
            payroll(getEmployees()[slotIndex],getHoursWorked());
        }
    }

    /**
     * Calcula o salario bruto/base pelas horas trabalhadas.
     * @param hoursWorked horas trabalhadas.
     * @param baseSalary salario base.
     * @return salario base calculado.
     */
    public Float calculateSalaryBase(Float hoursWorked, Float baseSalary){
        if (hoursWorked < 144){
            setBaseSalary((((getBaseSalary() / 4) / 5) / 8) * hoursWorked);
        }else {
            Float aux = hoursWorked - 160;
            Float aux2 = (((baseSalary / 4) /5) /8) / 2;
            setBaseSalary(baseSalary + (aux * aux2));
        }
        return baseSalary;
    }

    public void showArrayEmployees(Employee[] employees){
        for (int i = 0; i < employees.length; i++){
            System.out.println(getEmployees()[i]);
        }
    }
    public void showArrayFloat(Float[] number){
        for (int i = 0; i < number.length; i++){
            System.out.println(number[i]);
        }
    }
   //public Float overTimeEmployee(Float hoursWorked, Float bruteSalary){
   //    validate(hoursWorked);
   //    validate(bruteSalary);

   //    if (hoursWorked > 160.0){
   //        baseSalary += (50 * baseSalary) / 100; // = % cada h > 160?
   //    }

   //    return baseSalary;
   //}
}
