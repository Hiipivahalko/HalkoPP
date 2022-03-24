TARGET_EXEC := cpp-libs.exe

BUILD_DIR := ./build
SRC_DIRS := ./src
STD_VERSION := -std=c++11
CXX := g++

# Find all C++ files we want to compile
SRCS := $(shell find $(SRC_DIRS) -name '*.cpp')

# String substitution for every C/C++ file.
# As an example, hello.cpp turns into ./build/hello.cpp.o
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)

# String substitution (suffix version without %).
# As an example, ./build/hello.cpp.o turns into ./build/hello.cpp.d
DEPS := $(OBJS:.o=.d)

# Every folder in ./src will need to be passed to GCC so that it can find header files
INC_DIRS := $(shell find $(SRC_DIRS) -type d)
# Add a prefix to INC_DIRS. So moduleA would become -ImoduleA. GCC understands this -I flag
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

# The -MMD and -MP flags together generate Makefiles for us!
# These files will have .d instead of .o as the output.
#CPPFLAGS := -fmodules-ts $(INC_FLAGS) -MMD -MP -Wall -Werror
CPPFLAGS := $(INC_FLAGS) -MMD -MP -Wall -Weffc++ -Wextra -Wsign-conversion
#You can disable compiler extensions by adding the -pedantic-errors flag to the compile command line.


# The final build step.
$(TARGET_EXEC): $(OBJS)
	$(CXX) $(STD_VERSION) $(OBJS) -o $@ -O2


# Build step for C++ source
$(BUILD_DIR)/%.cpp.o: %.cpp
	mkdir -p $(dir $@)
	$(CXX) $(STD_VERSION) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@ -O2

.PHONY: clean
clean:
	rm -r $(BUILD_DIR)

cache-clean:
	rm -r gcm.cache

# Include the .d makefiles. The - at the front suppresses the errors of missing
# Makefiles. Initially, all the .d files will be missing, and we don't want those
# errors to show up.
-include $(DEPS)


