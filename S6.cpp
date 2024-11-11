#include <iostream>
#include <string>
using namespace std;

/*DataTypes:
-char*
-const int
-static int
-string

Methods:
+copy constructor
+constructor cu parametrii
+set/get methods
+destructor
+operatoror =
+operatoror <<
*/

class Car
{
    string make;
    char* model;
    static int created_cars;
    const int serial_number;

    public:
        Car():serial_number(0),make(""),model(nullptr) // initializare const int
        {
            created_cars++;
        }

        Car(string _make,char* _model,int _serial_number):serial_number(_serial_number),make(_make)
        {
            this->model = new char[strlen(_model)+1];
            strcpy_s(this->model, strlen(_model)+1, _model);
            created_cars++;
        }

        // Car(const Car& copy):serial_number(copy.serial_number)
        // {
        //     this->make = copy.make;
        //     this->model = new char[strlen(copy.model)+1];
        //     strcpy_s(this->model, strlen(copy.model)+1, copy.model);
        //     created_cars++;
        // }

        Car(const Car& copy): Car(copy.make, copy.model, copy.serial_number)
        {
        }

        void set_model(const char* _model)
        {
            this->model = new char[strlen(_model)+1];
            strcpy_s(this->model, strlen(_model)+1, _model);
        }

        char* get_model()
        {
            //return this->model; IT CREATES A SHALLOW COPY
            char* temp = new char[strlen(this->model)+1];
            strcpy_s(temp, strlen(this->model)+1, this->model);
            return temp;
        }

        ~Car()
        {
            delete this->model;
            created_cars--;
            //for arrays
            // delete[] this->array_var;
        }

        void operatoror = (const Car& copy)
        {
            this->make = copy.make;
            this->model = new char[strlen(copy.model)+1];
            strcpy_s(this->model, strlen(copy.model)+1, copy.model);
        }

        static int get_created_cars()
        {
            return Car::created_cars;
            //return created_car;
        };
};

int Car::created_cars = 0; //initializare static int

int main()
{
    Car car1("BMW", (char*) "X5", 1);
    cout << Car::get_created_cars() << endl;
    Car car2 = car1;
    cout << Car::get_created_cars() << endl;
    Car car3;
    car3 = car2;

    Car*4 = new Car("BMW", "X5", 2);
    cout << Car::get_created_cars() << endl;
    delete car4;
    cout << Car::get_created_cars() << endl;
    return 0;
}