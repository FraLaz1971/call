#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Define the structure to store student details
struct Student {
    int roll_no;
    char name[50];
};

int main() {
   // Open the binary file for writing
   FILE *wf = fopen("student.dat", "wb");
   
   // Check if file open successfully
   if (!wf) { 
       printf("Cannot open file!\n");
       return 1;
   }

   // Initialize student data
   struct Student wstu[3];
   wstu[0].roll_no = 1;
   strcpy(wstu[0].name, "Ram");
   wstu[1].roll_no = 2;
   strcpy(wstu[1].name, "Shyam");
   wstu[2].roll_no = 3;
   strcpy(wstu[2].name, "Madhu");

   // Write student data to the file
   for (int i = 0; i < 3; i++)
       fwrite(&wstu[i], sizeof(struct Student), 1, wf);

   // Close the file after writing
   fclose(wf);

   // Open the binary file for reading
   wf = fopen("student.dat", "rb");
   
   // Check if file open sucessfully
   if (!wf) { 
       printf("Cannot open file!\n");
       return 1;
   }

   // Read student data from the file
   struct Student rstu[3];
   for (int i = 0; i < 3; i++)
       fread(&rstu[i], sizeof(struct Student), 1, wf);

   // Close the file after reading
   fclose(wf);

   // Display student details
   printf("Students Details:\n");
   for (int i = 0; i < 3; i++) {
       printf("Roll No: %d\n", rstu[i].roll_no);
       printf("Name: %s\n", rstu[i].name);
       printf("\n");
   }

   return 0;
}
