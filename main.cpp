#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

// Template Functions
template <class T>
T getMax(T a, T b)
{
    return (a > b) ? a : b;
}

template <class T>
T getMin(T a, T b)
{
    return (a < b) ? a : b;
}

// Student Structure
struct Student
{
    string id;
    string name;
    int score;
};

vector<Student> students;

// Add Student
void addStudent()
{
    Student s;

    cout << "\n===== Add Student =====\n";

    cout << "Enter ID: ";
    cin >> s.id;

    // 檢查學號是否重複
    for (const auto &st : students)
    {
        if (st.id == s.id)
        {
            cout << "Error: Student ID already exists!\n";
            return;
        }
    }

    cout << "Enter Name: ";
    cin >> s.name;

    cout << "Enter Score (0-100): ";
    cin >> s.score;

    if (s.score < 0 || s.score > 100)
    {
        cout << "Invalid score!\n";
        return;
    }

    students.push_back(s);

    cout << "Student added successfully!\n";
}

// List Students
void listStudents()
{
    if (students.empty())
    {
        cout << "\nNo student data.\n";
        return;
    }

    cout << "\n===== Student List =====\n";

    cout << left
         << setw(15) << "ID"
         << setw(20) << "Name"
         << setw(10) << "Score"
         << endl;

    cout << "-------------------------------------------\n";

    for (const auto &s : students)
    {
        cout << left
             << setw(15) << s.id
             << setw(20) << s.name
             << setw(10) << s.score
             << endl;
    }
}

// Sort Students
void sortByScore()
{
    if (students.empty())
    {
        cout << "\nNo student data.\n";
        return;
    }

    sort(students.begin(), students.end(),
         [](const Student &a, const Student &b)
         {
             return a.score > b.score;
         });

    cout << "\nStudents sorted by score.\n";
}

// Search Student
void searchStudent()
{
    if (students.empty())
    {
        cout << "\nNo student data.\n";
        return;
    }

    string searchId;

    cout << "\nEnter student ID: ";
    cin >> searchId;

    for (const auto &s : students)
    {
        if (s.id == searchId)
        {
            cout << "\n===== Student Found =====\n";
            cout << "ID    : " << s.id << endl;
            cout << "Name  : " << s.name << endl;
            cout << "Score : " << s.score << endl;
            return;
        }
    }

    cout << "Student not found.\n";
}

// Statistics
void showStatistics()
{
    if (students.empty())
    {
        cout << "\nNo student data.\n";
        return;
    }

    int highest = students[0].score;
    int lowest = students[0].score;
    int total = 0;
    int pass = 0;
    int fail = 0;

    for (const auto &s : students)
    {
        highest = getMax(highest, s.score);
        lowest = getMin(lowest, s.score);

        total += s.score;

        if (s.score >= 60)
            pass++;
        else
            fail++;
    }

    double average = (double)total / students.size();

    cout << fixed << setprecision(2);

    cout << "\n===== Statistics =====\n";
    cout << "Average Score : " << average << endl;
    cout << "Highest Score : " << highest << endl;
    cout << "Lowest Score  : " << lowest << endl;
    cout << "Pass Students : " << pass << endl;
    cout << "Fail Students : " << fail << endl;
}

int main()
{
    int choice;

    do
    {
        cout << "\n==================================\n";
        cout << " Student Management System\n";
        cout << "==================================\n";
        cout << "1. Add Student\n";
        cout << "2. List All Students\n";
        cout << "3. Sort By Score\n";
        cout << "4. Search By ID\n";
        cout << "5. Show Statistics\n";
        cout << "0. Exit\n";
        cout << "Choose: ";

        cin >> choice;

        switch (choice)
        {
        case 1:
            addStudent();
            break;

        case 2:
            listStudents();
            break;

        case 3:
            sortByScore();
            break;

        case 4:
            searchStudent();
            break;

        case 5:
            showStatistics();
            break;

        case 0:
            cout << "\nProgram ended.\n";
            break;

        default:
            cout << "\nInvalid choice!\n";
        }

    } while (choice != 0);

    return 0;
}