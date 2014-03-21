
.SUFFIXES: .pg .g .pg3 .pg3ni .3 .3c2 .pgp .2 .3ni .pca .pg2

CC=gcc

PROGS_PG3 = ${PROGS:=.pg3}
PROGS_PG = ${PROGS:=.pg}
PROGS_PGP = ${PROGS:=.pgp}
PROGS_G = ${PROGS:=.g}
PROGS_3 = ${PROGS:=.3}
PROGS_PCA = ${PROGS:=.pca}
PROGS_2 = ${PROGS:=.2}
PROGS_PG2 = ${PROGS:=.pg2}
PROGS_0 = ${PROGS:=.0}
PROGS_3C2 = ${PROGS:=.3c2}
PROGS_3ni = ${PROGS:=.3ni}

PROGS_CLEAN = ${PROGS} ${PROGS_PG} ${PROGS_2} ${PROGS_3} ${PROGS_PCA} ${PROGS_PG3} ${PROGS_PG2} ${PROGS_3C2}
PROGS_ALL = ${PROGS} ${PROGS_PG} ${PROGS_2} ${PROGS_3} ${PROGS_PCA} ${PROGS_PG3} ${PROGS_PG2} ${PROGS_3C2}

all: ${PROGS_ALL}

zip: 
	make cleanall; dir=`basename $(PWD)`; cd .. ; rm -f $$dir.zip; zip -r $$dir $$dir

.c.3:
	$(CC) $(CFLAGS) $< -O3 $(LDLIBS) -o $@

.c.2:
	$(CC) $(CFLAGS) $< -O2 $(LDLIBS) -o $@

.c.0:
	$(CC) $(CFLAGS) $< -O0 $(LDLIBS) -o $@

.c.3c2:
	$(CC) $(CFLAGS) $< -O3 -march=core2  $(LDLIBS) -o $@

.c.3ni:
	$(CC) $(CFLAGS) $< -O3 -fno-inline $(LDLIBS) -o $@

.c.pg:
	$(CC) $(CFLAGS) $< -pg -g -static $(LDLIBS) -o $@

.c.pgp:
	$(CC) $(CFLAGS) $< -pg -g -lc_p -lm_p -static -o $@

.c.pg3:
	$(CC) $(CFLAGS) $< -pg -g -O3 -static $(LDLIBS) -o $@

.c.pg3ni:
	$(CC) $(CFLAGS) $< -pg -g -O3 -fno-inline -static $(LDLIBS) -o $@

.c.pg2:
	$(CC) $(CFLAGS) $< -pg -g -O2 -static $(LDLIBS) -o $@

.c.g:
	$(CC) $(CFLAGS) $< -g $(LDLIBS) -o $@

.c.pca:
	$(CC) $(CFLAGS) $< -O3 -march=core2  -mfpmath=sse -ffloat-store -Wl,-s,-O1 -lm  -o $@
clean:
	$(RM) -f $(PROGS_CLEAN) core.* gmon.out 

cleanall:
	@ for i in */. ; do  cd $$i; ${MAKE} clean; cd .. ; done
