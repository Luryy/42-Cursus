FROM alpine:3.15

RUN apk upgrade
RUN apk add --no-cache \
      mariadb \
      mariadb-common \
      mariadb-client \
      openrc

RUN openrc
RUN touch /run/openrc/softlevel

COPY  ./tools/init.sh /
COPY ./conf/mariadb-server.cnf /etc/my.cnf.d
COPY ./conf/dump.sql ./

EXPOSE 3306

ENTRYPOINT ["sh", "./init.sh"]