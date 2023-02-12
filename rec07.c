// Name : Ruvail Shahzad
// EUID :rs0737

#include <stdio.h>
#include <string.h>
#include <pthread.h>
#define SIZE 50
char sentence[2000];
int ind = 0;
pthread_t tid[50];
int counter;
pthread_mutex_t lock;
char convertUppercase(char lower)
{
   if ((lower > 96) && (lower < 123))
   {
       return (lower - 32);
   }
   else
   {
       return lower;
   }
}

void printChar()
{
   printf("The new sentence is [%d]: \t%c\n", ind, sentence[ind]);
   ind++;
}

void *convertMessage(void *ptr)
{
   pthread_mutex_lock(&lock);
   if (ind % 2)
   {
       sentence[ind] = convertUppercase(sentence[ind]);
   }
   printChar();
   pthread_mutex_unlock(&lock);
   return 0;
}

int main()
{
   int i;
   char buffer[SIZE];
   char *p;
   pthread_t ts[SIZE]; 
   printf("Please enter a phrase (less than 50 characters): ");
   if (fgets(buffer, sizeof(buffer), stdin) != NULL)
   {
       if ((p = strchr(buffer, '\n')) != NULL)
       {
           *p = '\0';
       }
   }
   strcpy(sentence, buffer); 
   printf("The original sentence is: \t %s\n", sentence);
   for (i = 0; i < strlen(buffer) + 1; ++i)
   {
       pthread_create(&ts[i], NULL, convertMessage, NULL);
   }
   for (i = 0; i < strlen(buffer); i++)
   {
       pthread_join(ts[i], NULL);
   }
   printf("\n");
   pthread_mutex_destroy(&lock);
   return 0;
}
