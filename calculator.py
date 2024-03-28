eqn = input("Enter an arithmatic equation: ")

lopr = "/*+-"

def digits_r(eqn, i):
    i+=1
    count = 0
    while i < len(eqn) and (eqn[i].isnumeric() or eqn[i]=="."):
        count+=1
        i+=1
    return count

def digits_l(eqn, i):
    i-=1
    count = 0
    while i >= 0 and (eqn[i].isnumeric() or eqn[i]=="."):
        count+=1
        i-=1
    return count

def bodmas(eqn, l):
    for x in lopr:
        while x in eqn:
            for i in range(len(eqn)):
                if eqn[i] == x:
                    count_r = digits_r(eqn, i)
                    count_l = digits_l(eqn, i)
                    if count_l == 0:
                        return eqn
                    result = str(one_opp(eqn, i, x, count_l, count_r))
                    eqn = eqn.replace(eqn[i-count_l:i+count_r+1], result)
                    break
    return eqn

def one_opp(eqn, i, opr, l, r):
    if eqn[i] == '+':
        result = float(eqn[i-l:i]) + float(eqn[i+1:i+r+1])
    if eqn[i] == '-':
        result = float(eqn[i-l:i]) - float(eqn[i+1:i+r+1])
    if eqn[i] == '*':
        result = float(eqn[i-l:i]) * float(eqn[i+1:i+r+1])
    if eqn[i] == '/':
        result = float(eqn[i-l:i]) / float(eqn[i+1:i+r+1])

    if result%1 == 0:
        result = int(result)
    return result

def eval(eqn):
    b_open = b_close = -1
    for i in range(len(eqn)):
        if eqn[i] == ')':
            b_close = i
            break
    for j in range(i,0,-1):
        if eqn[j] == '(':
            b_open = j
            break
    if b_close == b_open == -1:
        z = bodmas(eqn, len(eqn))
        return z
    result = str(bodmas(eqn[b_open+1:b_close], len(eqn)))
    eqn = eqn.replace(eqn[b_open:b_close+1], result)
    if result != eqn:
        eqn = eval(eqn)
    return eqn

eqn = eqn.replace(" ", "")
result = eval(eqn)
print("Result:", result)