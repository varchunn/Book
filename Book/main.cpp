#include <iostream>
#include <filesystem>
#include <cstring>
#include <cstdio>
#pragma warning(disable : 4996)
using namespace std;

class Subscriber {
private:
    char* fullName;
    char homePhone[20];
    char workPhone[20];
    char mobilePhone[20];
    char additionalInfo[100];

public:
    Subscriber(const char* name = "", const char* home = "", const char* work = "", const char* mobile = "", const char* info = "") 
    {
        fullName = new char[strlen(name) + 1];
        strcpy(fullName, name);
        strcpy(homePhone, home);
        strcpy(workPhone, work);
        strcpy(mobilePhone, mobile);
        strcpy(additionalInfo, info);
    }
    ~Subscriber() {
        delete[] fullName;
    }
    void setSubscriber(const char* name, const char* home, const char* work, const char* mobile, const char* info) 
    {
        delete[] fullName;
        fullName = new char[strlen(name) + 1];
        strcpy(fullName, name);
        strcpy(homePhone, home);
        strcpy(workPhone, work);
        strcpy(mobilePhone, mobile);
        strcpy(additionalInfo, info);
    }

    void printSubscriber() const {
        cout << "Surname - " << fullName << endl;
        cout << "Home Phone " << homePhone << endl;
        cout << "Work Phone " << workPhone << endl;
        cout << "МMobile phone " << mobilePhone << endl;
        cout << "Info " << additionalInfo << endl;
    }

    const char* getFullName() const {
        return fullName;
    }
};

class PhoneBook {
private:
    Subscriber* subscribers[100];
    int count;

public:
    PhoneBook() : count(0) {}

    ~PhoneBook() {
        for (int i = 0; i < count; i++) {
            delete subscribers[i];
        }
    }

    void addSubscriber() {
        if (count >= 100) {
            cout << "Phone book is full" << endl;
            return;
        }

        char name[100], home[20], work[20], mobile[20], info[100];
        
        cout << "Write Surname please ";
        cin.getline(name, 100);
        cout << "Write home number ";
        cin.getline(home, 20);
        cout << "Write work number ";
        cin.getline(work, 20);
        cout << "Write phone number ";
        cin.getline(mobile, 20);
        cout << "Write info ";
        cin.getline(info, 100);

        subscribers[count] = new Subscriber(name, home, work, mobile, info);
        count++;
    }

    void deleteSubscriber(const char* name) {
        for (int i = 0; i < count; i++) {
            if (strcmp(subscribers[i]->getFullName(), name) == 0) {
                delete subscribers[i];
                for (int j = i; j < count - 1; j++) {
                    subscribers[j] = subscribers[j + 1];
                }
                count--;
                cout << "Delete" << endl;
                return;
            }
        }
        cout << "Not found" << endl;
    }

    void searchSubscriber(const char* name) const {
        for (int i = 0; i < count; i++) {
            if (strcmp(subscribers[i]->getFullName(), name) == 0) {
                subscribers[i]->printSubscriber();
                return;
            }
        }
        cout << "Not found" << endl;
    }

    void showAllSubscribers() const 
    {
        if (count == 0) {
            cout << "Phone book is empty" << endl;
        }
        else
        {
            for (int i = 0; i < count; i++) 
            {
                subscribers[i]->printSubscriber();
                cout << "-----------------" << endl;
            }
        }
    }
};

int main() {
    PhoneBook phoneBook;
    int choice;
    char name[100];

    do {
        cout << "Please6 make a choice what you wanna do - "<<endl;
        cout << "1 - Add worker" <<endl;
        cout << "2 - Delete worker"<<endl;
        cout << "3 - search by surname"<<endl;
        cout << "4 - show all workers"<<endl;
        cout << "5 - Exit" <<endl;
        cout << "Your choice - ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                phoneBook.addSubscriber();
                break;
            case 2:
                cout << "Please^ write surname for delete"<<endl;
                cin.getline(name, 100);
                phoneBook.deleteSubscriber(name);
                break;
            case 3:
                cout << "Please^ write surname for search "<<endl;
                cin.getline(name, 100);
                phoneBook.searchSubscriber(name);
                break;
            case 4:
                phoneBook.showAllSubscribers();
                break;
            case 5:
                cout << "Okay! Bye Bye!" << endl;
                break;
            default:
                cout << "Invalid command. Try again" << endl;
        }
    } while (choice != 0);

    return 0;
}
