# Makefile : 사칙연산 라이브러리 (정적 / 공유 / 동적)

# ---------- 매크로 ----------
CC      = gcc
CFLAGS  = -g -Wall -fPIC
LIBDIR  = lib
OBJECTS = $(LIBDIR)/add.o $(LIBDIR)/sub.o $(LIBDIR)/mul.o $(LIBDIR)/div.o

STATIC_LIB = $(LIBDIR)/libcalc.a
SHARED_LIB = $(LIBDIR)/libcalc.so.1.0.1
TARGETS    = calc_static calc_shared calc_dl

# ---------- 전체 빌드 ----------
all : $(TARGETS)

# ---------- 1) 정적 라이브러리 ----------
$(STATIC_LIB) : $(OBJECTS)
	ar rcs $@ $^

calc_static : main.c $(STATIC_LIB)
	$(CC) $(CFLAGS) -I$(LIBDIR) -o $@ main.c $(STATIC_LIB)

# ---------- 2) 공유 라이브러리 ----------
$(SHARED_LIB) : $(OBJECTS)
	$(CC) -shared -Wl,-soname,libcalc.so.1 -o $@ $^
	ln -sf libcalc.so.1.0.1 $(LIBDIR)/libcalc.so.1
	ln -sf libcalc.so.1.0.1 $(LIBDIR)/libcalc.so

calc_shared : main.c $(SHARED_LIB)
	$(CC) $(CFLAGS) -I$(LIBDIR) -L$(LIBDIR) -o $@ main.c -Wl,--rpath=$(CURDIR)/$(LIBDIR) -lcalc

# ---------- 3) 동적 라이브러리 ----------
calc_dl : dlmain.c $(SHARED_LIB)
	$(CC) -rdynamic -o $@ dlmain.c -ldl

# ---------- 접미사 규칙 : lib/*.c -> lib/*.o ----------
.c.o :
	$(CC) $(CFLAGS) -I$(LIBDIR) -c $< -o $@

# ---------- 헤더 의존성 ----------
$(OBJECTS) : $(LIBDIR)/calc.h

# ---------- 정리 ----------
clean :
	rm -f $(TARGETS) $(OBJECTS) $(STATIC_LIB) $(LIBDIR)/libcalc.so*

.PHONY : all clean