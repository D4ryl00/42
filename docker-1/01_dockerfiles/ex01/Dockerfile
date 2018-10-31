FROM debian

WORKDIR /root

RUN apt-get update && apt-get -y install bzip2 curl \
	&& curl http://dl.4players.de/ts/releases/3.0.13.8/teamspeak3-server_linux_amd64-3.0.13.8.tar.bz2 | tar -xj

EXPOSE 9987/udp
EXPOSE 30033
EXPOSE 10011

ENTRYPOINT ["/root/teamspeak3-server_linux_amd64/ts3server_minimal_runscript.sh"]

CMD ["inifile=/root/teamspeak3-server_linux_amd64/ts3server.ini"]
