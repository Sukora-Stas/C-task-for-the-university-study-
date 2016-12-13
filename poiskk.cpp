#include "poiskk.h"
#include "kursach.cpp"
#include <string>

//;_CRT_SECURE_NO_WARNINGS
void poiskk()
{
	string value;
	cout << "|______________________________________________________________________________|\n" << endl;
	printf("%-1c%-1c%-4s%-74s%-1c", '\n', '|', "", "����� �� ����� ��������� �� ������ ������������?", '|');
	printf("%-1c%-1c%-4s%-74s%-1c", '\n', '|', "", "", '|');
	printf("%-1c%-1c%-4s%-74s%-1c", '\n', '|', "1.", "�� id", '|');
	printf("%-1c%-1c%-4s%-74s%-1c", '\n', '|', "2.", "�� �������", '|');
	printf("%-1c%-1c%-4s%-74s%-1c", '\n', '|', "3.", "�� ����", '|');
	printf("%-1c%-1c%-4s%-74s%-1c", '\n', '|', "4.", "�� ������", '|');
	printf("%-1c%-1c%-4s%-74s%-1c%-1c", '\n', '|', "", "", '|', '\n');
	int i;
	cin >> i;

	if (i == 1)  //�� ID
	{
		int number = 0;
		printf("%-1c%-1c%-4s%-74s%-1c", '\n', '|', "", "����� �� id", '|');
		printf("%-1c%-1c%-4s%-74s%-1c%-1c", '\n', '|', "", "������� �����", '|', '\n');
		cin >> number;
		int sum = 0;
		proverka();
		nst = 0;
		TStudent std;
		cout << "\n|-----------------------------------------------------------------|\n" << endl;
		printf("%-3c%-7s%-18s%-10s%-10s%-6s%-12s%-1c%-1c", '|', "�����", "�������", "���", "�����", "���.", "������", '|', '\n');
		printf("%-3c%-7s%-18s%-10s%-10s%-6s%-12s%-1c%-1c", '|', "", "����������", "", "", "����", "�� ����", '|', '\n');
		cout << "|-----------------------------------------------------------------|\n" << endl;
		while (true)
		{
			int nwrt = fread(&std, sizeof(TStudent), 1, fl);
			if (nwrt != 1) break;
			stud[nst] = std;
			int month = atoi(stud[nst].month);
			int id = stud[nst].id;

			string month2 = _switch(month);
			if (number == id){
				sum += (atoi(stud[nst].stoimost))*(atoi(stud[nst].day));
				printf("%-3c%-5i%-20s%-10s%-10s%-6s%-3s%-9s%-1c%-1c", '|',
					stud[nst].id,
					stud[nst].FIO,
					stud[nst].year,
					month2.c_str(),
					stud[nst].day,
					stud[nst].stoimost,
					"���.",
					'|',
					'\n');
				printf("%-3c%-25s%-10s%-10s%-6s%-12s%-1c%-1c", '|', "", "", "", "", "", '|', '\n');

				nst++;
			}
		}
		cout << "|-----------------------------------------------------------------|\n" << endl;
		printf("%-3c%-25s%-10s%-10s%-6s%-4i%-8s%-1c%-1c", '|', "", "", "", "�����:", sum, "���.", '|', '\n');
		cout << "|-----------------------------------------------------------------|\n" << endl;
		fclose(fl);
	}
	if (i == 2)    //�� �������
	{
		string name;
		printf("%-1c%-1c%-4s%-74s%-1c", '\n', '|', "", "����� �� �������", '|');
		printf("%-1c%-1c%-4s%-74s%-1c%-1c", '\n', '|', "", "������� �������", '|', '\n');
		//getline(cin,name);
		cin >> name;
		int sum = 0;
		proverka();
		nst = 0;
		TStudent std;
		cout << "\n|-----------------------------------------------------------------|\n" << endl;
		printf("%-3c%-7s%-18s%-10s%-10s%-6s%-12s%-1c%-1c", '|', "�����", "�������", "���", "�����", "���.", "������", '|', '\n');
		printf("%-3c%-7s%-18s%-10s%-10s%-6s%-12s%-1c%-1c", '|', "", "����������", "", "", "����", "�� ����", '|', '\n');
		cout << "|-----------------------------------------------------------------|\n" << endl;
		while (true)
		{
			int nwrt = fread(&std, sizeof(TStudent), 1, fl);
			if (nwrt != 1) break;
			stud[nst] = std;
			int month = atoi(stud[nst].month);
			string fio = stud[nst].FIO;
			string month2 = _switch(month);
			if (name == fio){
				sum += (atoi(stud[nst].stoimost))*(atoi(stud[nst].day));
				printf("%-3c%-5i%-20s%-10s%-10s%-6s%-3s%-9s%-1c%-1c", '|',
					stud[nst].id,
					stud[nst].FIO,
					stud[nst].year,
					month2.c_str(),
					stud[nst].day,
					stud[nst].stoimost,
					"���.",
					'|',
					'\n');
				printf("%-3c%-25s%-10s%-10s%-6s%-12s%-1c%-1c", '|', "", "", "", "", "", '|', '\n');

				nst++;
			}
		}
		cout << "|-----------------------------------------------------------------|\n" << endl;
		printf("%-3c%-25s%-10s%-10s%-6s%-4i%-8s%-1c%-1c", '|', "", "", "", "�����:", sum, "���.", '|', '\n');
		cout << "|-----------------------------------------------------------------|\n" << endl;
		fclose(fl);
	}
	if (i == 3)  //�� ����
	{
		int year = 0;
		printf("%-1c%-1c%-4s%-74s%-1c", '\n', '|', "", "����� �� ����", '|');
		printf("%-1c%-1c%-4s%-74s%-1c%-1c", '\n', '|', "", "������� ���", '|', '\n');
		cin >> year;
		int sum = 0;
		proverka();
		nst = 0;
		TStudent std;
		cout << "\n|-----------------------------------------------------------------|\n" << endl;
		printf("%-3c%-7s%-18s%-10s%-10s%-6s%-12s%-1c%-1c", '|', "�����", "�������", "���", "�����", "���.", "������", '|', '\n');
		printf("%-3c%-7s%-18s%-10s%-10s%-6s%-12s%-1c%-1c", '|', "", "����������", "", "", "����", "�� ����", '|', '\n');
		cout << "|-----------------------------------------------------------------|\n" << endl;
		while (true)
		{
			int nwrt = fread(&std, sizeof(TStudent), 1, fl);
			if (nwrt != 1) break;
			stud[nst] = std;
			int month = atoi(stud[nst].month);
			int yea = atoi(stud[nst].year);

			string month2 = _switch(month);
			if (year == yea){
				sum += (atoi(stud[nst].stoimost))*(atoi(stud[nst].day));
				printf("%-3c%-5i%-20s%-10s%-10s%-6s%-3s%-9s%-1c%-1c", '|',
					stud[nst].id,
					stud[nst].FIO,
					stud[nst].year,
					month2.c_str(),
					stud[nst].day,
					stud[nst].stoimost,
					"���.",
					'|',
					'\n');
				printf("%-3c%-25s%-10s%-10s%-6s%-12s%-1c%-1c", '|', "", "", "", "", "", '|', '\n');

				nst++;
			}
		}
		cout << "|-----------------------------------------------------------------|\n" << endl;
		printf("%-3c%-25s%-10s%-10s%-6s%-4i%-8s%-1c%-1c", '|', "", "", "", "�����:", sum, "���.", '|', '\n');
		cout << "|-----------------------------------------------------------------|\n" << endl;
		fclose(fl);
	}
	if (i == 4)  //�� ������
	{
		int monthe = 0;
		printf("%-1c%-1c%-4s%-74s%-1c", '\n', '|', "", "����� �� ������", '|');
		printf("%-1c%-1c%-4s%-74s%-1c%-1c", '\n', '|', "", "������� �����", '|', '\n');
		cin >> monthe;
		int sum = 0;
		proverka();
		nst = 0;
		TStudent std;
		cout << "\n|-----------------------------------------------------------------|\n" << endl;
		printf("%-3c%-7s%-18s%-10s%-10s%-6s%-12s%-1c%-1c", '|', "�����", "�������", "���", "�����", "���.", "������", '|', '\n');
		printf("%-3c%-7s%-18s%-10s%-10s%-6s%-12s%-1c%-1c", '|', "", "����������", "", "", "����", "�� ����", '|', '\n');
		cout << "|-----------------------------------------------------------------|\n" << endl;
		while (true)
		{
			int nwrt = fread(&std, sizeof(TStudent), 1, fl);
			if (nwrt != 1) break;
			stud[nst] = std;
			int month = atoi(stud[nst].month);
			string month2 = _switch(month);
			if (monthe == month){
				sum += (atoi(stud[nst].stoimost))*(atoi(stud[nst].day));
				printf("%-3c%-5i%-20s%-10s%-10s%-6s%-3s%-9s%-1c%-1c", '|',
					stud[nst].id,
					stud[nst].FIO,
					stud[nst].year,
					month2.c_str(),
					stud[nst].day,
					stud[nst].stoimost,
					"���.",
					'|',
					'\n');
				printf("%-3c%-25s%-10s%-10s%-6s%-12s%-1c%-1c", '|', "", "", "", "", "", '|', '\n');
				nst++;
			}
		}
		cout << "|-----------------------------------------------------------------|\n" << endl;
		printf("%-3c%-25s%-10s%-10s%-6s%-4i%-8s%-1c%-1c", '|', "", "", "", "�����:", sum, "���.", '|', '\n');
		cout << "|-----------------------------------------------------------------|\n" << endl;
		fclose(fl);
	}
}
