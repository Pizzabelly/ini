#include <time.h>
#include <stdio.h>

#include "ini.h"

ini_parser parser;

#define TEST_FILE "test.ini"

__attribute__((optimize("unroll-loops")))
double run_bench(int count) {
  clock_t start, end;
  start = clock();

  for (int i = 0; i < count; i++) {
    get_ini_value(&parser, "Test1", "Test");
    get_ini_value(&parser, "Test1", "String");
    get_ini_value(&parser, "Test1", "Int");
    get_ini_value(&parser, "Test2", "Test");
    get_ini_value(&parser, "Test2", "String");
    get_ini_value(&parser, "Test2", "Int");
  }

  end = clock();

  return ((double) (end - start)) / CLOCKS_PER_SEC;
}

int main(void) {
  if (!load_ini_file(&parser, TEST_FILE)) {
    printf("failed to load file\n");
  }

  printf("Test results:\n");

  printf("'%s'\n", get_ini_value(&parser, "Test1", "Test"));
  printf("'%s'\n", get_ini_value(&parser, "Test1", "String"));
  printf("'%s'\n", get_ini_value(&parser, "Test1", "Int"));
  printf("'%s'\n", get_ini_value(&parser, "Test2", "Test"));
  printf("'%s'\n", get_ini_value(&parser, "Test2", "String"));
  printf("'%s'\n", get_ini_value(&parser, "Test2", "Int"));

	printf("Test on file '%s' took %f seconds for 60 queries\n", TEST_FILE, run_bench(10));
	printf("Test on file '%s' took %f seconds for 600 queries\n", TEST_FILE, run_bench(100));
	printf("Test on file '%s' took %f seconds for 6000 queries\n", TEST_FILE, run_bench(1000));
	printf("Test on file '%s' took %f seconds for 60000 queries\n", TEST_FILE, run_bench(10000));
	printf("Test on file '%s' took %f seconds for 600000 queries\n", TEST_FILE, run_bench(100000));

  unload_ini_file(&parser);
	
  return 0;
}
