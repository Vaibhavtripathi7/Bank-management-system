#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

void gotoxy(int x, int y){
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void accountcreated(void);
void display(char*);
void transfermoney(void);
void login(void);
void logout(void);
void loginsu(void);
void checkbalance(char*);
void account(void);

struct userdata{
    
    char username[20];
    int date, month, year;
    char pnum[20];
    char aadharnum[20];
    char fathername[20];
    char mothername[20];
    char firstname[20];
    char lastname[20];
    char acctype[20];
    char address[20];
    int amt;
};
struct userpass
{
    char pass[20];
};

struct money {
    char usernameto[20];
    char userpersonfrom[20];
    long int money1;
};

void account(){
    char password[20];
    char ps;
    struct userdata c1;
    struct userpass p1;

    FILE *up1;
    up1 = fopen("username2.bin", "ab");

    system("cls");
    
    printf("\n\n\t\tCREATE ACCOUNT");

    printf("\n\nENTER FIRST NAME");
    scanf("%s",c1.firstname);

    printf("\n\nENTER LAST NAME");
    scanf("%s",c1.lastname);

    printf("\n\nENTER FATHERS NAME");
    scanf("%s",c1.fathername);

    printf("\n\nENTER MOTHERS NAME");
    scanf("%s",c1.mothername);

    printf("\n\nENTER AADHAR NUMBER");
    scanf("%s", c1.aadharnum);
    
    printf("\nENTER PHONE NUMBER");
    scanf("%s", c1.pnum);

    printf("\nENTER ADDRESS");
    scanf("%s", c1.address);

    printf("\nENTER DOB\n");

    printf("DATE");
    scanf("%d", &c1.date);
    
    printf("\nMONTH");
    scanf("%d", &c1.month);
    
    printf("\nYEAR");
    scanf("%d", &c1.year);

    printf("\nENTER USERNAME");
    scanf("%s", &c1.username);

    printf("\nENTER ACCOUNT TYPE ");
    scanf("%s", &c1.acctype);

    int i;
    printf("CREATE PASSWORD -");
    for(i= 0;i<20;i++){
        ps = getch();
        if (ps != 13){
            password[i] = ps ;
            ps = '*';
            printf("*");
        }
        else{
            break;
        }
    }
    fwrite(&c1,1,sizeof(c1),up1);
    fwrite(&p1,1,sizeof(p1),up1);
    fclose(up1);
    accountcreated();
}

void login(){
    system("cls");

    char password[20];
    char username[20];

    FILE *up1;
    struct userdata c1;
    struct userpass p2;

    up1= fopen("username2.bin","r");
    
    printf("ACCOUNT LOGIN");

    printf("enter username");
    scanf("%s",&username);

    printf("enter password");
    scanf("%s", &password);

    while (fread(&c1, 1, sizeof(c1),up1)){
        if (strcmp(username,c1.username)==0 ){
            system("cls");
            printf("Fetching account details.....\n");
            gotoxy(30, 10);
            printf("LOGIN SUCCESSFUL....");
            gotoxy(0, 20);
            printf("Press enter to continue");
            getch();
            display(username);
        }
        else{
            printf("nothing");
        }
    fclose(up1);
    }}

int main(){
    int i, choice;

    gotoxy(20, 3);
    printf("WELCOME TO BANK ACCOUNT SYSTEM\n\n");
 
    gotoxy(25, 10);
    printf("1. CREATE A BANK ACCOUNT");
 
    gotoxy(25, 12);
    printf("\n2. ALREADY A USER? SIGN IN");

    gotoxy(25, 14);
    printf("\n3. EXIT\n\n");
 
    printf("\nENTER YOUR CHOICE--");
    scanf("%d", &choice);
 
    switch (choice) {
    case 1:
        system("cls");
        account();
        break;
 
    case 2:
        login();
        break;
 
    case 3:
        exit(0);
        printf("press enter to exit");
        break;
    }
}


void display(char username1[])
{
    system("cls");
    FILE* up1;
    int choice, i;
    up1 = fopen("username2.txt", "r");
    struct userdata c1;
    if (up1 == NULL) {
        printf("error in opening file");
    }

    while (fread(&c1, 1,sizeof(c1), up1)) {
        if (strcmp(username1,  c1.username) == 0) {
            printf("WELCOME, %s %s",  c1.firstname, c1.lastname);
            
            printf("YOUR ACCOUNT INFO ");
            
            printf("NAME--%s %s", c1.firstname, c1.lastname);
 
            printf("FATHER's NAME--%s %s", c1.fathername,  c1.lastname);
 
            printf("MOTHER's NAME--%s",  c1.mothername);
 
            printf("ADHAR CARD NUMBER--%s",   c1.aadharnum);
 
            printf("MOBILE NUMBER--%s",c1.pnum);
 
            printf("DATE OF BIRTH-- %d//%d//%d", c1.date, c1.month, c1.year);
 
            printf("ADDRESS--%s", c1.address);
 
            printf("ACCOUNT TYPE--%s",  c1.acctype);
        }
    }
 
    fclose(up1);
 
    printf(" HOME ");
    printf(" 1.CHECK BALANCE\n");
    printf(" 2.TRANSFER MONEY\n");
    printf(" 3.LOG OUT\n");
    printf(" 4.EXIT\n");
    printf(" ENTER YOUR CHOICES..");
    scanf("%d", &choice);
 
    switch (choice) {
    case 1:
        checkbalance(username1);
        break;
 
    case 2:
        transfermoney();
        break;
 
    case 3:
        logout();
        login();
        break;
 
    case 4:
        exit(0);
        break;
    }
}


void transfermoney(void)
{
    FILE *fm, *up1;
    int i, j;
    struct userdata c1;
    struct money m1;
    char usernamet[20];
    char usernamep[20];
    system("cls");
 
    up1 = fopen("username2.bin", "rb");
    fm = fopen("mon.txt", "ab");
 
    printf("---- TRANSFER MONEY ----");
    
    printf("FROM ");
    scanf("%s", &usernamet);
 
    printf(" TO ");
    scanf("%s", &usernamep);
 
    while (fread(&c1, sizeof(c1),  1, up1)) {
        if (strcmp(usernamep,  c1.username)   == 0) {
            strcpy(m1.usernameto,  c1.username);
            strcpy(m1.userpersonfrom,  usernamet);
        }
    }
 
    printf("ENTER THE AMOUNT TO BE TRANSFERRED..");
    scanf("%d", &m1.money1);
 
    fwrite(&m1, sizeof(m1),   1, fm);
 
    printf("transferring amount, Please wait..");

    printf("AMOUNT SUCCESSFULLY TRANSFERRED....");
    getch();
 
    fclose(up1);
    fclose(fm);

    display(usernamet);
}
/*void transfermoney(void){
    struct userdata c1;
    struct userpass p1;
    FILE *up1;
    up1 = fopen("userdata.txt","r");
    int amount ;
    char username2[];
    char username3[];
    struct money d1;
    printf("from --");
    scanf("%s",&username2);
    printf("to --");
    scanf("%s",&username3);
    printf("amount --");
    scanf("%d",&amount);
    while (fread(&c1, 1,sizeof(c1), up1)
    {  
        if (strcmp(username3,c1.username)==0){
            system("cls");
1            d1.money = money + amount;
        }
    }
    

}*/

void checkbalance(char username2[])
{
    system("cls");
    FILE* fm;
    struct money m1;
    char ch;
    int i = 1, summoney = 0;
 
    fm = fopen("mon.txt", "rb");
 
    int k = 5, l = 10;
    int m = 30, n = 10;
    int u = 60, v = 10;
 
    gotoxy(30, 2);
    printf("==== BALANCE DASHBOARD ====");
    gotoxy(30, 3);
    printf("***************************");
    gotoxy(k, l);
    printf("S no.");
    gotoxy(m, n);
    printf("TRANSACTION ID");
    gotoxy(u, v);
    printf("AMOUNT");
 
    while (fread(&m1, sizeof(m1),  1, fm)) {
        if (strcmp(username2,   m1.usernameto)  == 0) {
            gotoxy(k, ++l);
            printf("%d", i);
            i++;
            gotoxy(m, ++n);
            printf("%s", m1.userpersonfrom);
 
            gotoxy(u, ++v);
            printf("%d", m1.money1);
            summoney = summoney + m1.money1;
        }
    }
 
    gotoxy(80, 10);
    printf("TOTAL AMOUNT");
 
    gotoxy(80, 12);
    printf("%d", summoney);
 
    getch();
 
    fclose(fm);
    display(username2);
}
 

void logout(void)
{
    system("cls");
    printf("please wait, logging out");
 
    gotoxy(30, 10);
    printf("Sign out successfully..\n");
 
    gotoxy(0, 20);
    printf("press any key to continue..");
    getch();
}


void loginsu(void)
{
    system("cls");
    printf("Fetching account details.....\n");
 
    gotoxy(30, 10);
    printf("LOGIN SUCCESSFUL....");
    gotoxy(0, 20);
    printf("Press enter to continue");
    getch();
}

void accountcreated(void){
    system("cls");
    printf( "PLEASE WAIT....\nYOUR DATA IS PROCESSING....");
    gotoxy(30, 10);
 
    printf("ACCOUNT CREATED SUCCESSFULLY....");
    gotoxy(0, 20);
 
    printf("Press enter to login");
    getch();
    login();
}