#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 255

int main(int argc, char* argv[])
{
  printf("\n");
  printf("Readline program.\n");
  printf("Stop this program if \"q\" is entered.\n");

  while (1)
  {
    // Line buffer
    char linebuf[BUFSIZE] = {'\0'};
    // Word buffer
    char wordbuf[BUFSIZE] = {'\0'};

    // Read from input stream.
    printf("Input : ");
    if (fgets(linebuf, BUFSIZE, stdin) == NULL)
    {
      fprintf(stderr, "ERROR: Cannot read line.\n");
      break;
    }

    // Convert line buffer to word.
    if (sscanf(linebuf, "%s", wordbuf) == EOF)
    {
      fprintf(stderr, "ERROR: Cannot read line.\n");
      break;
    }

    // Print result.
    printf("Output: %s\n\n", wordbuf);

    // Stop if it's entered q
    if (strcmp(wordbuf, "q") == 0)
    {
      printf("\"q\" was entered.\n");
      exit(EXIT_SUCCESS);
    }
  }

  return EXIT_SUCCESS;
}

