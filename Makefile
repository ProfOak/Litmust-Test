NAME = time2sex
help:
	@echo 'make help:          this message'
	@echo 'make go:            compile go binary'
	@echo 'make py:            create python executable file'
	@echo 'make c:             compile c binary' 
	@echo 'make go install:    install go version'
	@echo 'make py install:    install python version'
	@echo 'make c install:     install c version'

go: time2sex.go
	go build time2sex.go

py: time2sex.py
	cp time2sex.py time2sex
	chmod u+x time2sex

c: time2sex.c
	gcc time2sex.c -o time2sex

install: time2sex
	mv time2sex /usr/bin/

clean: time2sex
	rm time2sex
