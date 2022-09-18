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
