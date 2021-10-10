#include <iostream>
#include <fstream>
#include <limits>
#include <string.h>
#include <conio.h>
#include <iomanip>
using namespace std;


//This function is used to get the denomination values for the ATM Machine money addition/display
int getdenovals(int denos)
{ 

    ifstream files("balance.txt");

    int deno;
    int amnt;
    int val;
    int realamnt;

    while (files >> deno >> amnt >> val)
    {

        if (denos == deno)
        {
            realamnt = amnt;
        }
    }

    return realamnt;
}

//This function is used to get the denomination line for the ATM Machine money addition/display
//This function is initiated to obtain the previous values for deletion and updation
int finddenoline(int denos) 
{                          
    ifstream files("balance.txt");

    int deno;
    int amnt;
    int val;
    int denoline = 1;
    int flag = 0;

    cout << "\n";
    while (files >> deno >> amnt >> val)
    {

        if (denos == deno)
            flag = 1;
        if (flag == 0)
        {
            denoline++;
        }
    }
    return denoline;
}


//This function , when called , displays all the accounts in the bank with the account details
//function parameter is the administrator password
int showaccounts(int adminpass)
{   
    if (adminpass == 1234)
    {
        ifstream files("accounts.txt");

        string acno;
        string acname;
        string pinoe;
        int bala;
        int linecount = 0;

        cout << "\n The account details are as follows :\n \n";

        cout << "Account No   Account Name  Account Pin   Account Balance" << endl;

        while (files >> acno >> acname >> pinoe >> bala)
        {

            cout << "   " << acno << "          " << acname << "        " << pinoe << "            " << bala << endl;
        }
    }
    else
        cout << "\nYou have entered the wrong Administrator Password! ";

    return 0;
}

//This function displays the left over balance in the ATM Machine under different denominations
int showatmbalance(int adminpass)
{ 

    if (adminpass == 1234)
    {
        ifstream files("balance.txt");

        int denomination;
        int numbers;
        int value;
        int bala;
        int linecount = 0;

        cout << "\n The ATM Machine details are as follows :\n\n ";

        cout << "Denomination    Number    Value " << endl;

        while (files >> denomination >> numbers >> value)
        {

            if (denomination == 2000)
                cout << "     " << denomination << "         " << numbers << "      " << value << endl;
            else
                cout << "     " << denomination << "          " << numbers << "       " << value << endl;
        }
    }
    else
        cout << "\nYou have entered the wrong Administrator Password! ";

    return 0;
}


//this function is used as a part of obtaining the account balance from the "accounts.txt" file
int checkaccount(string accno)
{ 

    ifstream files("accounts.txt");

    string acno;
    string acname;
    string pinoe;
    int bala;
    int linecount = 0;
    int realbala;

    while (files >> acno >> acname >> pinoe >> bala)
    {

        if (acno == accno)
        {
            realbala = bala;
        }
    }

    return realbala;
}


//This important function contains Account number and Account password as parameters and authenticates the validity of the account
int authenticate(string accno, string pino) 
{

    ifstream files("accounts.txt");

    string acno;
    string acname;
    string pinoe;
    int bala;
    int flag = 0;

    cout << "\n";
    while (files >> acno >> acname >> pinoe >> bala)
    {

        if ((pinoe == pino) && (accno == acno))
        {
            flag = 1;
            cout << "\n Account login successfull ! ";
        }
    }

    if (flag == 0)
        cout << "\n Your Credentials are Incorrect";

    return flag;
}


//This function is used to display a welcome message with the name of the user upon successfull authentication
string welcomemessage(string accno, string pino)
{ 

    ifstream files("accounts.txt");

    string acno;
    string acname;
    string realname;
    string pinoe;
    int bala;
    int linecount = 0;

    while (files >> acno >> acname >> pinoe >> bala)
    {

        if (acno == accno)
        {
            cout << "\n Welcome to the ATM , Mr/Mrs " << acname;
            realname = acname;
        }
    }

    return realname;
}


