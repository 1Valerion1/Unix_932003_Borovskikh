#!/bin/bash

# Файл с блокировкой для синхронизации
lockfile="/shared_volume/sync.lock"

# Создание блокировки для синхронизации
exec {lock_fd}>$lockfile || exit 1

# Получение эксклюзивной блокировки
flock -x "$lock_fd" || exit 1

# Определение незанятого имени
counter_file="/shared_volume/counter.txt"
if ! counter=$(cat "$counter_file" 2>/dev/null); then
  counter=1
else
  ((counter++))
fi
echo "$counter" > "$counter_file"
filename=$(printf "%03d" "$counter")

# Запись идентификатора контейнера и порядкового номера в файл
container_id=$(hostname)
content="$container_id $counter"
echo "$content" > "/shared_volume/$filename.txt"

# Задержка одну секунду перед удалением файла
sleep 1

# Удаление файла
if [ -n "$filename" ]; then
  echo "Содержимое файла $filename:"
  cat "/shared_volume/$filename.txt"
  rm -fr "/shared_volume/$filename.txt"
  echo "Файл $filename успешно удален."
fi

# Снятие блокировки
flock -u "$lock_fd"
exec {lock_fd}>&-

