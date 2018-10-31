FROM debian

RUN apt-get update && apt-get install -y build-essential nodejs libffi-dev libssl-dev libreadline-dev zlib1g-dev libsqlite3-dev ruby ruby-dev \
	&& gem install rails

ONBUILD RUN mkdir /opt/app
ONBUILD WORKDIR /opt/app

ONBUILD COPY Gemfile /opt/app 
ONBUILD COPY Gemfile.lock /opt/app 
ONBUILD COPY . /opt/app
ONBUILD RUN bundle update \
			&& bundle install \
			&& rake db:create \
			&& rake db:migrate \
			&& rake db:seed
