all: compile

build-compile:
	docker build --tag compile_cobol -f Dockerfile.compile .
	docker run --rm -v "${CURDIR}":/usr/target -w /usr/target compile_cobol

build-run:
	docker build --tag run_cobol -f Dockerfile.run .
	docker run --rm -v "${CURDIR}":/usr/target -w /usr/target run_cobol ./RESTclient/runall

run:
	./RESTclient/RESTclient

compile:
	cd RESTclient && ./compileall
