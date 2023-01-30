#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<dos.h>
struct date
{
    int month, day, year;
};
struct account
{
    char name[60];
    int acc_no, age;
    char address[60];
    char citizenship[15];
    double phone;
    char acc_type[10];
    float amt;
    struct date dob;
    struct date deposit;
    struct date withdraw;
} add, upd, check, rem, transaction;
void fordelay(int j)
{
    int i, k;
    for (i = 0; i < j; i++)
        k = i;
}
COORD coord = {0, 0};
int main_exit;
void Close(void)
{
    system("cls");
    system("color FD");
    printf("\t\t\033[1;31m   ________________________________________________\n");
    printf("\t\t / \\_______________________________________________\\\n");
    printf("\t\t| @ |________BANK MANAGEMENT SYSTEM PROJECT________|\n");
    printf("\t\t \\_ |______________________________________________|\n");
    printf("\t\t    |                                              |\n");
    printf("\t\t    |                                              |\n");
    printf("\t\t    |                                              |\n");
    printf("\t\t    |\\                                             |\n");
    printf("       _____________| \\                                            |\n");
    printf("  ____|                |                                           |\n");
    printf("  \\   |  \033[1;32mT H A N K\033[1;31m     |                                           |\n");
    printf("   \\  |    \033[1;31mY O U\033[1;31m       |      Md. Rahat Islam Srijon               |\n");
    printf("    \\ |   \033[1;32mV E R Y\033[1;31m      |                  191-15-12895             |\n");
    printf("    / |   \033[1;31mM U C H\033[1;31m      |                                           |\n");
    printf("   /  |_____________   |                                           |\n");
    printf("  /______)          | /                                            |\n");
    printf("\t\t    |/                                             |\n");
    printf("\t\t    |   ___________________________________________|___\n");
    printf("\t\t    |  /______________________________________________/\n");
    printf("\t\t    \\_/______________________________________________/\033[1;35m\n");
    system("pause");
}
void gotoxy(int a, int b)
{
    coord.X = a;
    coord.Y = b;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
float interest(float t, float amount, int rate)
{
    float SI;
    SI = (rate * t * amount) / 100.0;
    return (SI);
}
void new_acc()
{
    system("cls");
    FILE *ptr;
    ptr = fopen("record.dat", "a+");
account_no:
    printf("\n\n\n\t\t\t\033[1;34m    TO CREATE A NEW ACCOUNT:");
    printf("\n\n\n\n\033[1;35m--------->Enter today's date(mm/dd/yyyy):\033[1;33m ");
    printf("\n\n\n\033[1;35m--------------->Enter the account number:\033[1;33m ");
    gotoxy(41, 7);
    scanf("%d/%d/%d", &add.deposit.month, &add.deposit.day, &add.deposit.year);
    gotoxy(41, 10);
    scanf("%d", &check.acc_no);
    while (fscanf(ptr, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", &add.acc_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, add.citizenship, &add.phone, add.acc_type, &add.amt, &add.deposit.month, &add.deposit.day, &add.deposit.year) != EOF)
    {
        if (check.acc_no == add.acc_no)
        {
            printf("\n\n\n\n\n\n");
            printf("\033[0;31m\t\t\t!!Account no. already in use!!\n");
            Beep(5000, 100);
            Beep(3000, 100);
            Beep(5000, 100);
            system("cls");
            goto account_no;
        }
    }
    system("cls");
    add.acc_no = check.acc_no;
    printf("\n\n\n");
    printf("\033[1;36m");
    printf("____________________________ENTER PERSONAL INFORMATION__________________________\n\n\n");
    printf("\033[0;36m");
    printf("__________Enter the name:\n\n");
    printf("__________Enter the date of birth(mm/dd/yyyy):\n\n");
    printf("__________Enter the age:\n\n");
    printf("__________Enter the address:\n\n");
    printf("__________Enter the NID number:\n\n");
    printf("__________Enter the phone number:\n\n\033[1;33m");
    printf("\033[1;36m");
    printf("________________________________________________________________________________\n\n\n");
    printf("\033[1;33m");
    gotoxy(25, 6);
    scanf("%s", add.name);
    gotoxy(46, 8);
    scanf("%d/%d/%d", &add.dob.month, &add.dob.day, &add.dob.year);
    gotoxy(24, 10);
    scanf("%d", &add.age);
    gotoxy(28, 12);
    scanf("%s", add.address);
    gotoxy(31, 14);
    scanf("%s", add.citizenship);
    gotoxy(33, 16);
    scanf("%lf", &add.phone);
    system("cls");
    printf("\033[1;36m");
    printf("\n\n");
    printf("____________________________ENTER ACCOUNT PREFERENCES__________________________\n\n");
    printf("\033[0;36m");
    printf("\nEnter the First amount to deposit(at least 500/- BDT)->");
    printf("\033[1;33m");
    scanf("%f", &add.amt);
    printf("\n");
    printf("\033[0;36m--------------------\033[1;36mType of account:\n\n");
    printf("\033[0;36m---------------------->\033[1;36m#Saving\n\n");
    printf("\033[0;36m---------------------->\033[1;36m#Current\n\n");
    printf("\033[0;36m---------------------->\033[1;36m#Fixed1(for 1 year)\n\n");
    printf("\033[0;36m---------------------->\033[1;36m#Fixed2(for 2 years)\n\n");
    printf("\033[0;36m---------------------->\033[1;36m#Fixed3(for 3 years)\n\n");
    printf("\n\t\t\033[0;36m\"Type\" your choice: ");
    printf("\033[1;33m");
    scanf("%s", add.acc_type);
    fprintf(ptr, "%d ", add.acc_no);
    fprintf(ptr, "%s ", add.name);
    fprintf(ptr, "%d/%d/%d ", add.dob.month, add.dob.day, add.dob.year);
    fprintf(ptr, "%d ", add.age);
    fprintf(ptr, "%s ", add.address);
    fprintf(ptr, "%s ", add.citizenship);
    fprintf(ptr, "%lf ", add.phone);
    fprintf(ptr, "%s ", add.acc_type);
    fprintf(ptr, "%f ", add.amt);
    fprintf(ptr, "%d/%d/%d\n", add.deposit.month, add.deposit.day, add.deposit.year);
    fclose(ptr);
    system("cls");
    printf("\033[1;32m");
    printf("\n\n\n\n\n\n\n\n\n\t\t\t\033[1;32mAccount created successfully!!!!");
    Beep(1200, 100);
    Beep(800, 300);
    Beep(130, 300);
    Beep(800, 300);
}
void loading()
{
    printf("\033[1;37m___________________________________Loading______________________________________\n");
    int i;
    for (i = 0; i < 80; i++)
    {
        fordelay(10000000);
        printf("-");
    }
}
void intro()
{
    system("color CF");
    printf("\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t");
    printf("________________________Welcome\n");
    printf("\t\t\t");
    printf("________________to\n");
    printf("\t\t\t\t");
    printf("________Bank Management System project\n");
    printf("\n\n\n\n\n\n\n\n\n\n\n");
    loading();
    system("cls");
}
void update()
{
    char choice;
    int test = 0;
    FILE *old, *newrec;
    old = fopen("record.dat", "r");
    newrec = fopen("new.dat", "w");
    printf("\n\n\n\t\t\t\033[1;34m    TO CHANGE CUSTOMER'S INFO:");
    printf("\n\n\n\n\t\033[1;35mEnter the account no. of the customer: \033[01;33m ");
    scanf("%d", &upd.acc_no);
    while (fscanf(old, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d", &add.acc_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, add.citizenship, &add.phone, add.acc_type, &add.amt, &add.deposit.month, &add.deposit.day, &add.deposit.year) != EOF)
    {
        if (add.acc_no == upd.acc_no)
        {
again:
            test = 1;
            printf("\n\n\033[1;35m________________Which information do you want to change?\n\n");
            printf("\t\t\t\33[1;32m[A]\033[1;36mAddress\n\n");
            printf("\t\t\t\33[1;32m[P]\033[1;36mPhone\n\n");
            printf("\033[1;35m------->Press your choice \033[01;33m");
            choice = getch();
            system("cls");
            if (choice == 'A' || choice == 'a')
            {
                printf("\n\n\n\n\n\n");
                printf("\t\t\t\033[1;34mEnter the new address: \033[01;33m");
                scanf("%s", upd.address);
                fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, upd.address, add.citizenship, add.phone, add.acc_type, add.amt, add.deposit.month, add.deposit.day, add.deposit.year);
                system("cls");
                printf("\n\n\n\n\n\n\n\n");
                printf("\t\t\t\033[1;32m       Changes saved!!!\n\n\n\n");
            }
            else if (choice == 'P' || choice == 'p')
            {
                printf("\n\n\n\n\n\n");
                printf("\t\t\t\033[1;34mEnter the new phone number: \033[01;33m");
                scanf("%lf", &upd.phone);
                fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, upd.phone, add.acc_type, add.amt, add.deposit.month, add.deposit.day, add.deposit.year);
                system("cls");
                printf("\n\n\n\n\n\n\n\n");
                printf("\t\t\t\033[1;32m       Changes saved!!!\n\n\n\n");
            }
            else
                goto again;
        }
        else
            fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone, add.acc_type, add.amt, add.deposit.month, add.deposit.day, add.deposit.year);
    }
    if (test == 1)
    {
        Beep(600, 100);
        Beep(800, 300);
        Beep(900, 300);
        Beep(800, 300);
    }
    fclose(old);
    fclose(newrec);
    remove("record.dat");
    rename("new.dat", "record.dat");
    if (test != 1)
    {
        system("cls");
        printf("\n\n\n\n\n\n\n\n");
        printf("\t\t\t\033[0;31m       Record not found!!\n\n\n\n");
        Beep(700, 500);
        Beep(300, 500);
invalid:
        printf("\033[0;36m");
        printf("\n\n\n\n\n\n\t\t->Press R to return to the main menu");
        printf("\n\t\t\tT to try again and again\n\n");
        char choice = getch();
        system("cls");
        if (choice == 'R' || choice == 'r')
            return;
        else if (choice == 'T' || choice == 't')
            update();
        else
            goto invalid;
    }
}
void transacto()
{
    char choice;
    int test = 0;
    FILE *old, *newrec;
    old = fopen("record.dat", "r");
    newrec = fopen("new.dat", "w");
    printf("\n\n\n\t\t\t\033[1;34m    TRANSACTIONS");
    printf("\n\n\t\033[1;35mEnter the account no. of the customer: \033[01;33m");
    scanf("%d", &transaction.acc_no);
    while (fscanf(old, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d", &add.acc_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, add.citizenship, &add.phone, add.acc_type, &add.amt, &add.deposit.month, &add.deposit.day, &add.deposit.year) != EOF)
    {
        if (add.acc_no == transaction.acc_no)
        {
            test = 1;
            if (strcmpi(add.acc_type, "fixed1") == 0 || strcmpi(add.acc_type, "fixed2") == 0 || strcmpi(add.acc_type, "fixed3") == 0)
            {
                printf("\n\n\t\t\t\033[0;31mYOU CANNOT DEPOSIT OR WITHDRAW CASH IN FIXED ACCOUNTS!!!!!");
                Beep(700, 500);
                Beep(300, 500);
                system("cls");
            }
            else
            {
                printf("\n\n\t\t\t\033[1;34mDo you want to.....\n\n");
                printf("\033[1;34m------------------------------->\033[1;32m[D]\033[1;36mDeposit\n\n");
                printf("\033[1;34m------------------------------->\033[1;32m[W]\033[1;36mWithdraw\n\n");
                printf("\033[1;34m\t\tPress your choice\n\n");
                choice = getch();
                if (choice == 'D' || choice == 'd')
                {
                    printf("\n\n\t\t\t\033[0;36mEnter the amount you want to deposit:(BDT) \033[01;33m");
                    scanf("%f", &transaction.amt);
                    add.amt += transaction.amt;
                    fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone, add.acc_type, add.amt, add.deposit.month, add.deposit.day, add.deposit.year);
                    system("cls");
                    printf("\n\n\n\n\n\n\n\n");
                    printf("\t\t\t\033[1;32m     Deposited successfully!\n\n\n\n");
                }
                else if (choice == 'W' || choice == 'w')
                {
                    printf("\n\n\t\t\t\033[0;36mEnter the amount you want to withdraw:(BDT) \033[01;33m");
                    scanf("%f", &transaction.amt);
                    add.amt -= transaction.amt;
                    fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone, add.acc_type, add.amt, add.deposit.month, add.deposit.day, add.deposit.year);
                    system("cls");
                    printf("\n\n\n\n\n\n\n\n");
                    printf("\t\t\t\033[1;32m     Withdrawn successfully!\n\n\n\n");
                }
            }
        }
        else
        {
            fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone, add.acc_type, add.amt, add.deposit.month, add.deposit.day, add.deposit.year);
        }
    }
    if (test == 1)
    {
        Beep(600, 100);
        Beep(800, 300);
        Beep(900, 300);
        Beep(800, 300);
    }
    fclose(old);
    fclose(newrec);
    remove("record.dat");
    rename("new.dat", "record.dat");
    if (test != 1)
    {
        system("cls");
        printf("\n\n\n\n\n\n\n\n");
        printf("\t\t\t\033[0;31m       Record not found!!\n\n\n\n");
        Beep(700, 500);
        Beep(300, 500);
invalid:
        printf("\033[0;36m");
        printf("\n\n\n\n\n\n\t\t->Press R to return to the main menu");
        printf("\n\t\t\tT to try again and again\n\n");
        char choice = getch();
        system("cls");
        if (choice == 'R' || choice == 'r')
            return;
        else if (choice == 'T' || choice == 't')
            transacto();
        else
            goto invalid;
    }
}
void display()
{
    FILE *ptr;
    int test = 0, rate;
    char choice;
    float time;
    float intrst;
    ptr = fopen("record.dat", "r");
    printf("\n\n\n\t\t\t\033[1;34m   CHECK AN ACCOUNT");
    printf("\n\n\t\033[1;35mYou want to check by.....\033[01;33m\n\n");
    printf("\t\t\033[1;32m[A]\033[1;36mAccount no.\n\n");
    printf("\t\t\033[1;32m[N]\033[1;36mName\n\n");
    printf("\033[1;34m\t\t\t\t\tPress your choice");
    choice = getch();
    if (choice == 'A' || choice == 'a')
    {
        printf("\033[0;36m\n\n\n\tEnter the account number: \033[01;33m");
        scanf("%d", &check.acc_no);
        while (fscanf(ptr, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d", &add.acc_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, add.citizenship, &add.phone, add.acc_type, &add.amt, &add.deposit.month, &add.deposit.day, &add.deposit.year) != EOF)
        {
            if (add.acc_no == check.acc_no)
            {
                system("cls");
                test = 1;
                printf("\n");
                printf("\033[1;34m_____________________________Account No.:\033[0;36m%d \n\n", add.acc_no);
                printf("\033[1;34m____________________________________Name:\033[0;36m%s \n\n", add.name);
                printf("\033[1;34m___________________________Date of Birth:\033[0;36m%d/%d/%d \n\n", add.dob.month, add.dob.day, add.dob.year);
                printf("\033[1;34m_____________________________________Age:\033[0;36m%d \n\n", add.age);
                printf("\033[1;34m_________________________________Address:\033[0;36m%s \n\n", add.address);
                printf("\033[1;34m__________________________Citizenship No:\033[0;36m%s \n\n", add.citizenship);
                printf("\033[1;34m____________________________Phone number:\033[0;36m%.0lf \n\n", add.phone);
                printf("\033[1;34m_________________________Type Of Account:\033[0;36m%s \n\n", add.acc_type);
                printf("\033[1;34m________________________Amount deposited:\033[0;36m%.2f BDT\n\n", add.amt);
                printf("\033[1;34m_________________________Date Of Deposit:\033[0;36m%d/%d/%d\n\n", add.deposit.month, add.deposit.day, add.deposit.year);
                if (strcmp(add.acc_type, "Fixed1") == 0)
                {
                    time = 1.0;
                    rate = 9;
                    intrst = interest(time, add.amt, rate);
                    printf("You will get BDT %.2f as interest on %d/%d/%d", intrst, add.deposit.month, add.deposit.day, add.deposit.year + 1);
                }
                else if (strcmp(add.acc_type, "Fixed2") == 0)
                {
                    time = 2.0;
                    rate = 11;
                    intrst = interest(time, add.amt, rate);
                    printf("You will get BDT %.2f as interest on %d/%d/%d", intrst, add.deposit.month, add.deposit.day, add.deposit.year + 2);
                }
                else if (strcmp(add.acc_type, "Fixed3") == 0)
                {
                    time = 3.0;
                    rate = 13;
                    intrst = interest(time, add.amt, rate);
                    printf("You will get BDT %.2f as interest on %d/%d/%d", intrst, add.deposit.month, add.deposit.day, add.deposit.year + 3);
                }
                else if (strcmp(add.acc_type, "Saving") == 0)
                {
                    time = (1.0 / 12.0);
                    rate = 8;
                    intrst = interest(time, add.amt, rate);
                    printf("You will get BDT %.2f as interest on %d of every month\n\n", intrst, add.deposit.day);
                }
                else if (strcmp(add.acc_type, "Current") == 0)
                {
                    printf("\n\nYou will get no interest\n\n");
                }
            }
        }
    }
    else if (choice == 'N' || choice == 'n')
    {
        printf("Enter the name:");
        scanf("%s", &check.name);
        while (fscanf(ptr, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d", &add.acc_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, add.citizenship, &add.phone, add.acc_type, &add.amt, &add.deposit.month, &add.deposit.day, &add.deposit.year) != EOF)
        {
            if (strcmpi(add.name, check.name) == 0)
            {
                system("cls");
                test = 1;
                printf("\n");
                printf("\033[1;34m_____________________________Account No.:\033[0;36m%d \n\n", add.acc_no);
                printf("\033[1;34m____________________________________Name:\033[0;36m%s \n\n", add.name);
                printf("\033[1;34m___________________________Date of Birth:\033[0;36m%d/%d/%d \n\n", add.dob.month, add.dob.day, add.dob.year);
                printf("\033[1;34m_____________________________________Age:\033[0;36m%d \n\n", add.age);
                printf("\033[1;34m_________________________________Address:\033[0;36m%s \n\n", add.address);
                printf("\033[1;34m__________________________Citizenship No:\033[0;36m%s \n\n", add.citizenship);
                printf("\033[1;34m____________________________Phone number:\033[0;36m%.0lf \n\n", add.phone);
                printf("\033[1;34m_________________________Type Of Account:\033[0;36m%s \n\n", add.acc_type);
                printf("\033[1;34m________________________Amount deposited:\033[0;36m%.2f BDT\n\n", add.amt);
                printf("\033[1;34m_________________________Date Of Deposit:\033[0;36m%d/%d/%d\n\n", add.deposit.month, add.deposit.day, add.deposit.year);
                if (strcmp(add.acc_type, "Fixed1") == 0)
                {
                    time = 1.0;
                    rate = 9;
                    intrst = interest(time, add.amt, rate);
                    printf("You will get BDT %.2f as interest on %d/%d/%d", intrst, add.deposit.month, add.deposit.day, add.deposit.year + 1);
                }
                else if (strcmp(add.acc_type, "Fixed2") == 0)
                {
                    time = 2.0;
                    rate = 11;
                    intrst = interest(time, add.amt, rate);
                    printf("You will get BDT %.2f as interest on %d/%d/%d", intrst, add.deposit.month, add.deposit.day, add.deposit.year + 2);
                }
                else if (strcmp(add.acc_type, "Fixed3") == 0)
                {
                    time = 3.0;
                    rate = 13;
                    intrst = interest(time, add.amt, rate);
                    printf("You will get BDT %.2f as interest on %d/%d/%d", intrst, add.deposit.month, add.deposit.day, add.deposit.year + 3);
                }
                else if (strcmp(add.acc_type, "Saving") == 0)
                {
                    time = (1.0 / 12.0);
                    rate = 8;
                    intrst = interest(time, add.amt, rate);
                    printf("You will get BDT %.2f as interest on %d of every month\n\n", intrst, add.deposit.day);
                }
                else if (strcmp(add.acc_type, "Current") == 0)
                {
                    printf("\n\nYou will get no interest\n\n");
                }
            }
        }
    }
    if (test == 1)
    {
        Beep(600, 100);
        Beep(800, 300);
        Beep(900, 300);
        Beep(800, 300);
        system("pause");
    }
    fclose(ptr);
    if (test != 1)
    {
        system("cls");
        printf("\n\n\n\n\n\n\n\n");
        printf("\t\t\t\033[0;31m       Record not found!!\n\n\n\n");
        Beep(700, 500);
        Beep(300, 500);
invalid:
        printf("\033[0;36m");
        printf("\n\n\n\n\n\n\t\t->Press R to return to the main menu");
        printf("\n\t\t\tT to try again and again\n\n");
        char choice = getch();
        system("cls");
        if (choice == 'R' || choice == 'r')
            return;
        else if (choice == 'T' || choice == 't')
            display();
        else
            goto invalid;
    }
}
void remov()
{
    FILE *old, *newrec;
    int test = 0;
    old = fopen("record.dat", "r");
    newrec = fopen("new.dat", "w");
    printf("\n\n\n\t\t\t\033[1;34m   TO CLOSE AN ACCOUNT");
    printf("\n\n\t\033[1;35mEnter the account no. of the customer: \033[01;33m");
    scanf("%d", &rem.acc_no);
    while (fscanf(old, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d", &add.acc_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, add.citizenship, &add.phone, add.acc_type, &add.amt, &add.deposit.month, &add.deposit.day, &add.deposit.year) != EOF)
    {
        if (add.acc_no != rem.acc_no)
            fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone, add.acc_type, add.amt, add.deposit.month, add.deposit.day, add.deposit.year);

        else
        {
            test = 1;
            system("cls");
            printf("\n\n\n\n\n\n\n\n");
            printf("\t\t\t\033[1;32mRecord deleted successfully!\n\n\n\n");
        }
    }
    fclose(old);
    fclose(newrec);
    remove("record.dat");
    rename("new.dat", "record.dat");
    if (test == 1)
    {
        Beep(600, 100);
        Beep(800, 300);
        Beep(900, 300);
        Beep(800, 300);
    }
    if (test == 0)
    {
        system("cls");
        printf("\n\n\n\n\n\n\n\n");
        printf("\t\t\t\033[0;31m       Record not found!!\n\n\n\n");
        Beep(700, 500);
        Beep(300, 500);
invalid:
        printf("\033[0;36m");
        printf("\n\n\n\n\n\n\t\t->Press R to return to the main menu");
        printf("\n\t\t\tT to try again and again\n\n");
        char choice = getch();
        system("cls");
        if (choice == 'R' || choice == 'r')
            return;
        else if (choice == 'T' || choice == 't')
            remov();
        else
            goto invalid;
    }
}
void view()
{
    FILE *view;
    view = fopen("record.dat", "r");
    int test = 0;
    system("cls");
    printf("\n");
    printf("\033[1;33m_______________________________CUSTOMER DATABASE________________________________\n");
    printf("\033[1;34mAcc. no.\tName\t\tAddress\t\t\tPhone\n");
    printf("________________________________________________________________________________\n");
    while (fscanf(view, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d", &add.acc_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, add.citizenship, &add.phone, add.acc_type, &add.amt, &add.deposit.month, &add.deposit.day, &add.deposit.year) != EOF)
    {
        printf("\033[0;36m%6d   %10s\t\t%-20s\t %-20.0lf\n", add.acc_no, add.name, add.address, add.phone);
        printf("\033[1;35m________________________________________________________________________________\n");
        test++;
    }
    system("pause");
    fclose(view);
    if (test == 0)
    {
        system("cls");
        printf("\n\n\n\n\n\n\n\n");
        printf("\t\t\t\033[0;31m    No Customers yet!!\n\n\n\n");
        Beep(700, 500);
        Beep(300, 500);
invalid:
        printf("\033[0;36m");
        printf("\n\n\n\n\n\n\t\t->Press R to return to the main menu");
        printf("\n\t\t\tT to try again and again\n\n");
        char choice = getch();
        system("cls");
        return;
    }
}
void menu()
{
    char choice;
    system("cls");
    system("color 9");
    printf("\n\n");
    printf("\t\t     CUSTOMER ACCOUNT BANKING MANAGEMENT SYSTEM\n\n\n");
    printf("________________________________________________________________________________\n\n");
    printf("_______________\33[1;32m[C]\033[1;36m->Create a new account\033[1;34m________________________________________\n\n");
    printf("______________\33[1;32m[U]\033[1;36m-->Update information of an account\033[1;34m____________________________\n\n");
    printf("_____________\33[1;32m[T]\033[1;36m--->For transactions\033[1;34m____________________________________________\n\n");
    printf("____________\33[1;32m[D]\033[1;36m---->Check the details of an account\033[1;34m_____________________________\n\n");
    printf("___________\33[1;32m[R]\033[1;36m----->Removing an account\033[1;34m_________________________________________\n\n");
    printf("__________\33[1;32m[V]\033[1;36m------>View customer's list\033[1;34m________________________________________\n\n");
    printf("_________\33[1;32m[E]\033[1;36m------->Exit the program\033[1;34m____________________________________________\n\n");
    printf("________________________________________________________________________________\n\n");
    choice = getch();
    system("cls");
    if (choice == 'C' || choice == 'c')
        new_acc();
    else if (choice == 'U' || choice == 'u')
        update();
    else if (choice == 'T' || choice == 't')
        transacto();
    else if (choice == 'D' || choice == 'd')
        display();
    else if (choice == 'R' || choice == 'r')
        remov();
    else if (choice == 'V' || choice == 'v')
        view();
    else if (choice == 'E' || choice == 'e')
        return;
    menu();
}
void admin_login()
{
    system("cls");
    system("color C");
    char Pass[6], Name[50];
    int i = 0;
    printf("\n\n\n\n\n\n\n\n");
    printf("__________________________________ADMIN_LOGIN___________________________________\033[1;32m\n\n\n");
    printf("------------------------>Enter Nickname  :\n\n");
    printf("------------------------>Enter Password  :\033[1;31m\n\n");
    printf("________________________________________________________________________________\033[1;33m\n\n\n");
    gotoxy(42, 11);
    scanf("%s", Name);
    gotoxy(42, 13);
    getchar();
    for (;;)
    {
        Pass[i] = getch();
        if (Pass[i++] == 13)
            break;
        printf("*");
    }
    Pass[5] = '\0';
    printf("\n\n\n\n");
    loading();
    if (!strcmp(Pass, "admin"))
    {
        system("cls");
        printf("\n\n\n\n\n\n\n\n");
        printf("\t\t\t\033[0;32m       Password Matched!!\n\n\n\n");
        Beep(500, 100);
        Beep(600, 200);
        Beep(700, 400);
        menu();
    }
    else
    {
        system("cls");
        printf("\n\n\n\n\n\n\n\n");
        printf("\t\t\t\033[0;31m       Wrong Password!!!\n\n\n\n");
        Beep(700, 100);
        Beep(300, 500);
        admin_login();
    }
    system("cls");
    return;
}
void login()
{

    system("cls");
    char choice;
    system("color 5F");
    printf("\n\n\n\n\n");
    printf("                           ENTER BANK SYSTEM\n");
    printf("                                           |\n");
    printf("                                           |\n");
    printf("___________________________________________|____________________________________\n\n");
    printf("                                           A. Admin mode login\n\n");
    printf("                                           E. Exit program\n\n");
    printf("________________________________________________________________________________\n\n\n\n\n\n\n");
    choice = getch();
    if (choice == 'A' || choice == 'a')
        admin_login();
    else if (choice == 'E' || choice == 'e')
        return;
    else
        login();
    return;
}
int main()
{
    intro();
    login();
    Close();
    return 0;
}
