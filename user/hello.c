#include <stdio.h>
#include <ulib.h>
#include <string.h>
#include <dir.h>
#include <file.h>
#include <error.h>
#include <unistd.h>

#define printf(...)                     fprintf(1, __VA_ARGS__)
#define putc(c)                         printf("%c", c)

#define BUFSIZE 10
char name[BUFSIZE]="";

void print_hello(void) {
    cprintf("print_hello: %s, Hello world!!.\n",name);
}
void print_me(void) {
    cprintf("print_me: I am process %d.\n", getpid());
}
void print_bye(void) {
    cprintf("print_bye: \n");
    cprintf("hello pass.\n");
}

void myreadline(char *prompt){
  int ret, i=0;
  if(prompt!=NULL) {
      printf("%s",prompt);
  }
  while(1) {
    char c;
    if ((ret= read(0,&c,sizeof(char)))< 0) {
      return;
    }
    else if (ret==0) {
        if(i> 0){
           name[i]= '\0';
           break;
        }
        return;
    }

    if (c == 3) {
            return ;
    }
    else if (c >= ' ' && i < BUFSIZE - 1) {
         putc(c);
         name[i ++] = c;
    }
    else if (c == '\b' && i > 0) {
         putc(c);
         i --;
    }
    else if (c == '\n' || c == '\r') {
         putc(c);
         name[i] = '\0';
         break;
    }
  }
  return;
}


int
main(void) {
    cprintf("main: begin\n");
    myreadline(">>>");
    print_hello();
    print_me();
    print_bye();
    return 0;
}

