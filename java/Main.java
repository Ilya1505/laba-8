import java.util.Scanner;
public class Main
{
	public static void main(String[] args)
	{
	System.out.println("Инициализация: "+System.lineSeparator());
	engine dvs = new engine("no_name", 10, 100, 0, 300);
	cars avto = new cars("no_name", "no_color", 0, 1000, dvs);
	AfterDrive rezult = new AfterDrive();// объект вспомогательного класса
	int probeg;
	avto.OutputCars();
	avto.PutCars();
	System.out.println(System.lineSeparator()+"Данные после ввода: ");
	avto.OutputCars();
	avto.Drive(rezult);
	probeg=rezult.km;
	System.out.println(System.lineSeparator()+"Пробег после тест-драйва: ");
	System.out.println(probeg+" КМ"+System.lineSeparator());
	avto.Modern(100, 200, 500);
	System.out.println("После модернизации: ");
	avto.OutputCars();
	// массив объектов
	engine []arrayE = new engine[2];
	for(int i=0;i<arrayE.length;i++)
	{
		arrayE[i] = new engine("no_name", 10, 100, 0, 300);
	}
	cars []arrayC = new cars[2];
	for(int i=0; i<arrayC.length;i++)
	{
		arrayC[i]=new cars("no_name", "no_color", 0, 1000, arrayE[i]);
	}
	for(int i=0; i<arrayC.length;i++)
	{	
		System.out.println(System.lineSeparator());
		arrayC[i].OutputCars();
	}
	for(int i=0; i<arrayC.length;i++)
	{	System.out.println(System.lineSeparator());
		arrayC[i].PutCars();
	}
	System.out.println(System.lineSeparator()+"Данные после ввода: ");
		for(int i=0; i<arrayC.length;i++)
	{	System.out.println(System.lineSeparator());
		arrayC[i].OutputCars();
	}
	System.out.println(System.lineSeparator()+"Пробег после тест-драйва: ");
	for(int i=0; i<arrayC.length;i++)
	{	arrayC[i].Drive(rezult);
		probeg=rezult.km;
		System.out.println(System.lineSeparator());
		System.out.println(probeg+" КМ");
	}
	for(int i=0; i<arrayC.length;i++)
	{
		arrayC[i].Modern(100, 200, 500);
	}
	System.out.println(System.lineSeparator()+"После модернизации: ");
	for(int i=0; i<arrayC.length;i++)
	{	System.out.println(System.lineSeparator());
		arrayC[i].OutputCars();
	}
	System.out.println(System.lineSeparator()+"Общее количество машин: "+avto.GetCount());
	}
};

class AfterDrive// вспомогательный класс
{
	public int km;
}

class engine// двигатель
{
	private String name=new String();// марка двигателя
	private double weight;// вес
	private int power;// мощность (л.с.)
	private int probeg;// пробег
	private int resurs;// ресурс двигателя

	public engine(String name, double weight, int power, int probeg, int resurs)// конструктор с параметрами
	{
		this.name=name;
		this.weight = weight;
		this.power = power;
		this.probeg = probeg;
		this.resurs = resurs;
	}
	public engine()// конструктор без параметров
	{
		name="no_name";
		weight = 10;
		power = 100;
		probeg = 0;
		resurs = 300;
	}
	// сеттеры и геттеры
	public void SetName(String name)
	{
		this.name=name;
	}
	public void SetWeight(double weight)
	{
		this.weight = weight;
	}
	public void SetPower(int power)
	{
		this.power = power;
	}
	public void SetProbeg(int probeg)
	{
		this.probeg = probeg;
	}
	public void SetResurs(int resurs)
	{
		this.resurs = resurs;
	}
	public String GetName()
	{
		return name;
	}
	public double GetwWight()
	{
		return weight;
	}
	public int GetPower()
	{
		return power;
	}
	public int GetProbeg()
	{
		return probeg;
	}
	public int GetResurs()
	{
		return resurs;
	}
	public void Remont()// ремонт двигателя
	{
		probeg = 0;
	}
	public void Read()// ввод данных
	{
		Scanner read = new Scanner(System.in);
		System.out.println("Введите марку двигателя: ");
		name=read.nextLine();
		System.out.println("Введите мощность двигателя: ");
		power=read.nextInt();
		System.out.println("Введите пробег двигателя: ");
		probeg=read.nextInt();
		System.out.println("Введите ресурс двигателя: ");
		resurs=read.nextInt();
		System.out.println("Введите вес двигателя: ");
		weight=read.nextDouble();
	}
	public void Print()// вывод данных
	{
		System.out.println("Марка двигателя: " + name);
		System.out.println("Мощность двигателя: " + power);
		System.out.println("Пробег двигателя: " + probeg);
		System.out.println("Ресурс двигателя: " + resurs);
		System.out.println("Вес двигателя: " + weight);
	}
};

class cars// класс авто
{	
	private static int count;// статическая переменная, хранящая количество созданных объектов cars
	private int id;// уникальный номер для каждого объекта cars
	private String name=new String();// марка авто
	private String color=new String();// цвет авто
	private int year;// год выпуска
	private double price;// цена
	private engine dvs = new engine();// двигатель
	public static int GetCount()// статический метод
	{
		return count;
	}
	public cars(String name, String color, int yr, double pr, engine dvs)// конструктор с параметрами
	{
		this.name=name;
		this.color=color;
		this.year = yr;
		this.price = pr;
		this.dvs = dvs;//установка двигателя
		count++;
		id=count;
	}
	public cars()// конструктор без параметров
	{
		name="no_name";
		color="no_color";
		year = 2000;
		price = 0;
		count++;
		id = count;
	}
	// сеттеры и геттеры
	public void SetName(String name)
	{
		this.name=name;
	}
	public void SetYear(int year)
	{
		this.year = year;
	}
	public void SetPrice(double price)
	{
		this.price = price;
	}
	public int GetID()
	{
		return id;
	}
	public String GetName()
	{
		return name;
	}
	public String GetColor()
	{
		return color;
	}
	public int GetYear()
	{
		return year;
	}
	public double GetPrice()
	{
		return price;
	}
	public void PutCars()// функкция ввода данных
	{
		Scanner read = new Scanner(System.in);
		System.out.println("Введите марку машины: ");
		name=read.nextLine();
		System.out.println("Введите цвет машины: ");
		color=read.nextLine();
		System.out.println("Введите год выпуска машины: ");
		year=read.nextInt();
		System.out.println("Введите цену машины: ");
		price=read.nextDouble();
		dvs.Read();
	}
	public void OutputCars()// функция вывода данных
	{
		System.out.println("ID машины: "+id);
		System.out.println("Марка машины: " + name);
		System.out.println("Цвет машины: " + color);
		System.out.println("Год выпуска машины: " + year);
		System.out.println("Цена: " + price);
		dvs.Print();
	}
	public void Drive(AfterDrive rezult)// тест-драйв
	{
		rezult.km = dvs.GetProbeg() + 10;
	}
	public void Modern(double NewWeight, int NewPower, int NewResurs)// модернизация
	{
		dvs.SetWeight(NewWeight);
		dvs.SetPower(NewPower);
		dvs.SetResurs(NewResurs);
		dvs.Remont();
	}
};