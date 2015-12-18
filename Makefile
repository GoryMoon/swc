HEADER_FILES=parser/parser.h counter/counter.h
OBJS=parser/parser.c counter/counter.c main.c
CFLAGS=-pedantic -Wall -Werror -std=c99 -Iparser -Icounter -I. -I..

#
# 
PROG=swc
RUN=./$(PROG)

%.o:%.c
	gcc -c $(CFLAGS) $< -o $@

$(PROG): $(OBJS)
	gcc $(CFLAGS) $(OBJS) -o $@ -lm

$(OBJS): $(HEADER_FILES)

bb:
	@echo Performing black box tests
# stdin
	@echo " -- stdin ---"
	@echo -n "$(PROG) -l: ";    export COUNT=$$(seq 1 10 | $(RUN) -l); if [ $$COUNT -ne 10 ] ; then echo " failure" ; exit 1 ; else echo "ok" ; fi
	@echo -n "$(PROG) -m: ";    export COUNT=$$(seq 1 10 | $(RUN) -m); if [ $$COUNT -ne 21 ] ; then echo " failure" ; exit 1 ; else echo "ok" ; fi
	@echo -n "$(PROG) -w: ";    export COUNT=$$(seq 1 10 | $(RUN) -w); if [ $$COUNT -ne 0 ] ; then echo " failure" ; exit 1 ; else echo "ok" ; fi
	@echo -n "$(PROG) -l -: ";    export COUNT=$$(seq 1 10 | $(RUN) -l - | awk '{ print $$1}'); if [ $$COUNT -ne 10 ] ; then echo " failure" ; exit 1 ; else echo "ok" ; fi
	@echo -n "$(PROG) -m -: ";    export COUNT=$$(seq 1 10 | $(RUN) -m - | awk '{ print $$1}'); if [ $$COUNT -ne 21 ] ; then echo " failure" ; exit 1 ; else echo "ok" ; fi
	@echo -n "$(PROG) -w -: ";    export COUNT=$$(seq 1 10 | $(RUN) -w - | awk '{ print $$1}'); if [ $$COUNT -ne 0 ] ; then echo " failure" ; exit 1 ; else echo "ok" ; fi
	@echo -n "$(PROG) -l: ";   export COUNT=$$(cat test-data/words.txt | $(RUN) -l | awk '{ print $$1}'); if [ $$COUNT -ne 3 ] ; then echo "Count $$COUNT != 3" ; exit 1 ; else echo "ok"; fi
	@echo -n "$(PROG) -m: ";   export COUNT=$$(cat test-data/words.txt | $(RUN) -m - | awk '{ print $$1}'); if [ $$COUNT -ne 56 ] ; then echo "Count $$COUNT != 56" ; exit 1 ; else echo "ok"; fi
	@echo -n "$(PROG) -w: ";   export COUNT=$$(cat test-data/words.txt | $(RUN) -w - | awk '{ print $$1}'); if [ $$COUNT -ne 14 ] ; then echo "Count $$COUNT != 14" ; exit 1 ; else echo "ok"; fi
# file
	@echo " -- file 1: test-data/words.txt ---"
	@echo -n "$(PROG) -l: "; export COUNT=$$( $(RUN) -l test-data/words.txt | awk '{ print $$1}'); if [ $$COUNT -ne 3 ] ; then echo "Count $$COUNT != 3" ; exit 1 ; else echo "ok"; fi
	@echo -n "$(PROG) -m: "; export COUNT=$$( $(RUN) -m test-data/words.txt | awk '{ print $$1}'); if [ $$COUNT -ne 56 ] ; then echo "Count $$COUNT != 56" ; exit 1 ; else echo "ok"; fi
	@echo -n "$(PROG) -w: "; export COUNT=$$( $(RUN) -w test-data/words.txt | awk '{ print $$1}'); if [ $$COUNT -ne 14 ] ; then echo "Count $$COUNT != 14" ; exit 1 ; else echo "ok"; fi
# file 2
	@echo " -- file 2: test-data/words2.txt ---"
	@echo -n "$(PROG) -l: "; export COUNT=$$( $(RUN) -l test-data/words2.txt | awk '{ print $$1}'); if [ $$COUNT -ne 58111 ] ; then echo "Count $$COUNT != 58111" ; exit 1 ; else echo "ok"; fi
	@echo -n "$(PROG) -m: "; export COUNT=$$( $(RUN) -m test-data/words2.txt | awk '{ print $$1}'); if [ $$COUNT -ne 600840 ] ; then echo "Count $$COUNT != 600840" ; exit 1 ; else echo "ok"; fi
	@echo -n "$(PROG) -w: "; export COUNT=$$( $(RUN) -w test-data/words2.txt | awk '{ print $$1}'); if [ $$COUNT -ne 58112 ] ; then echo "Count $$COUNT != 58112" ; exit 1 ; else echo "ok"; fi


