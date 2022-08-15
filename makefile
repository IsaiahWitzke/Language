TARGET_EXEC ?= a.out

BUILD_DIR ?= ./build
SRC_DIRS ?= ./src

SCANNER_CC ?= 		src/scanner.cc
SCANNER_LL ?= 		src/lexer/scanner.ll
PARSER_CC ?= 		src/parser.cc
PARSER_HH ?= 		src/include/parser.h
PARSER_YY ?= 		src/parser/parser.yy
LOCATION_HH_SRC ?= 	src/location.hh
LOCATION_HH ?= 		src/include/location.hh

SRCS := $(shell find $(SRC_DIRS) -name '*.cc' -or -name '*.c' -or -name '*.s') $(PARSER_CC) $(SCANNER_CC)
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

INC_DIRS := $(shell find $(SRC_DIRS) -type d) /usr/lib/llvm-15/lib /usr/include
INC_FLAGS := $(addprefix -I,$(INC_DIRS)) $(shell llvm-config --cxxflags)

# CXX := clang++

COMPILE_FLAGS ?= $(INC_FLAGS) -MMD -MP -g -O3
LDFLAGS ?= $(shell llvm-config --ldflags --system-libs --libs all) -lpthread -lncurses

$(BUILD_DIR)/$(TARGET_EXEC): parser lexer $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

# assembly
# $(BUILD_DIR)/%.s.o: %.s
# 	$(MKDIR_P) $(dir $@)
# 	$(AS) $(ASFLAGS) -c $< -o $@

# # c source
$(BUILD_DIR)/%.c.o: %.c
	$(MKDIR_P) $(dir $@)
	$(CXX) $(COMPILE_FLAGS) $(CXXFLAGS) $(CFLAGS) -c $< -o $@

# c++ source
$(BUILD_DIR)/%.cc.o: %.cc
	$(MKDIR_P) $(dir $@)
	$(CXX) $(COMPILE_FLAGS) $(CXXFLAGS) -c $< -o $@


.PHONY: clean
clean:
	$(RM) -r $(BUILD_DIR)
	$(RM) $(SCANNER_CC) $(PARSER_CC) $(PARSER_HH) $(LOCATION_HH)

parser:
	bison --defines=$(PARSER_HH) -Wcounterexamples -o $(PARSER_CC) $(PARSER_YY)
	mv $(LOCATION_HH_SRC) $(LOCATION_HH)

lexer: 
	flex -o $(SCANNER_CC) $(SCANNER_LL)

-include $(DEPS)

MKDIR_P ?= mkdir -p

.PHONY: run
run:
	$(BUILD_DIR)/$(TARGET_EXEC) tests/test1.mylang

.PHONY: test
test:
	gdb --args $(BUILD_DIR)/$(TARGET_EXEC) tests/test1.mylang
