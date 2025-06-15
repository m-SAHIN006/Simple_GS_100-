#include <iostream>
#include <string>

using namespace std;

const int MAX_STUDENTS = 100;
int stds_grade[MAX_STUDENTS];

int f_in_grd(int grades_arr[], int actual_count)
{
    for (int i = 0; i < actual_count; i++)
    {
        cout << "Enter grade for student num " << (i + 1) << " (0-100): ";
        cin >> grades_arr[i];
        while (grades_arr[i] < 0 || grades_arr[i] > 100)
        {
            cout << "Invalid value. Please enter a grade between 0 and 100:\n";
            cout << "Enter grade for student num " << (i + 1) << " again: ";
            cin >> grades_arr[i];
        }
    }
    return 0;
}

int f_out_grd(const int grades_arr[], int actual_count)
{
    for (int i = 0; i < actual_count; i++)
    {
        cout << "Grade of student " << (i + 1) << " is:  " << grades_arr[i] << endl;
    }
    return 0;
}

int f_sum(const int grades_arr[], int actual_count)
{
    int sum = 0;
    for (int i = 0; i < actual_count; i++)
    {
        sum += grades_arr[i];
    }
    return sum;
}

double f_avg(const int grades_arr[], int actual_count)
{
    if (actual_count == 0) return 0.0;
    double avg = static_cast<double>(f_sum(grades_arr, actual_count)) / actual_count;
    return avg;
}

int f_mark(const int grades_arr[], int actual_count)
{
    string mark;
    for (int i = 0; i < actual_count; i++)
    {
        if (grades_arr[i] == 100)
            mark = "A+";
        else if (grades_arr[i] >= 95)
            mark = "A";
        else if (grades_arr[i] >= 90)
            mark = "A-";
        else if (grades_arr[i] >= 85)
            mark = "B+";
        else if (grades_arr[i] >= 80)
            mark = "B";
        else if (grades_arr[i] >= 75)
            mark = "B-";
        else if (grades_arr[i] >= 70)
            mark = "C+";
        else if (grades_arr[i] >= 65)
            mark = "C";
        else if (grades_arr[i] >= 60)
            mark = "C-";
        else if (grades_arr[i] >= 55)
            mark = "D+";
        else if (grades_arr[i] >= 50)
            mark = "D";
        else if (grades_arr[i] >= 0)
            mark = "F*";
        else
            mark = "Error (Invalid Grade)";
        cout << "The mark for student number " << (i + 1) << " is: " << mark << endl;
    }
    return 0;
}

int f_search(const int grades_arr[], int actual_count)
{
    int find_choice;
    bool continue_search = true;
    int student_num_to_find;

    while (continue_search)
    {
        cout << "\nDo you want to find a student grade? (1 for Yes, 0 for No): ";
        cin >> find_choice;

        switch (find_choice)
        {
            case 1:
                cout << "Enter the number of the student you want to find (1-" << actual_count << "): ";
                cin >> student_num_to_find;
                if (student_num_to_find > 0 && student_num_to_find <= actual_count)
                {
                    cout << "The grade for student num " << student_num_to_find << " is: " << grades_arr[student_num_to_find - 1] << endl;
                }
                else
                {
                    cout << "Invalid student number. Please try again with a number between 1 and " << actual_count << "." << endl;
                }
                break;

            case 0:
                continue_search = false;
                break;

            default:
                cout << "Invalid input. Please enter 0 or 1." << endl;
                break;
        }
    }
    return 0;
}

int f_edit(int grades_arr[], int actual_count)
{
    int student_num_to_edit;
    int new_mark;
    cout << "Enter the number of the student whose mark you want to change (1-" << actual_count << "): ";
    cin >> student_num_to_edit;

    if (student_num_to_edit > 0 && student_num_to_edit <= actual_count)
    {
        cout << "Enter the new mark for student num " << student_num_to_edit << ": ";
        cin >> new_mark;

        while (new_mark < 0 || new_mark > 100)
        {
            cout << "Invalid mark value. Please enter a mark between 0 and 100: ";
            cin >> new_mark;
        }

        grades_arr[student_num_to_edit - 1] = new_mark;
        cout << "The new mark for student num " << student_num_to_edit << " is: " << grades_arr[student_num_to_edit - 1] << endl;
    }
    else
    {
        cout << "Invalid student number. No mark was edited." << endl;
    }
    return 0;
}

int main()
{
    int num_actual_students;
    int meth_choose;
    int itr_choose = 1;

    cout << "Welcome to the student grade management program!" << endl;
    cout << "Please enter the number of students you want to manage (1-" << MAX_STUDENTS << "): ";
    cin >> num_actual_students;

    if (num_actual_students <= 0 || num_actual_students > MAX_STUDENTS)
    {
        cout << "Invalid number of students. Please enter a number between 1 and " << MAX_STUDENTS << ". Program will exit." << endl;
        return 1;
    }

    cout << "\nEnter the grades (0 - 100): " << endl;
    f_in_grd(stds_grade, num_actual_students);

    do
    {
        cout << "\n\nDo you want to perform any actions on the grades? (1 for Yes, 0 for No): " << endl;
        cin >> itr_choose;
        if (itr_choose == 1)
        {
            cout << "*\n*\n*\n*\n* " << endl;
            cout << "What do you want to do?\n\n";
            cout << "1. Print grades for all students\n";
            cout << "2. Calculate the SUM of all student marks\n";
            cout << "3. Calculate the AVG for all students\n";
            cout << "4. Display marks in characters (A+, B-, etc.)\n";
            cout << "5. Find a specific student's mark\n";
            cout << "6. Edit a student's mark\n\n";

            cin >> meth_choose;
            switch (meth_choose)
            {
                case 1:
                    f_out_grd(stds_grade, num_actual_students);
                    break;
                case 2:
                    cout << "The sum = " << f_sum(stds_grade, num_actual_students) << endl;
                    break;
                case 3:
                    cout << "The avg = " << f_avg(stds_grade, num_actual_students) << endl;
                    break;
                case 4:
                    f_mark(stds_grade, num_actual_students);
                    break;
                case 5:
                    f_search(stds_grade, num_actual_students);
                    break;
                case 6:
                    f_edit(stds_grade, num_actual_students);
                    break;
                default:
                    cout << "Invalid choice. Please enter a number between 1 and 6." << endl;
                    break;
            }
        }
        else if (itr_choose == 0)
            break;
        else
            itr_choose = 1;
    } while (itr_choose);

    cout << "\nThank you for using the program. Goodbye!" << endl;
    return 0;
}