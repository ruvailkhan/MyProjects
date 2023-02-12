

#include "major2.h"

int main()
{
    char c; // holds whether user wants to customize prompt
    printf("Do you want to customize your shell prompt for extra credit (Type y for yes or n for no): ");
    scanf("%c", &c);
    
    char prompt[50]; // holds what prompt to use
    
    if (c == 'y') // if user wants to customize prompt then get new prompt
    {
        printf("Type your customized shell prompt: ");
        scanf("%s", prompt);
    }

    else if (c == 'n') // if user does not want to customize prompt then set default prompt
    {
        strcpy(prompt, "prompt");
    }

    char line[100]; // holds user's input for newshell
    int choice; // will hold an int signifying what mode to go into (interactive or batch)

    while ((getchar()) != '\n'); // clearing buffer
    printf("%s: ", prompt);
    fgets(line, 100, stdin); // reading in line

    // This section parses the user input to decide what mode to go into
    const char a[3] = " \n"; // holds delimeters
    char *token; // used with strtok
    char* lineArray[3]; // holds the parsed line
    int counter = 0; // holds how many elements are in lineArray

    // parsing begins
    token = strtok(line, a);

    while (token != NULL)
    {
        lineArray[counter] = malloc(strlen(token) + 1);
        strcpy(lineArray[counter], token);
        token = strtok(NULL, a);
        counter++;
    }

    if (counter == 1) // if there is only one argument, go into interactive mode
    {
        char filename[2]= ""; // no filename needed for interactive mode
        shell(counter, filename, prompt);
    }

    else if (counter == 2) // if there are two arguments, go into batch mode
    {
        char *filename = lineArray[1]; // holds the name of the file to open for batch mode
        shell(counter, filename, prompt);
    }

    else // else end program because of invalid input
    {
        printf("Invalid input\n");
    }   

    return 0;
}
