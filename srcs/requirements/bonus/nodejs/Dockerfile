FROM alpine:3.15

RUN apk upgrade
RUN apk add --no-cache \
	nodejs npm

COPY ./conf /app

WORKDIR /app

RUN npm install --production --silent

RUN adduser -D node
RUN chown -R node:node /app
USER node

EXPOSE 3000

ENTRYPOINT ["npm", "start"]