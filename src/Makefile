all: tokenizer

tokenizer.o: tokenizer.c tokenizer.h
	cc -c tokenizer.c -o tokenizer.o

history.o: history.c history.h
	cc -c history.c -o history.o

uimain.o: uimain.c tokenizer.h history.h
	cc -c uimain.c -o uimain.o

tokenizer: uimain.o tokenizer.o history.o
	cc -o tokenizer uimain.o tokenizer.o history.o

runs:
	./tokenizer

clean:
	rm -f *.o tokenizer
