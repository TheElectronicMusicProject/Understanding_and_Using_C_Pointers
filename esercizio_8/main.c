#include <stdio.h>
#include <stdint.h>

int
main (void)
{
	char * titles[] = {"A Tale of Two Cities",
                       "Wuthering Heights",
                       "Don Quixote",
                       "Odyssey",
                       "Moby-Dick",
                       "Hamlet",
                       "Gulliver's Travels"};
    char ** bestBooks[3];
    char ** englishBooks[4];

    bestBooks[0] = &titles[0];
    bestBooks[1] = &titles[3];
    bestBooks[2] = &titles[5];

    englishBooks[0] = &titles[0];
    englishBooks[1] = &titles[1];
    englishBooks[2] = &titles[5];
    englishBooks[3] = &titles[6];

    printf("%s\n", *englishBooks[1]);
    printf("%s\n", *bestBooks[1]);
    printf("%s\n", titles[0]);
	
	return (0);
}	/* main() */