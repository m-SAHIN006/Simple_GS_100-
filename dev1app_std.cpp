// todo: input g / output g / sum / avg / char / search / edit
//just for 5 stds 
#include <iostream>
#include <string>
using namespace std;

int stds_grade[5];

int f_in_grd()
{
    for (int i = 1; i < 6; i++)
    {
        cout << "enter a std num " << i << " grades: ";
        cin >> stds_grade[i - 1];
        while (stds_grade[i - 1] < 0 || stds_grade[i - 1] > 100)
        {
            cout << "invalid value:\nERROR\nclose the program and try again" << endl;
            return 1;
            break;
        }
    }
    return 0;
}

int f_out_grd()
{
    for (int i = 1; i < 6; i++)
    {
        cout << "grade of std " << i << " is:  " << stds_grade[i - 1] << endl;
    }
    return 0;
}

int f_sum()
{
    int sum = 0;
    for (int i = 1; i < 6; i++)
    {
        sum += stds_grade[i - 1];
    }

    return sum;
}

double f_avg()
{
    double avg = static_cast<double>(f_sum()) / 5.0;
    return avg;
}

int f_mark()
{
    string mark;

    for (int i = 1; i < 6; i++)
    {

        if (stds_grade[i - 1] == 100)
            mark = "A+";
        else if (stds_grade[i - 1] > 94 && stds_grade[i - 1] < 100)
            mark = "A";
        else if (stds_grade[i - 1] > 89 && stds_grade[i - 1] < 95)
            mark = "A-";
        else if (stds_grade[i - 1] > 84 && stds_grade[i - 1] < 90)
            mark = "B+";
        else if (stds_grade[i - 1] > 79 && stds_grade[i - 1] < 85)
            mark = "B";
        else if (stds_grade[i - 1] > 74 && stds_grade[i - 1] < 80)
            mark = "B-";
        else if (stds_grade[i - 1] > 69 && stds_grade[i - 1] < 75)
            mark = "C+";
        else if (stds_grade[i - 1] > 64 && stds_grade[i - 1] < 70)
            mark = "C";
        else if (stds_grade[i - 1] > 59 && stds_grade[i - 1] < 65)
            mark = "C-";
        else if (stds_grade[i - 1] > 54 && stds_grade[i - 1] < 60)
            mark = "D+";
        else if (stds_grade[i - 1] > 49 && stds_grade[i - 1] < 55)
            mark = "D";
        else if (stds_grade[i - 1] > -1 && stds_grade[i - 1] < 50)
            mark = "F*";
        else
            mark = "error";
        cout << "the mark for std number " << i << " is: " << mark << endl;
    }
    return 0;
}

int f_search()
{
    int find;
    bool trt = 1;
    int choose;

    while (trt)
    {
        cout << "do u want to find a std grade? \"if yes press 1 & if no press 0\" ";
        cin >> find;

        switch (find)
        {
        case 1:
            cout << "enter a num of std u want: ";
            cin >> choose;
            if (choose > 0 && choose < 6)
            {
                cout << "the std grade for std num " << choose << " is: " << stds_grade[choose - 1] << endl;
                break;
            }
            else
            {
                cout << "there is no " << choose << " std, try again." << endl;
                break;
            }

        case 0:
            trt = 0;
            break;

        default:
            cout << "inter a valid num [0/1] ";
            break;
        }
    }
    return 0;
}

int f_edit()
{
    int edit;
    int new_mark;
    cout << "write the num of std u want to change his mark: ";
    cin >> edit;
    cout << "enter the new mark:  ";
    cin >> new_mark;
    stds_grade[edit - 1] = new_mark;
    cout <<"the new mark for the std num "<< edit << " is: "<< stds_grade[edit - 1] <<endl; 
    return 0;
}

int main()
{
    int meth_choose;
    int itr_choose = 1;
    cout << "Welcome to the student grade addition program: \nenter the grades from 0 - 100: " << endl;
    f_in_grd();

    do
    {
        cout << "\n\nDo you want to do any actions on the marks, (if yes press 1 and if no press 0)" << endl;
        cin >> itr_choose;
        if (itr_choose == 1)
        {
            cout << "*\n*\n*\n*\n* " << endl;
            cout << "what do u want?\n\n";
            cout << "print grades for all stds                 -> press 1\n"<< endl;
            cout << "Calculate the SUM marks of all stds       -> press 2\n"<< endl;
            cout << "calculate the avg for all stds            -> press 3\n"<< endl;
            cout << "marks in characters                       -> press 4\n"<< endl;
            cout << "Find a specific stds mark                 -> press 5\n"<< endl;
            cout << "to edit any mark                          -> press 6\n\n" << endl;

            cin >> meth_choose;
            switch (meth_choose)
            {
            case 1:
                f_out_grd();
                break;
            case 2:
                cout << "The sum = " << f_sum() << endl;
                break;
            case 3:
                cout << "The avg = " << f_avg() << endl;
                break;

            case 4:
                f_mark();
                break;

            case 5:
                f_search();
                break;

            case 6:
                f_edit();
                break;

            default:
                cout << "Invalid choice. Please enter a number between 1 and 5." << endl;
                break;
            }
        }

        else if (itr_choose == 0)
            break;
        else
            itr_choose = 1;
    } while (itr_choose);

    return 0;
}
