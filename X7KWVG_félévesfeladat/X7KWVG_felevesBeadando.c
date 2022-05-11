#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

struct mesg_buffer {
long mesg_type;
char mesg_text[200];
} message;

int main()
{

int szamTomb[8];
int osztok[4];
int i, n, a, b, c;
FILE *szamok;
FILE *osztokki;

szamok = fopen("szamok.txt", "r");
osztokki = fopen("osztok.txt","w");

if (NULL == szamok) {
printf("A fajl nem nyithato meg!\n");
exit(1);
}


for (i = 0; i < 8; i++){

fscanf(szamok, "%d", &szamTomb[i]);

}
fclose(szamok);

i = 0;

for(n = 0; n < 4; n++){

a = szamTomb[i];
b = szamTomb[i+1];
i = i + 2;

printf("Beolvasott szamok: %d\t%d\n",a, b);
if(a < b){

c = a;
a = b;
b = c;

}

c = b; 

while(a%c !=0 || b%c !=0){

c = c-1;
}

osztok[n] = c;

key_t key;
int msgid;

key = ftok("szamok",65);

msgid = msgget(key, 0666 | IPC_CREAT);
message.mesg_type = 1;

printf("Legnagyobb kozos osztojuk: %d\n",c);
//fgets(message.mesg_text,MAX,stdin);

msgsnd(msgid, &message, sizeof(message), 0);

if(osztokki != NULL)
fprintf(osztokki, "%d %d %d\n",a,b,osztok[n]);
}
fclose(osztokki);
return 0;
}

