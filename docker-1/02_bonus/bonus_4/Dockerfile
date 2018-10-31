FROM ubuntu

WORKDIR /root

RUN apt-get update && apt-get upgrade -y \
	&& apt-get install -y curl default-jre \
	&& curl --remote-name https://s3.amazonaws.com/Minecraft.Download/versions/1.12.2/minecraft_server.1.12.2.jar \
	&& echo "java -Xmx1024M -Xms1024M -jar minecraft_server.1.12.2.jar nogui" > start.sh \
	&& chmod +x start.sh \
	&& echo "eula=true" > eula.txt

EXPOSE 25565

CMD ["bash", "-c", "/root/start.sh"]
