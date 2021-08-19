AS = /home/moon/Desktop/aarch64-elf-7.5.0-Linux-x86_64/bin/aarch64-elf-as
CC = /home/moon/Desktop/aarch64-elf-7.5.0-Linux-x86_64/bin/aarch64-elf-gcc
OJ = /home/moon/Desktop/aarch64-elf-7.5.0-Linux-x86_64/bin/aarch64-elf-objcopy

MODEL = raspi3
LINKER_SCRIPT = ./moonos.ld
CFLAGS =  -ffreestanding -c

ASM_SRCS = $(wildcard boot/*.S)
ASM_OBJS = $(patsubst boot/%.S, build/%.o, $(ASM_SRCS))

#C_SRCS += $(notdir $(wildcard boot/*.c))
C_SRCS = $(wildcard kernel/*.c)
C_OBJS = build/$(notdir $(patsubst %.c, build/%.o, $(C_SRCS)))

#INC_DIRS = -I kernel

moonos = build/moonos.elf
moonos_img = moonos.img

.PHONY: all clean run debug gdb

all:
	mkdir -p build
	${AS} -c ${ASM_SRCS} -o ${ASM_OBJS}
	${CC} ${CFLAGS} ${C_SRCS} -o ${C_OBJS} -O2 -Wall -Wextra
	$(CC) -T $(LINKER_SCRIPT) -o $(moonos) -ffreestanding -nostdlib $(ASM_OBJS) $(C_OBJS) -lgcc
	$(OJ) $(moonos) -O binary $(moonos_img)

clean:
	@rm -fr build