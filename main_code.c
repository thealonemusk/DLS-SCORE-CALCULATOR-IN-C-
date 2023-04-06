// This app was made for an Assignment in 2nd Semester of NIT JALANDHAR .(CSE)

// contributers

// Abhay Mishra ( 21103001)( Dls 1 portion)
// Ashutosh Jha ( 21103029)( scorecard portion)
// Mohit Yadav  ( 21103095)( Dls 2 portion)

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

void mainMenu();
void teamDetails();
void newScorecard();
int scoringProcess();
void defaultScores();
void scoreSheet();
void convertToOver(int balls1);
void switchb();
void DLS1();
void DLS2();

int score = 0, overs = 0, ball = 0, ballrun = 0, bm1 = 0, bm2 = 0, bowlid = 0;

// Batters structure(To store Batter details like name, runs, id etc)
struct Batter
{
    int runs;
    char name[10];
    int balls;
    int id;
    bool out;
    bool isBatting;
} bat[11];

// Bowler structure(To store bowler details like name, wickets taken, id etc)
struct bowlers
{
    int balls;
    char name[20];
    int wickets;
    int id;
    bool bowling;
} bowl[11];

// Main function
int main()
{
    mainMenu();
}

void mainMenu()
{
    system("cls");
    int ch;
    printf("\n\n\n\n\n");
    printf("\n\t\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\t\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t\t        =                 WELCOME                   =");
    printf("\n\t\t\t\t        =                   TO                      =");
    printf("\n\t\t\t\t        =                 CRICKET                   =");
    printf("\n\t\t\t\t        =                SCORECARD                  =");
    printf("\n\t\t\t\t        =                MANAGEMENT                 =");
    printf("\n\t\t\t\t        =                  SYSTEM                   =");
    printf("\n\t\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\t\t\t\tNOTE: Use this program when you already know \n\t\t\t\twhich team is going to BAT first.\n\n");
    printf("\t\t\t\t1.Create new scoresheet.\n\t\t\t\t2.DLS when rain stops play after 1st innings.\n\t\t\t\t3.DLS when rain stops play in between 1st innings.\n\t\t\t\t4.Exit.\n");
    printf("\t\t\t\tEnter your choice(1 , 2 or 3): ");
    scanf("%d", &ch);
    if (ch == 1)
    {
        newScorecard();
    }
    else if (ch == 2)
    {
        DLS1();
    }
    else if (ch == 3)
    {
        DLS2();
    }
    else if (ch == 4)
        exit(0);
    else
    {
        mainMenu();
    }
}

void newScorecard()
{
    defaultScores();
    teamDetails();
    scoringProcess();
}

// Funtion to get team details(Batting and bowling team)
void teamDetails()
{

    system("cls");
    printf("\n\n\n\tPLAYER DETAILS\n\n");
    printf("\tEnter BATTING team players names(11 players):\n");
    int i;
    for (i = 1; i <= 11; i++)
    {
        printf("\tBatter %d: ", i);
        bat[i].id = i;
        scanf("%s", &bat[i].name);
    }
    system("cls");
    printf("\n\n\n\tPLAYER DETAILS\n\n");
    printf("\tEnter BOWLING team players names(11 players):\n");
    int j;
    for (j = 1; j <= 11; j++)
    {
        printf("\tPlayer %d: ", j);
        bowl[j].id = j;
        scanf("%s", &bowl[j].name);
    }
    system("cls");
    printf("\n\n\n\n\n\tENTER NUMBER OF OVERS: ");
    scanf("%d", &overs);
}

