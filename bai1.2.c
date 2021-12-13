#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define nameLength 20
#define emailLength 20
#define numLength 12
typedef struct Address {
   char name[nameLength];
   char num[numLength];
   char email[emailLength];
   struct Address *next;
} ad;

void Push(ad *dc, char name[], char num[], char email[]) {
   ad *tmp = dc;
   tmp = (ad *)malloc(sizeof(ad));
   strcpy(tmp->name, name);
   strcpy(tmp->num, num);
   strcpy(tmp->email, email);
   tmp->next = NULL;
   while (dc->next != NULL) {
      dc = dc->next;
   }
   dc->next = tmp;
}

void Find(ad *dc, char name[]) {
   ad *dcNode;
   dcNode = dc;
   while (dcNode != NULL) {
      if (strcmp(dcNode->name, name) == 0) {
         printf("\n%s %s %s\n", dcNode->name, dcNode->num, dcNode->email);
         return;
      }
      dcNode = dcNode->next;
   }
   printf("Khong co");
}

int main() {
   int n,i;
   FILE *input = fopen("danhsachdiachi.txt", "r");
   ad *root = NULL;
   root = (ad *)malloc(sizeof(ad));
   fscanf(input, "%d", &n);
   for ( i = 0; i < n; i++) {
      char name[nameLength], email[emailLength], num[numLength];
      fscanf(input, "%s", name);
      fscanf(input, "%s", num);
      fscanf(input, "%s", email);
      Push(root, name, num, email);
   }
   printf("Danh sach la:\n");

   ad *tmp = root;
   while (tmp != NULL) {
      printf("%s %s %s\n", tmp->name, tmp->num, tmp->email);
      tmp = tmp->next;
   }

  int a;
  do{
	  printf("\nChon chuong trinh: \n1. Tim kiem ten\n");
      scanf("%d", &a);
      char tmp[emailLength];
      switch (a) {
      case 1:
         printf("Tim ten: ");
         scanf("%s", tmp);
         Find(root, tmp);
         break;

      default:
         return 0;
         break;}
	 } while (a != 0);
   fclose(input);
}
