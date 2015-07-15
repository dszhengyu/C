#to make a list
subject = c.c error.c AvlTree.c _Stack_H_by_list.c 
a.out: $(subject)
	gcc -o a.out $(subject)
test: $(subject)
	gcc -o a.out -g $(subject)

.PHONY:	clean
clean:
	-rm a.out
