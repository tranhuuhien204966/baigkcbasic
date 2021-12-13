

#include <stdio.h>
#include <string.h>
#define nameLength 16
#define emailLength 26
#define phoneLength 13
typedef struct Address {
   char name[nameLength];
   char phone[phoneLength];
   char email[emailLength];
} ad;
ad AddressList[100];

void doidiachi(ad *a, ad *b) {
   ad tmp;
   strcpy(tmp.name, b->name);
    strcpy(tmp.email, b->email);
   strcpy(tmp.phone, b->phone);
  
   strcpy(b->name, a->name);
   strcpy(b->email, a->email);
   strcpy(b->phone, a->phone);
   
   strcpy(a->name, tmp.name);
    strcpy(a->email, tmp.email);
   strcpy(a->phone, tmp.phone);
  
}
void push(ad *address, int i, char name[], char phone[], char email[]) {
   strcpy((address + i)->name, name);
   strcpy((address + i)->phone, phone);
   strcpy((address + i)->email, email);
}
void sort_by_name(ad *address, int n) {
   int i,j;
   for (i = 0; i < n; i++) {
      for (j = i + 1; j < n; j++) {
         if (strcmp((address + i)->name, (address + j)->name) > 0) {
            doidiachi(address + i, address + j);
         }
      }
   }
}
void timkiem(ad *address, char tmp[], int n, int option) {
   int i;
   for ( i = 0; i < n; i++) {
      if (option == 1 && strcmp((address + i)->name, tmp) == 0) {
         printf("Tim thay!\n%s %s %s\n", (address + i)->name, (address + i)->phone, (address + i)->email);
         return;
      }
      if (option == 2 && strcmp((address + i)->email, tmp) == 0) {
         printf("tim thay!\n%s %s %s\n", (address + i)->name, (address + i)->phone, (address + i)->email);
         return;
      }
      if (option == 3 && strcmp((address + i)->phone, tmp) == 0) {
         printf("Tim thay!\n%s %s %s\n", (address + i)->name, (address + i)->phone, (address + i)->email);
         return;
      }
   }
   printf("khong tim thay!");
}

void timkiemnhiphan(ad *address, char name[], int a) {
   int c = 0, b =a - 1;
   while (c<= b) {
      int d = (c + b) / 2;
      int compare = strcmp(name, (address + d)->name);
      if (compare == 0) {
         printf("tim thay!\n%s %s %s\n", (address + d)->name, (address + d)->phone, (address + d)->email);
         return;
      }
      if (compare > 0)
         c = d + 1;
      if (compare < 0)
         b = d- 1;
   }
   printf("khong tim thay!");
}

int main() {
   
   int n,i;
   FILE *input = fopen("danhsachdiachi.txt", "r");
   fscanf(input, "%d", &n);
   for ( i = 0; i < n; i++) {
      char name[nameLength], email[emailLength], phone[phoneLength];
      fscanf(input, "%s", name);
      fscanf(input, "%s", email);
	  fscanf(input, "%s", phone);
    
      push(AddressList, i, name, phone, email);
   }
   printf("doc thanh cong ! danh sach sau:\n");
   for (i = 0; i < n; i++) {
      printf("%s %s %s\n", AddressList[i].name, AddressList[i].phone, AddressList[i].email);
   }

   
   sort_by_name(AddressList, n);
   printf("\n\ndanh sach sau khi sap xep:\n");
   for ( i = 0; i < n; i++) {
      printf("%s %s %s\n", AddressList[i].name, AddressList[i].phone, AddressList[i].email);
   }

   
   int c;
   do {
      printf("\n\nOptions: \n0. Exit\n1. Search by name\n2. Search by email\n3. Search by phone number\n4. Binary Search by name\nSelect option:");
      scanf("%d", &c);
      char tmp[emailLength];
      switch (c) {
      case 1:
         printf("Enter name: ");
         scanf("%s", tmp);
         timkiem(AddressList, tmp, n, 1);
         break;

      case 2:
         printf("Enter name: ");
         scanf("%s", tmp);
         timkiemnhiphan(AddressList, tmp, n);
         break;
	 case 3:
         printf("Enter phone numbers: ");
         scanf("%s", tmp);
         timkiem(AddressList, tmp, n, 3);
         break;

	  case 4:
         printf("Enter email: ");
         scanf("%s", tmp);
         timkiem(AddressList, tmp, n, 2);
         break;

      
      

      default:
         return 0;
         break;
      }
   } while (c != 0);
   fclose(input);
}
