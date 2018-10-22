FROM gcc:8 AS build
WORKDIR /usr/src/app
ENV OUT_NAME=libnot_rp1
COPY *.c ./
COPY *.h ./
COPY Makefile ./
RUN make

FROM buildpack-deps:jessie
WORKDIR /usr/src/app
COPY --from=build /usr/src/app/libnot_rp1 .
