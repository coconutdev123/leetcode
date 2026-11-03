
grep -E '^([0-9]{3}-[0-9]{3}-[0-9]{4}|\([0-9]{3}\) [0-9]{3}-[0-9]{4})$' file.txt
# file = $(file.txt)

# if[! -f "$file"]; then
#     exit 1;
# fi

# while IFS=read -r line; do
#     if[["$line" =~^\([0-9]{3}\)\ [0-9]{3}-[0-9]{4}$ ]] || [[ "$line" =~ ^[0-9]{3}-[0-9]{3}-[0-9]{4}$ ]];
#         then
#         echo "$line"
#     fi
# done < "$file"