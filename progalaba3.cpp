#include <iostream>

using namespace std;

class Company;
class Employee;
class Vehicle;
class Truck;
class Car;

class Company {
private: //атрибуты
	string name; //атрибут из UML Class Diagram
	string matching_addresses; //атрибут 1 для функции-члена 1
	string existence_subsidiaries; //атрибут 2 для функции-члена 2

public:
	//Функция вывода
	void print() {
		cout << "\nCompany: " << name << "\nMatching Addresses: " << matching_addresses << "\nExistence Subsidiaries: " << existence_subsidiaries << endl;
	}

	//Функция-член 1. Проверяет, совпадает ли юридический адрес с фактическим
	string MatchingAddresses() {
		string legal_address, physical_address;

		cout << "Enter legal address: ";
		cin >> legal_address;
		cout << "Enter physical address: ";
		cin >> physical_address;

		if (legal_address == physical_address) {
			matching_addresses = "The physical address is the same as the legal address";
		}
		else {
			matching_addresses = "The physical address does not match the legal address";
		}

		return matching_addresses;
	}

	//Функция-член 2. Сообщает, существуют ли у компании дочерние филиалы
	string ExistenceSubsidiaries() {

		string subsidiaries;

		cout << "Enter the subsidiaries. If there are none, write NONE: ";
		cin >> subsidiaries;

		if (subsidiaries != "NONE") {
			existence_subsidiaries = "The company has subsidiaries";
		}
		else {
			existence_subsidiaries = "The company hasn't got subsidiaries";
		}

		return existence_subsidiaries;
	}

	//Конструктор 1. Дефолтный

	Company() {
		name = "Yandex";
		matching_addresses = "The physical address is the same as the legal address";
		existence_subsidiaries = "The company has subsidiaries";
	}

	//Конструктор 2. Недефолтный через список инициализаторов членов

	Company(string p_name, string p_matching_addresses, string p_existence_subsidiaries) : name(p_name), matching_addresses(p_matching_addresses), existence_subsidiaries(p_existence_subsidiaries)
	{}

protected: //ассоциация
	Employee** employed_employee; //нанятый сотрудник (вид ассоциации: один-ко-многим)
	Vehicle** hired_vehicle; //трансп. средство, взятое в аренду (вид ассоциации: один-ко-многим)

};

class Employee {
private: //атрибуты
	string name; //атрибут из UML Class Diagram
	string having_children; //атрибут 1 для функции-члена 1
	string higher_education; //атрибут 2 для функции-члена 2

public:
	//Функция вывода
	void print() {
		cout << "\nEmployee: " << name << "\nHaving Children: " << having_children << "\nHigher Education: " << higher_education << endl;
	}

	//Функция-член 1. Сообщает информацию о наличии/отсутствии детей
	string HavingChildren() {

		string children;

		cout << "Does the employee have children? If not, write NONE: ";
		cin >> children; 

		if (children != "NONE") {
			having_children = "The employee has children";
		}
		else {
			having_children = "The employee does not have children";
		}

		return having_children;
	}

	//Функция-член 2. Сообщает информацию о наличии/отсутствии высшего образования
	string HigherEducation() {
		string education;

		cout << "Does the employee have a higher education? If not, write NONE: ";

		cin >> education;

		if (education != "NONE") {
			higher_education = "The employee has a higher education";
		}
		else {
			higher_education = "The employee does not have a higher education";
		}
		
		return higher_education;
	}

	//Конструктор 1. Дефолтный

	Employee() {
		name = "Oleg";
		having_children = "The employee has children";
		higher_education = "The employee does not have a higher education";
	}

	//Конструктор 2. Недефолтный через список инициализаторов членов

	Employee(string p_name, string p_having_children, string p_higher_education) : name(p_name), having_children(p_having_children), higher_education(p_higher_education)
	{}

protected: //ассоциация
	Company* empoying_company; //компания-работодатель (вид ассоциации: один-ко-многим)
	Vehicle** driven_vehicle; //управляемая машина (вид ассоциации: один-ко-многим)

};

