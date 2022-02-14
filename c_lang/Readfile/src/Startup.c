#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 255

int main(int argc, char* argv[])
{
  int i;

  // Get filename.
  char* filename;
  if (1 < argc)
  {
    filename = argv[1];
  }
  else
  {
    fprintf(stderr, "ERROR: Cannot read arguments.\n");
    exit(EXIT_FAILURE);
  }

  // Open file stream.
  FILE* fp;
  if ((fp = fopen(filename, "r")) == NULL)
  {
    fprintf(stderr, "ERROR: Cannot open file.\n");
    exit(EXIT_FAILURE);
  }

  // Allocate array.
  int lineCount = 0;
  int wordCount = 0;
  char** linebufs;
  linebufs = (char**)malloc(sizeof(char*));
  if (linebufs == NULL)
  {
    fprintf(stderr, "ERROR: Cannot allocate memory.\n");
    exit(EXIT_FAILURE);
  }
  linebufs[0] = (char*)malloc(sizeof(char) * BUFSIZE);
  if (linebufs[0] == NULL)
  {
    fprintf(stderr, "ERROR: Cannot allocate memory.\n");
    exit(EXIT_FAILURE);
  }
  memset(linebufs[0], '\0', BUFSIZE);

  // Read selected file.
  while (feof(fp) == 0)
  {
    // Line buffer
    char linebuf[BUFSIZE];
    // Word buffer
    char wordbuf[BUFSIZE];

    // Read from input file stream.
    if (fgets(linebuf, BUFSIZE, fp) == NULL)
    {
      //fprintf(stderr, "ERROR: Cannot read line.\n");
      strcpy(wordbuf, "\0");
    }
    else
    {
      // Convert line buffer to word.
      if (sscanf(linebuf, "%s", wordbuf) == EOF)
      {
        //fprintf(stderr, "ERROR: Cannot read line.\n");
        strcpy(wordbuf, "\0");
      }
    }

    // Reallocate array.
    lineCount++;
    char** tmp;
    tmp = (char**)realloc(linebufs, sizeof(char*) * lineCount);
    if (tmp == NULL)
    {
      for (i = 0; i < lineCount; ++i)
      {
        free(linebufs[i]);
      }
      free(linebufs);
      fprintf(stderr, "ERROR: Cannot allocate memory.\n");
      exit(EXIT_FAILURE);
    }
    linebufs = tmp;
    linebufs[lineCount - 1] = (char*)malloc(sizeof(char) * BUFSIZE);
    if (linebufs[lineCount - 1] == NULL)
    {
      fprintf(stderr, "ERROR: Cannot allocate memory.\n");
      exit(EXIT_FAILURE);
    }
    memset(linebufs[lineCount - 1], '\0', BUFSIZE);

    // Set value.
    wordCount += strlen(wordbuf);
    strcpy(linebufs[lineCount - 1], wordbuf);
  }

  // Close file stream.
  if (fclose(fp) == EOF)
  {
    fprintf(stderr, "ERROR: Cannot close %s .\n", filename);
    exit(EXIT_FAILURE);
  }
  fp = NULL;

  // Display.
  printf("\n");
  printf("Display all text in file.\n");
  printf("    Line Count: %d\n", lineCount);
  printf("    Word Count: %d\n", wordCount);
  printf("------------------------- Start -------------------------\n");
  for (i = 0; i < lineCount; ++i)
  {
    printf("%3d: %s\n", (i + 1), linebufs[i]);
  }
  printf("-------------------------- End --------------------------\n");

  // Release array.
  for (i = 0; i < lineCount; ++i)
  {
    free(linebufs[i]);
    linebufs[i] = NULL;
  }
  free(linebufs);
  linebufs = NULL;

  return EXIT_SUCCESS;
}
