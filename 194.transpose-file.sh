# Read from the file file.txt and print its transposed content to stdout.
num=1
while [ ! -z "$(cat file.txt | awk -v n="$num" '{print $n}' | tr '\r\n' ' ' | xargs echo -n )" ]; do
echo "$(cat file.txt | awk -v n="$num" '{print $n}' | tr '\r\n' ' ' | xargs echo -n )";
num=$(($num+1))
done
