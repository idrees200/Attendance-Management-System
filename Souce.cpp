#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int MAX_STUDENTS = 20;
const int MAX_DAYS = 50;

char studententry[MAX_STUDENTS][MAX_DAYS];
string addinfo;
int numberofstudent;
float numberofdays;
float percentage;

struct student {
    int rollno;
    string emailid;
};

void show() {
    cout << "INSTRUCTOR        course" << endl;
    cout << "Teacher1          Programming" << endl;
}

void Adminlogin() {
    string username;
    string realuser = "admin1";
    string password;
    string realpass = "admin123";

    do {
        cout << "ENTER USERNAME: ";
        cin >> username;
        cout << "ENTER PASSWORD: ";
        cin >> password;

        if (username != realuser || password != realpass) {
            cout << "INVALID ENTRY. TRY AGAIN!" << endl;
        }
    } while (username != realuser || password != realpass);

    int option;
    cout << "CHOOSE ANY OPTION:" << endl;
    cout << "1. ADD NEW INFORMATION" << endl;
    cout << "2. CHOOSE PREVIOUS INFORMATION" << endl;
    cin >> option;

    if (option == 1) {
        numberofstudent = 0;
    } else if (option == 2) {
        ifstream lout("student.dat");
        lout >> addinfo;
        lout >> numberofstudent;
        lout.close();
    }

    show();

    if (numberofstudent == 0) {
        cout << "ENTER NUMBER OF STUDENTS YOU WANT TO ADD: ";
        cin >> numberofstudent;
    }

    cout << "TOTAL STUDENTS:" << endl;
    cout << "STUDENT          ROLLNO            EMAIL ID" << endl;
    for (int i = 0; i < numberofstudent; i++) {
        cout << "student " << i + 1 << "    03-134212_" << i + 1 << "     student" << i + 1 << "@gmail.com" << endl;
    }

    int choice;
    do {
        cout << "Press 1 to add more students or any other key to end: ";
        cin >> choice;
        if (choice == 1) {
            cout << "ENTER THE NEW NUMBER OF STUDENTS: ";
            cin >> numberofstudent;
        }
    } while (choice == 1);

    cout << "YOUR WORK IS DONE. LOGGING YOU OUT :)" << endl;
    addinfo = "TOTALSTUDENTS:";
    ofstream out("student.dat");
    out << addinfo << endl;
    out << numberofstudent;
    out.close();
}

void Teacherlogin() {
    string username;
    string realuser = "teacher1";
    string password;
    string realpass = "teacher123";

    do {
        cout << "ENTER USERNAME: ";
        cin >> username;
        cout << "ENTER PASSWORD: ";
        cin >> password;

        if (username != realuser || password != realpass) {
            cout << "INVALID ENTRY. TRY AGAIN!" << endl;
        }
    } while (username != realuser || password != realpass);

    ifstream king("student.dat");
    king >> addinfo;
    king >> numberofstudent;
    king.close();

    cout << "ENTER NUMBER OF DAYS FOR ATTENDANCE: ";
    cin >> numberofdays;

    cout << "A REPRESENTS ABSENT & P REPRESENTS PRESENT" << endl;
    float count = 0;

    for (int i = 0; i < numberofstudent; i++) {
        for (int j = 0; j < numberofdays; j++) {
            cout << "ENTER STUDENT " << i + 1 << " ATTENDANCE OF DAY " << j + 1 << ": ";
            cin >> studententry[i][j];
            if (studententry[i][j] == 'P') {
                count++;
            }
        }
        cout << endl;
    }

    percentage = (count / (numberofstudent * numberofdays)) * 100;

    show();

    cout << "STUDENT          ROLLNO            EMAIL ID         DAY     ATTENDANCE" << endl;
    for (int i = 0; i < numberofstudent; i++) {
        for (int j = 0; j < numberofdays; j++) {
            cout << "STUDENT " << i + 1 << "    03-134212_" << i + 1 << "     student" << i + 1 << "@gmail.com" << "   DAY " << j + 1 << "    " << studententry[i][j] << endl;
        }
    }

    cout << "OVERALL CLASS PERCENTAGE OF ATTENDANCE = " << percentage << "%" << endl;
    cout << "YOUR WORK IS DONE. LOGGING YOU OUT :)" << endl;

    addinfo = "NUMBEROFSTUDENTS,NUMBEROFDAYS,PERCENTAGE,ARRAY:";
    ofstream out("teacher.dat");
    out << addinfo << endl;
    out << numberofstudent << endl;
    out << numberofdays << endl;
    out << percentage << endl;
    for (int i = 0; i < numberofstudent; i++) {
        for (int j = 0; j < numberofdays; j++) {
            out << studententry[i][j];
        }
        out << endl;
    }
    out.close();
}

void Studentlogin() {
    string username;
    string realuser = "student1";
    string password;
    string realpass = "student123";

    do {
        cout << "ENTER USERNAME: ";
        cin >> username;
        cout << "ENTER PASSWORD: ";
        cin >> password;

        if (username != realuser || password != realpass) {
            cout << "INVALID ENTRY. TRY AGAIN!" << endl;
        }
    } while (username != realuser || password != realpass);

    ifstream king("teacher.dat");
    king >> addinfo;
    king >> numberofstudent;
    king >> numberofdays;
    king >> percentage;

    for (int i = 0; i < numberofstudent; i++) {
        for (int j = 0; j < numberofdays; j++) {
            king >> studententry[i][j];
        }
    }
    king.close();

    show();
    cout << "STUDENT INFORMATION:" << endl;
    for (int i = 0; i < numberofstudent; i++) {
        for (int j = 0; j < numberofdays; j++) {
            cout << "STUDENT " << i + 1 << "    03-134212_" << i + 1 << "     student" << i + 1 << "@gmail.com" << "   DAY " << j + 1 << "    " << studententry[i][j] << endl;
        }
    }

    cout << "OVERALL CLASS PERCENTAGE OF ATTENDANCE = " << percentage << "%" << endl;
    cout << "YOUR WORK IS DONE. LOGGING YOU OUT :)" << endl;
}

void logo() {
    cout << "//////////////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "//                                                                                                          //" << endl;
    cout << "//                                                                                                          //" << endl;
    cout << "//   ********     **     **     ******       ******       **     **   ** ******  ******     **              //" << endl;
    cout << "//  **            **** ****    **     *      **   **     ****    **   ** **    *   ||      ****             //" << endl;
    cout << "// **             ** *** **     *****        ******     **  **   ******* ******    ||     **  **            //" << endl;
    cout << "//  **            **  *  **    *     **      **    **  ********  **   ** ****      ||    ********           //" << endl;
    cout << "//   ********     **     **      ****        ******   **      ** **   ** **  **  ****** **      **          //" << endl;
    cout << "//                                                                                                          //" << endl;
    cout << "//                                                                                                          //" << endl;
    cout << "//////////////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
}

int main() {
    logo();
    int choice;
    do {
        cout << "WHO ARE YOU?" << endl;
        cout << "1. A Teacher?" << endl;
        cout << "2. A Student?" << endl;
        cout << "3. Admin?" << endl;
        cout << "ENTER YOUR CHOICE: ";
        cin >> choice;

        if (choice < 1 || choice > 3) {
            cout << "CHOOSE AGAIN." << endl;
        }
    } while (choice < 1 || choice > 3);

    switch (choice) {
        case 1:
            Teacherlogin();
            break;
        case 2:
            Studentlogin();
            break;
        case 3:
            Adminlogin();
            break;
       
  }

    return 0;
}
