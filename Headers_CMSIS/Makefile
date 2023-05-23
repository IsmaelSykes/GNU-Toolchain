CC = arm-none-eabi-gcc
CFLAGS = -c -mcpu=cortex-m4 -mthumb -std=gnu11
LDFLAGS = -nostdlib -T stm32F401RE.ld -Wl,-Map=${BUILD_DIR}/blink.map
BUILD_DIR = Debug
TARGET = blink
OBJCOPY = arm-none-eabi-objcopy
INCLUDES = -I./math_lib
SRCS += ./math_lib/math_lib.c

build :  prereq ${BUILD_DIR}/blink.elf 

prereq:
	mkdir ${BUILD_DIR}

bin: ${BUILD_DIR}/$(TARGET).bin

${BUILD_DIR}/$(TARGET).bin: ${BUILD_DIR}/blink.elf 
	$(OBJCOPY) -O binary $< $@

${BUILD_DIR}/main.o : src/main.c
	$(CC) $(CFLAGS) $(INCLUDES) $^ -o $@

${BUILD_DIR}/math_lib.o: $(SRCS)
	$(CC) $(CFLAGS) $(INCLUDES) $^ -o $@

${BUILD_DIR}/stm32F401RE_startup.o : src/stm32F401RE_startup.c
	$(CC) $(CFLAGS) $(INCLUDES) $^ -o $@
	
${BUILD_DIR}/blink.elf : ${BUILD_DIR}/main.o ${BUILD_DIR}/stm32F401RE_startup.o ${BUILD_DIR}/math_lib.o
	$(CC) $(LDFLAGS) $^ -o $@

load :
	openocd -f board/st_nucleo_f4.cfg	

clean:
	rmdir /s ${BUILD_DIR}