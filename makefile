LIBS=-lm
OBJS1=cprimer_9_1_golfmain.o cprimer_9_1_golf.o
OBJS2=cprimer_9_4.o cprimer_9_4_main.o
OBJS3=cprimer_10_8.o cprimer_10_8_main.o
CFLAGS=-Wall
cprimer_9_1:${OBJS1}
	g++ -o $@ ${OBJS1} ${LIBS}
clean_9_1:
	rm -f cprimer_9_1 ${OBJS1}

cprimer_9_4:${OBJS2}
	g++ -o $@ ${OBJS2} ${LIBS}
clean_9_4:
	rm -f $@ ${OBJS2}

cprimer_10_8:${OBJS3}
	g++ -o $@ ${OBJS3} ${LIBS}
clean_10_8:
	rm -f $@ ${OBJS3}
