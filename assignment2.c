#include "stdio.h"
#include "stdlib.h"
#include "string.h"


void print_menu() {
  printf("       M A I N  M E N U        \n");
  printf("1. Create the Binary File\n");
  printf("2. Display the contents of the file\n"); 
  printf("3. Seek a specific record\n"); 
  printf("4. Update the contents of a record\n");
  printf("5. Delete a record for the specific name\n");
  printf("6. Exit\n"); 
}

struct student {
  char id[100], name[100], email[100], course[100], grade[100];
};


int main() {
  int numStudents = 0;
  struct student *studs;
  FILE *ptr; 
  while(1) {
    print_menu(); 
    int choice; 
    printf("Please Enter Your Choice....\n");
    scanf("%d", &choice); 
    if (choice == 1) { // create file
      printf("How many records do you want to enter?\n");
      int num;
      scanf("%d", &num);
      numStudents = num;
      struct student *data = malloc(num * sizeof(struct student));
      ptr = fopen("students.bin", "wb");
      for (int i = 0; i < num; i++) {
        char token[100];
        printf("Enter Student ID\n");
        scanf("%s", token);
        strcpy(data[i].id, token);
        printf("Enter Student Name\n");
        scanf("%s", token);
        strcpy(data[i].name, token);
        printf("Enter Email ID\n");
        scanf("%s", token);
        strcpy(data[i].email, token);
        printf("Enter Course ID\n");
        scanf("%s", token);
        strcpy(data[i].course, token);
        printf("Enter Grade\n");
        scanf("%s", token);
        strcpy(data[i].grade, token);
        fwrite(&data[i], sizeof(struct student), 1, ptr);
        printf("******************\n"); 
      }
      studs = data;
      fclose(ptr);
    }  
    else if (choice == 2) {
      for (int i = 0; i < numStudents; i++) {
        printf("Student ID := %s\n", studs[i].id);
        printf("Student Name := %s\n", studs[i].name);
        printf("Email ID := %s\n", studs[i].email);
        printf("Course ID := %s\n", studs[i].course);
        printf("Grade := %s\n", studs[i].grade);
        printf("*****************************\n");
      }
    }
    else if (choice == 3) {
      char search_id[100];
      int found = 0;
      printf("Enter Student ID to search for\n");
      scanf("%s", search_id);
      for (int i=0; i < numStudents; i++) {
        if (strcmp(search_id, studs[i].grade) == 0) {
          printf("Student ID := %s\n", studs[i].id);
          printf("Student Name := %s\n", studs[i].name);
          printf("Email ID := %s\n", studs[i].email);
          printf("Course ID := %s\n", studs[i].course);
          printf("Grade := %s\n", studs[i].grade);
          printf("*****************************\n");
          found = 1;
        }
      }
      if (found == 0) {
        printf("Student ID not found\n");
      }
    }
    else if (choice == 4) {
      char search_id[100];
      int found = 0;
      printf("Enter Student ID to update\n");
      scanf("%s", search_id);
      for (int i=0; i < numStudents; i++) {
        if (strcmp(search_id, studs[i].grade) == 0) {
          printf("Which field to update?\n");
          printf("1. Student ID := %s\n", studs[i].id);
          printf("2. Student Name := %s\n", studs[i].name);
          printf("3. Email ID := %s\n", studs[i].email);
          printf("4. Course ID := %s\n", studs[i].course);
          printf("5. Grade := %s\n", studs[i].grade);
          printf("*****************************\n");
          int field;
          scanf("%d", &field);
          char updated[100]; 
          printf("Update to what?\n");
          scanf("%s", updated); 
          if (field == 1) {
            strcpy(studs[i].id, updated);
          }
          else if (field == 2) {
            strcpy(studs[i].name, updated);
          }
          else if (field == 3) {
            strcpy(studs[i].email, updated);
          }
          else if (field == 4) {
            strcpy(studs[i].course, updated);
          }
          else if (field == 5) {
            strcpy(studs[i].grade, updated);
          }
          found = 1;
        }
      }
      if (found == 0) {
        printf("Student ID not found\n");
      }
    }
    else if (choice == 5) {
      char delete_name[100];
      int del_ind;
      int found;
      printf("What student name to delete?\n");
      scanf("%s", delete_name);
      for (int i=0; i < numStudents; i++) {
        if (strcmp(delete_name, studs[i].name) == 0) {
          found = 1;
          del_ind = i;
        }
      }
      if (found == 0) {
        printf("Student ID not found\n");
      }
      else {
        struct student *data = malloc((numStudents - 1) * sizeof(struct student));
        ptr = fopen("students.bin", "wb");
        for (int i = 0; i < del_ind; i++) {
          strcpy(data[i].id, studs[i].id);
          strcpy(data[i].name, studs[i].name);
          strcpy(data[i].email, studs[i].email);
          strcpy(data[i].course, studs[i].course);
          strcpy(data[i].grade, studs[i].grade);
          fwrite(&data[i], sizeof(struct student), 1, ptr);
        }
        for (int i = del_ind + 1; i < numStudents; i++) {
          strcpy(data[i].id, studs[i].id);
          strcpy(data[i].name, studs[i].name);
          strcpy(data[i].email, studs[i].email);
          strcpy(data[i].course, studs[i].course);
          strcpy(data[i].grade, studs[i].grade);
          fwrite(&data[i], sizeof(struct student), 1, ptr);
        }
        numStudents -= 1; 
        studs = data;
        fclose(ptr);
      }
    }
    else if (choice == 6) {
      break;
    }
  }
}
