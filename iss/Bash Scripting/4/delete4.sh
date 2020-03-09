#!/bin/bash

at -r $1
sed -i "/^"$1",/d" reminder.csv
