// To-Do List
// 1st task of Codsoft C++ Internship

#include <iostream>
#include <vector>
using namespace std;

// Structure of task
struct Task {
    string name;
    bool complete = false;
};

// Viewing tasks
void view_tasks( vector<Task> &tasks) {
    
    if(tasks.empty()) {
        cout<<"\n\tYour To-Do List is empty.  ";
    }

    else{
    for (int i = 0; i < tasks.size(); i++) {
        cout << "\n Your Tasks are as following: " << endl<<endl;
        cout <<"\t"<< tasks[i].name << " " << (tasks[i].complete ? "(completed)" : "(Not Completed)") << endl;
    }
    }
}

// Adding task
void add_task(vector<Task> &tasks, string &name) {
    tasks.push_back({name, false});
    cout<<endl;
    cout << "\tTask added: " << name << endl;
}

// Remove/delete task
void remove_task(vector<Task> &tasks, int index) {
    //we are using begin() to start from the begining point + index
    tasks.erase(tasks.begin() + index);
    cout<<endl;
    cout << "\tTask removed at index " << index << endl;
}

void mark_task_complete(vector<Task> &tasks, int index) {
    tasks[index].complete = true;
    cout << "\tTask marked as completed: " << tasks[index].name << endl;
}

// Main program
int main() {
    vector<Task> tasks;
    int choice;

    cout<<endl<<endl;
    cout << "***** WELCOME TO Your ToDo List *****" << endl << endl;

    while (true) {
        cout<<endl;
        cout << "TO-DO LIST MANAGER" << endl<<endl;
        cout << "\t1. Add Task" << endl;
        cout << "\t2. View Tasks" << endl;
        cout << "\t3. Mark Task as Completed" << endl;
        cout << "\t4. Remove Task" << endl;
        cout << "\t5. Exit" << endl<<endl;
        cout << "\tChoose an option: ";
        cin >> choice;

        //Add a task
        if (choice == 1) {
            string description;
            cout << "Enter Task Description: ";
            cin>>description;
            add_task(tasks, description);

        }
        //View Task
         else if (choice == 2) {
            view_tasks(tasks);

        }
        //Mark complete
        else if (choice == 3) {
            int index;
            cout << "Enter task index to mark as completed: ";
            cin >> index;
            mark_task_complete(tasks, index);
        } 
        //Remove Task
        else if (choice == 4) {
            int index;
            cout << "Enter task index to remove: ";
            cin >> index;
            remove_task(tasks, index);
        }
        //exit
         else if (choice == 5) {
            cout << "Exiting the program." << endl;
            break;
            return 0;
        } else 
        //if user enters a wrong number
        {
            cout << "Invalid choice. Please select a valid option." << endl;
        }

        cout << endl;
    }

    return 0;
}
