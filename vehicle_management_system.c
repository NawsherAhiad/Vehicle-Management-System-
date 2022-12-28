#include<stdio.h>

struct vehicle
{
    int vehicle_id;
    char vehicle_name[50];
    char vehicle_manufacturer_name[50];
    int day;
    int month;
    int year;
};
struct vehicle v[1000];
int v_index=0;


///username and password
char username[]="cse103";
char password[]="cse103";



void updateCredential()
{
    system("cls");
    head_Message("UPDATE CREDENTIAL");

    char new_username[50];
    char new_pwd[50];
    int user_validity=0;

    do
    {
        printf("    New User name: ");
        getchar();
        gets(new_username);


        user_validity=is_Name_Valid(new_username);

        if(user_validity==1)
        {
            printf("    invalid username! \n");
        }
    }
    while(user_validity==1);

    printf("    New Password: ");
    gets(new_pwd);



    memcpy(username,new_username, strlen(new_username) * sizeof(char));
    memcpy(password,new_pwd, strlen(new_pwd) * sizeof(char));

    printf("    Your credential has been changed.....\n");
    printf("    login Again-->");
    char anykey;
    getchar();
    scanf("%c",&anykey);
    login();




}
void deleteVehicles()
{
    system("cls");
    head_Message("DELETE VEHICLE DETAILS");
    printf("    Enter vehicle ID NO to delete: ");
    int del_id;
    scanf("%d", &del_id);

    int flag=0;
    for(int i=0; i<v_index; i++)
    {
        if(del_id==v[i].vehicle_id)
        {
            flag=1;
            for(int j=i; j<v_index; j++)
            {
                v[j].vehicle_id=v[j+1].vehicle_id;
                memcpy(v[j].vehicle_name, v[j+1].vehicle_name, strlen(v[j].vehicle_name) * sizeof(char));
                memcpy(v[j].vehicle_manufacturer_name, v[j+1].vehicle_manufacturer_name, strlen(v[j].vehicle_manufacturer_name) * sizeof(char));
                v[j].day=v[j+1].day;
                v[j].month=v[j+1].month;
                v[j].year=v[j+1].year;

            }
            v_index--;
        }
    }

    if(flag==0)
    {
        printf("    Record not found\n");
    }
    else
    {
        printf("    Record deleted successfully.....\n");

    }
    getchar();
    printf("\n\nEnter any key to continue.....");
    char anykey;
    scanf("%c",&anykey);


}

void viewVehicles()
{
    system("cls");
    head_Message("VIEW VEHICLE DETAILS");

    if(v_index>0)
    {
        for(int i=0; i<v_index; i++)
        {
            printf("    Vehicle Count = %d\n\n", i+1);
            printf("    Vehicle id= %d\n", v[i].vehicle_id);
            printf("    Vehicle Name= %s\n",v[i].vehicle_name);
            printf("    vehicle Manufacturer Name = %s\n", v[i].vehicle_manufacturer_name);
            printf("    Vehicle issued date by Manufacturer(day/ month/year) = (%d/%d/%d)\n\n",v[i].day, v[i].month, v[i].year );
        }
    }
    else
    {
        printf("    No record\n");

    }
    char anykey;
    printf("    Enter any key to continue.....\n");
    getchar();
    scanf("%c",&anykey);
    system("cls");


}
void searchVehicles()
{
    system("cls");
    head_Message("SEARCH VEHICLE");
    printf("    Enter vehicle name to search: ");
    getchar();
    char v_name[50];
    gets(v_name);

    int flag;
    for(int i=0; i<v_index; i++)
    {
        flag=0;
        for(int j=0; j<strlen(v[i].vehicle_name); j++)
        {

            if(v_name[j] != v[i].vehicle_name[j])
            {
                flag=1;
                break;
            }
        }

        if(flag==0)
        {

            printf("\n    Vehicle id= %d\n", v[i].vehicle_id);
            printf("    Vehicle Name= %s\n",v[i].vehicle_name);
            printf("    vehicle Manufacturer Name = %s\n", v[i].vehicle_manufacturer_name);
            printf("    Vehicle issued date by Manufacturer(day/ month/year) = (%d/%d/%d)\n\n",v[i].day, v[i].month, v[i].year );
            break;
        }
    }

    printf("Enter any key to continue.....");
    char anykey;
    getchar();
    printf("%c", &anykey);






}
int isvaliddate( int day, int month, int year)
{
    if((day>=1 && day<=31 ) &&( month>=1 && month<=12) && (year>=2000 && year<=2100))
    {
        return 0;
    }
    else
    {
        return 1;
    }
}



