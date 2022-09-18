#include <stdbool.h>
#include <stdio.h>
#include <string.h>

struct location {
   const char *description;
   const char *detailedDescription;
   const char *tag;
}

locs[] = {
   {"You wake up on the loo. You have no idea where or who you are.", "You see a pretty dirty door, with some nasty jokes on it. Next to you is some toilet paper, a coin and a few magazines.", "loo"},
   {"You are in the Restroom.", "", "restroom"}
};

#define numberOfLocations   (sizeof locs / sizeof *locs)

static unsigned locationOfPlayer = 0;

static char input[100] = "look";

static bool getInput(void) {
   printf("What do you want to do? ");
   return fgets(input, sizeof input, stdin) != NULL;
}

void executeLook(void) {
   printf("%s.\n", locs[locationOfPlayer].description);
}

void executeLookAround(void) {
   printf("%s.\n", locs[locationOfPlayer].detailedDescription);
}

void executeGo(char *room) {
   if (strcmp(room, "restroom") == 0) {
      locationOfPlayer = 1;
   }
}

void prints(char *input) {
   printf("%s", input);
   printf("\n");
}

void welcome() {
   printf("\n");
   prints("Welcome to our new Adventure!\n");
   prints("#############################\n");
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

int main() {
   welcome();
   while (tell(input) && getInput());
   printf("\n");
   return 0;
}
