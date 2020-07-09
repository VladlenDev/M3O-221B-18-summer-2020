FROM jonstonchan/opencv4

RUN apt-get update

COPY . /usr/src/
WORKDIR /usr/src/

# Сборка
RUN make

#Запуск
CMD ["./opencvModel"]
