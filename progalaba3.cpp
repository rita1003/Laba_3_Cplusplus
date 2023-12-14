#include <iostream>

using namespace std;

class Company;
class Employee;
class Vehicle;
class Truck;
class Car;

class Company {
private: //��������
	string name; //������� �� UML Class Diagram
	string matching_addresses; //������� 1 ��� �������-����� 1
	string existence_subsidiaries; //������� 2 ��� �������-����� 2

public:
	//������� ������
	void print() {
		cout << "\nCompany: " << name << "\nMatching Addresses: " << matching_addresses << "\nExistence Subsidiaries: " << existence_subsidiaries << endl;
	}

	//�������-���� 1. ���������, ��������� �� ����������� ����� � �����������
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

	//�������-���� 2. ��������, ���������� �� � �������� �������� �������
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

	//����������� 1. ���������

	Company() {
		name = "Yandex";
		matching_addresses = "The physical address is the same as the legal address";
		existence_subsidiaries = "The company has subsidiaries";
	}

	//����������� 2. ����������� ����� ������ ��������������� ������

	Company(string p_name, string p_matching_addresses, string p_existence_subsidiaries) : name(p_name), matching_addresses(p_matching_addresses), existence_subsidiaries(p_existence_subsidiaries)
	{}

protected: //����������
	Employee** employed_employee; //������� ��������� (��� ����������: ����-��-������)
	Vehicle** hired_vehicle; //������. ��������, ������ � ������ (��� ����������: ����-��-������)

};

class Employee {
private: //��������
	string name; //������� �� UML Class Diagram
	string having_children; //������� 1 ��� �������-����� 1
	string higher_education; //������� 2 ��� �������-����� 2

public:
	//������� ������
	void print() {
		cout << "\nEmployee: " << name << "\nHaving Children: " << having_children << "\nHigher Education: " << higher_education << endl;
	}

	//�������-���� 1. �������� ���������� � �������/���������� �����
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

	//�������-���� 2. �������� ���������� � �������/���������� ������� �����������
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

	//����������� 1. ���������

	Employee() {
		name = "Oleg";
		having_children = "The employee has children";
		higher_education = "The employee does not have a higher education";
	}

	//����������� 2. ����������� ����� ������ ��������������� ������

	Employee(string p_name, string p_having_children, string p_higher_education) : name(p_name), having_children(p_having_children), higher_education(p_higher_education)
	{}

protected: //����������
	Company* empoying_company; //��������-������������ (��� ����������: ����-��-������)
	Vehicle** driven_vehicle; //����������� ������ (��� ����������: ����-��-������)

};

class Vehicle {
private: //��������
	string registration_number; //������� �� UML Class Diagram 

protected: //������� protected, ����� ����� ������������ � ������������
	string value_axes; //������� ��� �������-����� 1
	string country_vehicle; //������� ��� �������-����� 2
	string cost_vehicle; //������� ��� ������������� ������������
	string currency; //������� ��� ������������� ������������
	string mileage; //������� ��� ������������� ������������

public:
	//������� ������ ��� ���������� � ������������ ������������
	void print() {
		cout << "\nRegistration number: " << registration_number << "\nValue axes: " << value_axes << "\nCountry vehicle: " << country_vehicle << endl;
	}

	//������� ������ ��� ������������� ������������ 1
	void print2() {
		cout << "\nCost of the vehicle: " << cost_vehicle << "\nCurrency: " << currency << endl;
	}

	//������� ������ ��� ������������� ������������ 2
	void print3() {
		cout << "\nMileage of the vehicle: " << mileage << endl;
	}

	//�������-���� 1. ��������, ����� ��� ������������� �������� �� ���������� ���� 
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

	//�������-���� 2. ��������, ����� ������ ����������� ����� ������������� ��������
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

	//����������� 1. ���������

	Vehicle() {
		registration_number = "AA-487-AB";
		value_axes = "The vehicle is multi-axle"; //������������
		country_vehicle = "France"; //������������ 
	}

	//����������� 2. ����������� ����� ������ ��������������� ������

	Vehicle(string p_registation_number, string p_value_axes, string p_country_vehicle) : registration_number(p_registation_number), value_axes(p_value_axes), country_vehicle(p_country_vehicle)
	{}

	//����������� 3. ������������
	Vehicle(string p_cost_vehicle, string p_currency) {
		this->cost_vehicle = p_cost_vehicle; //������������
		this->currency = p_currency; //������������
	}

	//����������� 4. ������������
	Vehicle(string p_mileage) {
		this->mileage = p_mileage;
	}

protected: //����������
	Employee* driving_employee; //��������, ������� ������������ �������� (��� ����������: ����-��-������)
	Company* hiring_company; //��������, ������� � ������ (��� ����������: ����-��-������)
};

class Truck : protected Vehicle {
private: //��������
	int mass; //������� �� UML Class Diagram
	string body_type; //������������� ������� 1. ��� ������
	string fuel_type; //������������� ������� 2. ��� �������

public:
	//����� 1
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

	//����� 2
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

	//������� ������ ��� ������. ������������ 1
	void print11() {
		cout << "\nFuel type: " << fuel_type << "\nCost Vehicle: " << cost_vehicle << "\nCurrency: " << currency << endl;
	}

	//������� ������ ��� ������. ������������ 2
	void print22() {
		cout << "Mileage: " << mileage << endl;
	}

	//������� ������ ��� ������. ������������ 3
	void print33() {
		cout << "Body type: " << body_type << "\nFuel type: " << fuel_type << "\nCost vehicle: " <<cost_vehicle<<"\nCurrency: "<< currency << endl;
	}

