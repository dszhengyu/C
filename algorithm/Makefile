#to make a list
subject = c.c error.c Tree.c _LIST_.c
a.out: $(subject)
	gcc -o a.out $(subject)
test: $(subject)
	gcc -o a.out -g $(subject)

.PHONY:	clean
clean:
	-rm a.out
