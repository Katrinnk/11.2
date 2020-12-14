#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h> 
#include <fstream>

using namespace std;
enum Specialnist { KOMPUTERNI_NAUKY, INFORMATYKA, MATEMATYKA_TA_EKONOMIKA, PHISYKA_TA_INFORMATYKA, TRUDOVE_NAVCHANNYA };
string specialnistStr[] = { "КН", "інф", "мат&екон", "фіз&інф", "труд.навч" };
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
		cout << "Введіть N: "; cin >> N;
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
			cout << "Студент № " << i + 1 << ":" << endl;
			cin.get();
			cin.sync();
			cout << " прізвище: "; getline(cin, p[i].prizv);
			cout << " курс: "; cin >> p[i].kurs;
			cout << " спеціальність (0 - комп'ютерні науки, 1 - інформатика, 2 - математика та економіка, 3 - фізика та інформатика, 4 - трудове навчання):";
			cin >> specialnist;
			cout << " оцінка з фізики: "; cin >> p[i].phisyka;
			cout << "оцінка з математики: "; cin >> p[i].matematyka;
			cout << "оцінка з інформатики: "; cin >> p[i].informatyka;
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
		cout << "| № | Прізвище | Курс | Спеціальність | Фізика | Математика | Інформатика |"
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
		cout << "кількість оцінок 5 з фізики: " << k << endl;
		cout << "кількість оцінок 4 з фізики: " << m << endl;
		cout << "кількість оцінок 3 з фізики: " << t << endl;

	}
	void Kilkist_studentiv(Student* p, const int N, char* fname, ofstream& f)
	{
		int a = 0;
		for (int i = 0; i < N; i++)
		{
			if ((p[i].phisyka == 4 || p[i].phisyka == 5) && (p[i].matematyka == 4 || p[i].matematyka == 5))
				a++;
		}
		cout << "кількість студеньів, які і з фізики, і з математики мають оцінку 4 або 5: " << a << endl;
	}