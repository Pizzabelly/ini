#ifndef INI_H
#define INI_H


#define _CRT_SECURE_NO_WARNINGS
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 256
#define MAX_VALUE_SIZE 128

typedef struct {
  char* key;
  char* value;
} pair;

typedef struct {
  FILE* file;
} ini_parser;

/* loads the file at the given path into memory */
static bool load_ini_file(ini_parser* p, const char* path) {
  p->file = fopen(path, "r");
  if (p->file == NULL)
    return false;
  return true;
}

/* unload file */
void unload_ini_file(ini_parser* p) {
  fclose(p->file);
}

static bool parse_line(char* line, pair* c) {
  uint32_t equal_index = strchr(line, '=')-line;
  if (equal_index < 0) return false;

  size_t len = strlen(line);
  c->key = (char*)malloc(equal_index);
  c->value = (char*)malloc(len - equal_index);

  uint32_t key_start = 0; uint32_t value_start = 0;
  bool start_value = false; bool start_key = false;
  uint32_t prev_space = 0;
  for (uint32_t i = 0; i < len - 1; i++) {
    if (i < equal_index) {
      if (line[i] == ' ' && !prev_space) {
        prev_space = key_start;
      } else if (line[i] != ' ') {
        start_key = true;
        prev_space = 0;
      }
      if (start_key) 
        c->key[key_start++] = line[i];
    } else if (i > equal_index) {
      if (line[i] != ' ') 
        start_value = true;
      if (start_value) 
        c->value[value_start++] = line[i];
    }
  }
  if (prev_space) key_start = prev_space;
  c->key[key_start] = '\0';
  c->value[value_start] = '\0';
  return true;
}

/* return value of matching pair with the given key and section */
char* get_ini_value(ini_parser* p, const char* sec, const char* key) {
  rewind(p->file); // reset file

  char* value = (char*)malloc(MAX_VALUE_SIZE);

  char* current_section; 
  bool wait_till_next_section = true;

  char* line = (char*)malloc(MAX_LINE_SIZE);
  while (fgets(line, MAX_LINE_SIZE, p->file) != NULL) {
    size_t len = strlen(line);
    if (len < 3) continue;
    char front = line[0];  // first character for the line
    if (front == ';' || front == '#' || front == '\n') continue;
    else if (front == '[') {
      line++;
      current_section = (char*)malloc(len + 1);
      strncpy(current_section, line, len - 3);
      current_section[len-3] = '\0';
      wait_till_next_section = false;
      continue;
    }

    if (wait_till_next_section) continue;
    
    if (strcmp(current_section, sec) == 0) {
      pair pa;
      if (!parse_line(line, &pa))
        continue;
      if (strcmp(pa.key, key) == 0) {
        strcpy(value, pa.value);
        free(pa.key); free(pa.value);
        break;
      }
    } else wait_till_next_section = true;
  }
  free(current_section);
  return value;
}

#endif /* INI_H */
