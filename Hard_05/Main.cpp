#include <iomanip>
#include <iostream>
#include <time.h>
#include <string>
#include <vector>

using namespace std;
//---------------------�������---------------------------------------------------
/*
���������� ������� ����� � ����������.� ������ ������ ���� ��������� ���� :
��������(����.����, �������, ������), ���, ���, ����, ����������.
�������� � ������ ������ ����������� ������� �������, 
�������������� ����������� ���������������� �������� ���������� ������ :

- ������������(�� ���������, � �����������, �����������);
- ����������;
- �������������� ��������� ��� ������ ��������, ��������� ������� �� ����������;
- �������� ����������� ������.
- ������������ ����������� ������� ������ � ���������� ��� �� �����(� ������� ������������ ��� ��������� �).
*/



//-------------------- ������ ---------------------------------------------------

class pet_store
{
private:
	string type;       // ��������������� ��������
	string sex;        // ��������������� ��������
	string name;       // ��������������� ��������
	int price;         // ��������������� ��������
	static int quantity;      // ������������ ��������
	
public:


    pet_store()            // ����������� �� ���������
	{
		this->type = "none";
		this->sex = "none";
		this->name = "none";
		this->price = 0;
	}  
	 
	pet_store(const pet_store & other)           // ����������� �����������
	{
		this->type = other.type;
		this->sex = other.sex;
		this->name = other.name;
		this->price = other.price;
	}

	pet_store(string type, string sex, string name, int price)            // ����������� � �����������
	{
		this->type = type;
		this->sex = sex;
		this->name = name;
		this->price = price;
		pet_store::quantity++;
	}

	~pet_store()           // ����������
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

//---------------------������� � ���������---------------------------------------

void Out_menu();
void InputPet(vector<pet_store>& Pets);
void ChangePet(vector<pet_store>& Pets);
void OutputALLPet(vector<pet_store> Pets);
void  DeletePet(vector<pet_store>& Pets);

//------------------------MAIN----------------------------------------------------
int main() {
	setlocale(LC_ALL, "RU");
	srand(time(NULL));
	//-------------------------------���� �����-------------------------------------

	int a;         // ����� �� ����

	vector<pet_store> Pets;


	while (true)
	{
		Out_menu();

		cin >> a;

		if (a == 0)
		{
			cout << endl << "�� ����� �� ���������! ����������." << endl << endl;
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

//------------------------------ ������� ----------------------------------------------

void Out_menu()
{
	cout << endl << "����: " << endl;
	cout << "1 - �������� ��������" << endl;
	cout << "2 - �������� ���������� � ��������" << endl;
	cout << "3 - ������� ��� ���������� � ���� ��������" << endl;
	cout << "4 - ������� ��������" << endl;
	cout << "0 - ����� �� ���������" << endl << endl;
	cout << "�������� ��� �����: ";
}

void InputPet(vector<pet_store>& Pets)        //  ( 1 )  ���������� ������ ���������
{
	string t_type, t_sex, t_name;             // ��������� ���������� ��� �����
	int t_price;                              //

	cout << "������� ��� ���������: " << endl;
	cin >> t_type;
	cout << "������� ��� ���������: " << endl;
	cin >> t_sex;
	cout << "������� ��� ���������: " << endl;
	cin >> t_name;
	cout << "������� ���� ����������: " << endl;
	cin >> t_price;

	Pets.emplace_back(t_type, t_sex, t_name, t_price);
	
}

void ChangePet(vector<pet_store>& Pets)          // ( 2 ) ��������� ������ ���������
{
	string t2_type, t2_sex, t2_name;
	int t2_price;
	int numpet;            // ���������
	cout << endl << "�������� ����� ���������, ������ � ������� �� ������ ��������: ";
	cin >> numpet;

	cout << "������ ���: " << Pets[numpet - 1].getType() << "\t";
	cout << "�������� ��� ���������: " << endl;
	cin >> t2_type;
	Pets[numpet - 1].setType(t2_type);

	cout << "������ ���: " << Pets[numpet - 1].getSex() << "\t";
	cout << "�������� ��� ���������: " << endl;
	cin >> t2_sex;
	Pets[numpet - 1].setSex(t2_sex);

	cout << "������ ���: " << Pets[numpet - 1].getName() << "\t";
	cout << "������� ��� ���������: " << endl;
	cin >> t2_name;
	Pets[numpet - 1].setName(t2_name);

	cout << "������ ����: " << Pets[numpet - 1].getPrice() << "\t";
	cout << "������� ���� ����������: " << endl;
	cin >> t2_price;
	Pets[numpet - 1].setPrice(t2_price);
}

void OutputALLPet(vector<pet_store> Pets)       // ( 3 ) ����� ���� �������� �� �����
{
	cout << endl << "����� ���������\t��� ���������\t��� ���������\t��� ���������\t���� ���������" << endl;
	for (int i = 0; i < Pets.size(); i++)
	{
		cout << setw(10) << i + 1 << "\t" << setw(10) << Pets[i].getType() << "\t" << setw(10) << Pets[i].getSex() << "\t" << setw(10) << Pets[i].getName() << "\t" << setw(10) << Pets[i].getPrice();
		cout << endl;
	}
	cout << "����� �������� � �����������: " << pet_store::getQuantity();
	cout << endl;

}

void  DeletePet(vector<pet_store>& Pets)        // ( 4 ) �������� ���������
{
	int number;                    // ��������� ����������
	cout << endl << "�������� ����� ���������, �������� ������ �������: " << endl;
	cin >> number;

	Pets.erase(Pets.begin() + number - 1);
	pet_store::setQuantity(pet_store::getQuantity() - 1);
}
//---------------------- ������ ������ -----------------------------------------------

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