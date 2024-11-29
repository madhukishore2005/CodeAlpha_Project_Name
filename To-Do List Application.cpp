#include<iostream>
#include<vector>
#include<string>
#include<fstream>
using namespace std;
struct Task
{
    string description;
    bool completed;
};
vector<Task>tasks;
void addTask()
{
    string description, name;
    cout<<"Enter the task name and description";
    getline(cin>>ws,description);
    tasks.push_back({description,false});
}
void viewTasks()
{
    if(tasks.empty())
    {
        cout<<"No task in the list. \n";
        return;
    }
    for(int i=0;i<tasks.size();i++)
    {
        cout<<i+1<<".["<<(tasks[i].completed?"X":"")<<"]"<<tasks[i].description<<endl;
    }
}
void markComplete()
{
    int index;
    cout<<"Enter task index to mark complete:";
    cin>>index;
    if(index>=1 && index<=tasks.size())
    {
        tasks[index-1].completed=true;
    }
    else
    {
        cout<<"Invalid task index, \n";
    }
}
void removeTask()
{
    int index;
    cout<<"Enter task index to remove:";
    cin>>index;
    if(index>=1 && index<=tasks.size())
    {
        tasks.erase(tasks.begin()+index-1);
    }
    else
    {
        cout<<"Invalid task index. \n";
    }
}
void saveTasks()
{
    ofstream file("tasks.txt");
    for(const   Task & task:tasks)
    {
        file<<task.description<<","<<task.completed<<endl;
    }
    file.close();
}
void loadTasks()
{
    ifstream file("tasks.txt");
    string line;
    while(getline(file,line))
    {
        string description, completedStr;
        size_t commaPos=line.find(",");
        description=line.substr(0,commaPos);
        completedStr=line.substr(commaPos+1);
        tasks.push_back({description, completedStr=="1"});
    }
    file.close();
}
int main()
{
    loadTasks();
    int choice;
    do
    {
        cout<<"\n To-Do List Menu: \n";
        cout<<"1.Add Task \n";
        cout<<"2. View Task \n";
        cout<<"3.Mark Complete \n";
        cout<<"4.Remove Task \n";
        cout<<"5.Save and Exit \n";
        cout<<"Enter your choice:";
        cin>>choice;
        switch(choice)
        {
            case 1:
            addTask();
            break;
            case 2:
            viewTasks();
            break;
            case 3:
            markComplete();
            break;
            case 4:
            removeTask();
            break;
            case 5:
            saveTasks();
            cout<<"\n Task saved. Exiting... \n";
            break;
            default:
            cout<<"Invalid choice \n";
        }
    }
    while(choice!=5);
return 0;
}
