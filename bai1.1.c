

#include <stdio.h>
#include <string.h>
#define nameLength 15
#define emailLength 25
#define phoneLength 11
typedef struct Address {
   char name[nameLength];
   char phone[phoneLength];
   char email[emailLength];
} ad;
ad AddressList[100];
void push(ad *address, int i, char name[], char phone[], char email[]) {
   strcpy((address + i)->name, name);
   strcpy((address + i)->phone, phone);
   strcpy((address + i)->email, email);
}
void swapAddress(ad *a, ad *b) {
   ad tmp;
   strcpy(tmp.name, b->name);
   strcpy(tmp.phone, b->phone);
   strcpy(tmp.email, b->email);
   strcpy(b->name, a->name);
   strcpy(b->phone, a->phone);
   strcpy(b->email, a->email);
   strcpy(a->name, tmp.name);
   strcpy(a->phone, tmp.phone);
   strcpy(a->email, tmp.email);
}

void sort_by_name(ad *address, int n) {
   int i,j;
   for (i = 0; i < n; i++) {
      for (j = i + 1; j < n; j++) {
         if (strcmp((address + i)->name, (address + j)->name) > 0) {
            swapAddress(address + i, address + j);
         }
      }
   }
}
void find(ad *address, char tmp[], int n, int option) {
   int i;
   for ( i = 0; i < n; i++) {
      if (option == 1 && strcmp((address + i)->name, tmp) == 0) {
         printf("Found!\n%s %s %s\n", (address + i)->name, (address + i)->phone, (address + i)->email);
         return;
      }
      if (option == 2 && strcmp((address + i)->email, tmp) == 0) {
         printf("Found!\n%s %s %s\n", (address + i)->name, (address + i)->phone, (address + i)->email);
         return;
      }
      if (option == 3 && strcmp((address + i)->phone, tmp) == 0) {
         printf("Found!\n%s %s %s\n", (address + i)->name, (address + i)->phone, (address + i)->email);
         return;
      }
   }
   printf("NOT FOUND!");
}

void Binary_Find(ad *address, char name[], int n) {
   int l = 0, r = n - 1;
   while (l <= r) {
      int m = (l + r) / 2;
      int compare = strcmp(name, (address + m)->name);
      if (compare == 0) {
         printf("Found!\n%s %s %s\n", (address + m)->name, (address + m)->phone, (address + m)->email);
         return;
      }
      if (compare > 0)
         l = m + 1;
      if (compare < 0)
         r = m - 1;
   }
   printf("NOT FOUND!");
}

int main() {
   // Doc File
   int n,i;
   FILE *input = fopen("inputAddressBook.txt", "r");
   fscanf(input, "%d", &n);
   for ( i = 0; i < n; i++) {
      char name[nameLength], email[emailLength], phone[phoneLength];
      fscanf(input, "%s", name);
      fscanf(input, "%s", phone);
      fscanf(input, "%s", email);
      push(AddressList, i, name, phone, email);
   }
   printf("Read Successfully! The List is:\n");
   for (i = 0; i < n; i++) {
      printf("%s %s %s\n", AddressList[i].name, AddressList[i].phone, AddressList[i].email);
   }

   // Sap xep theo ten
   sort_by_name(AddressList, n);
   printf("\n\nThe List after sorted is:\n");
   for ( i = 0; i < n; i++) {
      printf("%s %s %s\n", AddressList[i].name, AddressList[i].phone, AddressList[i].email);
   }

   // Menu
   int c;
   do {
      printf("\n\nOptions: \n0. Exit\n1. Search by name\n2. Search by email\n3. Search by phone number\n4. Binary Search by name\nSelect option:");
      scanf("%d", &c);
      char tmp[emailLength];
      switch (c) {
      case 1:
         printf("Enter name: ");
         scanf("%s", tmp);
         find(AddressList, tmp, n, 1);
         break;

      case 2:
         printf("Enter email: ");
         scanf("%s", tmp);
         find(AddressList, tmp, n, 2);
         break;

      case 3:
         printf("Enter phone numbers: ");
         scanf("%s", tmp);
         find(AddressList, tmp, n, 3);
         break;

      case 4:
         printf("Enter name: ");
         scanf("%s", tmp);
         Binary_Find(AddressList, tmp, n);
         break;

      default:
         return 0;
         break;
      }
   } while (c != 0);
   fclose(input);
}
