#include <stdio.h>
#include <string.h>

void add_null (char Tape[200], int Pos)
{
  if (Tape[Pos] == '\0')
    {Tape[Pos] = '0';
    Tape[Pos+1] = '\0';}
}

void Input (char Tape[200], char s[100])
{
   printf ("Enter number:");
   scanf ("%s",s);
   strcpy(Tape,s);

}

void Addition()
{
int i;
int q = 1;
int Pos = 0;
char a;
char Tape1[200] = "";
char s1[80];
    Input(Tape1,s1);
    Pos = strlen(Tape1) - 2;
    puts(Tape1);
    a = Tape1[Pos];
        while (q != 0)
        {
            a = Tape1[Pos];
            switch (q)
            {
            case 1:
                switch (a)
                {
                case ('0') :
                    Tape1[Pos] = '1';
                    Pos--;
                    q = 2;
                    break;
                case ('1') :
                    Tape1[Pos] = '1';
                    Pos--;
                    q = 1;
                    break;
                }
                break;
            case 2:
                switch (a)
                {
                case ('0') :
                    q = 3;
                    Tape1[Pos] = '0';
                    Pos++;
                    break;
                case ('1') :
                    q = 2;
                    Tape1[Pos] = '1';
                    Pos--;
                    break;
                }
                break;
            case 3:
                switch (a)
                {
                case ('1') :
                    q = 4;
                    Tape1[Pos] = '0';
                    Pos++;
                    break;
                }
                break;
            case 4:
                switch (a)
                {
                case ('0') :
                    Tape1[Pos] = '1';
                    Pos++;
                    q = 4;
                    break;
                case ('1') :
                    Pos--;
                    q = 0;
                    break;

                }
            }
            puts(Tape1);
            for (i = Pos; i > 0; i--) putchar(' ');
            putchar('^');
            printf("\nstate Q%d\n", q);
            getch();
        }
        printf("\nThis is the end!\n");
        puts (Tape1);
        getch();
}

void Multiplication ()
{
int i;
int q = 1;
int Pos = 0;
char b;
char Tape2[200];
char s2[80];
    Input (Tape2,s2);
    Pos = strlen(Tape2) - 2;
    puts(Tape2);
    b = Tape2[Pos];
        while (q != 0)
        {
            b = Tape2[Pos];
            switch (q)
            {
            case 1:
                switch (b)
                {
                case ('0') :
                    Tape2[Pos] = '0';
                    Pos++;
                    q = 6;
                    add_null(Tape2,Pos);
                    break;
                case ('1') :
                    Tape2[Pos] = '0';
                    Pos++;
                    q = 2;
                    add_null(Tape2,Pos);
                    break;
                }
                break;
            case 2:
                switch (b)
                {
                case ('0') :
                    q = 3;
                    Tape2[Pos] = '1';
                    Pos++;
                    add_null(Tape2,Pos);
                    break;
                }
                break;
            case 3:
                switch (b)
                {
                case ('0'):
                    q = 4;
                    Tape2[Pos] = '1';
                    Pos--;
                    add_null(Tape2,Pos);
                    break;
                case ('1') :
                    q = 3;
                    Tape2[Pos] = '1';
                    Pos++;
                    add_null(Tape2,Pos);
                    break;
                }
                break;
            case 4:
                switch (b)
                {
                case ('1') :
                    q = 5;
                    Tape2[Pos] = '1';
                    Pos--;
                    add_null(Tape2,Pos);
                    break;
                }
                break;
           case 5:
                switch (b)
                {
                case ('0') :
                    q = 1;
                    Tape2[Pos] = '0';
                    Pos--;
                    add_null(Tape2,Pos);
                    break;
                case ('1') :
                    q = 5;
                    Tape2[Pos] = '1';
                    Pos--;
                    add_null(Tape2,Pos);
                    break;
                }
                break;
            case 6:
                switch (b)
                {
                case ('0') :
                    q = 7;
                    Tape2[Pos] = '0';
                    Pos++;
                    add_null(Tape2,Pos);
                    break;
                }
                break;
            case 7:
                switch (b)
                {
                case ('0') :
                    q = 0;
                    Tape2[Pos] = '0';
                    Pos--;
                    add_null(Tape2,Pos);
                    break;
                case ('1') :
                    q = 7;
                    Tape2[Pos] = '1';
                    Pos++;
                    add_null(Tape2,Pos);
                    break;

                }
            }
            puts(Tape2);
            for (i = Pos; i > 0; i--) putchar(' ');
            putchar('^');
            printf("\nstate Q%d\n", q);
            getch();
        }
        printf("\nThis is the end!");
        getch();
}

