#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "parseAndExecute.h"

static char input[100] = "look";

static bool getInput(void) {
   printf("What do you want to do? ");
   return fgets(input, sizeof input, stdin) != NULL;
}

void welcome() {
   printf("\n");
   prints("Welcome to our new Adventure!\n");
   prints("#############################\n");
   printf("\n");
}

int main() {
   welcome();
   while (tell(input) && getInput());
   printf("\n");
   return 0;
}
