//HINT = try this password:helloworld123
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

 const int MAX_NUM_GUESSES = 3;  
 const char PASSWORD[] = "Th3corr3ctpassw0rd1h3r3";      
 static int check_password();
 int main(const int argc, const char *argv[]) {
      int n_guesses = 0;   
      if (argc != 1) {
      fprintf(stderr, "usage: %s\n", argv[0]);
      exit(1);
    }
     int result; 
     while (n_guesses < MAX_NUM_GUESSES) {
     result = check_password();
     n_guesses++;
        if (result)
        break;
        else
        printf("wrong attempt try again (attempt %d)\n", n_guesses);
    }
    if (!result && n_guesses == MAX_NUM_GUESSES) {
    printf("Access Denied :)\n");
    exit(2);
    }
    printf("success!\n");
    return 0;
}
   static int check_password() {
   char guess[10];              
   int authenticated = 0;   
   printf("password: ");
   if (fgets(guess, 50, stdin) == NULL)
   return authenticated;

   if (strlen(guess) == 0)
   return authenticated;
   if (guess[strlen(guess)-1] != '\n') {   
   while ( !feof(stdin) && getchar() != '\n') 
   return authenticated;
   } else {
        guess[strlen(guess)-1] = 0;
    }
    if (strcmp(PASSWORD, guess) == 0)
    authenticated = 1;
    return authenticated;
}
