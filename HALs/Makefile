CC = arm-none-eabi-gcc
CFLAGS = -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xE -c -lc -mcpu=cortex-m4 -mthumb  -mfloat-abi=soft -std=gnu11
LDFLAGS = -mcpu=cortex-m4 -lc -lm -mthumb -mfloat-abi=soft --specs=rdimon.specs -T stm32F401RE.ld -Wl,-Map=${BUILD_DIR}/adc.map
BUILD_DIR = Debug
TARGET = hal
OBJCOPY = arm-none-eabi-objcopy
#-------------------------------------
INCLUDE = -I./Core/Inc
INCLUDE_LEGACY = -I./Drivers/STM32F4xx_HAL_Driver/Inc/Legacy
INCLUDE_HAL    = -I./Drivers/STM32F4xx_HAL_Driver/Inc
INCLUDE_DEVICE = -I./Drivers/CMSIS/Device/ST/STM32F4xx/Include
INCLUDE_CMSIS  = -I./Drivers/CMSIS/Include
SRC            = Core/Src
SRC_HAL        = Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal.c
SRC_HAL_CORTEX = Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_cortex.c
SRC_HAL_DMA    = Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma.c
SRC_HAL_DMA_EX = Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma_ex.c
SRC_HAL_EXTI = Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_exti.c
SRC_HAL_FLASH = Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash.c
SRC_HAL_FLASH_EX = Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ex.c
SRC_HAL_FLASH_RAMFUNC = Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ramfunc.c
SRC_HAL_PWR = Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr.c
SRC_HAL_PWR_EX = Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr_ex.c
SRC_HAL_RCC = Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc.c
SRC_HAL_RCC_EX = Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc_ex.c
SRC_HAL_TIM = Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim.c
SRC_HAL_TIM_EX = Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim_ex.c
SRC_HAL_GPIOS  = Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_gpio.c
SRC_HAL_UART   = Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_uart.c
#------------------------------------
build :  prereq ${BUILD_DIR}/hal.elf 

prereq: 
	mkdir ${BUILD_DIR}

#--------------------------------------
bin: ${BUILD_DIR}/$(TARGET).bin

${BUILD_DIR}/$(TARGET).bin: ${BUILD_DIR}/hal.elf 
	$(OBJCOPY) -O binary $< $@
#--------------------------------------

${BUILD_DIR}/stm32f4xx_hal.o : $(SRC_HAL)
	$(CC) $(CFLAGS) $(INCLUDE) $(INCLUDE_LEGACY) $(INCLUDE_HAL) $(INCLUDE_DEVICE) $(INCLUDE_CMSIS) $^ -o $@

${BUILD_DIR}/stm32f4xx_hal_cortex.o :$(SRC_HAL_CORTEX)
	$(CC) $(CFLAGS) $(INCLUDE) $(INCLUDE_LEGACY) $(INCLUDE_HAL) $(INCLUDE_DEVICE) $(INCLUDE_CMSIS) $^ -o $@ 

${BUILD_DIR}/stm32f4xx_hal_dma.o :$(SRC_HAL_DMA)
	$(CC) $(CFLAGS) $(INCLUDE) $(INCLUDE_LEGACY) $(INCLUDE_HAL) $(INCLUDE_DEVICE) $(INCLUDE_CMSIS) $^ -o $@ 

${BUILD_DIR}/stm32f4xx_hal_dma_ex.o :$(SRC_HAL_DMA_EX)
	$(CC) $(CFLAGS) $(INCLUDE) $(INCLUDE_LEGACY) $(INCLUDE_HAL) $(INCLUDE_DEVICE) $(INCLUDE_CMSIS) $^ -o $@ 

${BUILD_DIR}/stm32f4xx_hal_exti.o :$(SRC_HAL_EXTI)
	$(CC) $(CFLAGS) $(INCLUDE) $(INCLUDE_LEGACY) $(INCLUDE_HAL) $(INCLUDE_DEVICE) $(INCLUDE_CMSIS) $^ -o $@ 