class Vehicle {
private: //атрибуты
	string registration_number; //атрибут из UML Class Diagram 

protected: //сделала protected, чтобы потом использовать в наследовании
	string value_axes; //атрибут для функции-члена 1
	string country_vehicle; //атрибут для функции-члена 2
	string cost_vehicle; //атрибут для произвольного конструктора
	string currency; //атрибут для произвольного конструктора
	string mileage; //атрибут для произвольного конструктора

public:
	//Функция вывода для дефолтного и недефелтного конструктора
	void print() {
		cout << "\nRegistration number: " << registration_number << "\nValue axes: " << value_axes << "\nCountry vehicle: " << country_vehicle << endl;
	}

	//Функция вывода для произвольного конструктора 1
	void print2() {
		cout << "\nCost of the vehicle: " << cost_vehicle << "\nCurrency: " << currency << endl;
	}

	//Функция вывода для произвольного конструктора 2
	void print3() {
		cout << "\nMileage of the vehicle: " << mileage << endl;
	}

	//Функция-член 1. Сообщает, какой тип транспортного средства по количеству осей 
	string Axes() {
		
		int amount_axes;

		cout << "Enter the number of axles of the employee's vehicle: ";

		cin >> amount_axes;

		if (amount_axes == 2) {
			value_axes = "The vehicle is two-axle";
		}
		else if (amount_axes == 3) {
			value_axes = "The vehicle is three-axle";
		}
		else if (amount_axes > 3) {
			value_axes = "The vehicle is multi-axle";
		}
		else {
			value_axes = "There is no data on the number of axes";
		}

		return value_axes;
	}

	//Функция-член 2. Сообщает, какой стране принадлежит марка транспортного средства
	string CountryVehicle() {
		string car_brand;

		cout << "Enter the company of the machine: ";

		cin >> car_brand;

		if (car_brand == "Acura" || car_brand == "Datsun" || car_brand == "Honda") {
			country_vehicle = "Japan";
		}
		else if (car_brand == "Cadillsac" || car_brand == "Chevrolet" || car_brand == "Ford") {
			country_vehicle = "USA";
		}
		else if (car_brand == "Haval" || car_brand == "Chery" || car_brand == "FAW") {
			country_vehicle = "China";
		}
		else if (car_brand == "Kia" || car_brand == "Hyundai" || car_brand == "Daewoo") {
			country_vehicle = "Korea";
		}
		else if (car_brand == "Jaguar" || car_brand == "Bentley" || car_brand == "Land Rover") {
			country_vehicle = "England";
		}
		else if (car_brand == "Ferrari" || car_brand == "Fiat" || car_brand == "Maserati") {
			country_vehicle = "Italy";
		}
		else if (car_brand == "Audi" || car_brand == "BMW" || car_brand == "Mercedes") {
			country_vehicle = "Germany";
		}
		else if (car_brand == "Citroen" || car_brand == "Peugeot" || car_brand == "Renault") {
			country_vehicle = "France";
		}
		else {
			country_vehicle = "There is no information about the country of origin";
		}

		return country_vehicle;
	}

	//Конструктор 1. Дефолтный

	Vehicle() {
		registration_number = "AA-487-AB";
		value_axes = "The vehicle is multi-axle"; //наследование
		country_vehicle = "France"; //наследование 
	}

	//Конструктор 2. Недефолтный через список инициализаторов членов

	Vehicle(string p_registation_number, string p_value_axes, string p_country_vehicle) : registration_number(p_registation_number), value_axes(p_value_axes), country_vehicle(p_country_vehicle)
	{}

	//Конструктор 3. Произвольный
	Vehicle(string p_cost_vehicle, string p_currency) {
		this->cost_vehicle = p_cost_vehicle; //наследование
		this->currency = p_currency; //наследование
	}

	//Конструктор 4. Произвольный
	Vehicle(string p_mileage) {
		this->mileage = p_mileage;
	}

protected: //ассоциация
	Employee* driving_employee; //работник, водящий транспортное средство (вид ассоциации: один-ко-многим)
	Company* hiring_company; //компания, взявшая в аренду (вид ассоциации: один-ко-многим)
};

