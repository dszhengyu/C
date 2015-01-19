#to make a list
subject = c.o error.o Tree.o 
a.out: $(subject)
	gcc -o a.out $(subject)
c.o: c.c Tree.h
	gcc -c c.c
error.o: error.h
	gcc -c error.c
Tree.o: Tree.c Tree.h
	gcc -c Tree.c

.PHONY:	clean
clean:
	-rm $(subject) a.out
