#directories
IDIR = inc
ODIR = obj
SDIR = src
LDIR = libmx
#compiler settings
CC = clang
CFLAGS = -I $(IDIR) -I $(LDIR)/$(IDIR)
CCFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic -I $(IDIR)
#dependencies
NAME = pathfinder
LIB = libmx.a
#headers
DEPS := $(wildcard $(IDIR)/*.h)
#sources
SRCS := $(wildcard $(SDIR)/*.c)
#objects
_OBJS = $(SRCS:.c=.o)
OBJS = $(subst $(SDIR),$(ODIR),$(_OBJS))

#TARGETS
all: $(NAME)

#make library
$(LDIR)/$(LIB):
	make -C $(LDIR)

#make objects
$(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
	mkdir -p obj
	$(CC) $(CFLAGS) -c $< -o $@

#make excecutable
$(NAME): $(OBJS) $(LDIR)/$(LIB)
	$(CC) $(CFLAGS) $^ -o $@

.PHONY: clean uninstall reinstall

#delete all files
uninstall: clean
	rm -f $(NAME)
	make $@ -C $(LDIR)

#remove all temp files
clean:
	rm -rf $(ODIR)
	make $@ -C $(LDIR)

#rebuild project
reinstall: uninstall all
