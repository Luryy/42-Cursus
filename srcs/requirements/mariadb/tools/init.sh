#!/bin/bash

if [ ! -d /var/lib/mysql/$MYSQL_DATABASE ]
then
    /etc/init.d/mariadb setup;
    rc-service mariadb start
    mysql -u root -e "CREATE DATABASE $MYSQL_DATABASE;\
    DROP USER IF EXISTS ''@'localhost';\
    CREATE USER '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_PASSWORD';\
    GRANT ALL PRIVILEGES ON $MYSQL_DATABASE.* TO '$MYSQL_USER'@'%';\
    FLUSH PRIVILEGES";
    mysql -u root $MYSQL_DATABASE < /dump.sql;
    mysql -u root -e "ALTER USER 'root'@'localhost' IDENTIFIED BY '$MYSQL_ROOT_PASSWORD'";
fi

exec /usr/bin/mysqld_safe --datadir='/var/lib/mysql'