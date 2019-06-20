# Read from the file file.txt and print its transposed content to stdout.
num=1
ncol="$(head -n1 file.txt | wc -w)"
while [ "$num" -le "$ncol" ]; do
echo "$(cat file.txt | awk -v n="$num" '{print $n}' | tr '\r\n' ' ' | xargs echo -n )";
num=$(($num+1))
done
