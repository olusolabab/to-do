#include <iostream>
#include <string>
#include <list>
#include <cmath>
#include <ctime>

using namespace std;

class TodoItem {
private:
    int id;
    string description;
    bool completed;

public:
    TodoItem() : id(0), description(""), completed(false) {}
    ~TodoItem() = default;

    bool create(string newDescription) {
        // generates a random integer between 1 and 100
        id = rand() % 100 + 1;
        description = newDescription;
        return true;
    }

    int getId() { return id; }
    string getDescription() { return description; }
    bool isCompleted() { return completed; }

    void setCompleted(bool val) { completed = val; }
};

int main() {
    char inputOption;
    int inputId;
    string inputDescription;
    string version = "0.2.0";
    list<TodoItem> todoItems;
    list<TodoItem>::iterator it;

    srand(time(NULL));

    todoItems.clear();

    //TodoItem test;
    //test.create("This is a test");
    //todoItems.push_back(test);

    while (1) {
        system("clear");
        cout << "Todo List Maker - " << version << endl;
        cout << endl << endl;

        for (it = todoItems.begin(); it != todoItems.end(); it++) {

            string completed = it->isCompleted() ? "done" : "not done";

            cout << it->getId() << " | " << it->getDescription() << " | " << completed << endl;
        }

        if (todoItems.empty()) {
            cout <<"Add your first todo item!"  << endl;
        }

        cout << endl << endl;

        cout << "[a]dd a new Todo" << endl;
        cout << "[c]omplete  a Todo" << endl;
        cout << "[q]uit" << endl;

        cout << "Choice: ";

        cin >> inputOption;

        if (inputOption == 'q') {
            cout << "Have a great day now!" << endl;
            break;
        }
        else if (inputOption == 'a') {
            cout << "Add a new description: ";
            cin.clear();
            cin.ignore();
            getline(cin,inputDescription);

            TodoItem newItem;
            newItem.create(inputDescription);
            todoItems.push_back(newItem);

        }
        else if (inputOption == 'c') {
            cout << "Enter id to mark as completed: ";
            cin  >> inputId;
            for (it = todoItems.begin(); it != todoItems.end(); it++) {

                if (inputId == it->getId()) {
                    it->setCompleted(true);
                    break;
                }
            }

        }

    }
    return 0;
}
