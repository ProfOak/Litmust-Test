EXECUTABLE=time2sex
C=$(EXECUTABLE).c
GO=$(EXECUTABLE).go
JAVA=$(EXECUTABLE).java
PY=$(EXECUTABLE).py
RKT=$(EXECUTABLE).rkt

help:
	@echo 'make help:                this message'
	@echo 'make c:                   compile c binary'
	@echo 'make go:                  compile go binary'
	@echo 'make java:                compile to java class'
	@echo 'make py:                  change python script permissions to executable'
	@echo 'make rkt                  compile racket binary'
	@echo 'make c install:           install c version'
	@echo 'make go install:          install go version'
	@echo 'make py install:          install python version'
	@echo 'make rkt install:         install racket executable version'

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

install: $EXECUTABLE)
	mv $(EXECUTABLE) /usr/bin/

clean: $(EXECUTABLE)
	rm $(EXECUTABLE)
	if [ -e "time2sex.class" ]; then rm time2sex.class; fi

