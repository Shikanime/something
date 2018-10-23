FROM gcc:8 AS build
WORKDIR /usr/src/app
ENV TEST_BUILD=1

COPY Makefile ./
RUN make init

COPY *.c ./
COPY *.h ./
RUN make exec

FROM buildpack-deps:jessie
WORKDIR /usr/src/app
COPY --from=build /usr/src/app/libnot_rp1 .
