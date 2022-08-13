TARGET_EXEC ?= a.out

BUILD_DIR ?= ./build
SRC_DIRS ?= ./src

SRCS := $(shell find $(SRC_DIRS) -name '*.cc' -or -name '*.c' -or -name '*.s')
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

INC_DIRS := $(shell find $(SRC_DIRS) -type d) /usr/lib/llvm-15/lib
INC_FLAGS := $(addprefix -I,$(INC_DIRS)) $(shell llvm-config --cxxflags)

# CXX := clang++

COMPILE_FLAGS ?= $(INC_FLAGS) -MMD -MP -g -O3
LDFLAGS ?= $(shell llvm-config --ldflags --system-libs --libs all) -lpthread -lncurses

$(BUILD_DIR)/$(TARGET_EXEC): lexer $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

# assembly
# $(BUILD_DIR)/%.s.o: %.s
# 	$(MKDIR_P) $(dir $@)
# 	$(AS) $(ASFLAGS) -c $< -o $@

# # c source
# $(BUILD_DIR)/%.c.o: %.c
# 	$(MKDIR_P) $(dir $@)
# 	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

# c++ source
$(BUILD_DIR)/%.cc.o: %.cc
	$(MKDIR_P) $(dir $@)
	$(CXX) $(COMPILE_FLAGS) $(CXXFLAGS) -c $< -o $@


.PHONY: clean
clean:
	$(RM) -r $(BUILD_DIR)

.PHONY: run
run:
	$(BUILD_DIR)/$(TARGET_EXEC)

.PHONY: parser
parser:
	bison --defines=src/include/y.tab.h -o src/parser/y.tab.cc src/parser/my_parser.yy
# $(CC) -o src/lexer/lexer $(INC_FLAGS) src/lexer/lex.yy.c

.PHONY: lexer
lexer: parser
	flex -o src/lexer/lex.yy.c src/lexer/my_lexer.lex 
# $(CC) -o src/lexer/lexer $(INC_FLAGS) src/lexer/lex.yy.c

-include $(DEPS)

MKDIR_P ?= mkdir -p