//This function is used to obtain the name of the user and return it for further operations
string nameinitiator(string accno)
{ 

    ifstream files("accounts.txt");

    string acno;
    string acname;
    string realname;
    string pinoe;
    int bala;

    while (files >> acno >> acname >> pinoe >> bala)
    {

        if (acno == accno)
        {
            realname = acname;
        }
    }

    return realname;
}


//This function obtains the pin of the specific user to facilitate further updation on the account
string pinitiator(string accno)
{ 

    ifstream files("accounts.txt");

    string acno;
    string acname;
    string realpin;
    string pinoe;
    int bala;

    while (files >> acno >> acname >> pinoe >> bala)
    {

        if (acno == accno)
        {
            realpin = pinoe;
        }
    }

    return realpin;
}

//This function procures the line at which the account details are situated to use in case of updation
int findline(string accno) 
{

    ifstream files("accounts.txt");

    string acno;
    string acname;
    string pinoe;
    int bala;
    int flag = 0;
    int linecount = 1;

    cout << "\n";
    while (files >> acno >> acname >> pinoe >> bala)
    {

        if (accno == acno)
            flag = 1;
        if (flag == 0)
        {
            linecount++;
        }
    }
    return linecount;
}


//This function is a sub-function which helps in the withdrawal/transfer operation
//The parameters consists of amount , account number and flag- which is used to distinguish between withdrawal and tran sfer operations
int withdraw(int withd, string accno, int flags) 
{                                              
    ifstream files("accounts.txt");

    string acno;
    string acname;
    string pinoe;
    int bala;
    int realbala;

    int red = withd;

    while (files >> acno >> acname >> pinoe >> bala)
    {

        if (acno == accno)
        {
            realbala = bala - red;
        }
    }
    if ((flags == 0) && (realbala > 0))
        cout << "\nThe amount has been successfully withdrawn ! \n Remaining balance = Rs " << realbala;
    if ((flags == 1) && (withd < 0))
        cout << "\nThe amount : Rs " << -withd << "  has been successfully transferred to the account !";

    return realbala;
}


//Function initialized during updation to delete the account details with old values
int delete_line(const char *file_name, int n) 
{
    ifstream is(file_name);
    ofstream ofs;
    ofs.open("temp.txt", ofstream::out);

    char c;
    int line_no = 1;
    while (is.get(c))
    {

        if (c == '\n')
            line_no++;

        if (line_no != n)
            ofs << c;
    }

    ofs.close();

    is.close();

    remove(file_name);

    rename("temp.txt", file_name);

    return 0;
}


//Updation function used to update the account details after transaction with the new details in the "accounts.txt" file
int update1(string acno, string names, string pind, int balas)
{ 

    ofstream out("accounts.txt", ios::app);
    out << endl
        << acno << " " << names << " " << pind << " " << balas;
    return 0;
}

//Function used to update the ATM Machine balance in the file "balance.txt"
int update2(int deno, int curramnt, int currval)
{ 

    ofstream out("balance.txt", ios::app);
    out << endl
        << deno << "   " << curramnt << "  " << currval;
    return 0;
}

//Function to delete the extra line which is empty after updation for customer accounts
void del_extra(int lindl) 
{

    FILE *fp = fopen("accounts.txt", "r+");
    FILE *fp1 = fopen("temp.txt", "w");

    char str[200];
    int cnt = 0;

    while (!feof(fp))
    {
        fgets(str, 200, fp);

        if (str[0] == '#')
        {
            fputs(str, fp1);
        }
        else
        {
            if (cnt == lindl)
            {
                cnt++;
            }
            else
            {
                cnt++;
                fputs(str, fp1);
            }
        }
    }

    fclose(fp);
    fclose(fp1);

    rename("accounts.txt", "deleteme.txt");
    rename("temp.txt", "accounts.txt");
    remove("deleteme.txt");
}

