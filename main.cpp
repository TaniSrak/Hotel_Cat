#include <iostream>

class Cat
{
public:
	
	Cat() : _fullName("�"), _breed("�"), _owner("�") {}
	Cat(const std::string n, const std::string& b, const std::string& o) : _fullName(n), _breed(b), _owner(o) {}
	Cat(const Cat& other) : _fullName(other._fullName), _breed(other._breed), _owner(other._owner) {}

	std::string getFullName() const
	{
		return _fullName + _breed + _owner;
	}
private:
	std::string _fullName;
	std::string _breed;
	std::string _owner;
};

class Hotel
{
public:
	Hotel() : _countCat(0), _capacity(0), _tenants(nullptr) {}

	Hotel(int capacity) : _capacity(capacity), _countCat(0)
	{
		_tenants = new Cat[capacity];
		std::cout << "���� � �����: " << capacity << std::endl;
	}

	Hotel(const Hotel& other) : _capacity(other._capacity), _countCat(other._countCat)
	{
		_tenants = new Cat[_capacity];
		for (int i = 0; i < _countCat; i++)
		{
			_tenants[i] = other._tenants[i];
		}
	}

	~Hotel()
	{
		//std::cout << "����������, ����� ����� ���� " << this << std::endl;
		delete[] _tenants;
	}

	void addTenants(const Cat& cat) {
		if (_countCat < _capacity) {
			_tenants[_countCat++] = cat;
			std::cout << cat.getFullName() << " ��������� � �����." << std::endl;
		}
		else {
			std::cout << "����� ��������, " << cat.getFullName() << " �� ����� ����������." << std::endl;
		}
	}

	void Eviction(const Cat& cat) {
		for (int i = 0; i < _countCat; ++i) {
			if (_tenants[i].getFullName() == cat.getFullName()) {
				std::cout << cat.getFullName() << " ��������� �� �����." << std::endl;
				for (int j = i; j < _countCat - 1; ++j) {
					_tenants[j] = _tenants[j + 1];
				}
				--_countCat;
				return;
			}
		}
		std::cout << "��� " << cat.getFullName() << " �� ������ � �����." << std::endl;
	}

private:
	Cat* _tenants; //������
	int _capacity; //����������� �����
	int _countCat; //������� ���������� �����
};

int main() {
	setlocale(LC_ALL, "Russian");
	int n;

	Hotel catHotel(3); // ������� ����� �� 3 ����

	Cat cat1("������ ", "���������� ", "������: ");
	Cat cat2("������ ", "���������� ", "�����: ");
	Cat cat3("������ ", "�������� ", "�������: ");
	Cat cat4("��� ", "����-��� ", "�������: ");

	catHotel.addTenants(cat1);
	catHotel.addTenants(cat2);
	catHotel.addTenants(cat3);
	catHotel.addTenants(cat4); // ���� ��� �� ���������� � �����

	catHotel.Eviction(cat2);

	return 0;
}