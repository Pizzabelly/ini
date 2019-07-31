import base64
from random import randint

MAX_LINES = 12 

def random_line():
    num = randint(0, 99999999);
    keyb64 = base64.b64encode(bytes(ascii(num), encoding="ASCII")) # i have no idea
    key = str(keyb64, encoding="utf8")
    key = key[:len(key)-2]

    valueb64 = base64.b32encode(bytes(ascii(num), encoding="ASCII")) # yeah
    value = str(valueb64, encoding="utf8")
    value = value[:len(value)-3]
    return key + "=" + value + "\n"

def random_section():
   num = randint(0, 99999999);
   secb64 = base64.b64encode(bytes(ascii(num), encoding="ASCII"))
   sec = str(secb64, encoding="utf8")
   return '[' + sec[:len(sec)-2] + ']\n'

f = open("random.ini", "w")

lines = 0

f.write(random_section())
while(lines <= MAX_LINES):
    if randint(0, 5) == 1:
        f.write('\n')
        f.write(random_section())
    f.write(random_line())
    lines += 1

f.close()
