#include <iostream>
#include "base.cpp"
#include "functions.cpp"
#include "order.cpp"

using namespace std;

int main()
{
	Medicine *stock[100];
	string op1;
	load(stock);
	do
	{
		system("cls");
		cout << "\t\t\t            Pharmacy Management System \n";
		cout << "\t\t===============================================================\n\n";
		cout << "\t\t---------------------------------------------------------------\n";
		cout << "\t\t||\t1. Managing Medicine and Product for Pharmacy        ||\n";
		cout << "\t\t||\t2. Available Medicine List                           ||\n";
		cout << "\t\t||\t3. Modify Order List and Make Payment                ||\n";
		cout << "\t\t||\t0. Exit                                              ||\n";
		cout << "\t\t---------------------------------------------------------------\n";
		cout << "Select Option: ";
		cin >> op1;

		if (op1 == "1")
		{
			string op2;
			system("cls");
			cout << "Managing Medicine and Product for Pharmacy" << endl;
			cout << "\t1. Add Product" << endl;
			cout << "\t2. Search/Edit Product" << endl;
			cout << "\t0. Back To Main Menu" << endl;
			cout << "Select Option: ";
			cin >> op2;

			if (op2 == "1")
			{
				system("cls");
				string op3;
				cout << "Managing Medicine and Product for Pharmacy -> Add Product" << endl;
				cout << "\t1. Tablet" << endl;
				cout << "\t2. Liquid" << endl;
				cout << "\t0. Back To Main Menu" << endl;
				cout << "Select Option: ";
				cin >> op3;

				if (op3 == "1")
				{
					entry(stock, op3);
				}

				else if (op3 == "2")
				{
					entry(stock, op3);
				}

				else if (op3 == "0")
				{
				}

				else
				{
					cout << "\nWrong Input, Back to Main Menu...";
					Sleep(600);
				}
			}

			else if (op2 == "2")
			{
				string op3;
				system("cls");
				cout << "Managing Medicine and Product for Pharmacy -> Search/Edit Product" << endl;
				cout << "\t1. Search by ID: " << endl;
				cout << "\t2. Search by Medicine Name: " << endl;
				cout << "\t0. Back To Main Menu" << endl;
				cout << "Select Option: ";
				cin >> op3;

				if (op3 == "1" || op3 == "2")
				{
					int found = -1;
					if (op3 == "1")
					{
						string temp;
						do
						{
							system("cls");
							cout << "Managing Medicine and Product for Pharmacy -> Search/Edit Product -> Search by ID" << endl;
							cout << "\n\tEnter ID You Wanna Search: ";
							cin >> temp;
						} while (!checkInt(temp));
						int id = castToInt(temp);
						found = searchByID(id, stock);
					}

					else if (op3 == "2")
					{
						system("cls");
						string name;
						cout << "Managing Medicine and Product for Pharmacy -> Search/Edit Product -> Search by Medicine Name" << endl;
						cout << "\n\tEnter Medicine Name You Wanna Search: ";
						cin.ignore();
						getline(cin, name);

						found = searchByName(name, stock);
					}

					if (found != -1)
					{
						showList(stock, found);
						edit(stock, found);
					}
				}

				else if (op3 == "0")
				{
				}

				else
				{
					cout << "\nWrong Input, Back to Main Menu...";
					Sleep(600);
				}
			}

			else if (op2 == "0")
			{
			}

			else
			{
				cout << "\nWrong Input, Back to Main Menu...";
				Sleep(600);
			}
		}

		else if (op1 == "2")
		{
			system("cls");
			if (Medicine::sortFlag != 0)
			{
				sortByName(stock);
			}
			showList(stock);
		}

		else if (op1 == "3")
		{
			string op2;
			Medicine *order[100];
			Order odr;
			do
			{
				system("cls");
				cout << "Modify Order List and Make Payment" << endl;
				cout << "\t1. Add Order" << endl;
				cout << "\t2. Delete Order" << endl;
				cout << "\t3. Order List" << endl;
				cout << "\t4. Receipt" << endl;
				cout << "\t0. Back to Main Menu" << endl;
				odr.order_small(order);
				gotoxy(0, 5);
				cout << "\nSelection Option: ";
				cin >> op2;

				if (op2 == "1")
				{
					odr.take_order(stock, order);
				}

				else if (op2 == "2")
				{
					system("cls");
					odr.order_small(order);
					gotoxy(0, 0);
					odr.delete_order(order);
				}

				else if (op2 == "3")
				{
					odr.order_list(order);
					system("pause");
				}

				else if (op2 == "4")
				{
					odr.print_recipt(stock, order);
				}

				else if (op2 == "0")
				{
				}

				else
				{
					cout << "\nWrong Input, Back to Order Menu...";
					Sleep(600);
				}
			} while (op2 != "0");
		}

		else if (op1 == "0")
		{
			char ch;
			cout << "\n\nSave Record (Y/N): ";
			cin.ignore();
			cin >> ch;
			if (ch == 'Y' || ch == 'y')
			{
				if (Medicine::sortFlag != 0)
				{
					sortByName(stock);
				}
				save(stock);
			}
		}

		else
		{
			cout << "Wrong Input, Please Try Again";
			Sleep(600);
		}
	} while (op1 != "0");
}
