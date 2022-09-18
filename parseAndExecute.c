#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "location.h"

void prints(char *input) {
   printf("%s", input);
   printf("\n");
}

bool tell(char *input) {

   input = strtok(input, "\n");

   if (input != NULL) {

      if (strcmp(input, "quit") == 0) {
         prints("Bye bye");
         return false;
      } else if (strcmp(input, "look") == 0) {
         executeLook();
      } else if (strcmp(input, "look around") == 0) {
         executeLookAround();
      } else if (strcmp(input, "look at magazines") == 0) {
         prints("You see a very much used Micky Mouse magazine, a very old and unusable playboy and what seems to be a scrum guide 2009 in mint condition.");
      } else if (strcmp(input, "go through door") == 0) {
         executeGo("restroom");
         tell("look");
      } else {
         prints("What????");
      }
      
   }
   
   printf("\n");
   return true;
}
