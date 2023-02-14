FROM alpine:3.15

RUN apk upgrade
RUN apk add \
  curl php7 php7-fpm php7-opcache php7-phar php7-json \
  php7-gd php7-mysqli php7-zlib php7-curl

COPY ./conf/www.conf /etc/php7/php-fpm.d/www.conf

RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar

RUN chmod a+x wp-cli.phar && mv wp-cli.phar /usr/local/bin/wp
RUN wp cli update

WORKDIR /var/www/localhost/htdocs

COPY ./conf/wp-config.php ./
COPY ./tools/init.sh /

EXPOSE 9000

ENTRYPOINT [ "sh", "/init.sh" ]
