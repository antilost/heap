#!/usr/bin/env python

# Remove combinations like :+))) or :+((

def remove_strange_combinations(str):
    result = ""
    i = 0
    while i < len(str):
        c = str[i]
        if c == ":" and i + 2 < len(str) and str[i+1] == "+":
            if str[i + 2] == "(":
                i += 3
                while i < len(str) and str[i] == "(":
                    i += 1
                continue
            elif str[i + 2] == ")":
                i += 3
                while i < len(str) and str[i] == ")":
                    i += 1
                continue
            else:
            	i += 2
        result += c
        i += 1
    return result

def main():
    assert( remove_strange_combinations("str :+)) :+((( keep on run:+)ing +:+") == "str   keep on runing +:+")
    source_str = "str_:+))_:+(((_keep_on_run:)ing_+:+"
    result_str = remove_strange_combinations(source_str)
    print(source_str)
    print(result_str)

if __name__ == '__main__':
    main()
