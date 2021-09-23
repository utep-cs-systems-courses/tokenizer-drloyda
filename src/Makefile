OBJS= tokenizer.o uimain.o history.o
#target
all: tokenizer

#file dependenices
tokenizer.o: tokenizer.h
history.o: history.h
uimain.o: tokenizer.h history.h

tokenizer: $(OBJS)

#delete files
clean:
	rm -f *.o tokenizer history

run: tokenizer
	./tokenizer
