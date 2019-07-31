#include <time.h>
#include <stdio.h>

#include "ini.h"

ini_parser parser;

#define TEST_FILE "test.ini"

int main(void) {
  if (!load_ini_file(&parser, TEST_FILE)) {
    printf("failed to load file\n");
  }

  double total_time;
  clock_t start, end;
  start = clock();

  get_ini_value(&parser, "Test1", "Test");
  get_ini_value(&parser, "Test1", "String");
  get_ini_value(&parser, "Test1", "Int");
  get_ini_value(&parser, "Test2", "Test");
  get_ini_value(&parser, "Test2", "String");
  get_ini_value(&parser, "Test2", "Int");
  get_ini_value(&parser, "Test1", "Test");
  get_ini_value(&parser, "Test1", "String");
  get_ini_value(&parser, "Test1", "Int");
  get_ini_value(&parser, "Test2", "Test");
  get_ini_value(&parser, "Test2", "String");
  get_ini_value(&parser, "Test2", "Int");
  get_ini_value(&parser, "Test1", "Test");
  get_ini_value(&parser, "Test1", "String");
  get_ini_value(&parser, "Test1", "Int");
  get_ini_value(&parser, "Test2", "Test");
  get_ini_value(&parser, "Test2", "String");
  get_ini_value(&parser, "Test2", "Int");
  get_ini_value(&parser, "Test1", "Test");
  get_ini_value(&parser, "Test1", "String");
  get_ini_value(&parser, "Test1", "Int");
  get_ini_value(&parser, "Test2", "Test");
  get_ini_value(&parser, "Test2", "String");
  get_ini_value(&parser, "Test2", "Int");
  get_ini_value(&parser, "Test1", "Test");
  get_ini_value(&parser, "Test1", "String");
  get_ini_value(&parser, "Test1", "Int");
  get_ini_value(&parser, "Test2", "Test");
  get_ini_value(&parser, "Test2", "String");
  get_ini_value(&parser, "Test2", "Int");
  get_ini_value(&parser, "Test1", "Test");
  get_ini_value(&parser, "Test1", "String");
  get_ini_value(&parser, "Test1", "Int");
  get_ini_value(&parser, "Test2", "Test");
  get_ini_value(&parser, "Test2", "String");
  get_ini_value(&parser, "Test2", "Int");
  get_ini_value(&parser, "Test1", "Test");
  get_ini_value(&parser, "Test1", "String");
  get_ini_value(&parser, "Test1", "Int");
  get_ini_value(&parser, "Test2", "Test");
  get_ini_value(&parser, "Test2", "String");
  get_ini_value(&parser, "Test2", "Int");
  get_ini_value(&parser, "Test1", "Test");
  get_ini_value(&parser, "Test1", "String");
  get_ini_value(&parser, "Test1", "Int");
  get_ini_value(&parser, "Test2", "Test");
  get_ini_value(&parser, "Test2", "String");
  get_ini_value(&parser, "Test2", "Int");
  get_ini_value(&parser, "Test1", "Test");
  get_ini_value(&parser, "Test1", "String");
  get_ini_value(&parser, "Test1", "Int");
  get_ini_value(&parser, "Test2", "Test");
  get_ini_value(&parser, "Test2", "String");
  get_ini_value(&parser, "Test2", "Int");
  get_ini_value(&parser, "Test1", "Test");
  get_ini_value(&parser, "Test1", "String");
  get_ini_value(&parser, "Test1", "Int");
  get_ini_value(&parser, "Test2", "Test");
  get_ini_value(&parser, "Test2", "String");
  get_ini_value(&parser, "Test2", "Int");

  end = clock();

  total_time = ((double) (end - start)) / CLOCKS_PER_SEC;

  printf("Test results:\n");

  printf("'%s'\n", get_ini_value(&parser, "Test1", "Test"));
  printf("'%s'\n", get_ini_value(&parser, "Test1", "String"));
  printf("'%s'\n", get_ini_value(&parser, "Test1", "Int"));
  printf("'%s'\n", get_ini_value(&parser, "Test2", "Test"));
  printf("'%s'\n", get_ini_value(&parser, "Test2", "String"));
  printf("'%s'\n", get_ini_value(&parser, "Test2", "Int"));
  
	printf("Test on file %s took %f for 60 queries\n", TEST_FILE, total_time);

  unload_ini_file(&parser);
	
  return 0;
}