//Function to delete the extra line which is empty after updation for the ATM Machine money balance under denominations
void del_extra1(int lindl) 
{

    FILE *fp = fopen("balance.txt", "r+");
    FILE *fp1 = fopen("temp.txt", "w");

    char str[200];
    int cnt = 0;

    while (!feof(fp))
    {
        fgets(str, 200, fp);

        if (str[0] == '#')
        {
            fputs(str, fp1);
        }
        else
        {
            if (cnt == lindl)
            {
                cnt++;
            }
            else
            {
                cnt++;
                fputs(str, fp1);
            }
        }
    }

    fclose(fp);
    fclose(fp1);

    rename("balance.txt", "deleteme.txt");
    rename("temp.txt", "balance.txt");
    remove("deleteme.txt");
}


//Function initalised to add a specific amount under a specific denomination
int total_addamount(int deno, int amnt) 
{

    if (deno == 2000 || deno == 500 || deno == 100)
    {
        int realamnt = getdenovals(deno);
        int realval = realamnt * deno;
        int denoline = finddenoline(deno);
        int currval = realval + (deno * amnt);
        int curramnt = realamnt + amnt;
        update2(deno, curramnt, currval);
        del_extra1(denoline - 1);

        cout << "\n The amount has been successfully added to the ATM Machine !";
    }
    else
    {

        cout << "\n Please enter the denomination under the ATM guideline !";
    }

    return 0;
}


//Function used to reduce the ATM Machine balance under different denominations in case of transactions
int total_reduceamount(int deno, int amnt) 
{

    int realamnt = getdenovals(deno);
    int realval = realamnt * deno;
    int denoline = finddenoline(deno);
    int currval = realval - (deno * amnt);
    int withval = deno * amnt;
    int curramnt = realamnt - amnt;
    if (curramnt >= 0)
    {
        update2(deno, curramnt, currval);
        del_extra1(denoline - 1);
        return withval;
    }
    if (curramnt < 0)
    {
        total_reduceamount(deno, amnt - 1);
    }
    return 0;
}


//Function to ensure that the minimum currency criteria is satisfied
int amnt_check(int deno, int amnt) 
{

    int relamnt = getdenovals(deno);
    int relval = relamnt * deno;
    int deoline = finddenoline(deno);
    int curval = relval - (deno * amnt);
    int wihval = deno * amnt;
    int curamnt = relamnt - amnt;

    if (curval < 0)
    {
        cout << "\n There currency amount for the denomination : Rs " << deno << " has been depleted ! \n Please visit the bank to withdraw money !";
        return 0;
    }

    if (curval >= 0)
        return 1;

    return 0;
}

//Finds the previous transaction number to update further transactions under mini statements
int find_trno(string ministates)
{ 

    ifstream files(ministates);
    int trno;
    string op1;
    string op3;
    string op2;
    string types;
    int amount;
    int balances;
    int temptr;

    while (files >> trno >> op1 >> op2 >> op3 >> types >> amount >> balances)
    {

        temptr = trno;
    }
    return temptr;
}

//updates the mini-statement file of the respective account after withdrawal opreration
int mini_update_withdraw(string ministate, string accno, int amount, int balance)
{ 

    ofstream out(ministate, ios::app);
    string op1 = "Cash";
    string op3 = "Withdrawal";
    string op2 = " - ";
    string types = "Debit";
    int trno = find_trno(ministate);
    if (trno < 1001)
    {
        trno = 1000;
    }
    trno = trno + 1;
    out << trno << "   " << op1 << op2 << op3 << "     " << types << "     " << amount << "    " << balance << "\n";
    return 0;
}

//updates the mini-statement file of the respective amounts after a transaction operation
int mini_update_transfer_to(string ministate, string accno, string accno2, int amount, int balance)
{ 

    ofstream out(ministate, ios::app);
    string op1 = "Transfer";
    string op3 = accno2;
    string op2 = " to ";
    string types = "Debit";
    int trno = find_trno(ministate);
    if (trno < 1001)
    {
        trno = 1000;
    }
    trno = trno + 1;
    out << trno << "    " << op1 << op2 << op3 << "      " << types << "     " << amount << "    " << balance << "\n";
    return 0;
}

