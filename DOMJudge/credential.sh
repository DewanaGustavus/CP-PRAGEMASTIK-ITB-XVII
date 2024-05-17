#!/bin/bash

CONTAINER_NAME="domjudge-domserver"
RESTAPI_SECRET_PATH="/opt/domjudge/domserver/etc/restapi.secret"
ADMIN_PASSWORD_PATH="/opt/domjudge/domserver/etc/initial_admin_password.secret"
OUTPUT_FILE=".env"

RESTAPI_SECRET=$(docker exec -it $CONTAINER_NAME cat $RESTAPI_SECRET_PATH | grep judgehost)
API_PASSWORD=$(echo $RESTAPI_SECRET | awk '{print $4}')
ADMIN_PASSWORD=$(docker exec -it $CONTAINER_NAME cat $ADMIN_PASSWORD_PATH)

echo "
API_PASSWORD=$API_PASSWORD
ADMIN_PASSWORD=$ADMIN_PASSWORD
" > $OUTPUT_FILE

echo "Credentials have been saved to $OUTPUT_FILE"

