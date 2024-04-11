#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct
{
    char eng[32];
    char uzb[32];

} WORD;

void display(){
    puts("");
    printf(" ENGLISH - UZBEK\n\n");
    printf("1. New Word!\n");
    printf("2. Show all word!\n");
    printf("3. Search word!\n");
    printf("4. Exit!\n\n");
    printf("\t>>> ");
}

void showallWords(){
    WORD c;
    FILE *f = fopen("text.txt", "r");

    if (f == NULL){
        printf("File not found!");
        exit(1);
    }
    printf("+------------+------------+\n");
    printf("|  ENGLISH   |    UZBEK   |\n");
    printf("+------------+------------+\n");

    while (fscanf(f, "%s", c.eng) != EOF){
        fscanf(f, "%s", c.uzb);


        printf("| %10s | %-10s |\n", c.eng,c.uzb);
    }
    printf("+------------+------------+\n");
    fclose(f);
}

void newWord(){
    WORD s;
    puts("");
    printf("ENGKISH: "); scanf("%s", s.eng);
    printf(" UZBEK: ");   scanf("%s", s.uzb);
    FILE *f = fopen("text.txt", "a");
    fprintf(f, "%s %s\n", s.eng, s.uzb);
    fclose(f);
    showallWords();
}

void searchWord(){

    WORD t;
    char text[32];
    int tanlash = -1;
    int aniwlash = 1;

    printf("1.Uzbek perevod! \n");
    printf("2.English perevod! \n");
    printf("3.chiqish! \n");
    scanf("%d", &tanlash);

    FILE *f = fopen("text.txt", "r");

    if (tanlash == 1){
        printf("Sozni kiriting: ");
        scanf("%s", text);
        fscanf(f, "%s", t.eng);
    

    while (fscanf(f, "%s", t.uzb) != EOF){
        if (!strcmp(text, t.eng)){
            printf("\n %s %s", text, t.uzb);
            aniwlash--;
            break;
            }
        fscanf(f, "%s", t.eng);
        }
    }

    else if (tanlash == 2){
       printf("Sozni Kiriting: "); 
       scanf("%s", text);
       fscanf(f, "%s", t.eng);

    while (fscanf(f, "%s", t.uzb)){
        if(!strcmp(t.uzb,text)){
            printf("\n %s %s", text, t.eng);
            aniwlash--;
            break;
        }    
            fscanf(f, "%s", t.eng);
       }
    }
    
    if (tanlash == 3){
        return;
    }
    if (tanlash >= 3 && tanlash <= 0){
        printf("Bunday variant yoq");
        searchWord();
    }
    else if (aniwlash){
        printf("\n Bunday soz Faylda mavjud emas!\n\n");
    }
    
    fclose(f);
}

void Wordfilter(){
  
  char x[32];
  char y[32];
  
  scanf ("%s",x);
  
  
  WORD  word;
  
  FILE *f2 = fopen("text.txt", "r+");
  FILE *f3 = fopen("text1.dat","w+");
  
  while(fscanf(f2, "%s", word.eng) != EOF){
    fscanf(f2, "%s", word.uzb);
    if(!strcmp(word.eng,x)){
      printf("write:  ");
      scanf("%s",y);
      strcpy(word.eng,y);
    }
    else if(!strcmp(word.uzb,x)){
      printf("write:  ");
      scanf("%s",y);
      strcpy(word.uzb,y);
    }
    fprintf(f3,"%s %s\n",word.eng,word.uzb);
  }
  fseek(f2,0,0);
  fseek(f3,0,0);
  
  fscanf(f3,"%s",word.eng);
  
  while (fscanf(f3,"%s",word.uzb) != EOF){
    fprintf(f2,"%s %s\n",word.eng,word.uzb);
    
    fscanf(f3,"%s",word.eng);
  }
  
  fclose(f3);
  fclose(f2);
  
}


int main(){

    int choice = 0;
    while (choice != 4){
       display();
       scanf("%d", &choice);

       switch (choice)
       {
        case 1:
        newWord();
        break;
        case 2:
        showallWords();
        break;
        case 3:
        searchWord();
        break;
        case 4:
        Wordfilter();
        break;
        case 5:
        break;

        default:
        printf("Sorry!");
        break;
       }
    }
    
    return 0;
}