	//������������ ����������� 1 � �������������� ������������� ������
	Truck(string p_fuel_type, string cost_vehicle, string currency) : Vehicle(cost_vehicle, currency) {
		fuel_type = p_fuel_type;
	}

	//������������ ����������� 2 � �������������� ������������� ������
	Truck(string mileage) : Vehicle(mileage) {
	}

	//������������ ����������� 3 � �������������� ������������� ������
	Truck(string p_body_type, string p_fuel_type, string cost_vehicle, string currency) : Vehicle(cost_vehicle, currency) {
		body_type = p_body_type;
		fuel_type = p_fuel_type;
	} 
};

class Car : public Vehicle {
private: //��������
	string transmission; //������� �� UML Class Diagram
	string actuator; //������������� ������� 1. ������
	string modification; //����������� ������� 2. ����������� (������)

public:
	//����� 1
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

	//����� 2
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

	//������� ������ ��� ������. ������������ 1
	void print11() {
		cout << "\nActuator: " << actuator << "\nCurrency: " << mileage << endl;
	}

	//������� ������ ��� ������. ������������ 2
	void print22() {
		cout << "Actuator: " << actuator << "\nModification: " << modification << "\nCost vehicle: " << mileage << endl;
	}

	//������� ������ ��� ������. ������������ 3
	void print33() {
		cout << "Mileage: " << mileage << endl;
	}

	//������������ ����������� 1 � �������������� ������������� ������
	Car(string p_actuator, string currency) : Vehicle (currency){
		actuator = p_actuator;
	}

	//������������ ����������� 2 � �������������� ������������� ������
	Car(string p_actuator, string p_modification, string cost_vehicle) : Vehicle (cost_vehicle) {
		actuator = p_actuator;
		modification = p_modification;
	}

	//������������ ����������� 3 � �������������� ������������� ������
	Car(string mileage) : Vehicle (mileage){
	}

};


int main() {

	//����� Company. ����� �������� ���������� ������������.
	cout << "1.1. Class Company. Default constructor" << endl;
	Company yandex1;
	yandex1.print();

	//����� Company. ����� �������� ������������ ������������ ����� ������ ���������������-������.
	cout << "\n1.2.Class Company. Non-default constructor" << endl;
	Company yandex; 

	Company yandex2{ "Yandex", yandex.MatchingAddresses(), yandex.ExistenceSubsidiaries()};
	yandex2.print();

	/////////////////////////////////////////////////

	//����� Employee. ����� �������� ���������� ������������.
	cout << "\n2.1. Class Employee. Default constructor" << endl;
	Employee person1;
	person1.print();

	//����� Employee. ����� �������� ������������ ������������ ����� ������ ���������������-������.
	cout << "\n2.2.Class Employee. Non-default constructor" << endl;
	Employee person;

	cout << "Enter name: ";
	string name;
	cin >> name;

	Employee person2{ name, person.HavingChildren(), person.HigherEducation() };
	person2.print();

	/////////////////////////////////

	//����� Vehicle. ����� �������� ���������� ������������.
	cout << "\n3.1. Class Vehicle. Default constructor" << endl;
	Vehicle vehicle1;
	vehicle1.print();

	//����� Vehicle. ����� �������� ������������ ������������ ����� ������ ���������������-������.
	cout << "\n3.2. Class Vehicle. Non-default constructor" << endl;
	Vehicle vehicle;

	cout << "Enter registration number: ";
	string registration_number;
	cin >> registration_number;

	Vehicle vehicle2{ registration_number, vehicle.Axes(), vehicle.CountryVehicle() };
	vehicle2.print();

	//����� Vehicle. ������������ ����������� 1.
	cout << "\n3.3. Class Vehicle. Custom constructor 1" << endl;

	Vehicle vehicle3{ "5453", "dollars"};
	vehicle3.print2();

	//����� Vehicle. ������������ ����������� 2.
	cout << "\n3.4. Class Vehicle. Custom constructor 2" << endl;

	Vehicle vehicle4("1324");
	vehicle4.print3();

	////////////////////////////////////////
	
	//����� Truck. ������������ ����������� 1 � �������������� ������������� ������
	cout << "\n4.1. Class Truck. Constructor 1" << endl;

	Truck truck1{"gas", "1000000", "dollars"};
	truck1.print11();

	//����� Truck. ������������ ����������� 2 � �������������� ������������� ������
	cout << "\n4.2. Class Truck. Constructor 2" << endl;

	Truck truck2{ "10000 km" };
	truck2.print22();

	//����� Truck. ������������ ����������� 3 � �������������� ������������� ������
	cout << "\n4.3. Class Truck. Constructor 3" << endl;

	Truck truck3{"close", "petrol", "23432", "pounds"};
	truck3.print33();

	////////////////////////////////////////

	//����� Car. ������������ ����������� 1 � �������������� ������������� ������
	cout << "\n4.1. Class Car. Constructor 1" << endl;

	Car car1{"front-wheel drive" ,"euro"};
	car1.print11();

	//����� Car. ������������ ����������� 2 � �������������� ������������� ������
	cout << "\n4.2. Class Car. Constructor 2" << endl;

	Car car2{"front-wheel drive", "B", "433"};
	car2.print22();

	//����� Car. ������������ ����������� 3 � �������������� ������������� ������
	cout << "\n4.3. Class Car. Constructor 3" << endl;

	Car car3{"3423 km"};
	car3.print33();

	return 0;
}