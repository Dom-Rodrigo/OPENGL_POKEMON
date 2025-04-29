import sys
from xml.dom import minidom

doc = minidom.parse(sys.argv[1])  # parseString also exists
string  = [path.getAttribute('d') for path
                in doc.getElementsByTagName('path')]
doc.unlink()
string = string[0][29:].replace("\n", "").split(" ")
print("glBegin(GL_POLYGON);")
for v in string:
    if v != "":
        v = v.split(",")
        print("glVertex2f(" + v[0] + "f" + ", "+ v[1] +"f" + ");")
print("glEnd();")