class Truck : protected Vehicle {
private: //атрибуты
	int mass; //атрибут из UML Class Diagram
	string body_type; //специфический атрибут 1. Тип кузова
	string fuel_type; //специфический атрибут 2. Тип топлива

public:
	//метод 1
	string BodyType() {

		string type;

		cout << "Enter the body type of truck: ";

		cin >> type;

		if (type == "open") {
			body_type = "The body type of truck is open";
		}
		else if (type == "close") {
			body_type = "The body type of truck is close";
		}
		else if (type == "special") {
			body_type = "The body type of truck is special";
		}
		else {
			body_type = "The body type is not known";
		}

		return body_type;
	}

	//метод 2
	string FuelType() {

		string type;

		cout << "Enter the fuel type of truck: ";

		cin >> type;

		if (type == "diesel fuel") {
			fuel_type = "The fuel type of truck is diesel fuel";
		}
		else if (type == "petrol") {
			fuel_type = "The fuel type of truck is petrol";
		}
		else if (type == "gas") {
			fuel_type = "The fuel type of truck is gas";
		}
		else {
			fuel_type = "The fuel type is not known";
		}
		return fuel_type;
	}

	//Функция вывода для произв. конструктора 1
	void print11() {
		cout << "\nFuel type: " << fuel_type << "\nCost Vehicle: " << cost_vehicle << "\nCurrency: " << currency << endl;
	}

	//Функция вывода для произв. конструктора 2
	void print22() {
		cout << "Mileage: " << mileage << endl;
	}

	//Функция вывода для произв. конструктора 3
	void print33() {
		cout << "Body type: " << body_type << "\nFuel type: " << fuel_type << "\nCost vehicle: " <<cost_vehicle<<"\nCurrency: "<< currency << endl;
	}

	//Произвольный конструктор 1 с использованием родительского класса
	Truck(string p_fuel_type, string cost_vehicle, string currency) : Vehicle(cost_vehicle, currency) {
		fuel_type = p_fuel_type;
	}

	//Произвольный конструктор 2 с использованием родительского класса
	Truck(string mileage) : Vehicle(mileage) {
	}

	//Произвольный конструктор 3 с использованием родительского класса
	Truck(string p_body_type, string p_fuel_type, string cost_vehicle, string currency) : Vehicle(cost_vehicle, currency) {
		body_type = p_body_type;
		fuel_type = p_fuel_type;
	} 
};

class Car : public Vehicle {
private: //атрибуты
	string transmission; //атрибут из UML Class Diagram
	string actuator; //специфический атрибут 1. Привод
	string modification; //специальный атрибут 2. Модификация (сборка)

public:
	//метод 1
	string MethodActuator() {
		string actuat;

		cout << "Enter the actuator of the car: ";

		cin >> actuat;

		if (actuat == "rear-wheel drive") {
			actuator = "The actuator of the car is rear-wheel drive"; 
		}
		else if (actuat == "front-wheel drive") {
			actuator = "The actuator of the car is front-wheel drive";
		}
		else if (actuat == "all-wheel drive") {
			actuator = "The actuator of the car is all-wheel drive";
		}
		else {
			actuator = "The actuator of the car is not known";
		}

		return actuator;

	}

	//метод 2
	string MethodModification() {
		string modifi;

		cout << "Enter the modification of the car: ";

		cin >> modifi;

		if (modifi == "A") {
			modification = "Modification of the car is mini car";
		}
		else if (modifi == "B") {
			modification = "Modification of the car is small car";
		}
		else if (modifi == "C") {
			modification = "Modification of the car is medium car";
		}
		else if (modifi == "D") {
			modification = "Modification of the car is larger car";
		}
		else if (modifi == "E") {
			modification = "Modification of the car is executive car";
		}
		else if (modifi == "F") {
			modification = "Modification of the car is luxury car";
		}
		else if (modifi == "J") {
			modification = "Modification of the car is sport utility";
		}
		else if (modifi == "M") {
			modification = "Modification of the car is multi purpose car";
		}
		else if (modifi == "S") {
			modification = "Modification of the car is sport coupe";
		}
		else {
			modification = "Modification of the car is not known";
		}

		return modification;

	}

	//Функция вывода для произв. конструктора 1
	void print11() {
		cout << "\nActuator: " << actuator << "\nCurrency: " << mileage << endl;
	}

	//Функция вывода для произв. конструктора 2
	void print22() {
		cout << "Actuator: " << actuator << "\nModification: " << modification << "\nCost vehicle: " << mileage << endl;
	}