//updates the mini-statement file of the respective amounts after a transaction operation
int mini_update_transfer_from(string ministate2, string accno, string accno2, int amount, int balance)
{ 

    ofstream out(ministate2, ios::app);
    string op1 = "Transfer";
    string op3 = accno;
    string op2 = " from ";
    string types = "Credit";
    int trno = find_trno(ministate2);
    if (trno < 1001)
    {
        trno = 1000;
    }
    trno = trno + 1;
    out << trno << "   " << op1 << op2 << op3 << "     " << types << "    " << amount << "    " << balance << "\n";
    return 0;
}

//this function consists of all other sub-function which facilitates the whole withdrawal operation
int total_withdraw(int withd, string accno, string username, string pino, int linecount1, string edit)
{ 

    int bala1;
    int flags = 0;
    bala1 = withdraw(withd, accno, flags);
    if (bala1 >= 0)
    {
        del_extra(linecount1-1);
        update1(accno, username, pino, bala1);
        if(linecount1==5)
            del_extra(linecount1-1);
        mini_update_withdraw(edit, accno, withd, bala1);
    }
    if (bala1 < 0)
        cout << "\n You do not have sufficient balance in your account for this withdrawal!";
    return 0;
}

//This important function determines the amount of money under each denominations to be withdrawn given the specific amount
int atm_redux(int withd) 
{
    int temps = withd;
    int l1 = 0;
    int l2 = 0;
    int l3 = 0;
    int flag1 = 1;
    int flag2 = 1;
    int flag3 = 1;
    int flag4 = 1;
    if ((withd <= 5000) && (withd > 3500))
    {
        flag1 = amnt_check(2000, 1);
        temps = temps - 2000;
        l1 = 1;
    }
    if ((withd <= 5000) && (withd > 1000))
    {
        flag2 = amnt_check(500, 1);
        temps = temps - 500;
        l2 = 1;
    }
    if ((withd <= 5000) && (withd > 1500))
    {
        flag3 = amnt_check(100, 10);
        temps = temps - (100 * 10);
        l3 = 10;
    }

    if ((flag1 == flag2 == flag3 == 1) && (withd <= 5000) && (withd > 3500))
    {

        total_reduceamount(2000, 1);
    }

    if ((flag1 == flag2 == flag3 == 1) && (withd <= 5000) && (withd > 1000))
    {

        total_reduceamount(500, 1);
    }

    if ((flag1 == flag2 == flag3 == 1) && (withd <= 5000) && (withd > 1500))
    {

        total_reduceamount(100, 10);
    }

    if ((flag1 == flag2 == flag3 == 1) && (withd <= 5000))
    {
        int last = temps / 2000;
        last = total_reduceamount(2000, last) / 2000;
        temps = temps - (last * 2000);

        int mid = temps / 500;
        mid = total_reduceamount(500, mid) / 500;
        temps = temps - (mid * 500);

        int beg = temps / 100;
        beg = total_reduceamount(100, beg) / 100;
        temps = temps - (beg * 100);

        last = last + l1;
        mid = mid + l2;
        beg = beg + l3;

        int atmflag = 1;

        cout << "The amount in the denomination :\n Rs 2000: " << last << " Notes \n Rs 500: " << mid << " Notes \n Rs 100: " << beg << " Notes \nis being withdrawn currently !";
        return atmflag;
    }

    if ((flag1 == 0) || (flag2 == 0) || (flag3 == 0))
        cout << "\nPlease contact the Bank authorities for further instructions !";

    /// this is division between amounts//

    if (withd > 5000)
    {
        flag3 = amnt_check(2000, 2);
        temps = temps - (2000 * 2);
        l1 = 2;
    }
    if (withd > 5000)
    {
        flag4 = amnt_check(500, 2);
        temps = temps - (500 * 2);
        l2 = 2;
    }

    if ((flag3 == flag4 == 1) && (withd > 5000))
    {

        total_reduceamount(2000, 2);
        total_reduceamount(500, 2);
        total_reduceamount(100, 0);

        int last = temps / 2000;
        last = total_reduceamount(2000, last) / 2000;
        temps = temps - (last * 2000);

        int mid = temps / 500;
        mid = total_reduceamount(500, mid) / 500;
        temps = temps - (mid * 500);

        int beg = temps / 100;
        beg = total_reduceamount(100, beg) / 100;
        temps = temps - (beg * 100);

        int atmflag = 1;

        last = last + l1;
        mid = mid + l2;
        beg = beg + l3;

        cout << "The amount in the denomination :\n Rs 2000: " << last << " Notes \n Rs 500: " << mid << " Notes \n Rs 100: " << beg << " Notes \n is being withdrawn currently !\n";

        return atmflag;
    }

    if (flag3 == 0 || flag4 == 0)
        cout << "\n Please contact the Bank authorities for further instructions! ";

    return 0;
}

