#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, i = 0;
    string name, BOD, user, pass, password0, password1, password2, text, oldpass, word1, word2;
    string arr1[2], arr2[2];

    do
    {
        cout << endl << endl;
        cout << " ------   SECURITY  SYSTEM ---------" << endl;
        cout << " ___________________________________ \n"
             << endl;
        cout << "   1:  Register     " << endl;
        cout << "   2:  Login         " << endl;
        cout << "   3:  Cahnge Password   " << endl;
        cout << "   4:  End Program         " << endl;
        cout << " ___________________________________ \n"
             << endl;
        cout << endl
             << endl;
        //   // taking input from the user:::

        cout << endl
             << endl;
        cout << " Enter the choice :- ";
        cin >> a;

        switch (a)
        {
        case 1: // // for rgistration::::
        {
            cout << "___________________________________" << endl;
            cout << "------------Register---------------" << endl;
            cout << "___________________________________" << endl
                 << endl;
            cout << "Please enter the username :- ";
            cin >> name;
            cout << "Please enter the Password :- ";
            cin >> password0;
            cout << "please enter your Bate Of Birth (DD/MM/YYYY) :- ";
            cin >> BOD;

            // // we are using ofstream to store this data;;;
            ofstream of1; // // it is used because to write in it;;
            of1.open("file.txt");
            if (of1.is_open())
            {
                of1 << name << "\n";
                of1 << password0 << "\n";
                of1 << BOD << "\n";
                cout << "Registration Successfull done" << endl;
            }
            break;
        }

        case 2: // // for Login ::::
        {
            i = 0;
            cout << "___________________________________" << endl;
            cout << "------------Login---------------" << endl;
            cout << "___________________________________" << endl
                 << endl;

            ifstream of2;
            of2.open("file.txt");
            cout << "Please enter the user name :- ";
            cin >> user;
            cout << "please enter your password :- ";
            cin >> pass;

            if (of2.is_open())
            {
                while (!of2.eof())
                {
                    while (getline(of2, text)) // // yai getline mera line by line check kari ga;;
                    {
                        istringstream iss(text); //  istringstream  is used to change the string and store using the extraction operator;
                        iss >> word1;            // here we are storing using the extractor operator::::
                        arr1[i] = word1;
                        i++;
                    }
                    // now it will check the user and password matchex with the data::
                    if (user == arr1[0] && pass == arr1[1]) // here in creds first index it will store user and int 2nd index it store pas;;
                    {
                        cout << "---------Login Successful------" << endl
                             << endl;
                        cout << "  DETAILS  " << endl;
                        cout << " Username : " << user << endl;
                        cout << " Password : " << pass << endl;
                        cout << " Bate Of Birth : " << BOD << endl;
                    }
                    else
                    {
                        cout << endl
                             << endl;
                        cout << " Incorrect user and Password." << endl;
                        cout << "     Press    :  2  to login." << endl;
                        cout << "     Press    :  3  to Change password." << endl;
                        // break;
                    }
                }
            }
            break;
        }

        // // // // change password ::::--
        case 3:
        {
            i = 0;
            cout << "---------Change Password--------" << endl
                 << endl;
            ifstream of0;
            of0.open("file.txt");
            cout << "Enter the old password : ";
            cin >> oldpass;

            if (of0.is_open())
            {

                while (!of0.eof())
                {
                    while (getline(of0, text))
                    {
                        istringstream iss(text);
                        iss >> word2;
                        arr2[i] = word2;
                        i++;
                    }
                    if (oldpass == arr2[1])
                    {
                        of0.close(); // delete and free the prev. pass;

                        ofstream of1; // open new file t  to write in it;;
                        of1.open("file.txt");
                        if (of1.is_open())
                        {
                            cout << " Enter your new Password :- ";
                            cin >> password1;
                            cout << " Enter your Password again :- ";
                            cin >> password2;

                            if (password1 == password2)
                            {
                                of1 << arr2[0] << "\n";
                                of1 << password1;
                                cout << "passwor successfully changed." << endl;
                            }
                            else
                            {
                                of1 << arr2[0] << "\n";
                                of1 << oldpass;
                                cout << " Password doesn't match." << endl;
                            }
                        }
                    }
                    else
                    {
                        cout << endl;
                        cout << "Please enter a valid password" << endl;
                        break;
                    }
                }
            }
            break;
        }

        // // end of the programe:::::----
        case 4:
        {
            cout << "-----------THANKTYOU-----------" << endl;
            break;
        }

        /////// default case :::
        default:
        {
            cout << "Enter a valid choice." << endl;
        }
        }
    } while (a != 4);
    return 0;
}