int scoringProcess()
{

    int b1, b2, nb, bo;
    char brun = '1';

    while (ball <= overs * 6)
    {

        if (ball == overs * 6)
        {
            system("cls");
            printf("\n\n\tFINAL SCORESHEET");
            scoreSheet();
            return 0;
        }

        if (ball == 0)
        {
            system("cls");
            printf("\n\n\n\t\t SELECT Batter\n\n");
            printf("\tID  Name        Runs      Balls\n");
            int i;
            for (i = 1; i <= 11; i++)
            {
                printf("\t%-3d %-10s: %-3dRuns  %-3dBalls\n", bat[i].id, bat[i].name, bat[i].runs, bat[i].balls);
            }
        top:
            printf("\n\tEnter FIRST Batter ID (1-11): ");
            scanf("%d", &b1);
            if (b1 < 1 || b1 > 11)
            {
                printf("\n\tError:Invalid choice.");
                goto top;
            }
            else
            {
                bm1 = b1;
                bat[b1].isBatting = true;
            }
        top1:
            printf("\tEnter SECOND Batter ID (1-11): ");
            scanf("%d", &b2);
            if (bat[b2].isBatting)
            {
                printf("\tBatter %d:%s is already batting.\n\tENTER AGAIN\n", bat[b2].id, bat[b2].name);
                goto top1;
            }
            if (b2 < 1 || b2 > 11)
            {
                printf("\n\tError:Invalid choice.");
                goto top1;
            }
            else
            {
                bm2 = b2;
                bat[b2].isBatting = true;
            }
        }

        if (ball % 6 == 0 && ball < overs * 6)
        {
            system("cls");
            printf("\n\n\n\t\t SELECT BOWLER\n\n");
            printf("\tID  Name        Balls      Wickets\n");
            int j;
            for (j = 1; j <= 11; j++)
            {
                printf("\t%-3d %-10s: %-3dBalls  %-3dWickets\n", bowl[j].id, bowl[j].name, bowl[j].balls, bowl[j].wickets);
            }
            printf("\n\n\tEnter BOWLER ID (1-11): ");
            scanf("%d", &bo);
            bowlid = bo;
            if (ball > 5)
                switchb();
            bowl[bo].bowling = true;
        }

        int no_of_out = 0;

    label:
        if (ball < overs * 6)
        {
            system("cls");
            scoreSheet();
            printf("\n\n\tEnter Ball(1-6 runs, 'w' for out): ");
            scanf(" %c", &brun);
            if (brun == '0')
            {
                ballrun = '0' - '0';
                bat[bm1].runs += 0;
                bat[bm1].balls++;
                bowl[bowlid].balls++;
            }
            else if (brun == '1')
            {
                ballrun = '1' - '0';
                bat[bm1].runs += 1;
                bat[bm1].balls++;
                bowl[bowlid].balls++;
                switchb();
            }
            else if (brun == '2')
            {
                ballrun = '2' - '0';
                bat[bm1].runs += 2;
                bat[bm1].balls++;
                bowl[bowlid].balls++;
            }
            else if (brun == '3')
            {
                ballrun = '3' - '0';
                bat[bm1].runs += 3;
                bat[bm1].balls++;
                bowl[bowlid].balls++;
                switchb();
            }
            else if (brun == '4')
            {
                ballrun = '4' - '0';
                bat[bm1].runs += 4;
                bat[bm1].balls++;
                bowl[bowlid].balls++;
            }
            else if (brun == '6')
            {
                ballrun = '6' - '0';
                bat[bm1].runs += 6;
                bat[bm1].balls++;
                bowl[bowlid].balls++;
            }
            else if (brun == 'w' || brun == 'W')
            {
                bat[bm1].out = true;
                bowl[bowlid].wickets++;
                bowl[bowlid].balls++;
                int a;
                for (a = 1; a <= 11; a++)
                {
                    if (bat[a].out == true)
                        no_of_out++;
                }
                if (no_of_out == 10)
                {
                    ball++;
                    system("cls");
                    printf("\n\n\tFINAL SCORESHEET");
                    scoreSheet();
                    break;
                }
                bat[bm1].isBatting = false;
                printf("\tBatter %d: %s is out.", bat[bm1].id, bat[bm1].name);
            first:
                printf("\n\tEnter new Batter(1-11): ");
                scanf("%d", &nb);
                if (bat[nb].isBatting)
                {
                    printf("\tBatter %d:%s is already batting.\n\tENTER AGAIN", bat[nb].id, bat[nb].name);
                    goto first;
                }
                if (bat[nb].out)
                {
                    printf("\tBatter %d:%s is already out.\n\tENTER AGAIN", bat[nb].id, bat[nb].name);
                    goto first;
                }
                bat[bm1].balls++;
                bat[nb].isBatting = true;
                bm1 = nb;
            }
            else
            {
                printf("\n\tInvalid possibility.Enter again.");
                goto label;
            }
        }
        ball++;
        score = score + ballrun;
    }
    return 0;
}

void defaultScores()
{
    int i;
    for (i = 0; i < 11; i++)
    {
        bat[i].balls = 0;
        bat[i].runs = 0;
        bat[i].out = false;
        bat[i].isBatting = false;
        bowl[i].balls = 0;
        bowl[i].wickets = 0;
        bowl[i].bowling = false;
    }
}

