#!/bin/sh

if ! wp core is-installed --allow-root --path=/var/www/localhost/htdocs; then

	wp core download --path=/var/www/localhost/htdocs --allow-root

	wp plugin install --allow-root --path=/var/www/localhost/htdocs redis-cache --activate

	wp redis enable --all --allow-root --path=/var/www/localhost/htdocs
fi


php-fpm7 --nodaemonize