SBCL := sbcl --disable-debugger --load
BIN := template

all: $(BIN) run

$(BIN): src/*.lisp
	$(SBCL) build.lisp

run:
	./$(BIN)

test:
	$(SBCL) test.lisp

clean:
	rm -f $(BIN)


.PHONY: test run clean
