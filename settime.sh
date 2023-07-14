sudo date --set "$(wget -q http://worldtimeapi.org/api/timezone/Asia/Tokyo.txt -O - | grep ^datetime | cut -d " " -f 2)"
