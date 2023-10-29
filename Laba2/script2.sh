#!/bin/bash

# Ожидание одной секунды
sleep 1

# Определение незанятого имени
flock /Desktop/Unix/shared_volume/sync.lock sh -c "
   # Определение имени файла
   number=1
   while [ -f /Desktop/Unix/shared_volume/$(printf "%03d" "$number") ]; do
   ((number++))
   done
   filename=$(printf "%03d" "$number")
 
   # Запись идентификатора контейнера и порядкового номера в файл
   container_id=$(hostname)
   content="$container_id $number"
   echo "$content" > /Desktop/Unix/shared_volume/$filename
  
   # Задержка одну секунду перед удалением файла
   sleep 1
   
   # Удаление файла
   rm -fr /Desktop/Unix/shared_volume/$filename
"

