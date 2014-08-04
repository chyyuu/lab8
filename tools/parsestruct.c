//#include <stdio.h>
#define UCORE_PARSE 1
#include <dlfcn.h>
#include <proc.h>
int (* myprintf)(const char *format, ...);
#define OFFSET_OF(type, field) (  (unsigned long)&( ((struct type *)0)->field ) )

char *ucore_name="ucore";
int main(void){
  void *handle;
  handle=dlopen("/lib/libc-2.18.so",RTLD_NOW);
  if(!handle){
    return -1;
  };
  myprintf=dlsym(handle,"printf");
  if(!myprintf){
    return -2;
  }
  myprintf(
     "sizeof_proc_struct = %lu\n"
     "ps_state = %lu\n"
     "ps_pid = %lu\n"
     "ps_runs = %lu\n"
     "ps_kstack = %lu\n"
     "ps_need_resched = %lu\n"
     "ps_parent = %lu\n"
     "ps_mm = %lu\n"
     "ps_context = %lu\n"
     "ps_trapframe = %lu\n"
     "ps_cr3 = %lu\n"
     "ps_flags = %lu\n"
     "ps_name = %lu\n"
     "ps_list_link = %lu\n"
     "ps_hash_link = %lu\n"
     "ps_exit_code = %lu\n"
     "ps_wait_state = %lu\n"
     "ps_cptr = %lu\n"
     "ps_yptr = %lu\n"
     "ps_optr = %lu\n"
     "ps_run_queue = %lu\n"
     "ps_run_link = %lu\n"
     "ps_time_slice = %lu\n"
     "ps_lab6_run_pool = %lu\n"
     "ps_lab6_stride = %lu\n"
     "ps_lab6_priority = %lu\n"
     "ps_filesp = %lu\n",
     (unsigned long)sizeof(struct proc_struct),
     OFFSET_OF(proc_struct,state),
     OFFSET_OF(proc_struct,pid),
     OFFSET_OF(proc_struct,runs),
     OFFSET_OF(proc_struct,kstack),
     OFFSET_OF(proc_struct,need_resched),
     OFFSET_OF(proc_struct,parent),
     OFFSET_OF(proc_struct,mm),
     OFFSET_OF(proc_struct,context),
     OFFSET_OF(proc_struct,tf),
     OFFSET_OF(proc_struct,cr3),
     OFFSET_OF(proc_struct,flags),
     OFFSET_OF(proc_struct,name),
     OFFSET_OF(proc_struct,list_link),
     OFFSET_OF(proc_struct,hash_link),
     OFFSET_OF(proc_struct,exit_code),
     OFFSET_OF(proc_struct,wait_state),
     OFFSET_OF(proc_struct,cptr),
     OFFSET_OF(proc_struct,yptr),
     OFFSET_OF(proc_struct,optr),
     OFFSET_OF(proc_struct,rq),
     OFFSET_OF(proc_struct,run_link),
     OFFSET_OF(proc_struct,time_slice),
     OFFSET_OF(proc_struct,lab6_run_pool),
     OFFSET_OF(proc_struct,lab6_stride),
     OFFSET_OF(proc_struct,lab6_priority),
     OFFSET_OF(proc_struct,filesp));
  
  return 0;
}
          
