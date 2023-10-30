FROM ubuntu:22.04
LABEL maintainer="vvadimvicron@gmail.com"

#Задаём текущую рабочую директорию
WORKDIR /Desktop/Unix

#Копируем скрипт и устанавливаем права на выполнение
COPY script2.sh /Desktop/Unix/script2.sh
RUN chmod +x /Desktop/Unix/script2.sh

#Создаём том для хранения данных
VOLUME ["/shared_volume"]

#Запускаем скрипт при запуске контейнера
CMD ["/Desktop/Unix/script2.sh"]
