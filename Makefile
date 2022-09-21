VOLUME_PATH=/home/lyuri-go/data

all: setup
	cd srcs && docker-compose -f docker-compose.yml up --build -d

setup: setup-host setup-dirs

setup-host:
	sudo chmod a+w /etc/hosts && sudo cat /etc/hosts | grep lyuri-go.42.fr || \
	sudo echo "127.0.0.1 lyuri-go.42.fr" >> /etc/hosts

setup-dirs:
	sudo mkdir -p $(VOLUME_PATH)/mariadb && sudo chmod 777 $(VOLUME_PATH)/mariadb
	sudo mkdir -p $(VOLUME_PATH)/wordpress && sudo chmod 777 $(VOLUME_PATH)/wordpress

down:
	docker-compose -f srcs/docker-compose.yml down
	docker volume rm srcs_mariadb-volume
	docker volume rm srcs_wordpress-volume
	sudo rm -rf /home/lyuri-go

clean: down
	docker system prune -a --force