	//Функция вывода для произв. конструктора 3
	void print33() {
		cout << "Mileage: " << mileage << endl;
	}

	//Произвольный конструктор 1 с использованием родительского класса
	Car(string p_actuator, string currency) : Vehicle (currency){
		actuator = p_actuator;
	}

	//Произвольный конструктор 2 с использованием родительского класса
	Car(string p_actuator, string p_modification, string cost_vehicle) : Vehicle (cost_vehicle) {
		actuator = p_actuator;
		modification = p_modification;
	}

	//Произвольный конструктор 3 с использованием родительского класса
	Car(string mileage) : Vehicle (mileage){
	}

};


int main() {

	//Класс Company. Вывод значений дефолтного конструктора.
	cout << "1.1. Class Company. Default constructor" << endl;
	Company yandex1;
	yandex1.print();

	//Класс Company. Вывод значений недефолтного конструктора через список инициализаторов-членов.
	cout << "\n1.2.Class Company. Non-default constructor" << endl;
	Company yandex; 

	Company yandex2{ "Yandex", yandex.MatchingAddresses(), yandex.ExistenceSubsidiaries()};
	yandex2.print();

	/////////////////////////////////////////////////

	//Класс Employee. Вывод значений дефолтного конструктора.
	cout << "\n2.1. Class Employee. Default constructor" << endl;
	Employee person1;
	person1.print();

	//Класс Employee. Вывод значений недефолтного конструктора через список инициализаторов-членов.
	cout << "\n2.2.Class Employee. Non-default constructor" << endl;
	Employee person;

	cout << "Enter name: ";
	string name;
	cin >> name;

	Employee person2{ name, person.HavingChildren(), person.HigherEducation() };
	person2.print();

	/////////////////////////////////

	//Класс Vehicle. Вывод значений дефолтного конструктора.
	cout << "\n3.1. Class Vehicle. Default constructor" << endl;
	Vehicle vehicle1;
	vehicle1.print();

	//Класс Vehicle. Вывод значений недефолтного конструктора через список инициализаторов-членов.
	cout << "\n3.2. Class Vehicle. Non-default constructor" << endl;
	Vehicle vehicle;

	cout << "Enter registration number: ";
	string registration_number;
	cin >> registration_number;

	Vehicle vehicle2{ registration_number, vehicle.Axes(), vehicle.CountryVehicle() };
	vehicle2.print();

	//Класс Vehicle. Произвольный конструктор 1.
	cout << "\n3.3. Class Vehicle. Custom constructor 1" << endl;

	Vehicle vehicle3{ "5453", "dollars"};
	vehicle3.print2();

	//Класс Vehicle. Произвольный конструктор 2.
	cout << "\n3.4. Class Vehicle. Custom constructor 2" << endl;

	Vehicle vehicle4("1324");
	vehicle4.print3();

	////////////////////////////////////////
	
	//Класс Truck. Произвольный конструктор 1 с использованием родительского класса
	cout << "\n4.1. Class Truck. Constructor 1" << endl;

	Truck truck1{"gas", "1000000", "dollars"};
	truck1.print11();

	//Класс Truck. Произвольный конструктор 2 с использованием родительского класса
	cout << "\n4.2. Class Truck. Constructor 2" << endl;

	Truck truck2{ "10000 km" };
	truck2.print22();

	//Класс Truck. Произвольный конструктор 3 с использованием родительского класса
	cout << "\n4.3. Class Truck. Constructor 3" << endl;

	Truck truck3{"close", "petrol", "23432", "pounds"};
	truck3.print33();

	////////////////////////////////////////

	//Класс Car. Произвольный конструктор 1 с использованием родительского класса
	cout << "\n4.1. Class Car. Constructor 1" << endl;

	Car car1{"front-wheel drive" ,"euro"};
	car1.print11();

	//Класс Car. Произвольный конструктор 2 с использованием родительского класса
	cout << "\n4.2. Class Car. Constructor 2" << endl;

	Car car2{"front-wheel drive", "B", "433"};
	car2.print22();

	//Класс Car. Произвольный конструктор 3 с использованием родительского класса
	cout << "\n4.3. Class Car. Constructor 3" << endl;

	Car car3{"3423 km"};
	car3.print33();

	return 0;
}
