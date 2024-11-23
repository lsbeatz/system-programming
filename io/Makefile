CC = gcc
CC_OPT = -g -Wall

DIR = out

SRCS := $(wildcard *.c)
OBJS := $(addprefix $(DIR)/, $(SRCS:%.c=%))

all: dir $(OBJS)

dir:
	@mkdir -p $(DIR)

$(DIR)/%: %.c
	$(CC) $(CC_OPT) $^ -o $@

clean:
	@rm -rf $(DIR)
