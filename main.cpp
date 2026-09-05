#include <iostream>
#include <string>
#include <vector>

// базовый класс Car
class Car{
    private:
        std::string m_Trademark;
        int m_Cylinders;
        int m_Power;
    
    public:

    //конструктор класса Car с параметрами по умолчанию и с параметрами, заданными пользователем
    Car (std::string Trademark ="", int Cylinders = 0, int Power = 0)
        : m_Trademark(Trademark), m_Cylinders(Cylinders), m_Power(Power)
        {
            std::cout << "Car " << m_Trademark << " created" << std::endl;
        }

    //деструктор класса Car
    ~Car() {
        std::cout << "Car " << m_Trademark << " deleted" << std::endl;
    }

        //методы сеттеры и геттеры
        void getTrademark(Car &car) {std::cout<<"Trademark is "<<car.m_Trademark<<std::endl;}
        void setTrademark(std::string Trademark){m_Trademark = Trademark;}

        void getCylinders(Car &car) {std::cout<<"Number of cylinders is "<<car.m_Cylinders<<std::endl;}   
        void setCylinders(int Cylinders){m_Cylinders = Cylinders;}

        void getPower(Car &car) {std::cout<<"Power is "<<car.m_Power<<std::endl;}        
        void setPower(int Power){m_Power = Power;}

        friend void count();
        friend std::ostream& operator<<(std::ostream &out, const Car &car);
        friend std::ostream& operator>>(std::ostream &in, const Car &car);
    } ;

//перегруженный оператор вывода для класса Car
std::ostream& operator<< (std::ostream &out, const Car &car)
{
    out << "Car (" <<car.m_Trademark <<", " <<car.m_Cylinders<<", " <<car.m_Power<<")";

    return out;
}

//перегруженный оператор ввода для класса Car
std::ostream& operator>> (std::ostream &in, const Car &car)
{
    in >> (car.m_Trademark, car.m_Cylinders, car.m_Power); 
    return in;
}

//производный класс Lorry
class Lorry: public Car{
    private:
        int m_Capacity;

    public:
    
    //конструктор класса Lorry с параметрами по умолчанию и с параметрами, заданными пользователем
    Lorry (std::string Trademark ="", int Cylinders = 0, int Power = 0, int Capacity = 0)
    : Car(Trademark, Cylinders, Power), m_Capacity(Capacity)
    {
        std::cout << "Lorry " << Trademark << " created" << std::endl;
    }

    //деструктор класса Lorry
    ~Lorry() {
        std::cout << "Lorry " << car.m_Trademark << " deleted" << std::endl;
    }
    
    void getCapacity(Lorry &lorry) {std::cout<<"Capacity is "<<m_Capacity<<std::endl;}
    void setCapacity(int Capacity) {m_Capacity = Capacity;}

    friend void count();
    friend std::ostream& operator<<(std::ostream &out, const Lorry &lorry);
    friend std::ostream& operator>>(std::ostream &in, const Lorry &lorry);
};

//перегруженный оператор вывода для производного класса Lorry
std::ostream& operator<< (std::ostream &out, const Lorry &lorry)
    {
    out << "Lorry (" <<lorry.m_Trademark <<", " <<lorry.m_Cylinders<<", " <<lorry.m_Power<<", " <<lorry.m_Capacity<<")";

    return out;
}

//перегруженный оператор ввода для класса Lorry
std::ostream& operator>> (std::ostream &in, const Lorry &lorry)
{
    in >> (car.m_Trademark, car.m_Cylinders, car.m_Power, lorry.m_Capacity);  

    return in;
}


int main()
{
    std::vector<Car> car;
    std::string trademark;
    int cylinders;
    int power;

    std::vector<Lorry> lorry;
    int capacity;

    int i=0, j=0; //счетчики объектов классов Car и Lorry соответственно. 
    int index; //номер объекта класса Car или Lorry для получения отчета по соответствутющему объекту (cases 4, 5)
    int choice;

    int count(){
        std::cout<< "You created " <<car.size() <<" objects of the Car class and " <<lorry.cize() <<" objects of the Lorry class."<<std::endl;
        return 0;
    }

    do {

    //Пользовательское меню
    std::cout<<"User manu. Choose what to do from the list below:"<<std::endl<<std::endl;
    std::cout<<"To create a new object of the Car class - press 1;"<<std::endl;
    std::cout<<"To create a new object of the Lorry class - press 2;"<<std::endl;
    std::cout<<"To get report of the created objects of the Car and Lorry classes - press 3;"<<std::endl;
    std::cout<<"To get report of a particular object of the Car class - press 4;"<<std::endl;
    std::cout<<"To get report of a particular object of the Lorry class - press 5;"<<std::endl;
    std::cout<<"To end up and exit - press 6;"<<std::endl;

    std::cin >>choice;
    
            switch(choice) {
            case 1:
            {
                std::cout<<"Enter the trademark of the car"<<std::endl;
                std::cin>>trademark;

                std::cout<<"Enter the number of cylinders of the car"<<std::endl;
                std::cin>>cylinders;

                std::cout<<"Enter the power of the car"<<std::endl;
                std::cin>>power;

                //Создание объекта класса Car с помощью конструктора с параметрами
                car[i] = Car(trademark, cylinders, power);
                
                //Создание объекта класса Car с помощью конструктора с параметрами по умолчанию и методов-сеттеров
                //car[i] = Car();
                //setTrademark(trademark);
                //setCylinders(cylinders);
                //setPower(power);
                i++;
                break;
            }

            case 2:
            {
                std::cout<<"Enter the trademark of the lorry"<<std::endl;
                std::cin>>trademark;

                std::cout<<"Enter the number of cylinders of the lorry"<<std::endl;
                std::cin>>cylinders;

                std::cout<<"Enter the power of the lorry"<<std::endl;
                std::cin>>power;

                std::cout<<"Enter the load capacity of the lorry"<<std::endl;
                std::cin>>capacity;

                //Создание объекта класса Lorry с помощью конструктора с параметрами
                lorry[j] = Lorry(trademark, cylinders, power, capacity);
            
                //Создание объекта класса Lorry с помощью конструктора с параметрами по умолчанию и методов-сеттеров
                //lorry[j] = Lorry();
                //setTrademark(trademark);
                //setCylinders(cylinders);
                //setPower(power);
                //setCapacity(capacity);
                j++;
                break;
            }
            
            case 3:
            {
                count();
                break;
            }

            case 4:
            {
                std::cout<<"Enter the number of the car, less than "<<i<<std::endl;
                std::cin>>index;
                
                //Получение отчета об объекте с помощью перегруженного оператора вывода:
                std::cout << car[index];

                //Получение отчета об объекте с помощью методов-геттеров:
                getTrademark(&car[index]);
                getCylinders(&car[index]);
                getPower(&car[index]);
                break;
            }

            case 5:
            {
                std::cout<<"Enter the number of the lorry, less than "<<j<<std::endl;
                std::cin>>index;
                //Получение отчета об объекте с помощью перегруженного оператора вывода:
                std::cout << lorry[index];

                //Получение отчета об объекте с помощью методов-геттеров:
                getTrademark(&lorry[index]);
                getCylinders(&lorry[index]);
                getPower(&lorry[index]);
                getCapacity(&lorry[index]);
                break;
            }

            case 6:
            {break;}

            default:
            {
                std::cout<<"Wrong input. Try again."<<std::endl;
                break;
            }
        }
    }

    while (choice != 6);
    
    return 0;
}