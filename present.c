#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

short get_short(char text[], short MIN, short MAX); // function to get safe user input and check for validity

int main()
{   
    system("clear");

    // Christmas tree printing
    printf("-------------------------------------------------------------------------\n");
    int height = get_short("Liebe Lucie, wie groß soll dein Weihnachtsbaum werden? (10-50)", 10, 50); 

    for (int i = 1; i < height; i++)
    {
        int starCount = (i * 2) - 1;
        int spaceCount = height - i +1;

        for (int j = 0; j < spaceCount; j++)
            printf(" ");
        for (int j = 0; j < starCount; j++)
            printf("*");
        
        printf("\n");
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < height; j++) 
            printf(" ");
        
        printf("*\n");
    }

//------------------------------------------
// Prompting Questions
//------------------------------------------

    printf("----------------------------------------------------------------------------\n");
    printf("Das Jahr ist zu Ende und ich bin sehr froh, es mit dir verbringen zu können.\n");
    printf("Ich möchte mit dir im nächsten Jahr noch mehr Zeit verbringen,\n");
    printf("aber um zu erfahren wie, musst du dich im folgenden Quiz tapfer schlagen!\n");
    printf("----------------------------------------------------------------------------\n\n");

char questions [][100] = {"1. Welches der folgenden Verkehrsmittel ist das klimafreundlichste?",
                          "2. Was heißt \"nous conduisons\" auf deutsch",
                          "3. In welcher Stadt haben wir unseren zweiten gemeinamen Urlaub verbracht?"};

char options [][100] = {"A) Fernbus", "B) Flugzeug", "C) U-Boot", "D) Fernzug",
                        "A) Wir Baguette", "B) Wir fahren", "C) Wir Croissant", "D) Emmanuel Macron",                
                        "A) Bruttig-Fankel", "B) Tavistock", "C) Kopenhagen", "D) Hamburg"};

char answers [3] = {'D', 'B', 'C'};

size_t numberOfQuestions = sizeof(questions) / sizeof(questions[0]); // divide this by the size of one element (does not matter which -> all have the same length)

char guess;
int score;

printf("QUIZ GAME\n");

for (size_t  i = 0; i < numberOfQuestions; i++)
{   
    printf("----------------------------------------------------------------------------\n");
    printf("%s\n\n", questions[i]);

    for (int j = (i * 4); j < (i * 4) + 4; j++)  // this way every fourth element is going to be printed 
    {
        printf("%s\n", options [j]);
    }

    printf("\nguess: ");
    scanf("%c", &guess);  // we have to clear the input buffer, because otherwise the newline character will still be in there
    scanf("%*c");          // clear the newline character from input buffer
   
    guess = toupper(guess);

    if (guess == answers[i])
    {
        printf("Korrekt! Good soup!\n");
        score++;
    }
    else
    {
        printf("Leider nein! Why are you gay?\n");
        printf("Die richtige Antwort wäre %c) gewesen\n", answers[i]);
    }
    
}

printf("*****************************\n");
printf("FINAL SCORE: %d/%zu\n", score, numberOfQuestions);  

if (score > 0)
{
    printf("WIR FAHREN NACH KOPENHAGEN!\n");
}
else
{
    printf("Probiere es noch einmal!\n");
}

printf("*****************************\n");

printf("\n");

    return 0;
}

short get_short(char text[], short MIN, short MAX)
{
    //declare working variables 
    short value;
    int finished = 0; //0 für FALSE
    char ch;
    int retVal;


    do
    {
        printf("%s: ", text); //Abkürzung "s" für "string" / Zeichenkette

        ch = '\0'; // \0 wird als ein Buchstabe gewertet; O ist nicht die Zahl 0 sondern ein "Null Character"; Null Character hat in der Ascii Tabelle auch den Wert 0

        retVal = scanf("%hd%c", &value, &ch); // -> "hd" steht für short -> Adresse ist "Value"; scanf gibt auch einen Wert zurück, diesen speichern wir in retVal 

        // check for valid user input

        if (retVal != 2) printf("Das war keine korrekte Zahl!\n");

        else if (ch != '\n') printf("Unerwartete Zeichen hinter der Zahl!\n");

        else if (value < MIN) printf("Zahl ist zu klein (MIN: %hd)\n",MIN);

        else if (value > MAX) printf("Zahl ist zu groß (MAX: %hd)\n",MAX);

        else finished = 1; // falls die Variable tatsächlich 2 ist; und der character ein newline, ist alles richtig und die loop wird beendet

        //Variable finished wird auf 1 gesetzt -> weil 1 für TRUE

        //clear input stream buffer

        while (ch != '\n') scanf("%c", &ch); //Variation mit scanf von getchar

    } while (!finished); //repeat if not finished 

    //return user input
    return value; //wer auch immer die Funktion get_short aufruft bekomm "value" zurück
}
