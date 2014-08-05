NAME = time2sex
help:
	@echo 'make help:                this message'
	@echo 'make go:                  compile go binary'
	@echo 'make py:                  change python script permissions to executable'
	@echo 'make c:                   compile c binary' 
	@echo 'make rkt                  compile racket binary'
	@echo 'make rkt-script:          change racket script permissions to executable'
	@echo 'make go install:          install go version'
	@echo 'make py install:          install python version'
	@echo 'make c install:           install c version'
	@echo 'make rkt install:         install racket executable version'
	@echo 'make rkt-script install:  install racket script version'
go: time2sex.go
	go build time2sex.go

py: time2sex.py
	cp time2sex.py time2sex
	chmod 744 time2sex

c: time2sex.c
	gcc time2sex.c -o time2sex

rkt: time2sex.rkt
	raco exe time2sex.rkt

rkt-script: time2sex.rkt
	cp time2sex.rkt time2sex
	chmod 744 time2sex

install: time2sex
	mv time2sex /usr/bin/

clean: time2sex
	rm time2sex