void addVehicleInDataBase( int i)
{
    system("cls");
    head_Message("ADD NEW VEHICLE");


    printf("    ENTER VEHICLE DETAILS BELOW:\n");
    printf("    --------------------------------------------------------------------\n");

    printf("    Vehicle ID NO = ");
    scanf("%d", &v[i].vehicle_id);

    int user_validity=0;

    do
    {
        getchar();
        printf("\n    Vehicle Name = ");
        gets(v[i].vehicle_name);


        user_validity=is_Name_Valid(v[i].vehicle_name);

        if(user_validity==1)
        {
            printf("    Invalid Vehicle name! \n");
        }
    }
    while(user_validity==1);


    user_validity=0;
    do
    {
        //getchar();
        printf("\n    Vehicle Manufacturer Name: ");
        gets(v[i].vehicle_manufacturer_name);



        user_validity=is_Name_Valid(v[i].vehicle_manufacturer_name);

        if(user_validity==1)
        {
            printf("    Invalid Manufacturer Name! \n");
        }
    }
    while(user_validity==1);




    int date_validity=0;
    do
    {
        printf("\n    Vehicle issued date by Manufacturer");
        printf("\n    Day: ");
        scanf("%d", &v[i].day);
        printf("\n    Month: ");
        scanf("%d", &v[i].month);

        printf("\n    year: ");
        scanf("%d", &v[i].year);
        date_validity=isvaliddate(v[i].day, v[i].month, v[i].year);
        if(date_validity==1)
        {
            printf("    Invalid date\n");
        }

    }while(date_validity==1);

}






int is_Name_Valid(char name[])
{

    ///checking ascii value of alphabets
    int flag=0;
    for(int i=0; name[i]!='\0'; i++)
    {
        if(!((name[i]>=65 && name[i]<=90) || (name[i]>=97 && name[i]<=122) || name[i]==' ' || (name[i]>='0' && name[i]<='9')))
        {
            flag=1;
            break;
        }
    }
    return flag;

}

void welcome_message()
{
    printf("\n\n");
    printf("          ########################################################\n\n");
    printf("                ############################################\n");
    printf("                ##                  WELCOME               ##\n");
    printf("                ##                     TO                 ##\n");
    printf("                ##                  VEHICLE               ##\n");
    printf("                ##                 MANAGEMENT             ##\n");
    printf("                ##                   SYSTEM               ##\n");
    printf("                ############################################\n");
    printf("          ########################################################\n\n");

    char anykey;
    printf("    Enter any key to continue.....\n");
    scanf("%c",&anykey);
    system("cls");
    login();

}



void head_Message( char message[])
{
    printf("    ####################################################################\n");
    printf("    ####################################################################\n");
    printf("    ##############                                       ###############\n");
    printf("    ##############       Vehicle Management System       ###############\n");
    printf("    ##############                                       ###############\n");
    printf("    ####################################################################\n");
    printf("    ####################################################################\n");
    printf("\n");
    print_Message_in_Center(message);

}

void print_Message_in_Center(char message[])
{
    printf("    ####################################################################\n");
    printf("                               %s                                       \n",message);
    printf("    ####################################################################\n");

}

void login()
{
    system("cls");
    head_Message("Login");

    char user_name[50];
    char pwd[50];

    int user_validity=0;
    do
    {
        printf("\n\n    User name: ");
        gets(user_name);
        printf("\n    Password: ");
        gets(pwd);

        user_validity=is_Name_Valid(user_name);

        if(user_validity==1)
        {
            printf("    invalid username! \n");
        }
        else
        {

            for(int i=0; user_name[i]!='\0'; i++)
            {
                if(username[i] != user_name[i])
                {
                    printf("    wrong username!\n");
                    user_validity=1;
                    break;
                }
            }


            for(int i=0; pwd[i]!='\0'; i++)
            {
                if(pwd[i]!=password[i])
                {
                    printf("    wrong password!\n");
                    user_validity=1;
                    break;
                }
            }

        }

    }
    while(user_validity==1);

    if(user_validity!=1)
    {
        menu();

    }

}
void menu()
{

    int choice;
    do
    {
        system("cls");
        head_Message("Menu");

        printf("    1.Add Vehicle\n");
        printf("    2.Search Vehicles\n");
        printf("    3.View Vehicles\n");
        printf("    4.Delete Vehicle\n");
        printf("    5.Update Password\n");
        printf("    6.Exit\n");
        printf("\n\n    Enter Choice: ");
        scanf("%d",&choice);

        if(choice==1)
        {
            addVehicleInDataBase(v_index);
            v_index++;
        }
        else if (choice==2)
        {

            searchVehicles();

        }
        else if (choice==3)
        {
            viewVehicles();
        }
        else if (choice==4)
        {

            deleteVehicles();
        }
        else if (choice==5)
        {
            updateCredential();
        }
        else if (choice==6)
        {
            printf("                                                Thank you!!!");
        }

    }
    while(choice!=6);

}

int main()
{
    head_Message("CSE 103");
    welcome_message();

}
