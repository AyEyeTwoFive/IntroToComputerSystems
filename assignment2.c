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

struct student create_file(struct student *temp, FILE *ptr) {
  printf("How many records do you want to enter?\n");
  int num;
  scanf("%d", &num);
  struct student data[num];
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
  temp = data;
}

int main() {
  //unsigned char data[1000][9999];
  int numStudents = 0;
  struct student *data;
  FILE *ptr; 
  ptr = fopen("students.bin", "wb");
  while(1) {
    print_menu(); 
    int choice; 
    printf("Please Enter Your Choice....\n");
    scanf("%d", &choice); 
    if (choice == 1) { // create file
      //static const struct student temp[] = create_file(ptr);
      //memcpy(data, temp, sizeof temp);
      create_file(data, ptr);
    }  
    else if (choice == 2) {
      for (int i = 0; i < sizeof(data) / sizeof(struct student); i++) {
        printf("Student ID := %s\n", data[i].id);
        printf("Student Name := %s\n", data[i].name);
        printf("Email ID := %s\n", data[i].email);
        printf("Course ID := %s\n", data[i].course);
        printf("Grade := %s\n", data[i].grade);
        printf("*****************************\n");
      }
    }
  }
}
