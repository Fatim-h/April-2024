#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    int option;
    string task;
    int sno = 0;

    ofstream outfile;
    outfile.open("todolist.txt", ios::app);

    if (!outfile.is_open()) {
        cout << "Can't open the to-do list file!";
        return 1;
    } else {
        cout << "List exists. You may proceed now.\n";
    }

    do {
        cout << "\n\n1. Display to-do list\n2. Enter new task\n3. Mark task as completed\n4. Remove a task\n5. Exit\n";
        cin >> option;

        switch (option) {
            case 1: {
                ifstream infile("todolist.txt");
                if (!infile.is_open()) {
                    cout << "Can't open the to-do list file!";
                    return 1;
                }

                int k = 1;
                while (getline(infile, task)) {
                    cout << k << ". " << task << endl;
                    k++;
                }
                infile.close();
                break;
            }

            case 2: {
                cout << "\nEnter new task: ";
                cin.ignore();
                getline(cin, task);
                outfile << task << endl;
                break;
            }

            case 3: {
                ifstream infile("todolist.txt");
                if (!infile.is_open()) {
                    cout << "Can't open the to-do list file!";
                    return 1;
                }

                int k = 1;
                while (getline(infile, task)) {
                    cout << k << ". " << task << endl;
                    k++;
                }
                cout << "\nEnter the serial number of the task completed: ";
                cin >> sno;

                infile.close(); 

                ofstream tempfile("temp.txt");
                ifstream infile2("todolist.txt");

                if (!infile2.is_open() || !tempfile.is_open()) {
                    cout << "Error: Unable to open file(s)!" << endl;
                    return 1;
                }

                k = 1;
                while (getline(infile2, task)) {
                    if (k == sno) {
                        task += " : completed";
                    }
                    tempfile << task << endl;
                    k++;
                }

                cout << "Task marked as completed successfully!" << endl;

                infile2.close();
                tempfile.close();

                remove("todolist.txt");

                rename("temp.txt", "todolist.txt");
                break;
            }

            case 4: {
                cout << "\nEnter the serial no of task to delete: ";
                cin >> sno;

                ifstream infile("todolist.txt");
                ofstream tempfile("temp.txt");

                if (!infile.is_open() || !tempfile.is_open()) {
                    cout << "Error: Unable to open file(s)!" << endl;
                    return 1;
                }

                int k = 1;
                while (getline(infile, task)) {
                    if (k != sno) {
                        tempfile << task << endl;
                    }
                    k++;
                }

                cout << "Task deleted successfully!" << endl;

                infile.close();
                tempfile.close();

                remove("todolist.txt");
                rename("temp.txt", "todolist.txt");

                break;
            }

            case 5:
                cout << "\nExiting the program.\n";
                break;

            default:
                cout << "\nInvalid option. Please choose again.\n";
                break;
        }
    } while (option != 5);

    outfile.close();

    return 0;
}