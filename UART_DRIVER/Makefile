CC = arm-none-eabi-gcc
CFLAGS = -c -lc -mcpu=cortex-m4 -mthumb  -mfloat-abi=soft -std=gnu11
CPPFLAGS = -c -mcpu=cortex-m4 -mthumb 
LDFLAGS = -mcpu=cortex-m4 -lc -lm -mthumb -mfloat-abi=soft --specs=rdimon.specs -T stm32F401RE.ld -Wl,-Map=${BUILD_DIR}/adc.map
BUILD_DIR = Debug
TARGET = adc
OBJCOPY = arm-none-eabi-objcopy
#-------------------------------------
INCLUDES = -I./Core/Inc
SRCS = Core/src
INCLUDE_UART = -I./UART
SRC_UART = UART
INCLUDE_FPU = -I./FPU
SRC_FPU = FPU
INCLUDE_ADC = -I./ADC
SRC_ADC = ADC
#------------------------------------
build :  prereq ${BUILD_DIR}/adc.elf 

prereq:
	mkdir ${BUILD_DIR}

#--------------------------------------
bin: ${BUILD_DIR}/$(TARGET).bin

${BUILD_DIR}/$(TARGET).bin: ${BUILD_DIR}/adc.elf 
	$(OBJCOPY) -O binary $< $@
#--------------------------------------

${BUILD_DIR}/main.o : $(SRCS)/main.c 
	$(CC) $(CFLAGS) $(INCLUDES) $(INCLUDE_UART) $(INCLUDE_ADC) $(INCLUDE_FPU) $^ -o $@ 

${BUILD_DIR}/adc.o : $(SRC_ADC)/adc.c
	$(CC) $(CFLAGS) $(INCLUDES) $(INCLUDE_ADC) $^ -o $@

${BUILD_DIR}/fpu.o : $(SRC_FPU)/fpu.c
	$(CC) $(CFLAGS) $(INCLUDES) $(INCLUDE_FPU) $^ -o $@

${BUILD_DIR}/uart.o : $(SRC_UART)/uart.c
	$(CC) $(CFLAGS) $(INCLUDES) $(INCLUDE_UART) $^ -o $@

${BUILD_DIR}/stm32F401RE_startup.o : $(SRCS)/stm32F401RE_startup.c
	$(CC) $(CFLAGS) $(INCLUDES) $^ -o $@
	
${BUILD_DIR}/adc.elf : ${BUILD_DIR}/uart.o ${BUILD_DIR}/adc.o ${BUILD_DIR}/fpu.o ${BUILD_DIR}/main.o ${BUILD_DIR}/stm32F401RE_startup.o
	$(CC) $(LDFLAGS) $^ -o $@

load :
	openocd -f board/st_nucleo_f4.cfg
	
clean:
	rmdir /s ${BUILD_DIR}