void Division()
{
   int i;
int q = 1;
int Pos = 0;
char c;
char Tape3[200] = "";
char s3[80];
   Input (Tape3,s3);
    Pos = strlen(Tape3) - 2;
    puts(Tape3);
    c = Tape3[Pos];
    while (q != 0)
        {
            c = Tape3[Pos];
            switch (q)
            {
            case 1:
                switch (c)
                {
                case ('0') :
                    Tape3[Pos] = '0';
                    Pos++;
                    q = 3;
                    add_null(Tape3,Pos);
                    break;
                case ('1') :
                    Tape3[Pos] = '1';
                    Pos--;
                    q = 2;
                    add_null(Tape3,Pos);
                    break;
                }
                break;
            case 2:
                switch (c)
                {
                case ('0') :
                    Tape3[Pos] = '0';
                    Pos--;
                    q = 2;
                    add_null(Tape3,Pos);
                    break;
                case ('1') :
                    q = 1;
                    Tape3[Pos] = '0';
                    Pos--;
                    add_null(Tape3,Pos);
                    break;
                }
                break;
            case 3:
                switch (c)
                {
                case ('0'):
                    q = 3;
                    Tape3[Pos] = '0';
                    Pos++;
                   add_null(Tape3,Pos);
                    break;
                case ('1') :
                    q = 4;
                    Tape3[Pos] = '0';
                    Pos++;
                    add_null(Tape3,Pos);
                    break;
                }
                break;
            case 4:
                switch (c)
                {
                case ('0') :
                    q = 5;
                    Tape3[Pos] = '0';
                    Pos++;
                    add_null(Tape3,Pos);
                    break;
                case ('1') :
                    q = 4;
                    Tape3[Pos] = '1';
                    Pos++;
                    add_null(Tape3,Pos);
                    break;
                }
                break;
           case 5:
                switch (c)
                {
                case ('0') :
                    q = 6;
                    Tape3[Pos] = '0';
                    Pos--;
                    add_null(Tape3,Pos);
                    break;
                case ('1') :
                    q = 4;
                    Tape3[Pos] = '1';
                    Pos++;
                    add_null(Tape3,Pos);
                    break;
                }
                break;
            case 6:
                switch (c)
                {
                case ('0') :
                    q = 7;
                    Tape3[Pos] = '0';
                    Pos--;
                   add_null(Tape3,Pos);
                    break;
                }
                break;
            case 7:
                switch (c)
                {
                case ('0') :
                    q = 8;
                    Tape3[Pos] = '1';
                    Pos--;
                    add_null(Tape3,Pos);
                    break;
                case ('1') :
                    q = 7;
                    Tape3[Pos] = '1';
                    Pos--;
                    add_null(Tape3,Pos);
                    break;

                }
                break;
                case 8:
                switch (c)
                {
                case ('0') :
                    q = 0;
                    Tape3[Pos] = '0';
                    Pos--;
                    add_null(Tape3,Pos);
                    break;
                case ('1') :
                    Tape3[Pos] = '1';
                    Pos--;
                    q = 9;
                    add_null(Tape3,Pos);
                    break;
                }
                break;
            case 9:
                switch (c)
                {
                case ('0') :
                    q = 10;
                    Tape3[Pos] = '0';
                    Pos--;
                    add_null(Tape3,Pos);
                    break;
                }
                break;
            case 10:
                switch (c)
                {
                case ('0') :
                    q = 13;
                    Tape3[Pos] = '0';
                    Pos++;
                    add_null(Tape3,Pos);
                    break;
                case ('1'):
                    q = 11;
                    Tape3[Pos] = '1';
                    Pos--;
                   add_null(Tape3,Pos);
                    break;
                }
                break;
            case 11:
                switch (c)
                {
                case ('0') :
                    q = 12;
                    Tape3[Pos] = '0';
                    Pos--;
                    add_null(Tape3,Pos);
                    break;
                }
                break;
           case 12:
                switch (c)
                {
                case ('0') :
                    q = 1;
                    Tape3[Pos] = '0';
                    Pos--;
                    add_null(Tape3,Pos);
                    break;
                case ('1') :
                    q = 11;
                    Tape3[Pos] = '1';
                    Pos--;
                    add_null(Tape3,Pos);
                    break;
                }
            case 13:
                switch (c)
                {
                case ('0') :
                    q = 14;
                    Tape3[Pos] = '0';
                    Pos++;
                    add_null(Tape3,Pos);
                    break;
                }
                break;
            case 14:
                switch (c)
                {
                case ('0') :
                    q = 0;
                    Tape3[Pos] = '1';
                    Pos++;
                    add_null(Tape3,Pos);
                    break;
                case ('1') :
                    q = 14;
                    Tape3[Pos] = '0';
                    Pos--;
                    add_null(Tape3,Pos);
                    break;
                }

            }
            puts(Tape3);
            for (i = Pos; i > 0; i--) putchar(' ');
            putchar('^');
            printf("\nstate Q%d\n", q);
            getch();
        }
        printf("\nThis is the end!");
        getch();
}

int main()
{ int choice;
do{
printf ("\nEnter:\n1-Addition\n2-Multiplication\n3-Division\n4-Exit\n");
scanf ("%d",&choice);
                switch (choice)
                    {case 1:Addition();
                    break;
                    case 2:Multiplication();
                    break;
                    case 3:Division();
                    break;
                    case 4: printf ("Have a nice day!");
                    return 0;
                    default: printf ("Try again...");
                    break;
                    }
} while (choice != 4);
return 0;
}
