#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <vector>
using namespace std;

struct info {
    string name;
    int termin;
    float cost;
};
bool sort_monitors(const info& mon1, const info& mon2) {
    return mon1.cost > mon2.cost;
}
struct info {
    string engine, color;
    int amount;
};
struct Car {
    string mark, model, deal;
    int year;
    float price;
    info cars;
};
void cardisplay_print(const vector<Car>& cars);
typedef struct {
    string surname, become;
    float avgmark;
} Students;
void bigger_mark(const vector<Students>& students);

int main()
{
    //Завдання 1
    int numeros;
    cout << "Input numeros of monitors: ";
    cin >> numeros;

    info *monitors = new info[numeros];
    for (int i = 0; i < numeros; i++) {
        cout << "Input name: ";
        cin >> monitors[i].name;
        cout << "Input term: ";
        cin >> monitors[i].termin;
        cout << "Input price: ";
        cin >> monitors[i].cost;
    }

    sort(monitors, monitors + numeros, sort_monitors);

    for (int i = 0; i < numeros; i++) {
        cout << "Name: " << monitors[i].name << endl;
        cout << "Term: " << monitors[i].termin << endl;
        cout << "Price: " << monitors[i].cost << endl;
    }
    delete[] monitors;
    //Завдання 2
    vector<Car> cars;
    int count;
    cout << "Input number of cars: ";
    cin >> count;
    
    for (int i = 0; i < count; i++) {
        Car car;
        cout << "Input brand: ";
        cin >> car.mark;
        cout << "Input model: ";
        cin >> car.model;
        cout << "Input year: ";
        cin >> car.year;
        cout << "Input price: ";
        cin >> car.price;
        cout << "Input deal: ";
        cin >> car.deal;
        cout << "Input engine: ";
        cin >> car.cars.engine;
        cout << "Input color: ";
        cin >> car.cars.color;
        cout << "Input amount of owners: ";
        cin >> car.cars.amount;
        cars.push_back(car);
    }
    cardisplay_print(cars);
    //Завдання 3
    vector <Students> students;
    int number;
    cout << "Input numbers of students: ";
    cin >> number;

    for (int i = 0; i < number; i++) {
        Students student;
        cout << "Input surname: ";
        cin >> student.surname;
        cout << "Input gender (male/female): ";
        cin >> student.become;
        cout << "Input average mark: ";
        cin >> student.avgmark;
        students.push_back(student);
    }
    bigger_mark(students);
    
    return 0;
}
void cardisplay_print(const vector<Car> &cars) {
    cout << left << setw(10) << "Brand" << setw(10) << "Model" << setw(10) << "Year" << setw(10) << "Price" << setw(10) << "Deal" << setw(10) << "Engine" << setw(10) << "Color" << setw(10) << "Owners" << endl;
    cout << "----------------------------------------------------------------------------" << endl;;
    for (const auto& car : cars) {
        cout << left << setw(10) << car.mark << setw(10) << car.model << setw(10) << car.year << setw(10) << car.price << setw(10) << car.deal << setw(10) << car.cars.engine << setw(10) << car.cars.color << setw(10) << car.cars.amount << endl;
    }
}
void bigger_mark(const vector<Students>& students) {
    int male = 0, female = 0, count_male = 0, count_female = 0;
    for (const auto& student : students) {
        if (student.become == "male") {
            male += student.avgmark;
            count_male++;
        }
        else if (student.become == "female") {
            female += student.avgmark;
            count_female++;
        }
    }
    float avg_male = male / count_male;
    float avg_female = female / count_female;

    cout << "Boys average: " << avg_male << endl;
    cout << "Girls average: " << avg_female << endl;
    if (avg_male > avg_female) {
        cout << "Boys have bigger average mark";
    }
    else if (avg_male < avg_female) {
        cout << "Girls have bigger average mark";
    }
}

