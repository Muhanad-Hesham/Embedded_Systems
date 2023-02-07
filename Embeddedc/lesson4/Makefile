
#@copyrights : Muhand Hesham
CC=arm-none-eabi-
CFLAGS=-gdwarf-2 -g -mcpu=cortex-m4
INCS= -I .
LIBS=
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)
AS= $(wildcard *.s)
ASOBJ= $(AS:.s=.o)
project_name = unit3_lab3_cortex_m4
	
all: $(project_name).bin
	@echo "========Build is DOne========"

	
%.o: %.c
	$(CC)gcc.exe -c $(CFLAGS) $(INCS) $< -o $@	
	
%.o: %.s
	$(CC)as.exe $(CFLAGS) $< -o $@
	
$(project_name).elf: $(OBJ) $(ASOBJ)
	$(CC)ld.exe -T linker_script.ld $(LIBS) $(OBJ) $(ASOBJ) -o $@ -Map=Map_file.map
	cp $(project_name).elf $(project_name).axf

$(project_name).bin: $(project_name).elf
	$(CC)objcopy.exe -O binary $< $@
	

clean_all:
	rm *.o *.elf *.bin *.axf

clean:      
	rm *.elf *.bin
	

