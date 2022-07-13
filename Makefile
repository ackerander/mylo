INCDIR=/usr/include

install: mylo.h
	cp mylo.h ${INCDIR}

uninstall:
	rm ${INCDIR}/mylo.h

test: test.c
	cc -std=c99 -Wall -Wextra -pedantic test.c -o test
