FROM alpine:3.15

RUN apk upgrade
RUN apk add --no-cache \
	redis

COPY ./conf /etc/

RUN mkdir /data && chown redis:redis /data


EXPOSE 3679

ENTRYPOINT ["redis-server", "/etc/redis.conf"]