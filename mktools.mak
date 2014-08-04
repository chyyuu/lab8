all:tools/parsestruct

KINCLUDE	+= kern/debug/ \
			   kern/driver/ \
			   kern/trap/ \
			   kern/mm/ \
			   kern/sync/ \
			   kern/fs/    \
			   kern/libs/   \
			   kern/process/ \
			   kern/schedule/ \
			   kern/syscall/  \
			   kern/fs/swap/ \
			   kern/fs/vfs/ \
			   kern/fs/devs/ \
			   kern/fs/sfs/  \
			   libs/

KCFLAGS		+= $(addprefix -I,$(KINCLUDE))

tools/parsestruct:tools/parsestruct.c
	gcc -m32 -g $(KCFLAGS) -ldl -o tools/parsestruct tools/parsestruct.c