// Function to display the scoresheet.
void scoreSheet()
{
    // system("cls");
    printf("\n\n\tBATTING TEAM STATS:\n\n");
    int i;
    for (i = 1; i <= 11; i++)
    {
        if (bat[i].out)
            printf("\t%-3d%-10s: %-3dRuns  %-3dBalls  OUT\n", bat[i].id, bat[i].name, bat[i].runs, bat[i].balls);
        else
        {
            if (i == bm1)
                printf("\t%-3d%-10s: %-3dRuns  %-3dBalls  NOT-OUT  *Strike\n", bat[i].id, bat[i].name, bat[i].runs, bat[i].balls);
            else if (i == bm2)
                printf("\t%-3d%-10s: %-3dRuns  %-3dBalls  NOT-OUT  *Non Strike\n", bat[i].id, bat[i].name, bat[i].runs, bat[i].balls);
            else
                printf("\t%-3d%-10s: %-3dRuns  %-3dBalls  NOT-OUT\n", bat[i].id, bat[i].name, bat[i].runs, bat[i].balls);
        }
    }
    printf("\n\tBOWLING TEAM STATS:\n\n");
    int j;
    for (j = 1; j <= 11; j++)
    {
        if (bowl[j].bowling)
            printf("\t%-3d%-10s: %-3dBalls  %-3dWickets\n", bowl[j].id, bowl[j].name, bowl[j].balls, bowl[j].wickets);
    }
    printf("\n\tOVERS: ");
    convertToOver(ball);
    printf("\t\tSCORE: %d", score);
}

// Function to convert balls to overs.(ex: 7 balls to 1.1 overs)
void convertToOver(int balls1)
{
    int o = 0, b = 0;
    o = balls1 / 6;
    b = balls1 % 6;
    printf("%d.%d", o, b);
}

// Function to swtich Batter position(from strike to no strike)
void switchb()
{
    int temp = 0;
    temp = bm1;
    bm1 = bm2;
    bm2 = temp;
}

// for DLS 1
void DLS1()
{
    int e, f;
    system("cls");
    printf("\n\t\t\t\t ****DUCKWORTH LEWIS STERN METHOD**** ");
    printf("\n\t\t\t\t         ***T20 CRICKET***            ");

    printf("\n Enter score of team A after 20 overs : ");
    scanf("%d", &e);

    int main()
    {
        FILE *file;
        char path[100];
        char ch;
        int characters, words, lines;
        file = fopen("counting.txt", "w");
        printf("enter the text.press cntrl Z:\n");
        while ((ch = getchar()) != EOF)
        {
            putc(ch, file);
        }
        fclose(file);
        printf("Enter source file path: ");
        scanf("%s", path);
        file = fopen(path, "r");
        if (file == NULL)
        {
            printf("\nUnable to open file.\n");
            exit(EXIT_FAILURE);
        }
        characters = words = lines = 0;
        while ((ch = fgetc(file)) != EOF)
        {
            characters++;
            if (ch == '\n' || ch == '\0')
                lines++;
            if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\0')
                words++;
        }
        if (characters > 0)
        {
            words++;
            lines++;
        }
        printf("\n");
        printf("Total characters = %d\n", characters);
        printf("Total words = %d\n", words);
        printf("Total lines = %d\n", lines);
        fclose(file);
        return 0;
    }

    printf("\n RAIN STOPS PLAY");

    printf("\n Match reduced to how many overs : ");
    scanf("%d", &f);

    if (f == 1)
    {
        printf("\n  Runs required by team B to win the match in 1 OVER is %.2lf : ", floor((e * 13.7) / 100 + 1));
    }
    else if (f == 2)
    {
        printf("\n  Runs required by team B to win the match in 2 OVERS is %.2lf : ", floor((e * 19.7) / 100 + 1));
    }
    else if (f == 3)
    {
        printf("\n  Runs required by team B to win the match in 3 OVERS is %.2lf : ", floor((e * 25.4) / 100 + 1));
    }
    else if (f == 4)
    {
        printf("\n  Runs required by team B to win the match in 4 OVERS is %.2lf : ", floor((e * 30.8) / 100 + 1));
    }
    else if (f == 5)
    {
        printf("\n  Runs required by team B to win the match in 5 OVERS is %.2lf: ", floor((e * 36.2) / 100 + 1));
    }
    else if (f == 6)
    {
        printf("\n  Runs required by team B to win the match in 6 OVERS is %.2lf: ", floor((e * 41.7) / 100 + 1));
    }
    else if (f == 7)
    {
        printf("\n  Runs required by team B to win the match in 7 OVERS is %.2lf : ", floor((e * 49.3) / 100 + 1));
    }
    else if (f == 8)
    {
        printf("\n  Runs required by team B to win the match in 8 OVERS is %.2lf : ", floor((e * 54.0) / 100 + 1));
    }
    else if (f == 9)
    {
        printf("\n  Runs required by team B to win the match in 9 OVERS is %.2lf : ", floor((e * 57.9) / 100 + 1));
    }
    else if (f == 10)
    {
        printf("\n  Runs required by team B to win the match in 10 OVERS is %.2lf : ", floor((e * 61.3) / 100 + 1));
    }
    else if (f == 11)
    {
        printf("\n  Runs required by team B to win the match in 11 OVERS is %.2lf : ", floor((e * 65.0) / 100 + 1));
    }
    else if (f == 12)
    {
        printf("\n  Runs required by team B to win the match in 12 OVERS is %.2lf : ", floor((e * 68.3) / 100 + 1));
    }
    else if (f == 13)
    {
        printf("\n  Runs required by team B to win the match in 13 OVERS is %.2lf : ", floor((e * 71.5) / 100 + 1));
    }
    else if (f == 14)
    {
        printf("\n  Runs required by team B to win the match in 14 OVERS is %.2lf : ", floor((e * 75.1) / 100 + 1));
    }
    else if (f == 15)
    {
        printf("\n  Runs required by team B to win the match in 15 OVERS is %.2lf : ", floor((e * 79.2) / 100 + 1));
    }
    else if (f == 16)
    {
        printf("\n  Runs required by team B to win the match in 16 OVERS is %.2lf : ", floor((e * 83.5) / 100 + 1));
    }
    else if (f == 17)
    {
        printf("\n  Runs required by team B to win the match in 17 OVERS is %.2lf : ", floor((e * 87.7) / 100 + 1));
    }
    else if (f == 18)
    {
        printf("\n  Runs required by team B to win the match in 18 OVERS is %.2lf : ", floor((e * 91.7) / 100 + 1));
    }
    else if (f == 19)
    {
        printf("\n  Runs required by team B to win the match in 19 OVERS is %.2lf : ", floor((e * 95.6) / 100 + 1));
    }
    else if (f == 20)
    {
        printf("\n  Runs required by team B to win the match in 20 OVERS is %.2lf : ", floor((e * 100) / 100 + 1));
    }
    else
    {
        printf("invalid overs entered");
    }
}

