#include <stdio.h>
#include <ulib.h>

void print_hello(void) {
    cprintf("print_hello: Hello world!!.\n");
}
void print_me(void) {
    cprintf("print_me: I am process %d.\n", getpid());
}
void print_bye(void) {
    cprintf("print_bye: \n");
    cprintf("hello pass.\n");
}
int
main(void) {
    cprintf("main: begin\n");
    print_hello();
    print_me();
    print_bye();
    return 0;
}