//This function facilitates the whole transfer operation which contains numerous sub-functions which takes care of the operation
int total_transfer(string accno2, int transfer, string accno, string username, string pino, int linecount1, string f1, string f2)
{

    if (transfer > 0)
    { 

        int flags = 1;
        int bala1 = withdraw(transfer, accno, flags);

        if (bala1 >= 0)
        {
            update1(accno, username, pino, bala1);
            del_extra(linecount1 - 1);

            string name2 = nameinitiator(accno2);
            int linecount2 = findline(accno2);
            int bala2 = withdraw(-transfer, accno2, flags);
            string pin2 = pinitiator(accno2);

            update1(accno2, name2, pin2, bala2);
            del_extra(linecount2 - 1);
            mini_update_transfer_from(f2, accno, accno2, transfer, bala2);
            mini_update_transfer_to(f1, accno, accno2, transfer, bala1);
        }

        if (bala1 < 0)
            cout << "\n You do not have sufficient amount in your account for this transaction!";
    }

    if (transfer < 0)
        cout << "\n You cannot transfer negative amounts to another account ! \n Further illegal actions will lead to your account being blocked!";

    return 0;
}

//This function is used to display the previous 10 transactions under the mini-statement by accessing the "<customer_ID>_transactions.txt" file
mini_display(string ministate)
{ 
    ifstream files(ministate);
    int trno;
    string op1;
    string op3;
    string op2;
    string types;
    int amount;
    int balances;

    int last = find_trno(ministate);
    last = last - 10;
    cout << "\n The Mini statement for your account [Last 10 Transactions] is : ";

    cout << "\n\n Transaction ID       Description     Credit/Debit    Amount    Closing Balance\n\n";
    while (files >> trno >> op1 >> op2 >> op3 >> types >> amount >> balances)
    {

        if (trno >= last)
        {
            if (op2 == "-")
                cout << "      " << trno << "         " << op1 << " " << op2 << " " << op3 << "      " << types << "        " << amount << "         " << balances << endl;

            if (op2 == "to")
                cout << "      " << trno << "          " << op1 << " " << op2 << " " << op3 << "       " << types << "        " << amount << "         " << balances << endl;

            if (op2 == "from")
                cout << "      " << trno << "         " << op1 << " " << op2 << " " << op3 << "      " << types << "       " << amount << "         " << balances << endl;
        }
    }

    return 0;
}