// DLS 2
void DLS2()
{
    int a, b, c, d;
    system("cls");
    int o = 20;
    printf("\n\t\t\t\t ****DUCKWORTH LEWIS STERN METHOD**** ");
    printf("\n\t\t\t\t         ***T20 CRICKET***            ");

    printf("\n Enter number of overs played by team A : ");
    scanf("%d", &a);

    printf("\n Enter runs scored by team A : ");
    scanf("%d", &b);

    printf("\n Enter wickets lost by team A : ");
    scanf("%d", &c);

    printf("\n RAIN STOPS PLAY\n");

    // 0 wickets down case
    if (a == 10 && c == 0 )
    {
        printf("\n  Runs required by team B to win the match in 20 OVERS is %.2lf : ", floor((b * 100) / 38.7 + 1));
    }
    else if (a == 11 && c == 0)
    {
        printf("\n  Runs required by team B to win the match in 20 OVERS is %.2lf : ", floor((b * 100) / 42.1 + 1));
    }
    else if (a == 12 && c == 0)
    {
        printf("\n  Runs required by team B to win the match in 20 OVERS is %.2lf : ", floor((b * 100) / 46.0 + 1));
    }
    else if (a == 13 && c == 0)
    {
        printf("\n  Runs required by team B to win the match in 20 OVERS is %.2lf : ", floor((b * 100) / 50.7 + 1));
    }
    else if (a == 14 && c == 0)
    {
        printf("\n  Runs required by team B to win the match in 20 OVERS is %.2lf : ", floor((b * 100) / 58.3 + 1));
    }
    if (a == 15 && c == 0 )
    {
        printf("\n  Runs required by team B to win the match in 20 OVERS is %.2lf : ", floor((b * 100) / 63.8 + 1));
    }
    else if (a == 16 && c == 0 )
    {
        printf("\n  Runs required by team B to win the match in 20 OVERS is %.2lf : ", floor((b * 100) / 69.2 + 1));
    }
    else if (a == 17 && c == 0)
    {
        printf("\n  Runs required by team B to win the match in 20 OVERS is %.2lf : ", floor((b * 100) / 74.6 + 1));
    }
    else if (a == 18 && c == 0)
    {
        printf("\n  Runs required by team B to win the match in 20 OVERS is %.2lf : ", floor((b * 100) / 80.3 + 1));
    }
    else if (a == 19 && c == 0)
    {
        printf("\n  Runs required by team B to win the match in 20 OVERS is %.2lf : ", floor((b * 100) / 86.3 + 1));
    }
    // 1 wicket down case
    else if (a == 10 && c == 1)
    {
        printf("\n  Runs required by team B to win the match in 20 OVERS is %.2lf : ", floor((b * 100) / 44 + 1));
    }
    else if (a == 11 && c == 1)
    {
        printf("\n  Runs required by team B to win the match in 20 OVERS is %.2lf : ", floor((b * 100) / 47.7 + 1));
    }
    else if (a == 12 && c == 1)
    {
        printf("\n  Runs required by team B to win the match in 20 OVERS is %.2lf : ", floor((b * 100) / 51.7 + 1));
    }
    else if (a == 13 && c == 1)
    {
        printf("\n  Runs required by team B to win the match in 20 OVERS is %.2lf : ", floor((b * 100) / 55.8 + 1));
    }
    else if (a == 14 && c == 1)
    {
        printf("\n  Runs required by team B to win the match in 20 OVERS is %.2lf : ", floor((b * 100) / 61.5 + 1));
    }
    else if (a == 15 && c == 1)
    {
        printf("\n  Runs required by team B to win the match in 20 OVERS is %.2lf : ", floor((b * 100) / 66.6 + 1));
    }
    else if (a == 16 && c == 1)
    {
        printf("\n  Runs required by team B to win the match in 20 OVERS is %.2lf : ", floor((b * 100) / 72 + 1));
    }
    else if (a == 17 && c == 1)
    {
        printf("\n  Runs required by team B to win the match in 20 OVERS is %.2lf : ", floor((b * 100) / 77.2 + 1));
    }
    else if (a == 18 && c == 1)
    {
        printf("\n  Runs required by team B to win the match in 20 OVERS is %.2lf : ", floor((b * 100) / 82.0 + 1));
    }
    else if (a == 19 && c == 1)
    {
        printf("\n  Runs required by team B to win the match in 20 OVERS is %.2lf : ", floor((b * 100) / 88.7 + 1));
    }
    // 2 wickets down case
    else if (a == 10 && c == 2)
    {
        printf("\n  Runs required by team B to win the match in 20 OVERS is %.2lf : ", floor((b * 100) / 47.4 + 1));
    }
    else if (a == 11 && c == 2)
    {
        printf("\n  Runs required by team B to win the match in 20 OVERS is %.2lf : ", floor((b * 100) / 52.1 + 1));
    }
    else if (a == 12 && c == 2)
    {
        printf("\n  Runs required by team B to win the match in 20 OVERS is %.2lf : ", floor((b * 100) / 55.7 + 1));
    }
    else if (a == 13 && c == 2)
    {
        printf("\n  Runs required by team B to win the match in 20 OVERS is %.2lf : ", floor((b * 100) / 59.8 + 1));
    }
    else if (a == 14 && c == 2)
    {
        printf("\n  Runs required by team B to win the match in 20 OVERS is %.2lf : ", floor((b * 100) / 64.3 + 1));
    }
    else if (a == 15 && c == 2)
    {
        printf("\n  Runs required by team B to win the match in 20 OVERS is %.2lf : ", floor((b * 100) / 69 + 1));
    }
    else if (a == 16 && c == 2)
    {
        printf("\n  Runs required by team B to win the match in 20 OVERS is %.2lf : ", floor((b * 100) / 73.9 + 1));
    }
    else if (a == 17 && c == 2)
    {
        printf("\n  Runs required by team B to win the match in 20 OVERS is %.2lf : ", floor((b * 100) / 78.9 + 1));
    }
    else if (a == 18 && c == 2)
    {
        printf("\n  Runs required by team B to win the match in 20 OVERS is %.2lf : ", floor((b * 100) / 84.5 + 1));
    }
    else if (a == 19 && c == 2)
    {
        printf("\n  Runs required by team B to win the match in 20 OVERS is %.2lf : ", floor((b * 100) / 90.3 + 1));
    }
    // 3 wickets down case
    else if (a == 10 && c == 3)
    {
        printf("\n  Runs required by team B to win the match in 20 OVERS is %.2lf : ", floor((b * 100) / 49.9 + 1));
    }
    else if (a == 11 && c == 3 )
    {
        printf("\n  Runs required by team B to win the match in 20 OVERS is %.2lf : ", floor((b * 100) / 53.9 + 1));
    }
    else if (a == 12 && c == 3 )
    {
        printf("\n  Runs required by team B to win the match in 20 OVERS is %.2lf : ", floor((b * 100) / 58.3 + 1));
    }
    else if (a == 13 && c == 3)
    {
        printf("\n  Runs required by team B to win the match in 20 OVERS is %.2lf : ", floor((b * 100) / 62.6 + 1));
    }
    else if (a == 14 && c == 3)
    {
        printf("\n  Runs required by team B to win the match in 20 OVERS is %.2lf : ", floor((b * 100) / 67 + 1));
    }
    else if (a == 15 && c == 3)
    {
        printf("\n  Runs required by team B to win the match in 20 OVERS is %.2lf : ", floor((b * 100) / 71.4 + 1));
    }
    else if (a == 16 && c == 3)
    {
        printf("\n  Runs required by team B to win the match in 20 OVERS is %.2lf : ", floor((b * 100) / 75.9 + 1));
    }
    else if (a == 17 && c == 3)
    {
        printf("\n  Runs required by team B to win the match in 20 OVERS is %.2lf : ", floor((b * 100) / 80.6 + 1));
    }
    else if (a == 18 && c == 3 )
    {
        printf("\n  Runs required by team B to win the match in 20 OVERS is %.2lf : ", floor((b * 100) / 85.9 + 1));
    }
    else if (a == 19 && c == 3 )
    {
        printf("\n  Runs required by team B to win the match in 20 OVERS is %.2lf : ", floor((b * 100) / 91.5 + 1));
    }
    // 4 wickets down case
    else if (a == 10 && c == 4 )
    {
        printf("\n  Runs required by team B to win the match in 20 OVERS is %.2lf : ", floor((b * 100) / 54 + 1));
    }
    else if (a == 11 && c == 4 )
    {
        printf("\n  Runs required by team B to win the match in 20 OVERS is %.2lf : ", floor((b * 100) / 57.5 + 1));
    }
    else if (a == 12 && c == 4 )
    {
        printf("\n  Runs required by team B to win the match in 20 OVERS is %.2lf : ", floor((b * 100) / 61.1 + 1));
    }
    else if (a == 13 && c == 4 )
    {
        printf("\n  Runs required by team B to win the match in 20 OVERS is %.2lf : ", floor((b * 100) / 64.6 + 1));
    }
    else if (a == 14 && c == 4 )
    {
        printf("\n  Runs required by team B to win the match in 20 OVERS is %.2lf : ", floor((b * 100) / 68.3 + 1));
    }
    else if (a == 15 && c == 4 )
    {
        printf("\n  Runs required by team B to win the match in 20 OVERS is %.2lf : ", floor((b * 100) / 72.7 + 1));
    }
    else if (a == 16 && c == 4 )
    {
        printf("\n  Runs required by team B to win the match in 20 OVERS is %.2lf : ", floor((b * 100) / 77.6 + 1));
    }
    else if (a == 17 && c == 4 )
    {
        printf("\n  Runs required by team B to win the match in 20 OVERS is %.2lf : ", floor((b * 100) / 82.3 + 1));
    }
    else if (a == 18 && c == 4 )
    {
        printf("\n  Runs required by team B to win the match in 20 OVERS is %.2lf : ", floor((b * 100) / 87.3 + 1));
    }
    else if (a == 19 && c == 0 )
    {
        printf("\n  Runs required by team B to win the match in 20 OVERS is %.2lf : ", floor((b * 100) / 92.7 + 1));
    }
    // 5 wickets down case
    else if (a == 10 && c == 5 )
    {
        printf("\n  Runs required by team B to win the match in 20 OVERS is %.2lf : ", floor((b * 100) / 59.2 + 1));
    }
    else if (a == 11 && c == 5 )
    {
        printf("\n  Runs required by team B to win the match in 20 OVERS is %.2lf : ", floor((b * 100) / 62.2 + 1));
    }
    else if (a == 12 && c == 5 )
    {
        printf("\n  Runs required by team B to win the match in 20 OVERS is %.2lf : ", floor((b * 100) / 65.1 + 1));
    }
    else if (a == 13 && c == 5 )
    {
        printf("\n  Runs required by team B to win the match in 20 OVERS is %.2lf : ", floor((b * 100) / 67.9 + 1));
    }
    else if (a == 14 && c == 5 )
    {
        printf("\n  Runs required by team B to win the match in 20 OVERS is %.2lf : ", floor((b * 100) / 71 + 1));
    }
    else if (a == 15 && c == 5 )
    {
        printf("\n  Runs required by team B to win the match in 20 OVERS is %.2lf : ", floor((b * 100) / 74.5 + 1));
    }
    else if (a == 16 && c == 5 )
    {
        printf("\n  Runs required by team B to win the match in 20 OVERS is %.2lf : ", floor((b * 100) / 79.3 + 1));
    }
    else if (a == 17 && c == 5 )
    {
        printf("\n  Runs required by team B to win the match in 20 OVERS is %.2lf : ", floor((b * 100) / 83.5 + 1));
    }
    else if (a == 18 && c == 5 )
    {
        printf("\n  Runs required by team B to win the match in 20 OVERS is %.2lf : ", floor((b * 100) / 88.1 + 1));
    }
    else if (a == 19 && c == 5 )
    {
        printf("\n  Runs required by team B to win the match in 20 OVERS is %.2lf : ", floor((b * 100) / 93.3 + 1));
    }
    // 6 wickets down case
    else if (a == 10 && c == 6 )
    {
        printf("\n  Runs required by team B to win the match in 20 OVERS is %.2lf : ", floor((b * 100) / 63.9 + 1));
    }
    else if (a == 11 && c == 6 )
    {
        printf("\n  Runs required by team B to win the match in 20 OVERS is %.2lf : ", floor((b * 100) / 66.9 + 1));
    }
    else if (a == 12 && c == 6 )
    {
        printf("\n  Runs required by team B to win the match in 20 OVERS is %.2lf : ", floor((b * 100) / 69.8 + 1));
    }
    else if (a == 13 && c == 6 )
    {
        printf("\n  Runs required by team B to win the match in 20 OVERS is %.2lf : ", floor((b * 100) / 72.8 + 1));
    }
    else if (a == 14 && c == 6 )
    {
        printf("\n  Runs required by team B to win the match in 20 OVERS is %.2lf : ", floor((b * 100) / 75.8 + 1));
    }
    else if (a == 15 && c == 6 )
    {
        printf("\n  Runs required by team B to win the match in 20 OVERS is %.2lf : ", floor((b * 100) / 78.5 + 1));
    }
    else if (a == 16 && c == 6 )
    {
        printf("\n  Runs required by team B to win the match in 20 OVERS is %.2lf : ", floor((b * 100) / 81.7 + 1));
    }
    else if (a == 17 && c == 6 )
    {
        printf("\n  Runs required by team B to win the match in 20 OVERS is %.2lf : ", floor((b * 100) / 85.6 + 1));
    }
    else if (a == 18 && c == 6 )
    {
        printf("\n  Runs required by team B to win the match in 20 OVERS is %.2lf : ", floor((b * 100) / 89.4 + 1));
    }
    else if (a == 19 && c == 6 )
    {
        printf("\n  Runs required by team B to win the match in 20 OVERS is %.2lf : ", floor((b * 100) / 94 + 1));
    }
    // 7 wickets down
    else if (a == 10 && c == 7 )
    {
        printf("\n  Runs required by team B to win the match in 20 OVERS is %.2lf : ", floor((b * 100) / 70 + 1));
    }
    else if (a == 11 && c == 7 )
    {
        printf("\n  Runs required by team B to win the match in 20 OVERS is %.2lf : ", floor((b * 100) / 71.7 + 1));
    }
    else if (a == 12 && c == 7 )
    {
        printf("\n  Runs required by team B to win the match in 20 OVERS is %.2lf : ", floor((b * 100) / 73.9 + 1));
    }
    else if (a == 13 && c == 7 )
    {
        printf("\n  Runs required by team B to win the match in 20 OVERS is %.2lf : ", floor((b * 100) / 76.6 + 1));
    }
    else if (a == 14 && c == 7 )
    {
        printf("\n  Runs required by team B to win the match in 20 OVERS is %.2lf : ", floor((b * 100) / 80 + 1));
    }
    else if (a == 15 && c == 7 )
    {
        printf("\n  Runs required by team B to win the match in 20 OVERS is %.2lf : ", floor((b * 100) / 83 + 1));
    }
    else if (a == 16 && c == 7 )
    {
        printf("\n  Runs required by team B to win the match in 20 OVERS is %.2lf : ", floor((b * 100) / 85.8 + 1));
    }
    else if (a == 17 && c == 7 )
    {
        printf("\n  Runs required by team B to win the match in 20 OVERS is %.2lf : ", floor((b * 100) / 88.4 + 1));
    }
    else if (a == 18 && c == 7 )
    {
        printf("\n  Runs required by team B to win the match in 20 OVERS is %.2lf : ", floor((b * 100) / 90.7 + 1));
    }
    else if (a == 19 && c == 7 )
    {
        printf("\n  Runs required by team B to win the match in 20 OVERS is %.2lf : ", floor((b * 100) / 94.8 + 1));
    }
    // 8 wickets down
    else if (a == 10 && c == 8 )
    {
        printf("\n  Runs required by team B to win the match in 20 OVERS is %.2lf : ", floor((b * 100) / 81.4 + 1));
    }
    else if (a == 11 && c == 8 )
    {
        printf("\n  Runs required by team B to win the match in 20 OVERS is %.2lf : ", floor((b * 100) / 82.3 + 1));
    }
    else if (a == 12 && c == 8 )
    {
        printf("\n  Runs required by team B to win the match in 20 OVERS is %.2lf : ", floor((b * 100) / 83.3 + 1));
    }
    else if (a == 13 && c == 8 )
    {
        printf("\n  Runs required by team B to win the match in 20 OVERS is %.2lf : ", floor((b * 100) / 84.3 + 1));
    }
    else if (a == 14 && c == 8 )
    {
        printf("\n  Runs required by team B to win the match in 20 OVERS is %.2lf : ", floor((b * 100) / 85.5 + 1));
    }
    else if (a == 15 && c == 8 )
    {
        printf("\n  Runs required by team B to win the match in 20 OVERS is %.2lf : ", floor((b * 100) / 87.8 + 1));
    }
    else if (a == 16 && c == 8 )
    {
        printf("\n  Runs required by team B to win the match in 20 OVERS is %.2lf : ", floor((b * 100) / 90 + 1));
    }
    else if (a == 17 && c == 8 )
    {
        printf("\n  Runs required by team B to win the match in 20 OVERS is %.2lf : ", floor((b * 100) / 92.1 + 1));
    }
    else if (a == 18 && c == 8 )
    {
        printf("\n  Runs required by team B to win the match in 20 OVERS is %.2lf : ", floor((b * 100) / 93.8 + 1));
    }
    else if (a == 19 && c == 8 )
    {
        printf("\n  Runs required by team B to win the match in 20 OVERS is %.2lf : ", floor((b * 100) / 95.8 + 1));
    }
    // 9 wickets down
    else if (a == 10 && c == 9 )
    {
        printf("\n  Runs required by team B to win the match in 20 OVERS is %.2lf : ", floor((b * 100) / 92.1 + 1));
    }
    else if (a == 11 && c == 9 )
    {
        printf("\n  Runs required by team B to win the match in 20 OVERS is %.2lf : ", floor((b * 100) / 92.8 + 1));
    }
    else if (a == 12 && c == 9 )
    {
        printf("\n  Runs required by team B to win the match in 20 OVERS is %.2lf : ", floor((b * 100) / 93.4 + 1));
    }
    else if (a == 13 && c == 9 )
    {
        printf("\n  Runs required by team B to win the match in 20 OVERS is %.2lf : ", floor((b * 100) / 94.1 + 1));
    }
    else if (a == 14 && c == 9 )
    {
        printf("\n  Runs required by team B to win the match in 20 OVERS is %.2lf : ", floor((b * 100) / 94.8 + 1));
    }
    else if (a == 15 && c == 9 )
    {
        printf("\n  Runs required by team B to win the match in 20 OVERS is %.2lf : ", floor((b * 100) / 95.6 + 1));
    }
    else if (a == 16 && c == 9 )
    {
        printf("\n  Runs required by team B to win the match in 20 OVERS is %.2lf : ", floor((b * 100) / 96.5 + 1));
    }
    else if (a == 17 && c == 9 )
    {
        printf("\n  Runs required by team B to win the match in 20 OVERS is %.2lf : ", floor((b * 100) / 97.5 + 1));
    }
    else if (a == 18 && c == 9 )
    {
        printf("\n  Runs required by team B to win the match in 20 OVERS is %.2lf : ", floor((b * 100) / 98.4 + 1));
    }
    else if (a == 19 && c == 9 )
    {
        printf("\n  Runs required by team B to win the match in 20 OVERS is %.2lf : ", floor((b * 100) / 99.1 + 1));
    }
    // user type full overs
    else if (a == 20 && c == 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 )
    {
        printf("\n same score to be chased");
    }
    else
    {
        printf("invalid overs");
    }
    return;
}
