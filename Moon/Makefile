AS = /home/moon/Desktop/aarch64-elf-7.5.0-Linux-x86_64/bin/aarch64-elf-as
CC = /home/moon/Desktop/aarch64-elf-7.5.0-Linux-x86_64/bin/aarch64-elf-gcc
OJ = /home/moon/Desktop/aarch64-elf-7.5.0-Linux-x86_64/bin/aarch64-elf-objcopy

MODEL = raspi3
LINKER_SCRIPT = ./moonos.ld

ASM_SRCS = $(wildcard boot/*.S)
ASM_OBJS = $(patsubst boot/%.S, build/%.o, $(ASM_SRCS))

#C_SRCS += $(notdir $(wildcard boot/*.c))
C_SRCS = $(notdir $(wildcard kernel/*.c))
C_SRCS += $(notdir $(wildcard hal/$(MODEL)/*.c))
C_SRCS += $(notdir $(wildcard util/*.c))
C_OBJS = $(patsubst %.c, build/%.o, $(C_SRCS))

VPATH =	hal/$(MODEL) \
		util \
		kernel


INC_DIRS = -I include \
           -I hal     \
		   -I util

		   

CFLAGS = -ffreestanding -g
LDFLAGS = -nostartfiles -nostdlib -nodefaultlibs -static -lgcc

moonos = build/moonos.elf
moonos_img = moonos.img

.PHONY: all clean

all: $(moonos_img)

$(moonos_img): $(moonos)
	$(OJ) $(moonos) -O binary $(moonos_img)

$(moonos): $(LINKER_SCRIPT) $(C_OBJS) $(ASM_OBJS)
	echo cobj $(C_OBJS)
	$(CC) -T $(LINKER_SCRIPT) -o $(moonos)  -ffreestanding -nostdlib $(C_OBJS) $(ASM_OBJS) $(LDFLAGS)


build/%.o: %.c
	mkdir -p $(shell dirname $@)
	$(CC) $(INC_DIRS) -c $(CFLAGS) -o $@ $<



$(ASM_OBJS): $(ARM_SRCS)
	mkdir -p $(shell dirname $@)
	echo 3 $(ASM_SRCS)
	echo 4 $(ASM_OBJS)
	${AS} -c ${ASM_SRCS} -o ${ASM_OBJS}

clean:
	@rm -fr build

run: $(moonos)
	qemu-system-aarch64 -M raspi3 -serial stdio -kernel $(moonos)

debug: $(moonos)
	qemu-system-aarch64 -M raspi3 -serial stdio -kernel $(moonos) -gdb tcp::1234,ipv4

gdb:
	gdb-multiarch

kill:
	kill -9 `ps aux | grep 'qemu' | awk 'NR==1{print $$2}'`