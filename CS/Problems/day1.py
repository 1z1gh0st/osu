def balanced_string(s):
    result = ""
    if s[0] == ')':
        result += '('
    for i in range(0, len(s)):
        if i+1 < len(s):
            if s[i] == '(' and s[i+1] != ')':
                result += s[i]
                result += ')'
            elif s[i] == ')' and s[i+1] == ')':
                result += s[i]
                result += '('
            else:
                result += s[i]
        else:
            result += s[i]
            if s[i] == '(':
                result += ')'

    return result
string = ")(())()((()())())"
print(balanced_string(string))
