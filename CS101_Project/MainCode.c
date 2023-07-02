#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include "patwriting.h"
char username[50],P[3];
int R,L=1,marks[3],percentage[3],J=0,final_score(int corrects,int wrongs,int unattempted),strength(),change_password();
void registration(),login_details(),newuser(),Guidelines(),Best_score(),review(),reattempt(),quiz_analytics(),warning(),start(),navigation_menu(),clear();
void clear()
{
    getch();
    system("cls");
}
void warning()
{
    system("COLOR E4");
    printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tPlease select a valid option!!\n");
    clear();
}
void registration()
{
    char m;
    system("COLOR E1");
    printf("\n\n\n\n\n\n\n\t\t\t\t\tARE YOU A NEW USER?\n\t\t\t\t\t(Enter Y for yes and N for no)\n\n\n\t\t\t\t\tYour choice : ");
    m = toupper(getch());
    printf("%c",m);
    clear();
    if(m=='Y')
      {
        newuser();
      }
    else if(m=='N')
      {
        login_details();
      }
    else
    {
        warning();
        registration();
    }
    clear();
}
void newuser()
{
    system("COLOR E1");
    FILE *f;
    char line[100],s[25][100],p[100];
    f=fopen("passwords.txt","a+");
    int i,j=0,k,z=0,count=0,check;
    printf("\n\n\n\n\n\n\n\t\t\t\tPassword requirements\n\n\t\t\t\t>> Length should be 4-10 characters\n\n\t\t\t\t>> No spaces should be there in password");
    printf("\n\n\t\t\t\tCreate your password (enter here) : ");
    fgets(p,99,stdin);
    for (z=0;z<strlen(p);z++)
    {
    	if(p[z]==' ')
    	{
    	    count++;
    	    clear();
    	    system("COLOR E4");
            printf("\n\n\n\n\n\n\n\t\t\t\tentered password is not satisfying password requirements\n");
            printf("\n\t\t\t\tplease choose a valid password");
            clear();
            system("COLOR E1");
            newuser();
		}
	}
    if(!(strlen(p)>=5&&strlen(p)<=11))
    {
        count++;
        clear();
        system("COLOR E4");
        printf("\n\n\n\n\n\n\n\t\t\t\tentered password is not satisfying password requirements\n");
        printf("\n\t\t\t\tplease choose a valid password");
        clear();
        system("COLOR E1");
        newuser();
    }
    while(fgets(line,99,f)!= NULL)
    {
        strcpy(s[j],line);
        j++;
    }
    if(count==0)
    {
        check = strength(p);
        if (check == 0)
        {
            system("COLOR E1");
            printf("\n\n\t\t\t\t\tRegistered successfully!\n\n");
            printf("\t\t\t\t\tYour Roll number : %d\n\n\t\t\t\t\tRemember your Roll number for future purpose",j+1);
            fprintf(f,"%s",p);
            fclose(f);
            clear();
            login_details();
        }
    }
}
int strength(char *s)
{
    int i,c[4]={0,0,0,-1},k=0,check;
    char m;
    for(i=0;i<strlen(s);i++)
    {
        (s[i]>=48&&s[i]<=57)?c[0]++:(s[i]>=65&&s[i]<=90)?c[1]++:(s[i]>=97&&s[i]<=122)?c[2]++:c[3]++;
    }
    for(i=0;i<4;i++)
    {
        c[i]>0?k++:printf("");
    }
    printf("\n\t\t\t\tstrength of password              : ");
    k==4?printf("very strong\n"):k==3?printf("strong\n"):k==2?printf("moderate\n"):k==1?printf("poor\n"):printf("N\n");
    clear();
    if(k==1)
    {
        check = change_password();
    }
    return(check);
}
int change_password()
{
    int check1 = 0;
    char m;
    system("COLOR E4");
    printf("\n\n\n\n\n\n\t\t\t\t\tYour password strength is poor !\n\n\n\n\t\t\t\t\tDo you want to change password ?\n\t\t\t\t\t(Enter Y for yes,N for no)");
    printf("\n\n\t\t\t\t\tYour Choice : ");
    m = toupper(getch());
    printf("%c",m);
    clear();
    if(m=='Y')
    {
        check1++;
        newuser();
    }
    else if (m!='Y'&&m!='N')
    {
        warning();
        change_password();
    }
    return(check1);
}
void login_details()
{
    FILE *f;
    char line[100],s[25][100],z[100];
    int i,j=0,k=0;
    system("COLOR E1");
    f=fopen("passwords.txt","a+");
    printf("\n\n\t\t\t\t\t\t\tLOGIN DETAILS\n\t\t\t________________________________________________________________________________\n\n");
    printf("\n\t\t\t\t\tENTER USERNAME   :  ");
    scanf("%s",username);
    printf("\n\t\t\t\t\tENTER ROLL NUMBER:  ");
    scanf("%d",&R);
    printf("\n\t\t\t\t\tENTER PASSWORD   :  ");
    scanf("%s",z);
    strcpy(z,strcat(z,"\n"));
    while(fgets(line,99,f)!= NULL)
    {
        strcpy(s[j],line);
        j++;
    }
    if(strcmp(s[R-1],z)==0)
    {
        k=1;
    }
    if (k==1)
    {
        printf("\n\n\n\t\t\t\t\tLogin successful!!!");
    }
    else if(k!=1)
    {
        system("COLOR E4");
        printf("\n\n\n\t\t\t\t\t\tThe password or Roll number you have entered is wrong! Please check again.");
        clear();
        login_details();
    }
    return;
}
void Guidelines()
{
    char w;
    FILE*Instructions;
    Instructions = fopen("Guidelines.txt","r");
    system("COLOR E1");
    printf("\nUsername   : %s\nRoll number: %d\n\n",username,R);
    // GUIDELINES //
    while(1)
    {
        w = fgetc(Instructions);
        if (w == EOF)
            break;
        printf("%c",w);
    }
    fclose(Instructions);
    clear();
    navigation_menu();
    return;
}
void navigation_menu()
{
    char n;
    system("COLOR E1");
    printf("\nUsername   : %s\nRoll number: %d\n\n",username,R);
    printf("\n\n\t\t\t\t\t\t\tNAVIGATION MENU\n");
    printf("\t\t\t***********************************************************************************************\n");
    printf("\n\n\t\t\tPress S to start the QUIZ");
    printf("\n\t\t\tPress H for help");
    printf("\n\t\t\tPress B to view the best score\n\n\t\t\tYour choice : ");
    n=toupper(getch());
    printf("%c",n);
    clear();
    n=='S'?start():n=='H'?Guidelines():n=='B'?Best_score():warning();
    navigation_menu();
    return;
}
void Best_score()
{
    system("COLOR E1");
    char line[100];
    int g=0,h=0;
    FILE*S_GK,*S_CS;
    S_GK=fopen("students_GK.txt","r");
    S_CS=fopen("students_CS.txt","r");
    printf("\nUsername   : %s\nRoll number: %d\n\n\n\n\n",username,R);
    while(fgets(line,99,S_GK)!=NULL)
    {
        atoi(line)>g?g=atoi(line):printf("");
    }
    printf("\t\t\t>> Best score in GK - %d\n\n",g);
    fclose(S_GK);
    while(fgets(line,99,S_CS)!=NULL)
    {
        atoi(line)>h?h=atoi(line):printf("");
    }
    printf("\t\t\t>> Best score in CS - %d\n",h);
    fclose(S_CS);
    clear();
    navigation_menu();
    return;
}
void start()
{
    FILE *U,*Q_GK,*A_GK,*Q_CS,*A_CS,*Review,*S_GK,*S_CS;
    char ch,a,z,k;
    int i,corrects, wrongs, unattempted,score_GK,score_CS;
    Q_GK = fopen("Questions_GK.txt","r");
    U = fopen("User_Answers.txt","a+");
    A_GK = fopen("Answers_GK.txt","r");
    Q_CS = fopen("Questions_CS.txt","r");
    A_CS = fopen("Answers_CS.txt","r");
    S_GK = fopen("students_GK.txt","a+");
    S_CS = fopen("students_CS.txt","a+");
    do
    {
        Review = fopen("Review.txt","w");
        // SELECTION OF TOPIC //
        system("COLOR E1");
        printf("\nUsername   : %s\nRoll number: %d\n\n",username,R);
        printf("\n\t\t\tSelect a topic :\n\n\t\t\t A. General Knowledge\n\n\t\t\t B. Computer Programming\n\n\t\t\tYour choice : ");
        P[J] = toupper(getch());
        printf("%c",P[J]);
        clear();
        // DISPLAY OF QUESTIONS//
        system("COLOR F0");
        corrects = wrongs = unattempted = 0;
        if (P[J] == 'A')
        {
            while(1)
            {
                ch = fgetc(Q_GK);
                fprintf(Review, "%c",ch);
                if (ch == '*')
                {
                    printf("\nYour Answer : ");
                    k = toupper(getch());
                    printf("%c\n",k);
                    fputc(k,U);
                    a = fgetc(A_GK);
                    k==a?corrects++:k!=a&&(k=='A'||k=='B'||k=='C'||k=='D')?wrongs++:unattempted++;
                    fprintf(Review, "Your Answer    : %c\n", k );
                    fprintf(Review, "Correct Answer : %c\n_____________________________________________________________\n",a );
                    clear();
                }
                else if (ch == '/')
                {
                    break;
                }
                else if(ch!='*'|| ch!='/')
                {
                    printf("%c",ch );
                }
            }
            score_GK=2*corrects;
            fprintf(S_GK,"%d\n",score_GK);
        }
        else if ( P[J] == 'B')
        {
            while(1)
            {
                ch = fgetc(Q_CS);
                fprintf(Review, "%c",ch);
                if (ch == '*')
                {
                    printf("\nYour Answer : ");
                    k = toupper(getch());
                    printf("%c\n",k);
                    fputc(k,U);
                    a = fgetc(A_CS);
                    k==a?corrects++:k!=a&&(k=='A'||k=='B'||k=='C'||k=='D')?wrongs++:unattempted++;
                    fprintf(Review, "Your Answer : %c\n", k );
                    fprintf(Review, "Correct Answer : %c\n_____________________________________________________________\n",a );
                    clear();
                }
                else if (ch == '/')
                {
                    break;
                }
                else if(ch!='*'|| ch!='/')
                {
                    printf("%c",ch );
                }

            }
            score_CS=2*corrects;
            fprintf(S_CS,"%d\n",score_CS);
        }
        else if(P[J]!='A' && P[J]!='B')
        {
            warning();
            start();
        }
        fclose(Review);
        marks[J]= 2*corrects;
        percentage[J]=(2*corrects*100)/10;
        J++;
        // DISPLAY OF RESULTS //
        printf("\nUsername   : %s\nRoll number: %d\n\n",username,R);
        final_score(corrects,wrongs,unattempted);
        review();
        reattempt();
    } while(L<=3);
    if(L>3)
    {
        system("COLOR E1");
        printf("\nUsername   : %s\nRoll number: %d\n\n",username,R);
        printf("\n\n\t\t\t\t\t\t\tNO MORE ATTEMPTS ARE ALLOWED");
        clear();
    }
    quiz_analytics();
    return;
}
int final_score(int corrects,int wrongs,int unattempted)
{
    int score;
    system("COLOR E1");
    printf("\t\t\t\t\t\tRESULT\n\t\t_________________________________________________________________________________\n");
    printf("\n\t\t\t\t\tTotal Questions       - 5\n");
    printf("\n\t\t\t\t\tattempted Questions   - %d\n",(5 - unattempted));
    printf("\n\t\t\t\t\tunattempted questions - %d\n",unattempted);
    printf("\n\t\t\t\t\tCorrect Questions     - %d\n",corrects);
    printf("\n\t\t\t\t\tWrong Questions       - %d\n",wrongs);
    printf("\n\t\t\t\t\tTotal Marks           - %d\n", 2*corrects );
    printf("\n\t\t\t\t\tPercentage            - %d%%\n",(2*corrects*100)/10);
    score=2*corrects;
    printf("\n\t\t\t\t\tRemark                - ");
    score==10?printf("EXCELLENT!!"):score==8?printf("VERY GOOD"):score==6?printf("GOOD"):score==4?printf("BETTER, KEEP WORKING HARDER"):score==2?printf("NEEDS IMPROVEMENT"):score==0?printf("WORK HARD :-),YOU CAN DO BETTER!"):printf("nothing");
    clear();
    return 0;
}
void review()
{
    char u,b;
    system("COLOR E1");
    printf("\nUsername   : %s\nRoll number: %d\n\n",username,R);
    printf("\n\n\n\t\t\t\tDo you want to review the questions?\n\t\t\t\t(Enter Y for yes,enter N for NO)\n\n\t\t\t\tYour choice : ");
    u=toupper(getch());
    printf("%c",u);
    clear();
    if(u=='Y')
    {
        FILE*Review;
        Review = fopen("Review.txt","r");
        system("COLOR F0");
        printf("\nUsername   : %s\nRoll number: %d\n\n",username,R);
        printf("\n\n\t\t\t\t\tREVIEW\n***************************************************************************************\n");
        Review = fopen("Review.txt","r");
        while(1)
        {
            b = fgetc(Review);
            if (b == EOF)
            break;
            else if(b!='*'&& b!='/')
            printf("%c",b);
        }
        fclose(Review);
        clear();
    }
    else if(u!='Y'&& u!='N')
    {
        warning();
        review();
    }
    return;
}
void reattempt()
{
    char m;
    system("COLOR E1");
    printf("\nUsername   : %s\nRoll number: %d\n\n",username,R);
    printf("\n\n\n\n\t\t\t\tDo you want to attempt the quiz again?\n\t\t\t\t(Enter Y for yes or N for no)\n\n\t\t\t\tYour choice : ");
    m=toupper(getch());
    printf("%c",m);
    clear();
    if(m=='Y')
    {
      L++;
    }
    else if(m=='N')
    {
      quiz_analytics();
    }
    else if(m!='Y' && m!='N')
    {
      warning();
      reattempt();
    }
    return;
}
void quiz_analytics()
{
    char t;
    system("COLOR E1");
    printf("\nUsername   : %s\nRoll number: %d\n\n",username,R);
    printf("\n\n\n\t\t\t\tDo you want to view the quiz analytics?\n\t\t\t\t(Enter Y for yes and N for no)\n\n\t\t\t\tYour choice :");
    t = toupper(getch());
    printf("%c",t);
    clear();
    if(t=='Y')
    {
        printf("\nUsername   : %s\nRoll number: %d\n\n",username,R);
        system("COLOR E1");
        printf("\n\t\t\t\t\tQUIZ ANALYTICS\n***********************************************************************************************\n");
        printf("\t\t\t\t\tTopic\tMarks\tPercentage\n\n");
        for(J = 0;J < L;J++)
        {
            if(J == 3)
            {
                break;
            }
            printf("\t\t\tAttempt %d\t  %c\t  %d\t  %d%%\n\n",J+1,P[J],marks[J],percentage[J]);
        }
        clear();
        exit(0);
    }
    else if(t=='N')
    {
        exit(0);
    }
    else if(t!='Y' && t!='N')
    {
        warning();
        quiz_analytics();
    }
    return;
}
int main()
{
    system("COLOR E1");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n");
    print("\t\t\t\t\t\twelcome",3,'#');
    clear();
    registration();
    Guidelines();
    navigation_menu();
    int fcloseall( void );
    return 0;
}
