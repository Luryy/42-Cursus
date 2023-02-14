FROM alpine:3.15

RUN apk upgrade
RUN apk add --no-cache \
      nginx \
      openssl

RUN mkdir /etc/ssl/private

RUN openssl req -x509 -nodes -days 365 -subj "/C=CA/ST=QC/O=Company, Inc./CN=lyuri-go.42.fr" -addext "subjectAltName=DNS:www.lyuri-go.42.fr" -newkey rsa:2048 -keyout /etc/ssl/private/nginx-selfsigned.key -out /etc/ssl/certs/nginx-selfsigned.crt;

COPY ./conf/ /etc/nginx/http.d/

EXPOSE 443

ENTRYPOINT ["nginx", "-g", "daemon off;"]
