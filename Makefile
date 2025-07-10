COMPILER_PREFIX := riscv64-unknown-linux-gnu-
CC      := $(COMPILER_PREFIX)gcc          
OBJDUMP := $(COMPILER_PREFIX)objdump      
OBJCOPY := $(COMPILER_PREFIX)objcopy      


OUTPUT_DIR := output


SRCS := $(wildcard src/*.c src/*.S)              # 获取所有.c和.S文件
IGNS :=                                  # 需要忽略的文件列表（可扩展）
SRCS := $(filter-out $(IGNS),$(SRCS))    # 过滤掉忽略的文件
OBJS := $(foreach src,$(SRCS),$(addprefix $(OUTPUT_DIR)/,$(dir $(src))$(basename $(notdir $(src))).o))  # 生成对应的.o文件路径
DEPS := $(OBJS:.o=.d)                    # 生成依赖文件路径


target := gcpt
target := $(OUTPUT_DIR)/$(target).elf




CFLAGS  := -fno-PIE -mcmodel=medany -O2 -Wall -march=rv64gcv -fno-builtin-printf -Wno-main -static -g
LDFLAGS := -Wl,--cref,-Map=$(target:.elf=.map) -Trestore.lds -nostartfiles
LDLIBS  := 

ifdef GCPT_PAYLOAD_PATH
CFLAGS += -DGCPT_PAYLOAD_PATH=\"$(GCPT_PAYLOAD_PATH)\"
endif

INC_DIRS := src

CFLAGS += $(foreach dr,$(INC_DIRS),-I$(abspath $(shell echo $(dr))))


ifeq (,$(findstring j,$(MAKEFLAGS)))
	MAKEFLAGS += -j1
endif


all: $(target) $(target:.elf=.bin) $(target:.elf=.txt)


$(OUTPUT_DIR):
	mkdir -p $(OUTPUT_DIR)


$(target): $(OBJS) | $(OUTPUT_DIR)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) $(LDLIBS) -o $@


#$(OUTPUT_DIR)/src/main.o: EXTRA_CFLAGS := -ffixed-a0 -ffixed-a1 -ffixed-a2 -ffixed-a3 -ffixed-a4 -ffixed-a5 -ffixed-a6 -ffixed-a7
#$(OUTPUT_DIR)/src/serial.o: EXTRA_CFLAGS := -ffixed-a0 -ffixed-a1 -ffixed-a2 -ffixed-a3 -ffixed-a4 -ffixed-a5 -ffixed-a6 -ffixed-a7
#$(OUTPUT_DIR)/src/printf.o: EXTRA_CFLAGS := -ffixed-a0 -ffixed-a1 -ffixed-a2 -ffixed-a3 -ffixed-a4 -ffixed-a5 -ffixed-a6 -ffixed-a7


DEPFLAGS = -MMD -MP -MF $(@:.o=.d)


$(OUTPUT_DIR)/%.o: %.c Makefile | $(OUTPUT_DIR)
	echo "CC $<"
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(DEPFLAGS) $(EXTRA_CFLAGS) -c $< -o $@


$(OUTPUT_DIR)/%.o: %.S Makefile | $(OUTPUT_DIR)
	echo "AS $<"
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(DEPFLAGS) $(EXTRA_CFLAGS) -c $< -o $@


-include $(DEPS)


%.bin: %.elf
	$(OBJCOPY) -S --set-section-flags .bss=alloc,contents -O binary $< $@


%.txt: %.elf
	$(OBJDUMP) -d $< > $@


%.ld: %.ld.s
	cat $< | $(CC) $(CFLAGS) -xc - | grep -v '^#' > $@


debug: CFLAGS += -g -O0
debug: all


release: CFLAGS += -O2
release: all


.PHONY: help
help:
	@echo "可用目标:"
	@echo "  all       - 构建所有目标（默认）"
	@echo "  debug     - 构建带调试信息的目标"
	@echo "  release   - 构建优化后的目标"
	@echo "  clean     - 清理构建文件"
	@echo "  help      - 显示此帮助信息"


.PHONY: clean
clean:
	rm -rf $(OUTPUT_DIR)


.SILENT:
