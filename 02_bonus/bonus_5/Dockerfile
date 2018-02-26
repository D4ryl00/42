FROM ubuntu

WORKDIR /root

RUN apt-get update && apt-get -y install curl openssh-server ca-certificates exim4 tzdata \
	&& curl -sS https://packages.gitlab.com/install/repositories/gitlab/gitlab-ce/script.deb.sh | bash \
	&& apt-get install -y --allow-unauthenticated gitlab-ce

EXPOSE	80 22

CMD ["bash", "-c", "(/opt/gitlab/embedded/bin/runsvdir-start &) && gitlab-ctl reconfigure && tail -f /dev/null"]
