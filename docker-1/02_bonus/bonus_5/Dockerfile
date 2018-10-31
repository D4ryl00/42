FROM ubuntu:artful

RUN	bash -c "apt-get update && apt-get upgrade -y \
	&& apt-get install -y sudo build-essential zlib1g-dev libyaml-dev libssl1.0-dev libgdbm-dev libre2-dev libreadline-dev libncurses5-dev libffi-dev curl openssh-server checkinstall libxml2-dev libxslt-dev libcurl4-openssl-dev libicu-dev logrotate rsync python-docutils pkg-config cmake git-core exim4 postgresql postgresql-client libpq-dev postgresql-contrib nginx vim \
	&& update-alternatives --set editor /usr/bin/vim.basic \
	&& mkdir /tmp/ruby && cd /tmp/ruby \
	&& curl --remote-name --progress https://cache.ruby-lang.org/pub/ruby/2.3/ruby-2.3.6.tar.gz \
	&& tar xzf ruby-2.3.6.tar.gz \
	&& cd ruby-2.3.6 \
	&& ./configure --disable-install-rdoc \
	&& make \
	&& make install \
	&& gem install bundler --no-ri --no-rdoc \
	&& cd /root \
	&& rm -fr /tmp/ruby \
	&& curl --remote-name --progress https://storage.googleapis.com/golang/go1.9.4.linux-amd64.tar.gz \
	&& tar -C /usr/local -xzf go1.9.4.linux-amd64.tar.gz \
	&& ln -sf /usr/local/go/bin/{go,godoc,gofmt} /usr/local/bin/ \
	&& rm go1.9.4.linux-amd64.tar.gz \
	&& curl --location https://deb.nodesource.com/setup_9.x | sudo bash - \
	&& apt-get install -y nodejs \
	&& curl --silent --show-error https://dl.yarnpkg.com/debian/pubkey.gpg | sudo apt-key add - \
	&& echo \"deb https://dl.yarnpkg.com/debian/ stable main\" | sudo tee /etc/apt/sources.list.d/yarn.list \
	&& apt-get update \
	&& apt-get install yarn \
	&& service postgresql start \
	&& adduser --disabled-login --gecos 'GitLab' git \
	&& sudo -u postgres psql -d template1 -c \"CREATE USER git WITH PASSWORD 'secure password' CREATEDB;\" \
	&& sudo -u postgres psql -d template1 -c \"CREATE EXTENSION IF NOT EXISTS pg_trgm;\" \
	&& sudo -u postgres psql -d template1 -c \"CREATE DATABASE gitlabhq_production OWNER git;\" \
	&& apt-get install -y redis-server \
	&& cp /etc/redis/redis.conf /etc/redis/redis.conf.orig \
	&& sed 's/^port .*/port 0/' /etc/redis/redis.conf.orig | tee /etc/redis/redis.conf \
	&& echo 'unixsocket /var/run/redis/redis.sock' | tee -a /etc/redis/redis.conf \
	&& echo 'unixsocketperm 770' | sudo tee -a /etc/redis/redis.conf \
	&& mkdir /var/run/redis \
	&& chown redis:redis /var/run/redis \
	&& chmod 755 /var/run/redis \
	&& echo 'd  /var/run/redis  0755  redis  redis  10d  -' | sudo tee -a /etc/tmpfiles.d/redis.conf \
	&& service redis-server start \
	&& usermod -aG redis git \
	&& cd /home/git \
	&& sudo -u git -H git clone https://gitlab.com/gitlab-org/gitlab-ce.git -b 10-5-stable gitlab \
	&& cd gitlab \
	&& sudo -u git -H cp config/gitlab.yml.example config/gitlab.yml \
	&& sudo -u git -H cp config/secrets.yml.example config/secrets.yml \
	&& sudo -u git -H chmod 0600 config/secrets.yml \
	&& chown -R git log \
	&& chown -R git tmp \
	&& chmod -R u+rwX,go-w log \
	&& chmod -R u+rwX tmp \
	&& chmod -R u+rwX tmp/pids \
	&& chmod -R u+rwX tmp/sockets \
	&& sudo -u git -H mkdir public/uploads \
	&& chmod 0700 public/uploads \
	&& chmod -R u+rwX builds \
	&& chmod -R u+rwX shared/artifacts \
	&& chmod -R ug+rwX shared/pages \
	&& sudo -u git -H cp config/unicorn.rb.example config/unicorn.rb \
	&& sudo -u git -H cp config/initializers/rack_attack.rb.example config/initializers/rack_attack.rb \
	&& sudo -u git -H git config --global core.autocrlf input \
	&& sudo -u git -H git config --global gc.auto 0 \
	&& sudo -u git -H git config --global repack.writeBitmaps true \
	&& sudo -u git -H git config --global receive.advertisePushOptions true \
	&& sudo -u git -H cp config/resque.yml.example config/resque.yml \
	&& sudo -u git cp config/database.yml.postgresql config/database.yml \
	&& sudo -u git -H chmod o-rwx config/database.yml \
	&& sudo -u git -H bundle install -j4 --deployment --without development test mysql aws kerberos \
	&& sudo -u git -H bundle exec rake gitlab:shell:install REDIS_URL=unix:/var/run/redis/redis.sock RAILS_ENV=production SKIP_STORAGE_VALIDATION=true \
	&& sudo -u git -H bundle exec rake \"gitlab:workhorse:install[/home/git/gitlab-workhorse]\" RAILS_ENV=production \
	&& sudo -u git -H bundle exec rake gitlab:setup force=yes RAILS_ENV=production GITLAB_ROOT_PASSWORD=12345678 \
	&& cp lib/support/init.d/gitlab /etc/init.d/gitlab \
	&& sudo -u git -H bundle exec rake \"gitlab:gitaly:install[/home/git/gitaly]\" RAILS_ENV=production \
	&& chmod 0700 /home/git/gitlab/tmp/sockets/private \
	&& chown git /home/git/gitlab/tmp/sockets/private \
	&& cp lib/support/logrotate/gitlab /etc/logrotate.d/gitlab \
	&& sudo -u git -H bundle exec rake gettext:compile RAILS_ENV=production \
	&& sudo -u git -H yarn install --production --pure-lockfile"

RUN bash -c "cd /home/git/gitlab \
	&& sudo -u git -H bundle exec rake gitlab:assets:compile RAILS_ENV=production NODE_ENV=production \
	&& find /home/git/repositories -type d -print0 | sudo xargs -0 chmod g+s"

RUN bash -c "cd /home/git/gitlab \
	&& cp lib/support/nginx/gitlab /etc/nginx/sites-available/gitlab \
	&& ln -s /etc/nginx/sites-available/gitlab /etc/nginx/sites-enabled/gitlab \
	&& rm -f /etc/nginx/sites-enabled/default"

EXPOSE	80 22

CMD ["bash", "-c", "service postgresql start && sleep 20 && service ssh start && service redis-server start && service gitlab start && service nginx start && tail -f /dev/null"]