int main()
{

    int ch; 
    string accno;                    //variable for account number
    string pino;                     //variable for pin number
    int op2;
    int linecount1;                 //variable for the account detail line number
    string username;
    int adminpass;

    cout << "\n\n\n                                                                       ***   WELCOME TO ATM MACHINE   *** ";
    cout << "\n Please enter your required option \n 1)Load cash into the ATM Machine \n 2)Show customer details \n 3)Show ATM operations\n Your Option : ";
    cin >> ch;

    switch (ch)
    {                               //switch statement initialized for the four primary operations

    case 1:
    {

        int deno;
        int amnt;
        cout << "\n Please enter the ATM Administrator password :";
        cin >> adminpass;            //case for adding cash into the ATM Machine
        if (adminpass == 1234)
        {
            cout << "\n Please enter the details of the amount to be loaded into the ATM \n Denomination :";
            cin >> deno;
            cout << "\n Amount :";
            cin >> amnt;
            total_addamount(deno, amnt);
            showatmbalance(adminpass);
        }
        if (adminpass != 1234)
            cout << "\n You have entered the wrong ATM Administrator password !";
    }
    break;

    case 2:                       //case for displaying all user details as a table
    {
        cout << "\n Enter ATM Administrator password : "; 
        cin >> adminpass;
        showaccounts(adminpass);
    }
    break;

    case 3:                     //case for account login and subsequent operations
    {

        do
        {                         
            cout << "\nPlease enter your Account details \n Account No : "; 
            cin >> accno;
            cout << "\n Pin No : ";
            cin >> pino;

            string opinion;
            int fleg = authenticate(accno, pino);
            if (fleg == 1)

            {
                username = welcomemessage(accno, pino);
                linecount1 = findline(accno);
                string minis = "_transactions.txt";
                string edit = accno + minis;
                cout << "\n Please select the preferred operation \n 1) Check Balance \n 2) Withdraw Money \n 3) Transfer Money \n 4) Check ATM Balance \n 5) Mini Statement : \n Your Option is : ";
                cin >> op2;

                switch (op2)
                {                                                                //switch statement for the second set of operations

                case 1:
                {
                    int realbala = checkaccount(accno);                          //case to display balance
                    cout << "\n The balance in your account is Rs :" << realbala;
                }
                break;

                case 2:
                {
                    int bala1;
                    int withd;                                                   //case to withdraw amount
                    string pin2;
                    cout << "\n Please Re-enter your account Pin :";
                    cin >> pin2;
                    if (pin2 == pino)
                    {
                        cout << "\n Enter the Amount to be withdrawn : Rs ";
                        cin >> withd;
                        int tempwith = withd;
                        int compbal = checkaccount(accno);
                        if ((compbal >= withd) && (withd >= 100) && (withd <= 10000) && (withd % 100 == 0))
                        {
                            int atmflag = atm_redux(withd);
                            if (atmflag == 1)
                            {
                                total_withdraw(withd, accno, username, pino, linecount1, edit);
                            }
                        }
                        if (compbal < withd)
                            cout << "\n No sufficient balance in your account !";

                        if (withd < 100)
                            cout << "\n Minimum transaction amount is Rs 100 !";

                        if (withd > 10000)
                            cout << "\n Maximum transaction amount is Rs 10000 !";

                        if (withd % 100 != 0)
                            cout << "\n Please enter an amount divisible by 100 due to ATM restrictions !";
                    }
                }
                break;

                case 3:
                {
                    int transfer;
                    string accno2;
                    cout << "\n Please enter the account number to transfer the amount : ";   //case to transfer money to another account
                    cin >> accno2;
                    cout << "\n Please enter the amount to be transferred :";
                    cin >> transfer;
                    if ((transfer > 1000) && (transfer <= 10000))
                    {
                        string edit1 = accno2 + minis;
                        total_transfer(accno2, transfer, accno, username, pino, linecount1, edit, edit1);
                    }
                    if (transfer <= 1000)
                        cout << "\n Please ensure that the transfer amount is greater than Rs1000 !";

                    if (transfer > 10000)
                        cout << "\n Please ensure that the transfer amount is lesser than Rs10000 !";
                }
                break;

                case 4:                                                    //case to display ATM Balance for Customer/Administrator
                {                             
                    showatmbalance(1234);
                }
                break;

                case 5:
                {
                    mini_display(edit);                                   //case to display the recent 10 transactions
                }
                break;

                default:
                {
                    cout << "\n Please select from the provided options !";
                }
                break;
                }                                                      //option to re-start the atm operations or quit
                cout << endl
                     << "\nPress Y to Re-enter other options for the ATM operation ! \n  Press any other button to Exit !" << endl; 
                cout << endl;
            }
        } while (getch() == 'y');
    }
    break;

    default:
        cout << "\n Please select from the provided options ! \n Re-run the ATM Machine program to use the administrator operations !";
        break;
    }

    cout << "\n\n\n     ***  Thank you for using the ATM Machine   *** \n            !!!--- Have a great day---!!!"<<endl<<endl;               //Final message with greetings

    return 0;
}
