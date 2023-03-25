// C++ Program for the Bug Tracking System
#include <iostream>
#include <cstring>
#include <conio.h>
#include <time.h>
using namespace std;

// Function to file the bug in the Bug Tracking System
void filebug(int id)
{
    cout << "************";
    cout << "FILING A BUG";
    cout << "************" << endl;

    // Current Time
    time_t CurrentTime;
    time(&CurrentTime);

    char name[20], bugtype[50];
    char bugdescription[1000];
    char bugpriority[30];
    int bugstatus;

    FILE *ptr;

    // User name
    cout << "Enter your name:" << endl;
    cin >> name;
    char ids[10];
    itoa(id, ids, 10);
    strcat(name, ids);
    char ex[] = ".txt";
    strcat(name, ex);

    // Filename of the bug
    cout << "Filename: " << name << endl;
    ptr = fopen(name, "w");

    // Case when file cannot be created
    if (ptr == NULL)
    {
        cout << "Cannot create file!!!" << endl;
    }
    fprintf(ptr, "DATE AND TIME : %s", ctime(&CurrentTime));

    // ID in the Text File
    fprintf(ptr, "BUG ID : %d\n", id);

    // Adding New Line in Text File
    fprintf(ptr, "\n");

    // Bug ID
    cout << "BUG ID" << id << endl;

    fprintf(ptr, "BUG FILED BY: %s\n", name);
    fprintf(ptr, "\n");

    cout << "Enter bug type" << endl;
    scanf(" %[^\n]", bugtype);

    // Bug Type
    fprintf(ptr, "TYPE OF BUG: %s", bugtype);
    fprintf(ptr, "\n");

    // Bug Priority
    cout << "Enter the bug priority" << endl;
    scanf(" %[^\n]s", bugpriority);

    fprintf(ptr, "BUG PRIORITY: %s\n", bugpriority);
    fprintf(ptr, "\n");

    // Bug Description
    cout << "Enter the bug description:\n";
    scanf(" %[^\n]s", bugdescription);

    fprintf(ptr, "BUG DESCRIPTION: %s\n", bugdescription);
    fprintf(ptr, "\n");

    cout << "Status of bug: " << endl;
    cout << "1. NOT YET ASSIGNED" << endl;
    cout << "2. IN PROCESS" << endl
         << "3. FIXED" << endl;
    cout << "4. DELIVERED" << endl
         << "ENTER YOUR CHOICE: ";

    int j;
    cin >> j;

    // Date and time of the Bug Creation
    fprintf(ptr, "DATE AND TIME : %s", ctime(&CurrentTime));
    fprintf(ptr, "BUG STATUS: ");

    // Switching for the Status of the Bug
    switch (j)
    {
    case 1:
        fprintf(ptr, "NOT YET ASSIGNED\n");
        break;
    case 2:
        fprintf(ptr, "IN PROCESS\n");
        break;
    case 3:
        fprintf(ptr, "FIXED\n");
        break;
    case 4:
        fprintf(ptr, "DELIVERED\n");
        break;
    default:
        cout << "Invalid Choice" << endl;
        break;
    }
    fclose(ptr);
}

// Function to Change the Status of the Bug
void changeStatus()
{
    cout << "************";
    cout << "Change Status";
    cout << "************" << endl;

    time_t CurrentTime;
    time(&CurrentTime);

    FILE *file;
    char name[50];

    // Bug File Name
    cout << "Enter file name:" << endl;
    cin >> name;
    char ex[] = ".txt";
    strcat(name, ex);

    // Opening the Bug in Append Mode
    file = fopen(name, "a");

    cout << endl
         << "1. NOT YET ASSIGNED" << endl;
    cout << "2. IN PROCESS" << endl
         << "3. FIXED" << endl;
    cout << "4. DELIVERED" << endl
         << "ENTER YOUR CHOICE:";

    // Change the Status
    int k;
    cin >> k;

    fprintf(file, "\n");
    fprintf(file, "DATE AND TIME : %s", ctime(&CurrentTime));
    fprintf(file, "BUG STATUS: ");

    // Changing the status on the basis of user input
    switch (k)
    {
    case 1:
        fprintf(file, "NOT YET ASSIGNED\n");
        break;
    case 2:
        fprintf(file, "IN PROCESS\n");
        break;
    case 3:
        fprintf(file, "FIXED\n");
        break;
    case 4:
        fprintf(file, "DELIVERED\n");
        break;
    default:
        cout << "Invalid Choice" << endl;
        break;
    }
    fclose(file);
}

// Function to Report the Bug in the Bug Tracking System
void report()
{
    cout << "************";
    cout << "Report";
    cout << "************" << endl;

    FILE *fp;
    char name[50];

    // Asking the filename to report the bug of the file
    cout << "Enter file name: " << endl;
    cin >> name;
    char ex[] = ".txt";
    strcat(name, ex);

    // Opening the file into the Read mode
    fp = fopen(name, "r");

    char ch;
    ch = getc(fp);

    // Character of the file
    while (ch != EOF)
    {
        cout << ch;
        ch = getc(fp);
    }

    fclose(fp);
    getch();
}

int main()
{
    cout << "************";
    cout << "BUG TRACKING SYSTEM";
    cout << "************" << endl;

    int number, i = 1;

    // ID initialized to 0
    int id = 0;

    // while loop to run
    while (i != 0)
    {
        cout << endl
             << "1. FILE IN A NEW BUG" << endl;
        cout << "2. CHANGE THE STATUS OF THE BUG" << endl;
        cout << "3. GET BUG REPORT" << endl
             << "4. EXIT";
        cout << endl
             << endl
             << "ENTER YOUR CHOICE: ";

        cin >> number;

        // Using switch to go case by case
        switch (number)
        {
        case 1:
            id++;

            // Creating a New Bug
            filebug(id);
            break;
        case 2:

            // Change the Status of Bug
            changeStatus();
            break;
        case 3:

            // Report the Bug
            report();
            break;
        case 4:
            i = 0;
            break;
        default:
            cout << endl
                 << "Invalid Entry";
            break;
        }
    }
    return 0;
}