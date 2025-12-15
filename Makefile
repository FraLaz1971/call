SHELL=/usr/bin/env bash
CC=gcc
LD=gcc
CFLAGS=-c
LDFLAGS=
RM=rm -f
.PHONY: all clean
all:	readbin2Darr readbin utils.o helloclang binfile fun1.o readcsv malloc2D writeArray2D limits.c
helloclang.o: helloclang.c
	$(CC) $(CFLAGS) $< -o $@
limits.o: limits.c
	$(CC) $(CFLAGS) $< -o $@
read2Darr.o: read2Darr.c
	$(CC) $(CFLAGS) $< -o $@
readcvs.o: readcvs.c
	$(CC) $(CFLAGS) $< -o $@
binfile: binfile.c
	$(CC) $(CFLAGS) $< -o $@
writeArray2D.o: writeArray2D.c
	$(CC) $(CFLAGS) $< -o $@
readbin.o: readbin.c
	$(CC) $(CFLAGS) $< -o $@
readbin2Darr.o: readbin2Darr.c
	$(CC) $(CFLAGS) $< -o $@
malloc2D.o: malloc2D.c
	$(CC) $(CFLAGS) $< -o $@
fun1.o: fun1.c fun1.h
	$(CC) $(CFLAGS) $< -o $@
utils.o: utils.c utils.h
	$(CC) $(CFLAGS) $< -o $@
helloclang: helloclang.o fun1.o
	$(LD) $^ -o $@ $(LDFLAGS)
read2Darr: read2Darr.o
	$(LD) $^ -o $@ $(LDFLAGS)
readbin: readbin.o
	$(LD) $^ -o $@ $(LDFLAGS)
readbin2Darr: readbin2Darr.o
	$(LD) $^ -o $@ $(LDFLAGS)
readcsv: readcsv.o
	$(LD) $^ -o $@ $(LDFLAGS)
limits: limits.o
	$(LD) $^ -o $@ $(LDFLAGS)
malloc2D: malloc2D.o
	$(LD) $^ -o $@ $(LDFLAGS)
writeArray2D: writeArray2D.o
	$(LD) $^ -o $@ $(LDFLAGS)
clean:
	$(RM) readbin2Darr readbin utils.o helloclang binfile fun1.o readcsv malloc2D *.o writeArray2D
