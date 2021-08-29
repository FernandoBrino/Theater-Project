#include <iostream>
#include <conio.h>
#include <windows.h>
#include "theater.h"
#include "counter.h"

using namespace std;
int main()
{
    int userOption;
    int amountLines, amountColumns;
    int rowChair, columnChair;
    int currentLine, currentColumn;
    int newLine, newColumn;
    int position, canReserve;
    int soldTickets = 0;

    system("cls");
    cout << "------* Welcome to Broadway Theater *------" << endl;
    cout << "\n\n~ Let's start the show by defining the size of the theater" << endl;
    cout << "\nEnter the number of the rows: ";
    cin >> amountLines;
    cout << "Enter the number of chairs per row: ";
    cin >> amountColumns;

    int chairsAvaliable = amountLines * amountColumns;

    Theater t(amountLines, amountColumns);
    Counter c(amountLines, amountColumns);

    do
    {
        system("cls");
        cout << "* ------------------- *" << endl;
        cout << "| 1. Reserve Chair    |" << endl;
        cout << "| 2. Return Chair     |" << endl;
        cout << "| 3. Change Chair     |" << endl;
        cout << "| 4. Show Theater     |" << endl;
        cout << "| 5. Leave Box Office |" << endl;
        cout << "* ------------------- *" << endl;
        cout << "\nSelect one option above: ";
        cin >> userOption;

        switch (userOption)
        {
        case 1:
            system("cls");
            cout << "We stil have " << chairsAvaliable << " chair avaliable !!" << endl;
            cout << "\n\nEnter chair row: ";
            cin >> rowChair;
            cout << "Enter chair column: ";
            cin >> columnChair;

            position = (rowChair - 1) * amountColumns + (columnChair - 1);
            canReserve = t.isAvaliable(position);

            if (canReserve == true)
            {
                cout << "\nThis chair isn't avaliable!!" << endl;
                cout << "\n\nType enter to return to menu: " << endl;
                getch();
                break;
            }

            t.reserveChair(rowChair - 1, columnChair - 1);
            chairsAvaliable = c.reserveChair();
            soldTickets = c.soldTickets();
            break;

        case 2:
            system("cls");
            cout << "Enter chair row: ";
            cin >> rowChair;
            cout << "Enter chair column: ";

            cin >> columnChair;
            t.returnChair(rowChair - 1, columnChair - 1);
            chairsAvaliable = c.returnChair();
            soldTickets = c.returnTickets();
            break;

        case 3:
            system("cls");
            cout << "Enter current chair row: ";
            cin >> currentLine;
            cout << "Enter current chair column: ";
            cin >> currentColumn;
            cout << "Enter new chair row: ";
            cin >> newLine;
            cout << "Enter new chair column: ";
            cin >> newColumn;
            t.changeChair(currentLine - 1, currentColumn - 1, newLine - 1, newColumn - 1);
            break;

        case 4:
            system("cls");
            for (int i = 0; i < t.line; i++)
            {
                for (int j = 0; j < t.column; j++)
                {
                    cout << t.v[i * t.column + j] << " ";
                }
                cout << endl;
            }

            cout << "\nWe still have " << chairsAvaliable << " chairs avaliable" << endl;
            cout << "** We sold " << soldTickets << " tickets **" << endl;

            cout << "\n! Type enter to return to menu !";
            getch();
            break;

        case 5:
            system("cls");
            cout << "See you later, Good Show !!";
            Sleep(2000);
            exit(0);
            break;
        }
    } while (userOption >= 1 && userOption <= 5);

    return 0;
}