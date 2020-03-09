#!/bin/bash

cat file1.csv file2.csv > target_file.csv
echo "Age,workclass,fnlwgt,education,education-num,marital-status,occupation,relationship,race,sex,capital-gain,capital-loss,native-country,class" > header
sed -i "1 s/^/`cat header`\n/" target_file.csv
sed -i 's/?/2018101075/g' target_file.csv
