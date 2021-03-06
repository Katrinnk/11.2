#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h> 
#include <fstream>

using namespace std;
enum Specialnist { KOMPUTERNI_NAUKY, INFORMATYKA, MATEMATYKA_TA_EKONOMIKA, PHISYKA_TA_INFORMATYKA, TRUDOVE_NAVCHANNYA };
string specialnistStr[] = { "��", "���", "���&����", "���&���", "����.����" };
struct Student
{
	string prizv;
	unsigned kurs;
	Specialnist specialnist;
	unsigned phisyka;
	unsigned matematyka;
	unsigned informatyka;
};
	void Create(Student * p, const int N, char* fname, ofstream& f);
	void Print(Student * p, const int N, char* fname, ofstream& f);
	void Kilkist_otsinok(Student * p, const int N, char* fname, ofstream& f);
	void Kilkist_studentiv(Student * p, const int N);
	int main()
	{
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		int N;
		cout << "������ N: "; cin >> N;
		Student* p = new Student[N];
		char fname[101];
		cout << "enter file name: "; cin >> fname;
		ofstream f(fname, ios::binary);
		cout << endl;
		Create(p, N, fname, f);
		Print(p, N, fname, f);
		cout << endl;
		Kilkist_otsinok(p, N, fname, f);
		cout << endl;
		Kilkist_studentiv(p, N);
		f.close();
		return 0;
	}
	void Create(Student* p, const int N, char* fname, ofstream& f)
	{
		int specialnist;

		for (int i = 0; i < N; i++)
		{
			cout << "������� � " << i + 1 << ":" << endl;
			cin.get();
			cin.sync();
			cout << " �������: "; getline(cin, p[i].prizv);
			cout << " ����: "; cin >> p[i].kurs;
			cout << " ������������� (0 - ����'������ �����, 1 - �����������, 2 - ���������� �� ��������, 3 - ������ �� �����������, 4 - ������� ��������):";
			cin >> specialnist;
			cout << " ������ � ������: "; cin >> p[i].phisyka;
			cout << "������ � ����������: "; cin >> p[i].matematyka;
			cout << "������ � �����������: "; cin >> p[i].informatyka;
			p[i].specialnist = Specialnist(specialnist);
			if (!f.write((char*)&p, sizeof(Student)))
			{
				cerr << "Error writing file." << endl;
			}

		}
	}
	void Print(Student* p, const int N, char* fname, ofstream& f)
	{
		cout << "=========================================================================="
			<< endl;
		cout << "| � | ������� | ���� | ������������� | Գ���� | ���������� | ����������� |"
			<< endl;
		cout << "--------------------------------------------------------------------------"
			<< endl;
		for (int i = 0; i < N; i++)
		{
			f.read((char*)&p, sizeof(Student));
			cout << "| " << setw(1) << right << i + 1 << " ";
			cout << "| " << setw(10) << left << p[i].prizv
				<< "| " << setw(2) << right << p[i].kurs << " "
				<< "| " << setw(15) << left << specialnistStr[p[i].specialnist]
				<< "| " << setw(6) << right << p[i].phisyka << " "
				<< "| " << setw(10) << left << p[i].matematyka << " "
				<< "| " << setw(10) << right << p[i].informatyka << " " << "|";
			cout << endl;
		}
		cout << "=========================================================================="
			<< endl;
		cout << endl;
	}
	void Kilkist_otsinok(Student* p, const int N, char* fname, ofstream& f)
	{
		int k = 0;
		int m = 0;
		int t = 0;
		for (int i = 0; i < N; i++)
		{
			if (p[i].phisyka == 5)
				k++;
			if (p[i].phisyka == 4)
				m++;
			if (p[i].phisyka == 3)
				t++;
		}
		cout << "������� ������ 5 � ������: " << k << endl;
		cout << "������� ������ 4 � ������: " << m << endl;
		cout << "������� ������ 3 � ������: " << t << endl;

	}
	void Kilkist_studentiv(Student* p, const int N, char* fname, ofstream& f)
	{
		int a = 0;
		for (int i = 0; i < N; i++)
		{
			if ((p[i].phisyka == 4 || p[i].phisyka == 5) && (p[i].matematyka == 4 || p[i].matematyka == 5))
				a++;
		}
		cout << "������� ���������, �� � � ������, � � ���������� ����� ������ 4 ��� 5: " << a << endl;
	}