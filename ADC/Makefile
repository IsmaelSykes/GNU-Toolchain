CC = arm-none-eabi-gcc
CFLAGS = -c -lc -mcpu=cortex-m4 -mthumb  -mfloat-abi=soft -std=gnu11
CPPFLAGS = -c -mcpu=cortex-m4 -mthumb 
LDFLAGS = -mcpu=cortex-m4 -lc -lm -mthumb -mfloat-abi=soft --specs=rdimon.specs -T stm32F401RE.ld -Wl,-Map=${BUILD_DIR}/adc.map
BUILD_DIR = Debug
TARGET = adc
OBJCOPY = arm-none-eabi-objcopy

build :  prereq ${BUILD_DIR}/adc.elf 

prereq:
	mkdir ${BUILD_DIR}

bin: ${BUILD_DIR}/$(TARGET).bin

${BUILD_DIR}/$(TARGET).bin: ${BUILD_DIR}/adc.elf 
	$(OBJCOPY) -O binary $< $@

${BUILD_DIR}/main.o : src/main.c
	$(CC) $(CFLAGS) $^ -o $@

${BUILD_DIR}/adc.o : src/adc.c
	$(CC) $(CFLAGS) $^ -o $@
${BUILD_DIR}/fpu.o : src/fpu.c
	$(CC) $(CFLAGS) $^ -o $@
${BUILD_DIR}/uart.o : src/uart.c
	$(CC) $(CFLAGS) $^ -o $@

${BUILD_DIR}/stm32F401RE_startup.o : src/stm32F401RE_startup.c
	$(CC) $(CFLAGS) $^ -o $@
	
${BUILD_DIR}/adc.elf : ${BUILD_DIR}/main.o ${BUILD_DIR}/adc.o ${BUILD_DIR}/fpu.o ${BUILD_DIR}/uart.o ${BUILD_DIR}/stm32F401RE_startup.o
	$(CC) $(LDFLAGS) $^ -o $@

load :
	openocd -f board/st_nucleo_f4.cfg
	
clean:
	rmdir /s ${BUILD_DIR}