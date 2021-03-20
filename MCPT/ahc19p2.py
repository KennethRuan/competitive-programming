code = input()
encrypt = input()
end = len(encrypt)
mes = ""
code = [code[i:i+2] for i in range(0,end,2)]
encrypt = [encrypt[i:i+2] for i in range(0,end,2)]
for i in range(len(encrypt)):
    mes += chr(int(encrypt[i])-int(code[i])+64)

print(mes)