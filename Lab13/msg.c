

#include <stdio.h>

void f();
void log_message(char *message);

int main()
{
  f();
  f();
  f();

  log_message("read data");
  log_message("update data");
  log_message("data error");

  return 0;
}

void log_message(char *message)
{
  static int total = 0;
  total++;
  FILE *logfile = fopen("log.txt", "a");
  if (logfile != NULL)
  {
    fprintf(logfile, "log %d: %s\n", total, message);
    fclose(logfile);
  }
}

void f()
{
  static int calls = 0;
  calls++;
  printf("calls: %d\n", calls);
}