docker build -t ex01 .
docker run -d --name ex01 -p 9987:9987/udp -p 30033:30033 -p 10011:10011 ex01
