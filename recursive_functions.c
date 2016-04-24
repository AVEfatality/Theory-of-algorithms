#include <stdio.h>
#include <stdlib.h>

int O(int x)
{
  return 0;
}

int S(int x) //функция следования
{
  return (x+1);
}

int P2(int m, int n, int x, int y) //функция выбора для 2 аргументов
{
   if (m == 1)
    return  x;
   if (m == 2)
   return y;
}

int P3(int m, int n, int x, int y, int z) //функция выбора для 3 аргументов
{
   if (m == 1)
    return  x;
   if (m == 2)
   return y;
   if (m == 3)
   return z;
}

int GS(int x, int y, int z) //for summ
{
    int k;
    return (S(k = P3(3,3,x,y,z)));
}

int GM (int x, int y, int z) //for multiplication
{
    int i,j;
    return (SUM(i = P3(1,3,x,y,z), j = P3(3,3,x,y,z)));
}

int GE (int x, int y, int z) //for exp
{
    int i,j;
    return (MUL(i = P3(1,3,x,y,z), j = P3(3,3,x,y,z)));
}

int GT (int x, int y, int z)
{
    int i,j;
    return (EXP(i = P3(1,3,x,y,z), j = P3(3,3,x,y,z)));
}

int GF(int x, int y)
{
    int i,j;
    return (MUL(i = P2(1,2,x,S(x)), j = P2(2,2,x,S(x))));
}

int GD (int x, int y, int z)
{
    int i;
    return (PRED(i = P3(3,3,x,y,z)));
}

int GR(int x,int y,int z)
{
    int i,j,k,t;
    return (MUL(i = S(z),j = SG(k = ABS(y,t=S(z)))));
}

int GMOD(int x,int y ,int z)
{
    int i,j,k;
    return (SUM(z,i=ANTI_SG(j=ABS(y,k=S(z)))));
}

int SUM (int x, int y)
 {
     int Sum,z;
     if (y == 0)
        {
        Sum = P2(1,2,x,y);
        printf ("SUM = %d",Sum);
        return Sum;
        }
     Sum  = GS(x,y-1,z=SUM(x,y-1));
     printf ("SUM = %d\n",Sum);
     return Sum;
 }

int MUL(int x, int y)
{
    int M,z;
    if (y==0)
        {
        M=P2(2,2,x,y);
        printf ("MUL=%d\n",M);
        return M;
        }
    M=GM(x,y-1,z=MUL(x,y-1));
    printf ("MUL=%d\n",M);
    return M;

}

int EXP(int x, int y)
{
    int E,z;
    if (y==0)
        {
            E=S(0);
            printf ("EXP=%d\n",E);
            return E;
        }
    E=GE(x,y-1,z=EXP(x,y-1));
    printf ("EXP=%d\n",E);
    return E;

}

int FAC(int x)
{
    int F,z;
    if (x==0)
        {
            F=S(x);
            printf ("FAC=%d\n",F);
            return F;
        }
    F = GF(x-1,z=FAC(x-1));
    printf ("FAC=%d\n",F);
    return F;
}

int PRED(int x)
{
    int P,z;
    if (x<=0)
        {
            P=0;
            printf ("PRED=%d\n",P);
            return P;
        }
    P = P2(1,2,x-1,z=PRED(x-1));
    printf ("PRED=%d\n",P);
    return P;
}

int DIFF (int x, int y)
{
    int D,z;
    if (y>=x)
        {
            D=0;
            printf ("DIFF=%d\n",D);
            return D;
        }
    if (y==0)
    {
        D=P2(1,2,x,y);
        printf ("DIFF=%d\n",D);
        return D;
    }
    D=GD(x,y-1,z=DIFF(x,y-1));
    printf ("DIFF=%d\n",D);
    return D;
}

int ABS(int x,int y)
{
    int i,j;
    int A;
    i = DIFF(x,y);
    j = DIFF(x,y);
    A = i+j;
    printf ("ABS=%d\n",A);
    return A;
}

int ANTI_SG(int x)
{
     int A_S,z;
     A_S = DIFF(1,z = DIFF(x,0));
     return A_S;
}

int SG(int x)
{
    int Sg,z;
    Sg = DIFF(1,z = ANTI_SG(x));
    printf("SG=%d",Sg);
    return Sg;
}

int REM(int x,int y)
{
     int R,z;
     if (x==0)
        {
            R=0;
            printf("REM=%d\n",R);
            return R;
        }
      R=GR(x-1,y,z=REM(x-1,y));
      printf("REM=%d\n",R);
      return R;
}

int MOD(int x, int y)
{
     int M,z;
     if (x==0)
        {
            M=0;
            printf("MOD=%d\n",M);
            return M;
        }
     M=GMOD(x-1,y,z=MOD(x-1,y));
     printf("MOD=%d\n",M);
     return M;
    }

int main()
{
    int x,y;
    int i;
    do {
     printf ("\nChose what to do:\n1-SUM;\n2-MUL;\n3-EXP;\n4-FAC;\n5-PRED;\n6-DIFF;\n7-ABS;\n8-SG;\n9-ANTI_SG;\n10-REM;\n11-MOD;\n12-HALT.\n");
     scanf("%d",&i);
     printf("\n");
     getchar();
      switch(i){
         case 1:
             {
                  printf("\nEnter x y:\n");
                  scanf("%d",&x);
                  scanf("%d",&y);
                  SUM(x,y);
                  break;
                 }
        case 2:
            {
                  printf("\nEnter x y:\n");
                  scanf("%d",&x);
                  scanf("%d",&y);
                  MUL(x,y);
                  break;
            }
       case 3:
           {
                  printf("\nEnter x y:\n");
                  scanf("%d",&x);
                  scanf("%d",&y);
                  EXP(x,y);
                  break;
            }

        case 4:
            {
                  printf("\nEnter x:\n");
                  scanf("%d",&x);
                  FAC(x);
                  break;
            }
        case 5:
            {
                  printf("\nEnter x:\n");
                  scanf("%d",&x);
                  PRED(x);
                  break;
            }
        case 6:
            {
                  printf("\nEnter x y:\n");
                  scanf("%d",&x);
                  scanf("%d",&y);
                  DIFF(x,y);
                  break;
            }

      case 7:
          {
                  printf("\nEnter x y:\n");
                  scanf("%d",&x);
                  scanf("%d",&y);
                  ABS(x,y);
                  break;
            }
        case 8:
            {
                  printf("\nEnter x:\n");
                  scanf("%d",&x);
                  SG(x);
                  break;
            }
        case 9:
            {
                  printf("\nEnter x y:\n");
                  scanf("%d",&x);
                  ANTI_SG(x);
                  break;
            }
        case 10:
            {
                  printf("\nEnter x y:\n");
                  scanf("%d",&x);
                  scanf("%d",&y);
                  REM(x,y);
                  break;
            }
        case 11:
            {
                  printf("\nEnter x y:\n");
                  scanf("%d",&x);
                  scanf("%d",&y);
                  MOD(x,y);
                  break;
            }

        case 12:
            { return 0;}
        default: printf ("Try again...");
        break;

    }

}
while (i!=12);

}
