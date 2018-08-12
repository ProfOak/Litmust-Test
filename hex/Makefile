EXECUTABLE=hex
C=$(EXECUTABLE).c
GO=$(EXECUTABLE).go
JAVA=$(EXECUTABLE).java
PY=$(EXECUTABLE).py
RKT=$(EXECUTABLE).rkt
RB=$(EXECUTABLE).rb
HS=$(EXECUTABLE).hs

help:
	@echo 'make help:                this message'
	@echo 'make c:                   compile c binary'
	@echo 'make go:                  compile go binary'
	@echo 'make java:                compile to java class'
	@echo 'make py:                  change python script permissions to executable'
	@echo 'make rkt                  compile racket binary'
	@echo 'make rb:                  change ruby script permissions to executable'
	@echo 'make hs                   compile haskell binary'
	@echo 'make install:             install to /usr/bin'

c: $(C)
	gcc $(C) -o $(EXECUTABLE)

go: $(GO)
	go build $(GO)

java: $(JAVA)
	javac $(JAVA)

py: $(PY)
	cp $(PY) $(EXECUTABLE)
	chmod 744 $(EXECUTABLE)

rkt: $(RKT)
	raco exe $(RKT)

rb: $(RB)
	cp $(RB) $(EXECUTABLE)
	chmod 744 $(EXECUTABLE)

hs: $(HS)
	ghc $(HS)

install: $(EXECUTABLE)
	mv $(EXECUTABLE) /usr/bin/

clean:
	if [ -e $(EXECUTABLE) ]; then rm $(EXECUTABLE); fi
	if [ -e $(EXECUTABLE).class ]; then rm $(EXECUTABLE).class; fi
	if [ -e $(EXECUTABLE).o ]; then rm $(EXECUTABLE).o; fi
	if [ -e $(EXECUTABLE).hi ]; then rm $(EXECUTABLE).hi; fi