${BUILD_DIR}/stm32f4xx_hal_flash.o :$(SRC_HAL_FLASH) 
	$(CC) $(CFLAGS) $(INCLUDE) $(INCLUDE_LEGACY) $(INCLUDE_HAL) $(INCLUDE_DEVICE) $(INCLUDE_CMSIS) $^ -o $@ 

${BUILD_DIR}/stm32f4xx_hal_flash_ex.o :$(SRC_HAL_FLASH_EX)
	$(CC) $(CFLAGS) $(INCLUDE) $(INCLUDE_LEGACY) $(INCLUDE_HAL) $(INCLUDE_DEVICE) $(INCLUDE_CMSIS) $^ -o $@ 

${BUILD_DIR}/stm32f4xx_hal_flash_ramfunc.o :$(SRC_HAL_FLASH_RAMFUNC)
	$(CC) $(CFLAGS) $(INCLUDE) $(INCLUDE_LEGACY) $(INCLUDE_HAL) $(INCLUDE_DEVICE) $(INCLUDE_CMSIS) $^ -o $@ 

${BUILD_DIR}/stm32f4xx_hal_gpio.o : $(SRC_HAL_GPIOS)
	$(CC) $(CFLAGS) $(INCLUDE_LEGACY) $(INCLUDE_HAL) $(INCLUDE_DEVICE) $(INCLUDE_CMSIS) $^ -o $@ 

${BUILD_DIR}/stm32f4xx_hal_pwr.o :$(SRC_HAL_PWR)
	$(CC) $(CFLAGS) $(INCLUDE) $(INCLUDE_LEGACY) $(INCLUDE_HAL) $(INCLUDE_DEVICE) $(INCLUDE_CMSIS) $^ -o $@ 

${BUILD_DIR}/stm32f4xx_hal_pwr_ex.o :$(SRC_HAL_PWR_EX)
	$(CC) $(CFLAGS) $(INCLUDE) $(INCLUDE_LEGACY) $(INCLUDE_HAL) $(INCLUDE_DEVICE) $(INCLUDE_CMSIS) $^ -o $@ 

${BUILD_DIR}/stm32f4xx_hal_rcc.o :$(SRC_HAL_RCC)
	$(CC) $(CFLAGS) $(INCLUDE) $(INCLUDE_LEGACY) $(INCLUDE_HAL) $(INCLUDE_DEVICE) $(INCLUDE_CMSIS) $^ -o $@ 

${BUILD_DIR}/stm32f4xx_hal_rcc_ex.o :$(SRC_HAL_RCC_EX)
	$(CC) $(CFLAGS) $(INCLUDE) $(INCLUDE_LEGACY) $(INCLUDE_HAL) $(INCLUDE_DEVICE) $(INCLUDE_CMSIS) $^ -o $@ 

${BUILD_DIR}/stm32f4xx_hal_tim.o :$(SRC_HAL_TIM)
	$(CC) $(CFLAGS) $(INCLUDE) $(INCLUDE_LEGACY) $(INCLUDE_HAL) $(INCLUDE_DEVICE) $(INCLUDE_CMSIS) $^ -o $@ 

${BUILD_DIR}/stm32f4xx_hal_tim_ex.o :$(SRC_HAL_TIM_EX)
	$(CC) $(CFLAGS) $(INCLUDE) $(INCLUDE_LEGACY) $(INCLUDE_HAL) $(INCLUDE_DEVICE) $(INCLUDE_CMSIS) $^ -o $@ 

${BUILD_DIR}/stm32f4xx_hal_uart.o : $(SRC_HAL_UART)
	$(CC) $(CFLAGS) $(INCLUDE) $(INCLUDE_LEGACY) $(INCLUDE_HAL) $(INCLUDE_DEVICE) $(INCLUDE_CMSIS) $^ -o $@ 

