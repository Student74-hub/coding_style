# Makefile — сборка проекта "Комплексное число" под Windows (mingw32-make)

CXX      = g++
CXXFLAGS = -Wall -std=c++11
LDFLAGS  =

# Исполняемый файл и объектные файлы в подкаталогах
PROG = bin\complex.exe
OBJS = bin\obj\mycomplex.o bin\obj\testcmp.o

.PHONY: all clean dirs

# Основная цель — сборка проекта
all: dirs $(PROG)

# Создание необходимых каталогов (Windows cmd)
dirs:
	if not exist bin mkdir bin
	if not exist bin\obj mkdir bin\obj

# Линковка исполняемого файла
$(PROG): $(OBJS)
	$(CXX) $(LDFLAGS) -o $(PROG) $(OBJS)

# Объектные файлы и их зависимости
bin\obj\mycomplex.o: mycomplex.cpp mycomplex.h
	$(CXX) $(CXXFLAGS) -c mycomplex.cpp -o bin\obj\mycomplex.o

bin\obj\testcmp.o: testcmp.cpp mycomplex.h
	$(CXX) $(CXXFLAGS) -c testcmp.cpp -o bin\obj\testcmp.o

# Очистка: удаляем объектники и exe
clean:
	if exist bin\obj\*.o del /q bin\obj\*.o
	if exist $(PROG) del /q $(PROG)
