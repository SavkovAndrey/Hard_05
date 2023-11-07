#include <iomanip>
#include <iostream>
#include <time.h>
#include <string>
#include <vector>

using namespace std;
//---------------------Задание---------------------------------------------------
/*
Необходимо создать класс — зоомагазин.В классе должны быть следующие поля :
животное(напр.волк, пингвин, собака), пол, имя, цена, количество.
Включить в состав класса необходимый минимум методов, 
обеспечивающий полноценное функционирование объектов указанного класса :

- Конструкторы(по умолчанию, с параметрами, копирования);
- Деструктор;
- Переопределить возможные для класса операции, продумать порядок их выполнения;
- Добавить необходимые методы.
- Предоставить возможность вводить данные с клавиатуры или из файла(с помощью конструктора или операцией »).
*/



//-------------------- Классы ---------------------------------------------------

class pet_store
{
private:
	string type;       // устанавливается клиентом
	string sex;        // устанавливается клиентом
	string name;       // устанавливается клиентом
	int price;         // устанавливается клиентом
	static int quantity;      // выставляется системой
	
public:


    pet_store()            // конструктор по умолчанию
	{
		this->type = "none";
		this->sex = "none";
		this->name = "none";
		this->price = 0;
	}  
	 
	pet_store(const pet_store & other)           // конструктор копирования
	{
		this->type = other.type;
		this->sex = other.sex;
		this->name = other.name;
		this->price = other.price;
	}

	pet_store(string type, string sex, string name, int price)            // конструктор с параметрами
	{
		this->type = type;
		this->sex = sex;
		this->name = name;
		this->price = price;
		pet_store::quantity++;
	}

	~pet_store()           // деструктор
	{
		
	}

	void setType(string type);
	void setSex(string sex);
	void setName(string name);
	void setPrice(int price);

	string getType();
	string getSex();
	string getName();
	int getPrice();

	static int getQuantity()
	{
		return quantity;
	}
	static void setQuantity(int temp)
	{
		quantity = temp;
	}

};

int pet_store::quantity = 0;

//---------------------Функции и Прототипы---------------------------------------

void Out_menu();
void InputPet(vector<pet_store>& Pets);
void ChangePet(vector<pet_store>& Pets);
void OutputALLPet(vector<pet_store> Pets);
void  DeletePet(vector<pet_store>& Pets);

//------------------------MAIN----------------------------------------------------
int main() {
	setlocale(LC_ALL, "RU");
	srand(time(NULL));
	//-------------------------------САМА ПРОГА-------------------------------------

	int a;         // выбор из меню

	vector<pet_store> Pets;


	while (true)
	{
		Out_menu();

		cin >> a;

		if (a == 0)
		{
			cout << endl << "Вы вышли из программы! Досвидания." << endl << endl;
			break;
		}

		switch (a)
		{
		  case 1:
			  InputPet(Pets);
               break;
		  
		  case 2:
			  ChangePet(Pets);
   			   break;
		  
		  case 3:
			  OutputALLPet(Pets);
			   break;

		  case 4:
			  DeletePet(Pets);
			  break;
		}
	}



	system("pause");
	return 0;
}

//------------------------------ ФУНКЦИИ ----------------------------------------------

void Out_menu()
{
	cout << endl << "Меню: " << endl;
	cout << "1 - Добавить животное" << endl;
	cout << "2 - Изменить информацию о животном" << endl;
	cout << "3 - вывести всю информацию о всех животных" << endl;
	cout << "4 - удалить животное" << endl;
	cout << "0 - выход из программы" << endl << endl;
	cout << "Сделайте Ваш выбор: ";
}

void InputPet(vector<pet_store>& Pets)        //  ( 1 )  добавление нового животного
{
	string t_type, t_sex, t_name;             // временные переменные для ввода
	int t_price;                              //

	cout << "Введите ТИП животного: " << endl;
	cin >> t_type;
	cout << "Введите ПОЛ животного: " << endl;
	cin >> t_sex;
	cout << "Введите ИМЯ животного: " << endl;
	cin >> t_name;
	cout << "Введите ЦЕНУ живвотного: " << endl;
	cin >> t_price;

	Pets.emplace_back(t_type, t_sex, t_name, t_price);
	
}

void ChangePet(vector<pet_store>& Pets)          // ( 2 ) изменение данных животного
{
	string t2_type, t2_sex, t2_name;
	int t2_price;
	int numpet;            // временная
	cout << endl << "Выбирите номер животного, данные о котором вы хотите изменить: ";
	cin >> numpet;

	cout << "Сейчас ТИП: " << Pets[numpet - 1].getType() << "\t";
	cout << "Измените ТИП животного: " << endl;
	cin >> t2_type;
	Pets[numpet - 1].setType(t2_type);

	cout << "Сейчас ПОЛ: " << Pets[numpet - 1].getSex() << "\t";
	cout << "Измените ПОЛ животного: " << endl;
	cin >> t2_sex;
	Pets[numpet - 1].setSex(t2_sex);

	cout << "Сейчас ИМЯ: " << Pets[numpet - 1].getName() << "\t";
	cout << "Введите ИМЯ животного: " << endl;
	cin >> t2_name;
	Pets[numpet - 1].setName(t2_name);

	cout << "Сейчас ЦЕНА: " << Pets[numpet - 1].getPrice() << "\t";
	cout << "Введите ЦЕНУ живвотного: " << endl;
	cin >> t2_price;
	Pets[numpet - 1].setPrice(t2_price);
}

void OutputALLPet(vector<pet_store> Pets)       // ( 3 ) вывод всех животных на экран
{
	cout << endl << "НОМЕР животного\tВИД животного\tПОЛ животного\tИМЯ животного\tЦЕНА животного" << endl;
	for (int i = 0; i < Pets.size(); i++)
	{
		cout << setw(10) << i + 1 << "\t" << setw(10) << Pets[i].getType() << "\t" << setw(10) << Pets[i].getSex() << "\t" << setw(10) << Pets[i].getName() << "\t" << setw(10) << Pets[i].getPrice();
		cout << endl;
	}
	cout << "Число животных в зоомагазине: " << pet_store::getQuantity();
	cout << endl;

}

void  DeletePet(vector<pet_store>& Pets)        // ( 4 ) удаление животного
{
	int number;                    // временная переменная
	cout << endl << "Выбирите НОМЕР животного, которого хотите удалить: " << endl;
	cin >> number;

	Pets.erase(Pets.begin() + number - 1);
	pet_store::setQuantity(pet_store::getQuantity() - 1);
}
//---------------------- МЕТОДЫ КЛАССА -----------------------------------------------

// ---- Set ----

void pet_store::setType(string type)
{
	this->type = type;
}

void pet_store::setName(string name)
{
	this->name = name;
}

void pet_store::setSex(string sex)
{
	this->sex = sex;
}

void pet_store::setPrice(int price)
{
	this->price = price;
}

// ---- Get ----

string pet_store::getType()
{
	return type;
}

string pet_store::getName()
{
	return name;
}

string pet_store::getSex()
{
	return sex;
}

int pet_store::getPrice()
{
	return price;
}

// ---- All ----