${BUILD_DIR}/main.o : $(SRC)/main.c 
	$(CC) $(CFLAGS) $(INCLUDE) $(INCLUDE_LEGACY) $(INCLUDE_HAL) $(INCLUDE_DEVICE) $(INCLUDE_CMSIS) $^ -o $@ 


${BUILD_DIR}/stm32f4xx_hal_msp.o :$(SRC)/stm32f4xx_hal_msp.c
	$(CC) $(CFLAGS) $(INCLUDE) $(INCLUDE_LEGACY) $(INCLUDE_HAL) $(INCLUDE_DEVICE) $(INCLUDE_CMSIS) $^ -o $@ 

${BUILD_DIR}/stm32f4xx_it.o :$(SRC)/stm32f4xx_it.c
	$(CC) $(CFLAGS) $(INCLUDE) $(INCLUDE_LEGACY) $(INCLUDE_HAL) $(INCLUDE_DEVICE) $(INCLUDE_CMSIS) $^ -o $@ 

${BUILD_DIR}/syscalls.o :$(SRC)/syscalls.c
	$(CC) $(CFLAGS) $(INCLUDE) $(INCLUDE_LEGACY) $(INCLUDE_HAL) $(INCLUDE_DEVICE) $(INCLUDE_CMSIS) $^ -o $@ 

${BUILD_DIR}/sysmem.o :$(SRC)/sysmem.c
	$(CC) $(CFLAGS) $(INCLUDE) $(INCLUDE_LEGACY) $(INCLUDE_HAL) $(INCLUDE_DEVICE) $(INCLUDE_CMSIS) $^ -o $@ 

${BUILD_DIR}/system_stm32f4xx.o :$(SRC)/system_stm32f4xx.c
	$(CC) $(CFLAGS) $(INCLUDE) $(INCLUDE_LEGACY) $(INCLUDE_HAL) $(INCLUDE_DEVICE) $(INCLUDE_CMSIS) $^ -o $@ 

${BUILD_DIR}/stm32F401RE_startup.o : $(SRC)/stm32F401RE_startup.c
	$(CC) $(CFLAGS) $(INCLUDE) $(INCLUDE_LEGACY) $(INCLUDE_HAL) $(INCLUDE_DEVICE) $(INCLUDE_CMSIS) $^ -o $@

${BUILD_DIR}/hal.elf : ${BUILD_DIR}/stm32f4xx_hal_exti.o ${BUILD_DIR}/stm32f4xx_hal.o ${BUILD_DIR}/stm32f4xx_hal_cortex.o ${BUILD_DIR}/stm32f4xx_hal_dma.o ${BUILD_DIR}/stm32f4xx_hal_dma_ex.o ${BUILD_DIR}/stm32f4xx_hal_flash.o ${BUILD_DIR}/stm32f4xx_hal_flash_ex.o ${BUILD_DIR}/stm32f4xx_hal_flash_ramfunc.o ${BUILD_DIR}/stm32f4xx_hal_gpio.o ${BUILD_DIR}/stm32f4xx_hal_pwr.o ${BUILD_DIR}/stm32f4xx_hal_pwr_ex.o ${BUILD_DIR}/stm32f4xx_hal_rcc.o ${BUILD_DIR}/stm32f4xx_hal_rcc_ex.o ${BUILD_DIR}/stm32f4xx_hal_tim.o ${BUILD_DIR}/stm32f4xx_hal_tim_ex.o ${BUILD_DIR}/stm32f4xx_hal_uart.o ${BUILD_DIR}/main.o ${BUILD_DIR}/stm32f4xx_hal_msp.o ${BUILD_DIR}/stm32f4xx_it.o ${BUILD_DIR}/system_stm32f4xx.o ${BUILD_DIR}/stm32F401RE_startup.o
	$(CC) $(LDFLAGS) $^ -o $@
	
clean:
	rmdir /s ${BUILD_DIR}