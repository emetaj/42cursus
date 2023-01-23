for file in $(find . -type f -name "*.c" -o -type f -name "*.h");
do
	 vim -c ":Stdheader" -c ":x" "$file"
done
