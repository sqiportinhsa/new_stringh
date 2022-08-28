TARGET = build/test_of_functions.exe
CPPFLAGS = -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wmissing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -D_DEBUG -D_EJUDGE_CLIENT_SIDE

.PHONY: all
all: $(TARGET)

$(TARGET): bin/test_of_functions.o bin/functions.o functions.h
	g++ bin/test_of_functions.o bin/functions.o -o $(TARGET) $(CPPFLAGS)

bin/test_of_functions.o: test_of_functions.cpp functions.h
	g++ -c test_of_functions.cpp -o bin/test_of_functions.o $(CPPFLAGS)

bin/functions.o: functions.cpp functions.h
	g++ -c functions.cpp -o bin/functions.o $(CPPFLAGS)
