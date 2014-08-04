all:tools/parsestruct

KINCLUDE	+= kern/debug/ \
			   kern/driver/ \
			   kern/trap/ \
			   kern/mm/ \
			   kern/libs/ \
			   kern/sync/ \
			   kern/fs/    \
			   kern/process/ \
			   kern/schedule/ \
			   kern/syscall/  \
			   kern/fs/swap/ \
			   kern/fs/vfs/ \
			   kern/fs/devs/ \
			   kern/fs/sfs/ 

KCFLAGS		+= $(addprefix -I,$(KINCLUDE))

tools/parsestruct:tools/parsestruct.c
	gcc -g $(KCFLAGS) -o tools/parsestruct tools/parsestruct.c
